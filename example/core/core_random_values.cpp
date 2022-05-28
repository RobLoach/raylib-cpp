/*******************************************************************************************
*
*   raylib [core] example - Generate random values
*
*   This example has been created using raylib 1.1 (www.raylib.com)
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

    raylib::Window window(screenWidth, screenHeight, "raylib [core] example - generate random values");

    int framesCounter = 0;          // Variable used to count frames

    int randValue = GetRandomValue(-8, 5);   // Get a random integer number between -8 and 5 (both included)

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!window.ShouldClose()) {    // Detect window close button or ESC key
        // Update
        //----------------------------------------------------------------------------------
        framesCounter++;

        // Every two seconds (120 frames) a new random value is generated
        if (((framesCounter / 120) % 2) == 1) {
            randValue = GetRandomValue(-8, 5);
            framesCounter = 0;
        }
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();
        {
            window.ClearBackground(RAYWHITE);

            raylib::DrawText("Every 2 seconds a new random value is generated:", 130, 100, 20, MAROON);

            raylib::DrawText(TextFormat("%i", randValue), 360, 180, 80, LIGHTGRAY);
        }
        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    return 0;
}
