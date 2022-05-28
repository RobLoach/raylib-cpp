/*******************************************************************************
*
*   raylib example - loading thread
*
*   This example has been created using raylib-cpp (www.raylib.com)
*   raylib is licensed under an unmodified zlib/libpng license
*   (View raylib.h for details)
*
*   Copyright (c) 2014-2019 Ramon Santamaria (@raysan5)
*   Copyright (c) 2021 Paul Keir (University of the West of Scotland)
*
*******************************************************************************/

#include <thread>                           // C++11 standard library threads
#include <atomic>                           // C++ atomic data types
#include <chrono>                           // For: chrono::steady_clock::now()
#include <system_error>                     // May be thrown by thread c'tor

#include "raylib-cpp.hpp"

// Using C++ std::atomic_bool (aka. std::atomic<bool>) for synchronization.
// n.b. A plain built-in type can't be used for inter-thread synchronization
std::atomic_bool dataLoaded{false};
static void LoadDataThread();     // Loading data thread function declaration
static int dataProgress = 0;      // Data progress accumulator

int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;

    raylib::Window window(screenWidth, screenHeight,
                          "raylib [core] example - loading thread");

    std::thread threadId;         // Loading data thread id

    enum { STATE_WAITING, STATE_LOADING, STATE_FINISHED } state = STATE_WAITING;
    int framesCounter = 0;

    SetTargetFPS(60);             // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------

    // Main game loop
    while (!window.ShouldClose()) {    // Detect window close button or ESC key
        // Update
        //----------------------------------------------------------------------
        switch (state)
        {
            case STATE_WAITING:
                if (IsKeyPressed(KEY_ENTER))
                {
                    try {
                        threadId = std::thread(LoadDataThread);
                        TraceLog(LOG_INFO,
                            "Loading thread initialized successfully");
                    } catch (std::system_error e) {
                        TraceLog(LOG_ERROR, "Error: %s", e.what());
                    }

                    state = STATE_LOADING;
                }
                break;

            case STATE_LOADING:
                framesCounter++;
                if (dataLoaded.load())
                {
                    framesCounter = 0;
                    state = STATE_FINISHED;
                }
                break;

            case STATE_FINISHED:
                if (IsKeyPressed(KEY_ENTER))
                {
                    // Reset everything to launch again
                    dataLoaded = false;
                    dataProgress = 0;
                    state = STATE_WAITING;
                }
                break;

            default:
              break;
        }
        //----------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------
        BeginDrawing();
        {

            window.ClearBackground(RAYWHITE);

            switch (state)
            {
                case STATE_WAITING:
                    raylib::DrawText("PRESS ENTER to START LOADING DATA",
                              150, 170, 20, DARKGRAY);
                    break;

                case STATE_LOADING:
                    DrawRectangle(150, 200, dataProgress, 60, SKYBLUE);
                    if ((framesCounter/15)%2)
                        raylib::DrawText("LOADING DATA...", 240, 210, 40, DARKBLUE);
                    break;

                case STATE_FINISHED:
                    DrawRectangle(150, 200, 500, 60, LIME);
                    raylib::DrawText("DATA LOADED!", 250, 210, 40, GREEN);
                    break;
            }

            DrawRectangleLines(150, 200, 500, 60, DARKGRAY);
        }

        EndDrawing();
        //----------------------------------------------------------------------
    }

    if (threadId.joinable()) // The user might quit without creating a thread.
      threadId.join();       // Good etiquette, but may take a second.

    return 0;
}

// Loading data thread function definition
static void LoadDataThread()
{
    using namespace std::chrono;
    int timeCounter = 0;            // Time counted in ms

    auto prevTime = steady_clock::now();

    // We simulate data loading with a time counter for 5 seconds
    while (timeCounter < 5000)
    {
        auto currentTime = steady_clock::now() - prevTime;
        timeCounter = duration_cast<milliseconds>(currentTime).count();

        // We accumulate time over a global variable to be used in
        // main thread as a progress bar
        dataProgress = timeCounter/10;
    }

    // When data has finished loading, we set global variable
    dataLoaded = true;
}
