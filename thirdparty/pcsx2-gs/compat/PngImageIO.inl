// PNG loading for texture replacement through macOS ImageIO.
// Same output as PCSX2's PNGLoader: 32-bit RGBA rows; images without alpha get A = 0x80.

#include <CoreFoundation/CoreFoundation.h>
#include <CoreGraphics/CoreGraphics.h>
#include <ImageIO/ImageIO.h>
#include <limits>

bool PNGLoader(GSTextureReplacements::File& file, const char* filename,
	GSTextureReplacements::ReplacementTexture* tex, bool only_base_image)
{
	(void)only_base_image;
	const s64 size = file.Size();
	if (size <= 0 || size > 0x7FFFFFFF || !file.Seek(0))
		return false;

	std::vector<u8> bytes(static_cast<size_t>(size));
	if (!file.Read(bytes.data(), bytes.size()))
		return false;

	CFDataRef data = CFDataCreate(kCFAllocatorDefault, bytes.data(), static_cast<CFIndex>(bytes.size()));
	CGImageSourceRef source = data ? CGImageSourceCreateWithData(data, nullptr) : nullptr;
	CGImageRef image = source ? CGImageSourceCreateImageAtIndex(source, 0, nullptr) : nullptr;
	if (!image)
	{
		if (source)
			CFRelease(source);
		if (data)
			CFRelease(data);
		Console.Error("Failed to decode replacement texture %s", filename);
		return false;
	}

	const size_t width = CGImageGetWidth(image);
	const size_t height = CGImageGetHeight(image);
	const bool valid_size = width > 0 && height > 0 && width <= 32768 && height <= 32768 &&
		width <= (std::numeric_limits<size_t>::max() / 4u) &&
		height <= (std::numeric_limits<size_t>::max() / (width * 4u));
	if (!valid_size)
	{
		CGImageRelease(image);
		CFRelease(source);
		CFRelease(data);
		return false;
	}

	const CGImageAlphaInfo alpha_info = CGImageGetAlphaInfo(image);
	const bool has_alpha = alpha_info != kCGImageAlphaNone &&
		alpha_info != kCGImageAlphaNoneSkipFirst && alpha_info != kCGImageAlphaNoneSkipLast;
	const size_t pitch = width * 4u;
	tex->width = static_cast<u32>(width);
	tex->height = static_cast<u32>(height);
	tex->format = GSTexture::Format::Color;
	tex->pitch = static_cast<u32>(pitch);
	tex->data.assign(pitch * height, 0u);

	CGColorSpaceRef color_space = CGColorSpaceCreateDeviceRGB();
	CGContextRef context = color_space ? CGBitmapContextCreate(tex->data.data(), width, height, 8u, pitch, color_space,
		static_cast<CGBitmapInfo>(static_cast<uint32_t>(kCGImageAlphaPremultipliedLast) |
			static_cast<uint32_t>(kCGBitmapByteOrder32Big))) : nullptr;
	if (context)
	{
		CGContextSetBlendMode(context, kCGBlendModeCopy);
		CGContextDrawImage(context, CGRectMake(0.0, 0.0, static_cast<double>(width), static_cast<double>(height)), image);
		CGContextRelease(context);
	}
	if (color_space)
		CGColorSpaceRelease(color_space);
	CGImageRelease(image);
	CFRelease(source);
	CFRelease(data);
	if (!context)
		return false;

	for (u8* pixel = tex->data.data(), *end = pixel + tex->data.size(); pixel != end; pixel += 4)
	{
		if (!has_alpha)
		{
			pixel[3] = 0x80;
			continue;
		}
		const u32 alpha = pixel[3];
		if (alpha > 0u && alpha < 255u)
		{
			for (u32 channel = 0; channel < 3u; ++channel)
				pixel[channel] = static_cast<u8>(std::min(255u, (static_cast<u32>(pixel[channel]) * 255u + alpha / 2u) / alpha));
		}
	}
	return true;
}

bool GSTextureReplacements::SavePNGImage(const std::string& filename, u32 width, u32 height, const u8* buffer, u32 pitch)
{
	return false;
}
