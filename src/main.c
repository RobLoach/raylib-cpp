#include <stdio.h>
#include "libretro.h"
#include "raylib.h"
#include "rRetro.h"

int main(int argc, char* argv[]) {
	if (argc < 3) {
		printf("usage: %s <core> <game>\n", argv[0]);
		return 0;
	}

	core_load(argv[1]);
	core_load_game(argv[2]);

	int screenWidth = 800;
    int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

    if (!IsWindowReady()) {
    	printf("Failed to initialize window.");
    	return 0;
    }
    
    //SetTargetFPS(60);
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);

            DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

	CloseWindow();
	core_unload();
    return 0;
}