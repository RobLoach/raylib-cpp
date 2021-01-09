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

#include <string>
#include <array>

#include "raylib-cpp.hpp"

#define MAX_FONTS   8

int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;

    raylib::Window window(screenWidth, screenHeight, "raylib [text] example - raylib fonts");

    // NOTE: Textures MUST be loaded after Window initialization (OpenGL context is required)
    // Font fonts[MAX_FONTS] = { 0 };

    // fonts[0] = LoadFont("resources/fonts/alagard.png");
    // fonts[1] = LoadFont("resources/fonts/pixelplay.png");
    // fonts[2] = LoadFont("resources/fonts/mecha.png");
    // fonts[3] = LoadFont("resources/fonts/setback.png");
    // fonts[4] = LoadFont("resources/fonts/romulus.png");
    // fonts[5] = LoadFont("resources/fonts/pixantiqua.png");
    // fonts[6] = LoadFont("resources/fonts/alpha_beta.png");
    // fonts[7] = LoadFont("resources/fonts/jupiter_crash.png");

    // Vector
    std::vector<raylib::Font> fonts;
    fonts.emplace_back("resources/fonts/alagard.png");
    fonts.emplace_back("resources/fonts/pixelplay.png");
    fonts.emplace_back("resources/fonts/mecha.png");
    fonts.emplace_back("resources/fonts/setback.png");
    fonts.emplace_back("resources/fonts/romulus.png");
    fonts.emplace_back("resources/fonts/pixantiqua.png");
    fonts.emplace_back("resources/fonts/alpha_beta.png");
    fonts.emplace_back("resources/fonts/jupiter_crash.png");

    // Normal Array
    // raylib::Font fonts[MAX_FONTS] = {
    //     raylib::Font("resources/fonts/alagard.png"),
    //     raylib::Font("resources/fonts/pixelplay.png"),
    //     raylib::Font("resources/fonts/mecha.png"),
    //     raylib::Font("resources/fonts/setback.png"),
    //     raylib::Font("resources/fonts/romulus.png"),
    //     raylib::Font("resources/fonts/pixantiqua.png"),
    //     raylib::Font("resources/fonts/alpha_beta.png"),
    //     raylib::Font("resources/fonts/jupiter_crash.png")
    // };

    // Array
    // std::array<raylib::Font, MAX_FONTS> fonts = {
    //     raylib::Font("resources/fonts/alagard.png"),
    //     raylib::Font("resources/fonts/pixelplay.png"),
    //     raylib::Font("resources/fonts/mecha.png"),
    //     raylib::Font("resources/fonts/setback.png"),
    //     raylib::Font("resources/fonts/romulus.png"),
    //     raylib::Font("resources/fonts/pixantiqua.png"),
    //     raylib::Font("resources/fonts/alpha_beta.png"),
    //     raylib::Font("resources/fonts/jupiter_crash.png")
    // };

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

    std::array<const int, MAX_FONTS> spacings = { 2, 4, 8, 4, 3, 4, 4, 1 };

    std::array<raylib::Vector2, MAX_FONTS> positions;

    for (int i = 0; i < positions.size(); i++)
    {
        const raylib::Vector2 size = fonts[i].MeasureText(messages[i], fonts[i].baseSize*2, spacings[i]);
        //const raylib::Vector2 size = MeasureTextEx(fonts[i], messages[i].c_str(), fonts[i].baseSize*2, spacings[i]);
        positions[i].x = screenWidth / 2 - size.x / 2;
        positions[i].y = 60 + fonts[i].baseSize + 45 * i;
    }

    // Small Y position corrections
    positions[3].y += 8;
    positions[4].y += 2;
    positions[7].y -= 8;

    std::array<raylib::Color, MAX_FONTS> colors = { MAROON, ORANGE, DARKGREEN, DARKBLUE, DARKPURPLE, LIME, GOLD, RED };

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);

            DrawText("free fonts included with raylib", 250, 20, 20, DARKGRAY);
            DrawLine(220, 50, 590, 50, DARKGRAY);

            for (int i = 0; i < MAX_FONTS; i++)
            {
                //DrawTextEx(fonts[i], messages[i].c_str(), positions[i], fonts[i].baseSize*2, spacings[i], colors[i]);
                fonts[i].DrawText(messages[i], positions[i], fonts[i].baseSize*2, spacings[i], colors[i]);
            }

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------

    // Fonts unloading
    //for (int i = 0; i < MAX_FONTS; i++) UnloadFont(fonts[i]);

    //CloseWindow();                 // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
