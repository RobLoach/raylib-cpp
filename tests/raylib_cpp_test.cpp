#include "raylib-assert.h"
#include "raylib-cpp.hpp"
#include <string>
#include <vector>

int main(int argc, char* argv[]) {
    TraceLog(LOG_INFO, "---------------------");
    TraceLog(LOG_INFO, "TEST: raylib-cpp test");

    // Get a path to where the executable is so file loading is relative.
    std::string path = "";
    if (argc > 0) {
        path = GetDirectoryPath(argv[0]);
    }

    // Vector
    {
        raylib::Vector2 position(50, 100);
        AssertEqual(position.GetX(), position.x);
        position.x = 150;
        AssertEqual(position.GetX(), 150);
        position.SetX(300);
        AssertEqual(position.GetX(), 300);

        raylib::Vector2 speed(10, 10);
        position += speed;
        AssertEqual(position.x, 310);
        AssertEqual(raylib::Window::IsReady(), false);

        raylib::Vector2 size{50, 100};
        raylib::Vector2 halfsize = size / 2.0f;

        AssertEqual(size.x, 50);
        AssertEqual(size.y, 100);
        AssertEqual(halfsize.x, 25);
        AssertEqual(halfsize.y, 50);

        raylib::Vector2 doublesize = size * 2.0f;
        AssertEqual(size.x, 50);
        AssertEqual(doublesize.x, 100);

        const raylib::Vector2 zero2d;
        AssertEqual(zero2d.x, 0);
        AssertEqual(zero2d.y, 0);

        const raylib::Vector3 zero3d;
        AssertEqual(zero3d.x, 0);
        AssertEqual(zero3d.y, 0);
        AssertEqual(zero3d.z, 0);

        const raylib::Vector4 zero4d;
        AssertEqual(zero4d.x, 0);
        AssertEqual(zero4d.y, 0);
        AssertEqual(zero4d.z, 0);
        AssertEqual(zero4d.w, 0);
    }

    // Color
    {
        raylib::Color color = RED;
        AssertEqual(color.ToInt(), ::ColorToInt(RED));
        color = RAYWHITE;
        ::Color raylibColor = RAYWHITE;
        AssertEqual(color.r, raylibColor.r);
    }

    // Math
    {
        raylib::Vector2 direction(50, 50);
        raylib::Vector2 newDirection = direction.Rotate(30);
        AssertEqual((int)newDirection.x, 57);
    }

    // Image
    {
        // Loading
        raylib::Image image(path + "/resources/feynman.png");
        Assert(image.IsValid());

        // Chaining
        image.Crop(100, 100).Resize(50, 50);
        AssertEqual(image.GetWidth(), 50);
        AssertEqual(image.GetHeight(), 50);
    }

    // Keyboard
    { AssertNot(raylib::Keyboard::IsKeyPressed(KEY_MINUS)); }

    // raylib::LoadDirectoryFiles()
    {
        std::vector<std::string> files = raylib::LoadDirectoryFiles(::GetWorkingDirectory());
        Assert(files.size() > 3);
    }

    // raylib::TextReplace()
    {
        std::string input = "Hello World!";
        std::string output = raylib::TextReplace(input, "World", "Moon");
        AssertEqual(output, "Hello Moon!");
    }

    // raylib::TextInsert()
    {
        std::string input = "Hello World!";
        std::string output = raylib::TextInsert(input, "Good!", 0);
        AssertEqual(output, "Good! World!");
    }

    // raylib::TextSubtext()
    {
        std::string input = "Hello World!";
        std::string output = raylib::TextSubtext(input, 6, 5);
        AssertEqual(output, "World");
    }

    // TextSplit
    {
        std::vector<std::string> output = raylib::TextSplit("Hello|How|Are|You", '|');
        AssertEqual(output.size(), 4);
        AssertEqual(output[1], "How");
    }

    // Wave
    {
        raylib::Wave wave(path + "/resources/weird.wav");
        Assert(wave.IsValid(), "Expected wave to be loaded correctly");
    }

    // RaylibException
    {
        bool passed = false;
        try {
            raylib::Texture texture("notfound.png");
        } catch (raylib::RaylibException& error) {
            error.TraceLog(LOG_INFO);
            passed = true;
        }
        Assert(passed, "Expected to have a RaylibException to be thrown");
    }

    // Load FileData
    {
        raylib::FileData file(path + "/resources/weird.wav");
        Assert(file.GetBytesRead() > 0, "Expected file to be loaded correctly");
    }

    // Load FileText
    {
        raylib::FileText text(path + "/resources/lorem.txt");
        Assert(text.GetLength() > 0, "Expected file to be loaded correctly");
        AssertEqual(text.ToString().substr(0, 5), "Lorem");
    }

    TraceLog(LOG_INFO, "TEST: raylib-cpp test");
    TraceLog(LOG_INFO, "---------------------");
    return 0;
}
