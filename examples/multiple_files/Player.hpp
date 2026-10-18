#include "raylib-cpp.hpp"

class Player {
    public:
    Player();
    raylib::Rectangle position;
    int speed;
    void Draw();
    void Update();
};
