/*******************************************************************************************
*
*   raylib-cpp [core] example - Basic window with C++ Modules (adapted for HTML5 platform)
*
*   This example is prepared to compile for PLATFORM_WEB and PLATFORM_DESKTOP
*   It was adapted from the raylib-cpp [core] example - Basic Window
*   with changes made to allow for compiling with C++ modules
*   To compile it for PLATFORM_WEB just use the --preset DebugWeb or ReleaseWeb in
*   CMakePresets.json
*
*   This example has been created using raylib-cpp (www.raylib.com)
*   raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)
*
*   Copyright (c) 2015 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include <string>

#if defined(PLATFORM_WEB)
    #include <emscripten/emscripten.h>
#endif

import raylib;

using raylib::DrawText;
using raylib::Color;

//----------------------------------------------------------------------------------
// Global Variables Definition
//----------------------------------------------------------------------------------
int screenWidth = 800;
int screenHeight = 450;
static raylib::Window window(screenWidth, screenHeight, "raylib-cpp [core] example - basic window");

//----------------------------------------------------------------------------------
// Module Functions Declaration
//----------------------------------------------------------------------------------
void UpdateDrawFrame();     // Update and Draw one frame

//----------------------------------------------------------------------------------
// Main Enry Point
//----------------------------------------------------------------------------------
int main()
{
    // Initialization
    //--------------------------------------------------------------------------------------
    // raylib::Window window(screenWidth, screenHeight, "raylib-cpp [core] example - basic window");

#if defined(PLATFORM_WEB)
    emscripten_set_main_loop(UpdateDrawFrame, 0, 1);
#else
    window.SetTargetFPS(60);   // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!window.ShouldClose())    // Detect window close button or ESC key
    {
        UpdateDrawFrame();
    }
#endif

    return 0;
}

//----------------------------------------------------------------------------------
// Module Functions Definition
//----------------------------------------------------------------------------------
void UpdateDrawFrame()
{
    // Update
    //----------------------------------------------------------------------------------
    // TODO: Update your variables here
    //----------------------------------------------------------------------------------

    // Draw
    //----------------------------------------------------------------------------------
    while (window.Drawing()) {
        window.ClearBackground(Color::RayWhite());

        DrawText("Congrats! You created your first raylib-cpp window!", 160, 200, 20, Color::LightGray());
    }
    //----------------------------------------------------------------------------------
}
