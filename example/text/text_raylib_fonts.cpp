/*******************************************************************************************
*
*   raylib [text] example - raylib font loading and usage
*
*   NOTE: raylib is distributed with some free to use fonts (even for commercial pourposes!)
*         To view details and credits for those fonts, check raylib license file
*
*   This example has been created using raylib 1.7 (www.raylib.com)
*   raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)
*
*   Copyright (c) 2017 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include <vector>
#include <array>

#include "raylib-cpp.hpp"

#define MAX_FONTS   8

int main() {
    // Initialization
    //--------------------------------------------------------------------------------------
    int screenWidth = 800;
    int screenHeight = 450;

    raylib::Window window(screenWidth, screenHeight, "raylib [text] example - raylib fonts");
    raylib::Color textColor = DARKGRAY;

    // NOTE: Textures MUST be loaded after Window initialization (OpenGL context is required)
    std::array<raylib::Font, MAX_FONTS> fonts = {
        raylib::Font("resources/fonts/alagard.png"),
        raylib::Font("resources/fonts/pixelplay.png"),
        raylib::Font("resources/fonts/mecha.png"),
        raylib::Font("resources/fonts/setback.png"),
        raylib::Font("resources/fonts/romulus.png"),
        raylib::Font("resources/fonts/pixantiqua.png"),
        raylib::Font("resources/fonts/alpha_beta.png"),
        raylib::Font("resources/fonts/jupiter_crash.png")
    };

    std::array<std::string, MAX_FONTS> messages = {
        "ALAGARD FONT designed by Hewett Tsoi",
        "PIXELPLAY FONT designed by Aleksander Shevchuk",
        "MECHA FONT designed by Captain Falcon",
        "SETBACK FONT designed by Brian Kent (AEnigma)",
        "ROMULUS FONT designed by Hewett Tsoi",
        "PIXANTIQUA FONT designed by Gerhard Grossmann",
        "ALPHA_BETA FONT designed by Brian Kent (AEnigma)",
        "JUPITER_CRASH FONT designed by Brian Kent (AEnigma)"
    };

    std::array<int, MAX_FONTS> spacings = { 2, 4, 8, 4, 3, 4, 4, 1 };

    std::array<raylib::Vector2, MAX_FONTS> positions;

    for (int i = 0; i < fonts.size(); i++)
    {
        auto size = fonts[i].MeasureText(messages[i], fonts[i].baseSize * 2, spacings[i]);
        positions[i].x = screenWidth/2 - size.x/2;
        positions[i].y = 60 + fonts[i].baseSize + 45*i;
    }

    // Small Y position corrections
    positions[3].y += 8;
    positions[4].y += 2;
    positions[7].y -= 8;

    std::array<raylib::Color, MAX_FONTS> colors = { MAROON, ORANGE, DARKGREEN, DARKBLUE, DARKPURPLE, LIME, GOLD, RED };
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
            window.ClearBackground(RAYWHITE);

            textColor.DrawText("free fonts included with raylib", 250, 20, 20);
            textColor.DrawLine(220, 50, 590, 50);

            for (int i = 0; i < fonts.size(); i++)
            {
                fonts[i].DrawText(messages[i], positions[i], fonts[i].baseSize*2, spacings[i], colors[i]);
            }
        }
        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    return 0;
}
