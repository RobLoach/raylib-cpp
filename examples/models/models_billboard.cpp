/*******************************************************************************************
*
*   raylib [models] example - Drawing billboards
*
*   This example has been created using raylib 1.3 (www.raylib.com)
*   raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)
*
*   Copyright (c) 2015 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include "raylib-cpp.hpp"

int main() {
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;

    raylib::Window window(screenWidth, screenHeight, "raylib [models] example - drawing billboards");

    // Define the camera to look into our 3d world
    raylib::Camera camera(
        raylib::Vector3(5.0f, 4.0f, 5.0f),
        raylib::Vector3(0.0f, 2.0f, 0.0f),
        raylib::Vector3(0.0f, 1.0f, 0.0f),
        45.0f,
        CAMERA_PERSPECTIVE);

    raylib::Texture2D bill("resources/billboard.png");     // Our texture billboard
    raylib::Vector3 billPosition(0.0f, 2.0f, 0.0f);                // Position where draw billboard

    SetTargetFPS(60);                       // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!window.ShouldClose()) {    // Detect window close button or ESC key
        // Update
        //----------------------------------------------------------------------------------
        camera.Update(CAMERA_ORBITAL);              // Update camera
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();
        {
            window.ClearBackground(RAYWHITE);

            camera.BeginMode();
            {
                DrawGrid(10, 1.0f);        // Draw a grid
                bill.DrawBillboard(camera, billPosition, 2.0f);
            }
            camera.EndMode();

            DrawFPS(10, 10);
        }
        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    return 0;
}
