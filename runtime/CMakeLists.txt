# The PS2Recomp parts the port uses (runtime/README.md). Replaces upstream's top-level CMakeLists.txt, which also
# builds the analyzer, the studio, the unit tests and the Android/Vita targets.

add_library(ps2x_simd_compat INTERFACE)
if(CMAKE_SYSTEM_PROCESSOR MATCHES "^(arm64|aarch64|ARM64)$" OR CMAKE_OSX_ARCHITECTURES STREQUAL "arm64")
    include(FetchContent)
    FetchContent_Declare(
        sse2neon
        URL https://github.com/DLTcollab/sse2neon/archive/refs/tags/v1.9.1.tar.gz
        URL_HASH SHA256=6b70e7cb8c5ce4641002b85deaafe97efdf9ade9b49884edeaf678b35f0e132f
        DOWNLOAD_EXTRACT_TIMESTAMP TRUE
    )
    FetchContent_MakeAvailable(sse2neon)
    target_include_directories(ps2x_simd_compat INTERFACE "${sse2neon_SOURCE_DIR}")
    target_compile_definitions(ps2x_simd_compat INTERFACE USE_SSE2NEON=1)
endif()

if(URBAN_BUILD_RECOMP)
    add_subdirectory(ps2xRecomp)
endif()

add_subdirectory(ps2xIOP)
add_subdirectory(ps2xRuntime)

if(URBAN_BUILD_TOOLS)
    add_subdirectory(ps2xTest)
endif()
