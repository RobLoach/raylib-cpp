/*******************************************************************************************
*
*   raylib [core] example - Mouse input
*
*   This example has been created using raylib 1.0 (www.raylib.com)
*   raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)
*
*   Copyright (c) 2014 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include "raylib-cpp.hpp"

int main() {
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;

    raylib::Window window(screenWidth, screenHeight, "raylib [core] example - mouse input");

    raylib::Vector2 ballPosition(-100.0f, -100.0f);
    raylib::Color ballColor = raylib::Color::DarkBlue();
    raylib::Color textColor = raylib::Color::DarkGray();

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //---------------------------------------------------------------------------------------

    // Main game loop
    while (!window.ShouldClose()) {    // Detect window close button or ESC key
        // Update
        //----------------------------------------------------------------------------------
        ballPosition = GetMousePosition();

        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) ballColor = MAROON;
        else if (IsMouseButtonPressed(MOUSE_MIDDLE_BUTTON)) ballColor = LIME;
        else if (IsMouseButtonPressed(MOUSE_RIGHT_BUTTON)) ballColor = DARKBLUE;
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();
        {
            window.ClearBackground(RAYWHITE);

            ballPosition.DrawCircle(40, ballColor);

            textColor.DrawText("move ball with mouse and click mouse button to change color", 10, 10, 20);
        }
        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    return 0;
}
