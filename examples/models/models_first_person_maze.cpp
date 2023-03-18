/*******************************************************************************************
*
*   raylib [models] example - first person maze
*
*   This example has been created using raylib 2.5 (www.raylib.com)
*   raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)
*
*   Copyright (c) 2019 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include "raylib-cpp.hpp"

int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;

    raylib::Window window(screenWidth, screenHeight, "raylib [models] example - first person maze");

    // Define the camera to look into our 3d world
    raylib::Camera camera({ 0.2f, 0.4f, 0.2f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 1.0f, 0.0f }, 45.0f);

    raylib::Image imMap("resources/cubicmap.png");      // Load cubicmap image (RAM)
    raylib::Texture cubicmap(imMap);                    // Convert image to texture to display (VRAM)
    Mesh mesh = raylib::Mesh::Cubicmap(imMap, Vector3{ 1.0f, 1.0f, 1.0f });
    raylib::Model model(mesh);

    // NOTE: By default each cube is mapped to one part of texture atlas
    raylib::Texture texture("resources/cubicmap_atlas.png");    // Load map texture
    model.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = texture;     // Set map diffuse texture

    // Get map image data to be used for collision detection
    Color *mapPixels = imMap.LoadColors();

    imMap.Unload();                   // Unload image from RAM

    raylib::Vector3 mapPosition(-16.0f, 0.0f, -8.0f);   // Set model position
    raylib::Vector3 playerPosition(camera.position);    // Set player position

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!window.ShouldClose()) {    // Detect window close button or ESC key
        // Update
        //----------------------------------------------------------------------------------
        raylib::Vector3 oldCamPos(camera.position);    // Store old camera position

        camera.Update(CAMERA_FIRST_PERSON);        // Update camera

        // Check player collision (we simplify to 2D collision detection)
        raylib::Vector2 playerPos(camera.position.x, camera.position.z);
        float playerRadius = 0.1f;  // Collision radius (player is modelled as a cilinder for collision)

        int playerCellX = static_cast<int>(playerPos.x - mapPosition.x + 0.5f);
        int playerCellY = static_cast<int>(playerPos.y - mapPosition.z + 0.5f);

        // Out-of-limits security check
        if (playerCellX < 0) playerCellX = 0;
        else if (playerCellX >= cubicmap.width) playerCellX = cubicmap.width - 1;

        if (playerCellY < 0) playerCellY = 0;
        else if (playerCellY >= cubicmap.height) playerCellY = cubicmap.height - 1;

        // Check map collisions using image data and player position
        // TODO: Improvement: Just check player surrounding cells for collision
        for (int y = 0; y < cubicmap.height; y++)
        {
            for (int x = 0; x < cubicmap.width; x++)
            {
                if ((mapPixels[y*cubicmap.width + x].r == 255) &&       // Collision: white pixel, only check R channel
                    (playerPos.CheckCollisionCircle(playerRadius,
                    Rectangle{ mapPosition.x - 0.5f + x*1.0f, mapPosition.z - 0.5f + y*1.0f, 1.0f, 1.0f })))
                {
                    // Collision detected, reset camera position
                    camera.position = oldCamPos;
                }
            }
        }
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();
        {
            window.ClearBackground(RAYWHITE);

            camera.BeginMode();
            {
                model.Draw(mapPosition);               // Draw maze map
                // playerPosition.DrawCube((Vector3){ 0.2f, 0.4f, 0.2f }, RED);  // Draw player
            }
            camera.EndMode();

            cubicmap.Draw(Vector2{ static_cast<float>(GetScreenWidth() - cubicmap.width*4 - 20), 20 }, 0.0f, 4.0f, WHITE);
            DrawRectangleLines(GetScreenWidth() - cubicmap.width*4 - 20, 20, cubicmap.width*4, cubicmap.height*4, GREEN);

            // Draw player position radar
            DrawRectangle(GetScreenWidth() - cubicmap.width*4 - 20 + playerCellX*4, 20 + playerCellY*4, 4, 4, RED);

            DrawFPS(10, 10);
        }
        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------

    UnloadImageColors(mapPixels);          // Unload color array

    //----------------------------------------------------------------------------------

    return 0;
}
