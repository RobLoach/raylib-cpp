/*******************************************************************************************
*
*   raylib [audio] example - Sound loading and playing
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

    raylib::Window window(screenWidth, screenHeight, "raylib [audio] example - sound loading and playing");

    raylib::AudioDevice audiodevice;      // Initialize audio device

    raylib::Sound fxWav("resources/sound.wav");         // Load WAV audio file
    raylib::Sound fxOgg("resources/target.ogg");      // Load OGG audio file

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!window.ShouldClose()) {    // Detect window close button or ESC key
        // Update
        //----------------------------------------------------------------------------------
        if (IsKeyPressed(KEY_SPACE)) fxWav.Play();      // Play WAV sound
        if (IsKeyPressed(KEY_ENTER)) fxOgg.Play();      // Play OGG sound
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();
        {
            window.ClearBackground(RAYWHITE);

            DrawText("Press SPACE to PLAY the WAV sound!", 200, 180, 20, LIGHTGRAY);
            DrawText("Press ENTER to PLAY the OGG sound!", 200, 220, 20, LIGHTGRAY);
        }
        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    return 0;
}
