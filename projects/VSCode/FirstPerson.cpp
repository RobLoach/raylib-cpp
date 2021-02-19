#include "raylib.h"
#include <stdio.h>
#include "raymath.h"
#include "camera.h"
#include "include/raylib-cpp.hpp"
#include <vector>

#define MAX_COLUMNS 100
#define CollisionDetectionThreshold 15
const int screenWidth = 1280;
const int screenHeight = 720;
bool debug = false;
bool cameraCollided = false;
bool closeToCollider = false;

// TODO: WRITE CUSTOM MOVEMENT CODE
// TODO: NEED TO CHECK Y AXIS COLLISIONS
// TODO: NEED TO IMPELEMENT PHYSICS
struct BoxCollider
{
    BoundingBox BBox;
    Vector3 *center;
    Vector3 extents;

    BoxCollider() {}

    BoxCollider(Vector3 &center, raylib::Vector3 extents)
    {
        this->center = &center;
        this->extents = extents;
        UpdateBoundingBox();
    }
    void UpdateBoundingBox()
    {
        BBox.max.x = center->x + extents.x / 2;
        BBox.max.y = center->y + extents.y / 2;
        BBox.max.z = center->z + extents.z / 2;

        BBox.min.x = center->x - extents.x / 2;
        BBox.min.y = center->y - extents.y / 2;
        BBox.min.z = center->z - extents.z / 2;
    }
};

struct Player
{
    raylib::Camera camera;
    BoxCollider collider;

    Player()
    {
        camera = raylib::Camera(raylib::Vector3(4, 2, 4), raylib::Vector3(0.0f, 1.8f, 0.0f),
                                raylib::Vector3(0, 1, 0), 90.0f, CAMERA_PERSPECTIVE);
        SetCameraMode(camera, CAMERA_FIRST_PERSON);

        collider = BoxCollider(camera.position, raylib::Vector3(1, 1, 1));
    }
};

float DistanceSquared(Vector3 *A, Vector3 *B)
{
    float dx = A->x - B->x;
    float dy = A->y - B->y;
    float dz = A->z - B->z;
    return (dx * dx + dy * dy + dz * dz);
}

void GetInput()
{
    if (IsKeyPressed(KEY_Q))
        debug = !debug;
}

void Draw3D(Player player, Vector3 positions[], float heights[], Color colors[], BoxCollider BBoxes[])
{
    BeginMode3D(player.camera);
    DrawPlane((Vector3){0.0f, 0.0f, 0.0f}, (Vector2){32.0f, 32.0f}, LIGHTGRAY);
    DrawCube((Vector3){-16.0f, 2.5f, 0.0f}, 1.0f, 5.0f, 32.0f, BLUE);
    DrawCube((Vector3){16.0f, 2.5f, 0.0f}, 1.0f, 5.0f, 32.0f, LIME);
    DrawCube((Vector3){0.0f, 2.5f, 16.0f}, 32.0f, 5.0f, 1.0f, GOLD);

    if (!debug)
    {
        for (int i = 0; i < MAX_COLUMNS; i++)
        {
            DrawCube(positions[i], 2.0f, heights[i], 2.0f, colors[i]);
            DrawCubeWires(positions[i], 2.0f, heights[i], 2.0f, BLUE);
        }
    }
    else
    {
        for (int i = 0; i < MAX_COLUMNS; i++)
        {
            DrawBoundingBox(BBoxes[i].BBox, GREEN);
        }
        DrawBoundingBox(player.collider.BBox, BLUE);
    }

    EndMode3D();
}

void Draw2D()
{
    DrawText("First person camera default controls:", 20, 20, 10, BLACK);
    DrawText("- Move with keys: W, A, S, D", 40, 40, 10, DARKGRAY);
    DrawText("- Mouse move to look around", 40, 60, 10, DARKGRAY);
    if(closeToCollider)
    {
            DrawText("CHECKING COLLISIONS", 40, 100, 20, BLUE);
            closeToCollider = false;
    }
    if (cameraCollided)
        DrawText("Colliding", 40, 80, 20, GREEN);
}

void GenerateLevel(float heights[], BoxCollider BBoxes[], Vector3 positions[], Color colors[])
{
    for (int i = 0; i < MAX_COLUMNS; i++)
    {
        heights[i] = (float)GetRandomValue(1, 12);
        positions[i] = (Vector3){GetRandomValue(-15, 15), heights[i] / 2, GetRandomValue(-15, 15)};
        BBoxes[i].extents = (Vector3){2.0f, heights[i], 2.0f};
        BBoxes[i].center = &positions[i];
        BBoxes[i].UpdateBoundingBox();
        colors[i] = (Color){GetRandomValue(20, 255), GetRandomValue(10, 55), 30, 255};
    }
}

void CheckPlayerCollisions(Player *player, BoxCollider BBoxes[])
{
    for (int i = 0; i < MAX_COLUMNS; i++)
    {
        if (DistanceSquared(player->collider.center, BBoxes[i].center) < CollisionDetectionThreshold)
        {
            closeToCollider = true;
            if (CheckCollisionBoxes(player->collider.BBox, BBoxes[i].BBox))
            {
                cameraCollided = true;
                return;
            }
        }
    }
    cameraCollided = false;
}

void Abbas()
{
    for (int i = 0; i < screenWidth; i++)
    {
        DrawPixel(i,screenHeight/2,BLACK);
    }
    for (int i = 0; i < screenHeight; i++)
    {
        DrawPixel(screenWidth/2,i,BLACK);
    }  
}

int main()
{
    InitWindow(screenWidth, screenHeight, "LET ME HELP YOU SEE, SLAYER");

    Player player;
    float heights[MAX_COLUMNS] = {0};
    Vector3 positions[MAX_COLUMNS] = {0};
    Color colors[MAX_COLUMNS] = {0};
    BoxCollider BBoxes[MAX_COLUMNS];
    GenerateLevel(heights, BBoxes, positions, colors);

    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);
        CheckPlayerCollisions(&player, BBoxes);

        Draw3D(player, positions, heights, colors, BBoxes);
        Draw2D();

        Abbas();

        GetInput();
        UpdateCamera(&player.camera);
        player.collider.UpdateBoundingBox();

        EndDrawing();
    }

    CloseWindow();

    return 0;
}