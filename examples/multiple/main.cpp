/*******************************************************************************************
*
*   raylib-cpp [multiple] example - Includes raylib-cpp.hpp from multiple sources.
*
*   Welcome to raylib!
*
*   To test examples, just press F6 and execute raylib_compile_execute script
*   Note that compiled executable is placed in the same folder as .c file
*
*   You can find all basic examples on C:\raylib\raylib\examples folder or
*   raylib official webpage: www.raylib.com
*
*   Enjoy using raylib. :)
*
*   This example has been created using raylib-cpp
*   raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)
*
*   Copyright (c) 2021 Rob Loach (https://robloach.net)
*
********************************************************************************************/

#include "Player.hpp"
#include "raylib-cpp.hpp"

int main() {
    raylib::Window window(640, 480, "raylib-cpp [multiple] example");
    SetTargetFPS(60);

    Player player;
    while (!window.ShouldClose()) {
        window.BeginDrawing();
        {
            window.ClearBackground(SKYBLUE);
            player.Update();
            player.Draw();
        }
        window.EndDrawing();
    }
}
