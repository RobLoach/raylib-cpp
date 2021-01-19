/*******************************************************************************************
*
*   Physac - Physics demo
*
*   NOTE 1: Physac requires multi-threading, when InitPhysics() a second thread is created to manage physics calculations.
*   NOTE 2: Physac requires static C library linkage to avoid dependency on MinGW DLL (-static -lpthread)
*
*   Use the following line to compile:
*
*   gcc -o $(NAME_PART).exe $(FILE_NAME) -s -static  /
*       -lraylib -lpthread -lglfw3 -lopengl32 -lgdi32 -lopenal32 -lwinmm /
*       -std=c99 -Wl,--subsystem,windows -Wl,-allow-multiple-definition
*
*   Copyright (c) 2016-2018 Victor Fisac
*
********************************************************************************************/

#include "raylib-cpp.hpp"

#define PHYSAC_IMPLEMENTATION
#define PHYSAC_NO_THREADS
#include "Physics.hpp"

int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;

    SetConfigFlags(FLAG_MSAA_4X_HINT);
    raylib::Window window(screenWidth, screenHeight, "Physac [raylib-cpp] - Physics demo");

    // Physac logo drawing position
    int logoX = screenWidth - MeasureText("Physac", 30) - 10;
    int logoY = 15;
    bool needsReset = false;

    // Initialize physics and default physics bodies
    raylib::Physics physics;

    // Create floor rectangle physics body
    PhysicsBody floor = physics.CreateBodyRectangle(Vector2{screenWidth/2, screenHeight}, 500, 100, 10);
    floor->enabled = false;         // Disable body state to convert it to static (no dynamics, but collisions)

    // Create obstacle circle physics body
    PhysicsBody circle = physics.CreateBodyCircle(Vector2{screenWidth/2, screenHeight/2}, 45, 10);
    circle->enabled = false;        // Disable body state to convert it to static (no dynamics, but collisions)

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!window.ShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // Delay initialization of variables due to physics reset async
        physics.RunStep();

        if (needsReset)
        {
            floor = physics.CreateBodyRectangle((Vector2){ screenWidth/2, screenHeight }, 500, 100, 10);
            floor->enabled = false;

            circle = physics.CreateBodyCircle((Vector2){ screenWidth/2, screenHeight/2 }, 45, 10);
            circle->enabled = false;

            needsReset = false;
        }

        // Reset physics input
        if (IsKeyPressed('R'))
        {
            physics.Reset();
            needsReset = true;
        }

        // Physics body creation inputs
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) physics.CreateBodyPolygon(GetMousePosition(), GetRandomValue(20, 80), GetRandomValue(3, 8), 10);
        else if (IsMouseButtonPressed(MOUSE_RIGHT_BUTTON)) physics.CreateBodyCircle(GetMousePosition(), GetRandomValue(10, 45), 10);

        // Destroy falling physics bodies
        int bodiesCount = physics.GetBodiesCount();
        for (int i = bodiesCount - 1; i >= 0; i--)
        {
            PhysicsBody body = physics.GetBody(i);
            if (body != NULL && (body->position.y > screenHeight*2)) physics.DestroyBody(body);
        }
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(BLACK);

            DrawFPS(screenWidth - 90, screenHeight - 30);

            // Draw created physics bodies
            bodiesCount = physics.GetBodiesCount();
            for (int i = 0; i < bodiesCount; i++)
            {
                PhysicsBody body = physics.GetBody(i);

                if (body != NULL)
                {
                    int vertexCount = physics.GetShapeVerticesCount(i);
                    for (int j = 0; j < vertexCount; j++)
                    {
                        // Get physics bodies shape vertices to draw lines
                        // Note: GetPhysicsShapeVertex() already calculates rotation transformations
                        Vector2 vertexA = physics.GetShapeVertex(body, j);

                        int jj = (((j + 1) < vertexCount) ? (j + 1) : 0);   // Get next vertex or first to close the shape
                        Vector2 vertexB = physics.GetShapeVertex(body, jj);

                        DrawLineV(vertexA, vertexB, GREEN);     // Draw a line between two vertex positions
                    }
                }
            }

            DrawText("Left mouse button to create a polygon", 10, 10, 10, WHITE);
            DrawText("Right mouse button to create a circle", 10, 25, 10, WHITE);
            DrawText("Press 'R' to reset example", 10, 40, 10, WHITE);

            DrawText("Physac", logoX, logoY, 30, WHITE);
            DrawText("Powered by", logoX + 50, logoY - 7, 10, WHITE);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    // ClosePhysics();       // Unitializing physics handled through the garbage collector.

    // CloseWindow();        // Close window and OpenGL context is handled.
    //--------------------------------------------------------------------------------------

    return 0;
}
