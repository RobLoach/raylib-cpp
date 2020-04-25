add_library(raylib-cpp INTERFACE)

target_include_directories(raylib-cpp INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/)

install(FILES
	raylib/AudioDevice.hpp
	raylib/AudioStream.hpp
	raylib/BoundingBox.hpp
	raylib/Camera2D.hpp
	raylib/Camera3D.hpp
	raylib/Color.hpp
	raylib/DroppedFiles.hpp
	raylib/Font.hpp
	raylib/Gamepad.hpp
	raylib/Image.hpp
	raylib/Material.hpp
	raylib/Matrix.hpp
	raylib/Mesh.hpp
	raylib/ModelAnimation.hpp
	raylib/Model.hpp
	raylib/Mouse.hpp
	raylib/Music.hpp
	raylib/Physics.hpp
	raylib/RayHitInfo.hpp
	raylib/Ray.hpp
	raylib/raylib.hpp
	raylib/Rectangle.hpp
	raylib/RenderTexture2D.hpp
	raylib/Shader.hpp
	raylib/Sound.hpp
	raylib/Texture2D.hpp
	raylib/utils.hpp
	raylib/Vector2.hpp
	raylib/Vector3.hpp
	raylib/Vector4.hpp
	raylib/VrSimulator.hpp
	raylib/Wave.hpp
	raylib/Window.hpp
	DESTINATION include/raylib
)
