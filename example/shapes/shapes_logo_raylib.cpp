/*******************************************************************************************
*
*   raylib [shapes] example - Draw raylib logo using basic shapes
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

    raylib::Window window(screenWidth, screenHeight, "raylib [shapes] example - raylib logo using shapes");
    raylib::Color foreground(0, 68, 130);
    raylib::Color background = RAYWHITE;

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!window.ShouldClose()) {    // Detect window close button or ESC key
        // Update
        //----------------------------------------------------------------------------------
        // Update your variables here
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();
        {
            window.ClearBackground(background);

            foreground.DrawRectangle(screenWidth/2 - 128, screenHeight/2 - 128, 256, 256);
            background.DrawRectangle(screenWidth/2 - 112, screenHeight/2 - 112, 224, 224);
            foreground.DrawText("raylib", screenWidth/2 - 44, screenHeight/2 + 24, 50);
            foreground.DrawText("cpp", screenWidth/2 - 74, screenHeight/2 + 54, 50);

            DrawText("this is NOT a texture!", 350, 370, 10, GRAY);
        }
        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    return 0;
}
