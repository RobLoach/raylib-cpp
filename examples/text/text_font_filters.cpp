/*******************************************************************************************
*
*   raylib [text] example - Font filters
*
*   After font loading, font texture atlas filter could be configured for a softer
*   display of the font when scaling it to different sizes, that way, it's not required
*   to generate multiple fonts at multiple sizes (as long as the scaling is not very different)
*
*   This example has been created using raylib 1.3.0 (www.raylib.com)
*   raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)
*
*   Copyright (c) 2015 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include "raylib-cpp.hpp"

int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;

    raylib::Window window(screenWidth, screenHeight, "raylib [text] example - font filters");

    // TTF Font loading with custom generation parameters
    raylib::Font font("resources/KAISG.ttf", 96);

    // Generate mipmap levels to use trilinear filtering
    // NOTE: On 2D drawing it won't be noticeable, it looks like FILTER_BILINEAR
    font.GetTexture().GenMipmaps();

    raylib::Text msg("Loaded Font", font.GetBaseSize(), BLACK, font);

    Vector2 fontPosition = { 40.0f, screenHeight/2.0f - 80.0f };
    Vector2 textSize = { 0.0f, 0.0f };

    // Setup texture scaling filter
    font.GetTexture().SetFilter(TEXTURE_FILTER_POINT);
    int currentFontFilter = 0;      // TEXTURE_FILTER_POINT

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        msg.fontSize += GetMouseWheelMove() * 4.0f;

        // Choose font texture filter method
        if (IsKeyPressed(KEY_ONE))
        {
            font.GetTexture().SetFilter(TEXTURE_FILTER_POINT);
            currentFontFilter = 0;
        }
        else if (IsKeyPressed(KEY_TWO))
        {
            font.GetTexture().SetFilter(TEXTURE_FILTER_BILINEAR);
            currentFontFilter = 1;
        }
        else if (IsKeyPressed(KEY_THREE))
        {
            // NOTE: Trilinear filter won't be noticed on 2D drawing
            font.GetTexture().SetFilter(TEXTURE_FILTER_TRILINEAR);
            currentFontFilter = 2;
        }

        textSize = msg.MeasureEx();

        if (IsKeyDown(KEY_LEFT)) fontPosition.x -= 10;
        else if (IsKeyDown(KEY_RIGHT)) fontPosition.x += 10;

        // Load a dropped TTF file dynamically (at current fontSize)
        for (const auto& file : raylib::LoadDroppedFiles()) {
            if (raylib::IsFileExtension(file, ".ttf")) {
                msg.font = font = raylib::Font(file, font.GetBaseSize());
            }
        }
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);

            DrawText("Use mouse wheel to change font size", 20, 20, 10, GRAY);
            DrawText("Use KEY_RIGHT and KEY_LEFT to move text", 20, 40, 10, GRAY);
            DrawText("Use 1, 2, 3 to change texture filter", 20, 60, 10, GRAY);
            DrawText("Drop a new TTF font for dynamic loading", 20, 80, 10, DARKGRAY);

            msg.Draw(fontPosition);

            // TODO: It seems texSize measurement is not accurate due to chars offsets...
            //DrawRectangleLines(fontPosition.x, fontPosition.y, textSize.x, textSize.y, RED);

            DrawRectangle(0, screenHeight - 80, screenWidth, 80, LIGHTGRAY);
            DrawText(TextFormat("Font size: %02.02f", msg.GetFontSize()), 20, screenHeight - 50, 10, DARKGRAY);
            DrawText(TextFormat("Text size: [%02.02f, %02.02f]", textSize.x, textSize.y), 20, screenHeight - 30, 10, DARKGRAY);
            DrawText("CURRENT TEXTURE FILTER:", 250, 400, 20, GRAY);

            if (currentFontFilter == 0) DrawText("POINT", 570, 400, 20, BLACK);
            else if (currentFontFilter == 1) DrawText("BILINEAR", 570, 400, 20, BLACK);
            else if (currentFontFilter == 2) DrawText("TRILINEAR", 570, 400, 20, BLACK);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    return 0;
}
