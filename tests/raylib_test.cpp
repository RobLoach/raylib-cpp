#include <cassert>
#include <iostream>
#include <string>
#include <vector>
#include "raylib-cpp.hpp"

int main() {
    // Vector
    raylib::Vector2 position(50, 100);
    assert(position.GetX() == position.x);
    position.x = 150;
    assert(position.GetX() == 150);

    // Addition operator.
    raylib::Vector2 speed(10, 10);
    position += speed;
    assert(position.x == 160);
    assert(raylib::Window::IsReady() == false);

    // Color
    raylib::Color color = RED;
    assert(color.ToInt() == ::ColorToInt(RED));
    color = RAYWHITE;
    assert(color.r == RAYWHITE.r);

    // Math
    raylib::Vector2 direction(50, 50);
    raylib::Vector2 newDirection = direction.Rotate(30);
    std::cout << "Out: " << newDirection.x << std::endl;
    assert((int)newDirection.x == 57);

    // raylib::GetDirectoryFiles()
    std::vector<std::string> files = raylib::GetDirectoryFiles(::GetWorkingDirectory());
    assert(files.size() > 3);

    // Sound
    {
        raylib::Sound sound("resources/weird.wav");
        sound.Play();
    }

    std::cout << "Tests complete" << std::endl;
    return 0;
}
