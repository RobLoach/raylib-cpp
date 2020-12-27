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

#include <stdlib.h>           // Required for: free()

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
    raylib::Texture cubicmap(imMap);       // Convert image to texture to display (VRAM)
    raylib::Mesh mesh = raylib::Mesh::Cubicmap(imMap, (Vector3){ 1.0f, 1.0f, 1.0f });
    raylib::Model model(mesh);

    // NOTE: By default each cube is mapped to one part of texture atlas
    raylib::Texture texture("resources/cubicmap_atlas.png");    // Load map texture
    model.materials[0].maps[MAP_DIFFUSE].texture = texture;             // Set map diffuse texture

    // Get map image data to be used for collision detection
    Color *mapPixels = imMap.LoadColors();

    imMap.Unload();                   // Unload image from RAM

    raylib::Vector3 mapPosition(-16.0f, 0.0f, -8.0f);   // Set model position
    raylib::Vector3 playerPosition(camera.position);    // Set player position

    camera.SetMode(CAMERA_FIRST_PERSON);                // Set camera mode

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!window.ShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        raylib::Vector3 oldCamPos(camera.position);    // Store old camera position

        camera.Update();        // Update camera

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
                    (playerPos.CheckCollisionCircleRec(playerRadius,
                    (Rectangle){ mapPosition.x - 0.5f + x*1.0f, mapPosition.z - 0.5f + y*1.0f, 1.0f, 1.0f })))
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

            ClearBackground(RAYWHITE);

            camera.BeginMode3D();

                model.Draw(mapPosition);               // Draw maze map
                // DrawCubeV(playerPosition, (Vector3){ 0.2f, 0.4f, 0.2f }, RED);  // Draw player

            camera.EndMode3D();

            cubicmap.Draw((Vector2){ GetScreenWidth() - cubicmap.width*4 - 20, 20 }, 0.0f, 4.0f, WHITE);
            DrawRectangleLines(GetScreenWidth() - cubicmap.width*4 - 20, 20, cubicmap.width*4, cubicmap.height*4, GREEN);

            // Draw player position radar
            DrawRectangle(GetScreenWidth() - cubicmap.width*4 - 20 + playerCellX*4, 20 + playerCellY*4, 4, 4, RED);

            DrawFPS(10, 10);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    free(mapPixels);            // Unload color array

    /**
     * TODO: Fix double freeing of Mesh, possibly from UnloadModel() unloading meshes in Model.hpp?
     *
     * INFO: TEXTURE: [ID 4] Unloaded texture data from VRAM (GPU)
     * INFO: VAO: [ID 2] Unloaded vertex data from VRAM (GPU)
     * INFO: MODEL: Unloaded model (and meshes) from RAM and VRAM
     * double free or corruption (!prev)
    */
    mesh.vboId = NULL; // This shouldn't be needed, but currently is.

    //UnloadTexture(cubicmap);    // Unload cubicmap texture
    //UnloadTexture(texture);     // Unload map texture
    //UnloadModel(model);         // Unload map model

    //CloseWindow();              // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
