add_library(raylib-cpp INTERFACE)

# Include Directory
target_include_directories(raylib-cpp INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/)

# Set the header files as install files.
install(FILES
    AudioDevice.hpp
    AudioStream.hpp
    BoundingBox.hpp
    Camera2D.hpp
    Camera3D.hpp
    Color.hpp
    Functions.hpp
    Font.hpp
    Gamepad.hpp
    Image.hpp
    Material.hpp
    Matrix.hpp
    Mesh.hpp
    ModelAnimation.hpp
    Model.hpp
    Mouse.hpp
    Music.hpp
    Physics.hpp
    RayHitInfo.hpp
    Ray.hpp
    raylib.hpp
    raylib-cpp.hpp
    raylib-cpp-utils.hpp
    raymath.hpp
    Rectangle.hpp
    RenderTexture.hpp
    Shader.hpp
    Sound.hpp
    Texture.hpp
    Vector2.hpp
    Vector3.hpp
    Vector4.hpp
    VrSimulator.hpp
    Wave.hpp
    Window.hpp
    DESTINATION include
)
