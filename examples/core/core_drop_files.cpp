/*******************************************************************************************
*
*   raylib [core] example - Windows drop files
*
*   This example only works on platforms that support drag & drop (Windows, Linux, OSX, Html5?)
*
*   This example has been created using raylib-cpp (www.raylib.com)
*   raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)
*
*   Copyright (c) 2020 Rob Loach (@RobLoach)
*
********************************************************************************************/

#include "raylib-cpp.hpp"

int main()
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;

    raylib::Window w(screenWidth, screenHeight, "raylib [core] example - drop files");

    // Create the Dropped Files collection object.
    raylib::DroppedFiles droppedFiles;

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!w.ShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        if (droppedFiles.IsFileDropped()) {
        	droppedFiles.Get();
        }
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);

            // Check if there are files to process.
            if (droppedFiles.empty()) {
            	DrawText("Drop your files to this window!", 100, 40, 20, DARKGRAY);
            }
            else {
                DrawText("Dropped files:", 100, 40, 20, DARKGRAY);

                // Iterate through all the dropped files.
                for (int i = 0; i < droppedFiles.size(); i++) {
                    if (i%2 == 0)
                		DrawRectangle(0, 85 + 40*i, screenWidth, 40, Fade(LIGHTGRAY, 0.5f));
                    else
                    	DrawRectangle(0, 85 + 40*i, screenWidth, 40, Fade(LIGHTGRAY, 0.3f));

                    // Display the path to the dropped file.
                    DrawText(droppedFiles[i].c_str(), 120, 100 + 40*i, 10, GRAY);
                }

                DrawText("Drop new files...", 100, 110 + 40 * droppedFiles.size(), 20, DARKGRAY);
            }

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    // ClearDroppedFiles();    // Called for us.
    //--------------------------------------------------------------------------------------

    return 0;
}
