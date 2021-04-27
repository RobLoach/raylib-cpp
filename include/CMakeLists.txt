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
    Font.hpp
    Functions.hpp
    Gamepad.hpp
    Image.hpp
    Material.hpp
    Matrix.hpp
    Mesh.hpp
    Model.hpp
    ModelAnimation.hpp
    Mouse.hpp
    Music.hpp
    physac.hpp
    Physics.hpp
    Ray.hpp
    RayHitInfo.hpp
    raylib-cpp-utils.hpp
    raylib-cpp.hpp
    raylib.hpp
    raymath.hpp
    Rectangle.hpp
    RenderTexture.hpp
    Shader.hpp
    Sound.hpp
    Text.hpp
    Texture.hpp
    Vector2.hpp
    Vector3.hpp
    Vector4.hpp
    VrStereoConfig.hpp
    Wave.hpp
    Window.hpp
    DESTINATION include
)
