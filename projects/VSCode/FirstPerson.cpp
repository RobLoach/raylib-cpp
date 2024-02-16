#include <raylib-cpp.hpp>


void UpdateFrame(raylib::Window& window, raylib::Camera3D& cam) {
    static raylib::Vector3 position;

    window.BeginDrawing();
    
        cam.Update(CAMERA_ORBITAL);

        window.ClearBackground(raylib::Color::RayWhite());
        
        cam.BeginMode();
            
            position.DrawCube({2.0f, 2.0f, 2.0f}, raylib::Color::Red());
            position.DrawCubeWires({2.0f, 2.0f, 2.0f}, raylib::Color::Maroon());
            DrawGrid(10, 1.0f);
            
        cam.EndMode();

        raylib::Vector2 textPosition{10, 40};
        raylib::Text sampleText( GetFontDefault(),"This is a raylib-cpp example", 20.0f, 20.0f /10.0f, raylib::Color::DarkGray());
        sampleText.Draw(textPosition);
    window.EndDrawing();
    
}

int main() {

    const int screenWidth  = 800;
    const int screenHeight = 450;

    raylib::Window window(screenWidth, screenHeight);


    raylib::Vector3 position(10.0f, 10.0f, 8.0f);
    raylib::Vector3 target(0.0f, 0.0f, 0.0f);
    raylib::Vector3 up (0.0f, 1.0f, 0.0f);

    float fovy = 60.0f;
    raylib::Camera3D cam(position, target, up, fovy, CAMERA_PERSPECTIVE);

    window.SetTargetFPS(60);

    while (!window.ShouldClose()) {
        UpdateFrame(window, cam);    
    }

    window.Close();
    return EXIT_SUCCESS;
}