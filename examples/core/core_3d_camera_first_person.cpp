/*******************************************************************************************
*
*   raylib [core] example - 3d camera first person
*
*   This example has been created using raylib 1.3 (www.raylib.com)
*   raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)
*
*   Copyright (c) 2015 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include "raylib-cpp.hpp"

#define MAX_COLUMNS 20

int main() {
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;

    raylib::Window window(screenWidth, screenHeight, "raylib [core] example - 3d camera first person");

    // Define the camera to look into our 3d world (position, target, up vector)
    raylib::Camera camera(
        raylib::Vector3(4.0f, 2.0f, 4.0f),
        raylib::Vector3(0.0f, 1.8f, 0.0f),
        raylib::Vector3(0.0f, 1.0f, 0.0f),
        60.0f,
        CAMERA_PERSPECTIVE);

    // Generates some random columns
    float heights[MAX_COLUMNS] = { 0.0f };
    raylib::Vector3 positions[MAX_COLUMNS] = { 0 };
    raylib::Color colors[MAX_COLUMNS] = { 0 };

    for (int i = 0; i < MAX_COLUMNS; i++) {
        heights[i] = static_cast<float>(GetRandomValue(1, 12));
        positions[i] = raylib::Vector3(GetRandomValue(-15, 15), heights[i]/2, GetRandomValue(-15, 15));
        colors[i] = raylib::Color(GetRandomValue(20, 255), GetRandomValue(10, 55), 30);
    }

    camera.SetMode(CAMERA_FIRST_PERSON);  // Set a first person camera mode

    SetTargetFPS(60);                     // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!window.ShouldClose()) {       // Detect window close button or ESC key
        // Update
        //----------------------------------------------------------------------------------
        camera.Update();                  // Update camera
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();
        {
            window.ClearBackground(RAYWHITE);

            camera.BeginMode();
            {
                DrawPlane(Vector3{ 0.0f, 0.0f, 0.0f }, Vector2{ 32.0f, 32.0f }, LIGHTGRAY);  // Draw ground
                DrawCube(Vector3{ -16.0f, 2.5f, 0.0f }, 1.0f, 5.0f, 32.0f, BLUE);     // Draw a blue wall
                DrawCube(Vector3{ 16.0f, 2.5f, 0.0f }, 1.0f, 5.0f, 32.0f, LIME);      // Draw a green wall
                DrawCube(Vector3{ 0.0f, 2.5f, 16.0f }, 32.0f, 5.0f, 1.0f, GOLD);      // Draw a yellow wall

                // Draw some cubes around
                for (int i = 0; i < MAX_COLUMNS; i++) {
                    positions[i].DrawCube(2.0f, heights[i], 2.0f, colors[i]);
                    positions[i].DrawCubeWires(2.0f, heights[i], 2.0f, MAROON);
                }
            }
            camera.EndMode();

            DrawRectangle(10, 10, 220, 70, raylib::Color::SkyBlue().Fade(0.5f));
            DrawRectangleLines(10, 10, 220, 70, BLUE);

            DrawText("First person camera default controls:", 20, 20, 10, BLACK);
            DrawText("- Move with keys: W, A, S, D", 40, 40, 10, DARKGRAY);
            DrawText("- Mouse move to look around", 40, 60, 10, DARKGRAY);
        }
        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    return 0;
}
