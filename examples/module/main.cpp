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
using raylib::Vector2;
using raylib::Window;

int main() {
    int screenWidth = 800;
    int screenHeight = 450;

    // Mixing raymath with raylib runtime calls must not produce duplicate symbols when linking against raylib.
    Vector2 textPosition = Vector2(100, 180) + Vector2(20, 20);

    Window window(screenWidth, screenHeight, "raylib-cpp - modules example");

    while (!window.ShouldClose()) {
        window.BeginDrawing();
        window.ClearBackground(raylib::Colors::RAYWHITE);
        raylib::DrawText(
            "Congrats! You imported raylib as a module!",
            static_cast<int>(textPosition.x),
            static_cast<int>(textPosition.y),
            20,
            Color::LightGray());
        window.EndDrawing();
    }

    return 0;
}
