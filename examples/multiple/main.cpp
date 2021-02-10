#include "raylib-cpp.hpp"

#include "./Player.hpp"

int main() {
    raylib::Window window(640, 480);
    SetTargetFPS(60);

    Player player;
    while (!window.ShouldClose()) {
        window.BeginDrawing();
        ClearBackground(SKYBLUE);
        player.Update();
        player.Draw();
        window.EndDrawing();
    }

}
