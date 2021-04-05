/*******************************************************************************************
*
*   raylib [text] example - Font loading and usage
*
*   This example has been created using raylib 1.0 (www.raylib.com)
*   raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)
*
*   Copyright (c) 2014 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include <string>

#include "raylib-cpp.hpp"

int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;

    raylib::Window window(screenWidth, screenHeight, "raylib [text] example - sprite fonts usage");

    std::string msg1 = "THIS IS A custom SPRITE FONT...";
    std::string msg2 = "...and this is ANOTHER CUSTOM font...";
    std::string msg3 = "...and a THIRD one! GREAT! :D";

    // NOTE: Textures/Fonts MUST be loaded after Window initialization (OpenGL context is required)
    raylib::Font font1("resources/custom_mecha.png");          // Font loading
    raylib::Font font2("resources/custom_alagard.png");        // Font loading
    raylib::Font font3("resources/custom_jupiter_crash.png");  // Font loading

    raylib::Vector2 fontPosition1(screenWidth/2 - MeasureTextEx(font1, msg1.c_str(), font1.baseSize, -3).x/2,
                              screenHeight/2 - font1.baseSize/2 - 80);

    raylib::Vector2 fontPosition2(screenWidth/2 - MeasureTextEx(font2, msg2.c_str(), font2.baseSize, -2).x/2,
                              screenHeight/2 - font2.baseSize/2 - 10);

    raylib::Vector2 fontPosition3(screenWidth/2 - MeasureTextEx(font3, msg3.c_str(), font3.baseSize, 2).x/2,
                              screenHeight/2 - font3.baseSize/2 + 50);

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!window.ShouldClose()) {    // Detect window close button or ESC key
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update variables here...
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();
        {
            window.ClearBackground(RAYWHITE);

            font1.DrawText(msg1, fontPosition1, font1.baseSize, -3);
            font2.DrawText(msg2, fontPosition2, font2.baseSize, -2);
            font3.DrawText(msg3, fontPosition3, font3.baseSize, 2);
        }
        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    return 0;
}
