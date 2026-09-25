add_library(raylib_cpp INTERFACE)
add_library(raylib_cpp::raylib_cpp ALIAS raylib_cpp)

set(RAYLIB_CPP_HEADERS
    ${CMAKE_CURRENT_SOURCE_DIR}/AudioDevice.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/AudioStream.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/AudioStreamUnmanaged.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/AutomationEventList.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/BoundingBox.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Camera2D.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Camera3D.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Color.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/FileData.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/FileText.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Font.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/FontUnmanaged.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Functions.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Gamepad.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Image.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Keyboard.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Material.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/MaterialUnmanaged.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Matrix.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Mesh.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/MeshUnmanaged.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Model.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/ModelUnmanaged.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/ModelAnimation.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Mouse.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Music.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/MusicUnmanaged.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Quaternion.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Ray.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/RayCollision.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/RaylibException.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/raylib-cpp-utils.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/raylib-cpp.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/raylib.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/raymath.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Rectangle.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/RenderTexture.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/RenderTextureUnmanaged.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/ShaderUnmanaged.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Shader.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Sound.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/SoundUnmanaged.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Text.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Texture.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/TextureUnmanaged.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Touch.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Vector2.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Vector3.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Vector4.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/VrStereoConfig.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Wave.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/WaveUnmanaged.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Window.hpp
)

# Include Directory
target_include_directories(raylib_cpp INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/>
    $<INSTALL_INTERFACE:include>
)
# Set the header files as install files.
include(GNUInstallDirs)
install(TARGETS raylib_cpp
    EXPORT raylib_cppTargets
)
install(FILES
  ${RAYLIB_CPP_HEADERS}
  DESTINATION include
)
install(EXPORT raylib_cppTargets
    NAMESPACE raylib_cpp::
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/raylib_cpp
)
include(CMakePackageConfigHelpers)
message(STATUS ${PROJECT_SOURCE_DIR}/cmake/raylib_cppConfig.cmake.in)
message(STATUS ${PROJECT_BINARY_DIR}/cmake/raylib_cppConfig.cmake)
configure_package_config_file(
    ${PROJECT_SOURCE_DIR}/cmake/raylib_cppConfig.cmake.in
    ${PROJECT_BINARY_DIR}/cmake/raylib_cppConfig.cmake
    INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/raylib_cpp
)
write_basic_package_version_file(
    ${PROJECT_BINARY_DIR}/cmake/raylib_cppConfigVersion.cmake
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY SameMajorVersion
)
install(FILES
    ${PROJECT_BINARY_DIR}/cmake/raylib_cppConfig.cmake
    ${PROJECT_BINARY_DIR}/cmake/raylib_cppConfigVersion.cmake
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/raylib_cpp
)
if (RAYLIB_CPP_IS_MAIN)
    # @TODO: add examples files
    add_custom_target(format
            COMMAND clang-format
            -i
            ${RAYLIB_CPP_HEADERS}
    )
endif()
