add_library(raylib_cpp INTERFACE)

set(RAYLIB_CPP_HEADERS
    ${CMAKE_CURRENT_SOURCE_DIR}/AudioDevice.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/AudioStream.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/AutomationEventList.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/BoundingBox.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Camera2D.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Camera3D.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Color.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/FileData.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/FileText.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Font.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Functions.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Gamepad.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Image.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Keyboard.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Material.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Matrix.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Mesh.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/MeshUnmanaged.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Model.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/ModelAnimation.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Mouse.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Music.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Ray.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/RayCollision.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/RaylibException.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/raylib-cpp-utils.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/raylib-cpp.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/raylib.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/raymath.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Rectangle.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/RenderTexture.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/ShaderUnmanaged.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Shader.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Sound.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Text.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Texture.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/TextureUnmanaged.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Touch.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Vector2.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Vector3.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Vector4.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/VrStereoConfig.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Wave.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Window.hpp
)

# Include Directory
target_include_directories(raylib_cpp INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/)

# Set the header files as install files.
install(FILES
  ${RAYLIB_CPP_HEADERS}
  DESTINATION include
)

if (RAYLIB_CPP_IS_MAIN)
    # @TODO: add examples files
    add_custom_target(format
            COMMAND clang-format
            -i
            ${RAYLIB_CPP_HEADERS}
    )
endif()