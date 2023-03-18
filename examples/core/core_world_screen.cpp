/*******************************************************************************************
*
*   raylib [core] example - World to screen
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

    raylib::Window window(screenWidth, screenHeight, "raylib [core] example - 3d camera free");

    // Define the camera to look into our 3d world
    raylib::Camera camera(
        raylib::Vector3(10.0f, 10.0f, 10.0f),
        raylib::Vector3(),
        raylib::Vector3(0.0f, 1.0f, 0.0f),
        45.0f,
        CAMERA_PERSPECTIVE);

    Vector3 cubePosition;
    Vector2 cubeScreenPosition;

    SetTargetFPS(60);                   // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!window.ShouldClose()) {     // Detect window close button or ESC key
        // Update
        //----------------------------------------------------------------------------------
        camera.Update(CAMERA_THIRD_PERSON);                // Update camera

        // Calculate cube screen space position (with a little offset to be in top)
        cubeScreenPosition = GetWorldToScreen(Vector3{cubePosition.x, cubePosition.y + 2.5f, cubePosition.z}, camera);
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();
        {
            window.ClearBackground(RAYWHITE);

            camera.BeginMode();
            {
                DrawCube(cubePosition, 2.0f, 2.0f, 2.0f, RED);
                DrawCubeWires(cubePosition, 2.0f, 2.0f, 2.0f, MAROON);

                DrawGrid(10, 1.0f);
            }
            camera.EndMode();

            raylib::DrawText("Enemy: 100 / 100",
                cubeScreenPosition.x - MeasureText("Enemy: 100/100", 20) / 2,
                cubeScreenPosition.y, 20,
                BLACK);
            raylib::DrawText("Text is always on top of the cube",
                (screenWidth - MeasureText("Text is always on top of the cube", 20)) / 2,
                25, 20, GRAY);
        }
        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    return 0;
}
