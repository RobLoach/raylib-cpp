#include <cassert>
#include <string>
#include <vector>
#include "raylib-cpp.hpp"

int main(int argc, char *argv[]) {
    TraceLog(LOG_INFO, "TEST: raylib-cpp test");

    // Get a path to where the executable is so file loading is relative.
    std::string path = "";
    if (argc > 0) {
        path = GetDirectoryPath(argv[0]);
    }

    // Vector
    {
        raylib::Vector2 position(50, 100);
        assert(position.GetX() == position.x);
        position.x = 150;
        assert(position.GetX() == 150);
        position.SetX(300);
        assert(position.GetX() == 300);

        raylib::Vector2 speed(10, 10);
        position += speed;
        assert(position.x == 310);
        assert(raylib::Window::IsReady() == false);
    }

    // Color
    {
        raylib::Color color = RED;
        assert(color.ToInt() == ::ColorToInt(RED));
        color = RAYWHITE;
        assert(color.r == RAYWHITE.r);
    }

    // Math
    {
        raylib::Vector2 direction(50, 50);
        raylib::Vector2 newDirection = direction.Rotate(30);
        assert(((int)newDirection.x) == 57);
    }

    // raylib::GetDirectoryFiles()
    {
        std::vector<std::string> files = raylib::GetDirectoryFiles(::GetWorkingDirectory());
        assert(files.size() > 3);
    }

    // Sound
    {
        raylib::Wave wave(path + "/resources/weird.wav");
        assert(wave.IsLoaded());
    }

    TraceLog(LOG_INFO, "TEST: raylib-cpp test complete");
    return 0;
}
