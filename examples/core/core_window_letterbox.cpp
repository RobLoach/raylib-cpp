/*******************************************************************************************
*
*   raylib [core] example - window scale letterbox (and virtual mouse)
*
*   Example originally created with raylib 2.5, last time updated with raylib 4.0
*
*   Example contributed by Anata (@anatagawa) and reviewed by Ramon Santamaria (@raysan5)
*
*   Example licensed under an unmodified zlib/libpng license, which is an OSI-certified,
*   BSD-like license that allows static linking with closed source software
*
*   Copyright (c) 2019-2023 Anata (@anatagawa) and Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include "raylib-cpp.hpp"

#include "raymath.hpp"        // Required for: Vector2Clamp()

#define MAX(a, b) ((a)>(b)? (a) : (b))
#define MIN(a, b) ((a)<(b)? (a) : (b))

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
    const int windowWidth = 800;
    const int windowHeight = 450;

    // Enable config flags for resizable window and vertical synchro
    raylib::Window window(windowWidth, windowHeight,
        "raylib [core] example - window scale letterbox",
        FLAG_WINDOW_RESIZABLE | FLAG_VSYNC_HINT);
    window.SetMinSize(320, 240);

    int gameScreenWidth = 640;
    int gameScreenHeight = 480;

    // Render texture initialization, used to hold the rendering result so we can easily resize it
    raylib::RenderTexture2D target(gameScreenWidth, gameScreenHeight);
    target.GetTexture().SetFilter(TEXTURE_FILTER_BILINEAR); // Texture scale filter to use

    raylib::Color colors[10] = { 0 };
    for (int i = 0; i < 10; i++) {
        colors[i] = raylib::Color((unsigned char)GetRandomValue(100, 250), (unsigned char)GetRandomValue(50, 150), (unsigned char)GetRandomValue(10, 100), 255);
    }

    window.SetTargetFPS(60);                   // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!window.ShouldClose())        // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // Compute required framebuffer scaling
        float scale = MIN((float)GetScreenWidth()/gameScreenWidth, (float)GetScreenHeight()/gameScreenHeight);

        if (IsKeyPressed(KEY_SPACE))
        {
            // Recalculate random colors for the bars
            for (int i = 0; i < 10; i++) colors[i] = (Color){ (unsigned char)GetRandomValue(100, 250), (unsigned char)GetRandomValue(50, 150), (unsigned char)GetRandomValue(10, 100), 255 };
        }

        // Update virtual mouse (clamped mouse value behind game screen)
        raylib::Vector2 mouse = raylib::Mouse::GetPosition();
        raylib::Vector2 virtualMouse(
            (mouse.x - (GetScreenWidth() - (gameScreenWidth*scale))*0.5f)/scale,
            (mouse.y - (GetScreenHeight() - (gameScreenHeight*scale))*0.5f)/scale
        );
        virtualMouse = virtualMouse.Clamp(raylib::Vector2::Zero(), raylib::Vector2(gameScreenWidth, gameScreenHeight));

        // Apply the same transformation as the virtual mouse to the real mouse (i.e. to work with raygui)
        //SetMouseOffset(-(GetScreenWidth() - (gameScreenWidth*scale))*0.5f, -(GetScreenHeight() - (gameScreenHeight*scale))*0.5f);
        //SetMouseScale(1/scale, 1/scale);
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        // Draw everything in the render texture, note this will not be rendered on screen, yet
        target.BeginMode();
            ClearBackground(RAYWHITE);  // Clear render texture background color

            for (int i = 0; i < 10; i++) DrawRectangle(0, (gameScreenHeight/10)*i, gameScreenWidth, gameScreenHeight/10, colors[i]);

            DrawText("If executed inside a window,\nyou can resize the window,\nand see the screen scaling!", 10, 25, 20, WHITE);
            DrawText(TextFormat("Default Mouse: [%i , %i]", (int)mouse.x, (int)mouse.y), 350, 25, 20, GREEN);
            DrawText(TextFormat("Virtual Mouse: [%i , %i]", (int)virtualMouse.x, (int)virtualMouse.y), 350, 55, 20, YELLOW);
        target.EndMode();

        BeginDrawing();
            ClearBackground(BLACK);     // Clear screen background

            // Draw render texture to screen, properly scaled
            target.GetTexture().Draw(raylib::Rectangle(0.0f, 0.0f, target.texture.width, -target.texture.height),
                raylib::Rectangle(
                    (GetScreenWidth() - (gameScreenWidth*scale))*0.5f,
                    (GetScreenHeight() - (gameScreenHeight*scale))*0.5f,
                    gameScreenWidth*scale, gameScreenHeight*scale
                ),
                raylib::Vector2::Zero(), 0.0f, WHITE);
        EndDrawing();
        //--------------------------------------------------------------------------------------
    }

    return 0;
}
