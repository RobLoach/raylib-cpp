/*******************************************************************************************
*
*   raylib [shaders] example - Texture Waves
*
*   NOTE: This example requires raylib OpenGL 3.3 or ES2 versions for shaders support,
*         OpenGL 1.1 does not support shaders, recompile raylib to OpenGL 3.3 version.
*
*   NOTE: Shaders used in this example are #version 330 (OpenGL 3.3), to test this example
*         on OpenGL ES 2.0 platforms (Android, Raspberry Pi, HTML5), use #version 100 shaders
*         raylib comes with shaders ready for both versions, check raylib/shaders install folder
*
*   This example has been created using raylib 2.5 (www.raylib.com)
*   raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)
*
*   Example contributed by Anata (@anatagawa) and reviewed by Ramon Santamaria (@raysan5)
*
*   Copyright (c) 2019 Anata (@anatagawa) and Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include "raylib-cpp.hpp"

#if defined(PLATFORM_DESKTOP)
    #define GLSL_VERSION            330
#else   // PLATFORM_RPI, PLATFORM_ANDROID, PLATFORM_WEB
    #define GLSL_VERSION            100
#endif

int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;

    raylib::Window window(screenWidth, screenHeight, "raylib-cpp [shaders] example - texture waves");

    // Load texture texture to apply shaders
    raylib::Texture2D texture("resources/space.png");

    // Load shader and setup location points and values
    raylib::Shader shader(0, TextFormat("resources/shaders/glsl%i/wave.fs", GLSL_VERSION));

    int secondsLoc = shader.GetLocation("secondes");
    int freqXLoc = shader.GetLocation("freqX");
    int freqYLoc = shader.GetLocation("freqY");
    int ampXLoc = shader.GetLocation("ampX");
    int ampYLoc = shader.GetLocation("ampY");
    int speedXLoc = shader.GetLocation("speedX");
    int speedYLoc = shader.GetLocation("speedY");

    // Shader uniform values that can be updated at any time
    float freqX = 25.0f;
    float freqY = 25.0f;
    float ampX = 5.0f;
    float ampY = 5.0f;
    float speedX = 8.0f;
    float speedY = 8.0f;

    float screenSize[2] = { (float)window.GetWidth(), (float)window.GetHeight() };
    shader.SetValue(shader.GetLocation("size"), &screenSize, SHADER_UNIFORM_VEC2);
    shader.SetValue(freqXLoc, &freqX, SHADER_UNIFORM_FLOAT);
    shader.SetValue(freqYLoc, &freqY, SHADER_UNIFORM_FLOAT);
    shader.SetValue(ampXLoc, &ampX, SHADER_UNIFORM_FLOAT);
    shader.SetValue(ampYLoc, &ampY, SHADER_UNIFORM_FLOAT);
    shader.SetValue(speedXLoc, &speedX, SHADER_UNIFORM_FLOAT);
    shader.SetValue(speedYLoc, &speedY, SHADER_UNIFORM_FLOAT);

    float seconds = 0.0f;

    window.SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    // -------------------------------------------------------------------------------------------------------------

    // Main game loop
    while (!window.ShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        seconds += GetFrameTime();

        shader.SetValue(secondsLoc, &seconds, SHADER_UNIFORM_FLOAT);
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);

            shader.BeginMode();

                texture.Draw(0, 0, WHITE);
                texture.Draw(texture.GetWidth(), 0, WHITE);

            EndShaderMode();

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    return 0;
}
