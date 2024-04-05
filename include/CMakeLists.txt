add_library(raylib_cpp INTERFACE)

set(RAYLIB_CPP_HEADERS
  AudioDevice.hpp
  AudioStream.hpp
  AutomationEventList.hpp
  BoundingBox.hpp
  Camera2D.hpp
  Camera3D.hpp
  Color.hpp
  FileData.hpp
  FileText.hpp
  Font.hpp
  Functions.hpp
  Gamepad.hpp
  Image.hpp
  Keyboard.hpp
  Material.hpp
  Matrix.hpp
  Mesh.hpp
  MeshUnmanaged.hpp
  Model.hpp
  ModelAnimation.hpp
  Mouse.hpp
  Music.hpp
  Ray.hpp
  RayCollision.hpp
  RaylibException.hpp
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
  TextureUnmanaged.hpp
  Touch.hpp
  Vector2.hpp
  Vector3.hpp
  Vector4.hpp
  VrStereoConfig.hpp
  Wave.hpp
  Window.hpp
)

# Include Directory
target_include_directories(raylib_cpp INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/)

# Set the header files as install files.
install(FILES
  ${RAYLIB_CPP_HEADERS}
  DESTINATION include
)
