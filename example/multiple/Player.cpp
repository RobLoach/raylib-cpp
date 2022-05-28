#include "Player.hpp"
#include "raylib-cpp.hpp"

Player::Player() {
    position = Rectangle{
        GetScreenWidth() / 2.0f - 50,
        GetScreenHeight() / 2.0f - 50,
        100,
        100
    };
    speed = 3;
}

void Player::Draw() {
    position.Draw(RED);
}

void Player::Update() {
    if (IsKeyDown(KEY_UP)) {
        position.y -= speed;
    }
    if (IsKeyDown(KEY_DOWN)) {
        position.y += speed;
    }
    if (IsKeyDown(KEY_RIGHT)) {
        position.x += speed;
    }
    if (IsKeyDown(KEY_LEFT)) {
        position.x -= speed;
    }
}
