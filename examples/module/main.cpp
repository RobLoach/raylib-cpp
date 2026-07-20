/**
 * raylib-cpp example using C++20 modules.
 *
 * Build with modules enabled (requires the Ninja or Visual Studio generator
 * and a compiler that can scan for module dependencies):
 *
 *   cmake -B build -G Ninja -DBUILD_RAYLIB_CPP_MODULES=ON -DCMAKE_CXX_STANDARD=20
 *   cmake --build build --target module
 */
import raylib;

using raylib::Color;
using raylib::Window;

int main() {
    int screenWidth = 800;
    int screenHeight = 450;

    Window window(screenWidth, screenHeight, "raylib-cpp - modules example");

    while (!window.ShouldClose()) {
        window.BeginDrawing();
        window.ClearBackground(raylib::Colors::RAYWHITE);
        raylib::DrawText("Congrats! You imported raylib as a module!", 120, 200, 20, Color::LightGray());
        window.EndDrawing();
    }

    return 0;
}
