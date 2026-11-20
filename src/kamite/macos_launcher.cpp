#include <mach-o/dyld.h>
#include <unistd.h>

#include <cerrno>
#include <cstdio>
#include <cstring>
#include <filesystem>
#include <string>
#include <vector>

int main(int argc, char **argv)
{
    uint32_t pathSize = 0;
    _NSGetExecutablePath(nullptr, &pathSize);
    std::vector<char> launcherPath(pathSize);
    if (_NSGetExecutablePath(launcherPath.data(), &pathSize) != 0)
    {
        std::fputs("GHR.app: could not determine the launcher path\n", stderr);
        return 1;
    }

    std::error_code error;
    const std::filesystem::path launcher = std::filesystem::weakly_canonical(launcherPath.data(), error);
    if (error)
    {
        std::fprintf(stderr, "GHR.app: could not resolve the launcher path: %s\n", error.message().c_str());
        return 1;
    }

    const std::filesystem::path game = launcher.parent_path().parent_path().parent_path().parent_path() / "GHR";
    if (!std::filesystem::is_regular_file(game, error))
    {
        std::fprintf(stderr, "GHR.app: game executable not found at %s\n", game.c_str());
        return 1;
    }
    if (chdir(game.parent_path().c_str()) != 0)
    {
        std::fprintf(stderr, "GHR.app: could not use %s as the game folder: %s\n", game.parent_path().c_str(),
                     std::strerror(errno));
        return 1;
    }
    if (dup2(STDOUT_FILENO, STDERR_FILENO) < 0)
    {
        std::fprintf(stderr, "GHR.app: could not combine the game output: %s\n", std::strerror(errno));
        return 1;
    }

    const std::string gamePath = game.string();
    std::vector<char *> arguments;
    arguments.reserve(static_cast<size_t>(argc) + 1u);
    arguments.push_back(const_cast<char *>(gamePath.c_str()));
    for (int i = 1; i < argc; ++i)
        arguments.push_back(argv[i]);
    arguments.push_back(nullptr);

    execv(gamePath.c_str(), arguments.data());
    std::fprintf(stderr, "GHR.app: could not start %s: %s\n", gamePath.c_str(), std::strerror(errno));
    return 1;
}
