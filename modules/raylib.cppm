/**
 * @file raylib.cppm
 * @brief Module file exporting all symbols in raylib-cpp.
 */

module;

#define BUILD_RAYLIB_CPP_MODULES
#define RLCPPAPI
#define RAYMATH_IMPLEMENTATION
#include "../include/raylib-cpp.hpp"

#undef LIGHTGRAY
#undef GRAY
#undef DARKGRAY
#undef YELLOW
#undef GOLD
#undef ORANGE
#undef PINK
#undef RED
#undef MAROON
#undef GREEN
#undef LIME
#undef DARKGREEN
#undef SKYBLUE
#undef BLUE
#undef DARKBLUE
#undef PURPLE
#undef VIOLET
#undef DARKPURPLE
#undef BEIGE
#undef BROWN
#undef DARKBROWN
#undef WHITE
#undef BLACK
#undef BLANK
#undef MAGENTA
#undef RAYWHITE

export module raylib;

/**
 * @namespace raylib
 * @brief All raylib-cpp classes and functions appear in the raylib namespace.
 */
export namespace raylib {
    // Classes
    using raylib::AudioDevice;
    using raylib::AudioStream;
    using raylib::AutomationEventList;
    using raylib::BoundingBox;
    using raylib::Camera; // Alias for Camera3D
    using raylib::Camera2D;
    using raylib::Camera3D;
    using raylib::Color;
    using raylib::FileData;
    using raylib::FileText;
    using raylib::Font;
    using raylib::Gamepad;
    using raylib::Image;
    using raylib::Material;
    using raylib::Matrix;
    using raylib::Mesh;
    using raylib::Model;
    using raylib::ModelAnimation;
    using raylib::Music;
    using raylib::Ray;
    using raylib::RayCollision;
    using raylib::RaylibException;
    using raylib::Rectangle;
    using raylib::RenderTexture;
    using raylib::RenderTexture2D; // Alias for RenderTexture
    using raylib::Shader;
    using raylib::Sound;
    using raylib::Text;
    using raylib::Texture;
    using raylib::Texture2D; // Alias for Texture
    using raylib::TextureCubemap; // Alias for Texture
    using raylib::TextureUnmanaged;
    using raylib::Texture2DUnmanaged; // Alias for TextureUnmanaged
    using raylib::TextureCubemapUnmanaged; // Alias for TextureUnmanaged
    using raylib::Vector2;
    using raylib::Vector3;
    using raylib::Vector4;
    using raylib::Quaternion; // Alias for Vector4
    using raylib::VrStereoConfig;
    using raylib::Wave;
    using raylib::Window;

    // Enums
    using ::ConfigFlags;
    using ::TraceLogLevel;
    using ::KeyboardKey;
    using ::MouseButton;
    using ::MouseCursor;
    using ::GamepadButton;
    using ::GamepadAxis;
    using ::MaterialMapIndex;
    using ::ShaderLocationIndex;
    using ::ShaderUniformDataType;
    using ::ShaderAttributeDataType;
    using ::PixelFormat;
    using ::TextureFilter;
    using ::TextureWrap;
    using ::CubemapLayout;
    using ::FontType;
    using ::BlendMode;
    using ::Gesture;
    using ::CameraMode;
    using ::CameraProjection;
    using ::NPatchLayout;

    // From Functions.hpp
    using raylib::InitWindow;
    using raylib::SetWindowTitle;
    using raylib::GetMonitorName;
    using raylib::SetClipboardText;
    using raylib::GetClipboardText;
    using raylib::TakeScreenshot;
    using raylib::GetGamepadName;
    using raylib::LoadFileText;
    using raylib::SaveFileText;
    using raylib::FileExists;
    using raylib::DirectoryExists;
    using raylib::IsFileExtension;
    using raylib::GetFileExtension;
    using raylib::GetFileName;
    using raylib::GetFileNameWithoutExt;
    using raylib::GetDirectoryPath;
    using raylib::GetPrevDirectoryPath;
    using raylib::GetWorkingDirectory;
    using raylib::LoadDirectoryFiles;
    using raylib::ChangeDirectory;
    using raylib::LoadDroppedFiles;
    using raylib::GetFileModTime;
    using raylib::OpenURL;
    using raylib::LoadImage;
    using raylib::LoadImageRaw;
    using raylib::LoadImageAnim;
    using raylib::LoadImageFromMemory;
    using raylib::ExportImage;
    using raylib::ExportImageAsCode;
    using raylib::DrawText;
    using raylib::DrawTextEx;
    using raylib::DrawTextPro;
    using raylib::LoadFont;
    using raylib::LoadFontEx;
    using raylib::MeasureText;
    using raylib::TextIsEqual;
    using raylib::TextLength;
    using raylib::TextSubtext;
    using raylib::TextReplace;
    using raylib::TextInsert;
    using raylib::TextSplit;
    using raylib::TextFindIndex;
    using raylib::TextToUpper;
    using raylib::TextToLower;
    using raylib::TextToPascal;
    using raylib::TextToInteger;

    /**
     * @namespace raylib::Colors
     * @brief Re-exports all Color macros as inline constexpr
     */
    namespace Colors {
        inline constexpr ::Color LIGHTGRAY = CLITERAL(::Color){ 200, 200, 200, 255 };
        inline constexpr ::Color GRAY = CLITERAL(::Color){ 130, 130, 130, 255 };
        inline constexpr ::Color DARKGRAY = CLITERAL(::Color){ 80, 80, 80, 255 };
        inline constexpr ::Color YELLOW = CLITERAL(::Color){ 253, 249, 0, 255 };
        inline constexpr ::Color GOLD = CLITERAL(::Color){ 255, 203, 0, 255 };
        inline constexpr ::Color ORANGE = CLITERAL(::Color){ 255, 161, 0, 255 };
        inline constexpr ::Color PINK = CLITERAL(::Color){ 255, 109, 194, 255 };
        inline constexpr ::Color RED = CLITERAL(::Color){ 230, 41, 55, 255 };
        inline constexpr ::Color MAROON = CLITERAL(::Color){ 190, 33, 55, 255 };
        inline constexpr ::Color GREEN = CLITERAL(::Color){ 0, 228, 48, 255 };
        inline constexpr ::Color LIME = CLITERAL(::Color){ 0, 158, 47, 255 };
        inline constexpr ::Color DARKGREEN = CLITERAL(::Color){ 0, 117, 44, 255 };
        inline constexpr ::Color SKYBLUE = CLITERAL(::Color){ 102, 191, 255, 255 };
        inline constexpr ::Color BLUE = CLITERAL(::Color){ 0, 121, 241, 255 };
        inline constexpr ::Color DARKBLUE = CLITERAL(::Color){ 0, 82, 172, 255 };
        inline constexpr ::Color PURPLE = CLITERAL(::Color){ 200, 122, 255, 255 };
        inline constexpr ::Color VIOLET = CLITERAL(::Color){ 135, 60, 190, 255 };
        inline constexpr ::Color DARKPURPLE = CLITERAL(::Color){ 112, 31, 126, 255 };
        inline constexpr ::Color BEIGE = CLITERAL(::Color){ 211, 176, 131, 255 };
        inline constexpr ::Color BROWN = CLITERAL(::Color){ 127, 106, 79, 255 };
        inline constexpr ::Color DARKBROWN = CLITERAL(::Color){ 76, 63, 47, 255 };
        inline constexpr ::Color WHITE = CLITERAL(::Color){ 255, 255, 255, 255 };
        inline constexpr ::Color BLACK = CLITERAL(::Color){ 0, 0, 0, 255 };
        inline constexpr ::Color BLANK = CLITERAL(::Color){ 0, 0, 0, 0 };
        inline constexpr ::Color MAGENTA = CLITERAL(::Color){ 255, 0, 255, 255 };
        inline constexpr ::Color RAYWHITE = CLITERAL(::Color){ 245, 245, 245, 255 };
    }

    /**
     * @namespace raylib::Keyboard
     * @brief Input-related functions: keyboard
     */
    namespace Keyboard {
        using raylib::Keyboard::IsKeyPressed;
        using raylib::Keyboard::IsKeyPressedRepeat;
        using raylib::Keyboard::IsKeyDown;
        using raylib::Keyboard::IsKeyReleased;
        using raylib::Keyboard::IsKeyUp;
        using raylib::Keyboard::GetKeyPressed;
        using raylib::Keyboard::GetCharPressed;
    }

    /**
     * @namespace raylib::Mouse
     * @brief Input-related functions: mouse
     */
    namespace Mouse {
        using raylib::Mouse::IsButtonPressed;
        using raylib::Mouse::IsButtonDown;
        using raylib::Mouse::IsButtonReleased;
        using raylib::Mouse::IsButtonUp;
        using raylib::Mouse::GetX;
        using raylib::Mouse::GetY;
        using raylib::Mouse::SetX;
        using raylib::Mouse::SetY;
        using raylib::Mouse::GetPosition;
        using raylib::Mouse::SetPosition;
        using raylib::Mouse::GetDelta;
        using raylib::Mouse::SetOffset;
        using raylib::Mouse::SetScale;
        using raylib::Mouse::GetWheelMove;
        using raylib::Mouse::GetWheelMoveV;
        using raylib::Mouse::SetCursor;
        using raylib::Mouse::GetTouchX;
        using raylib::Mouse::GetTouchY;
        using raylib::Mouse::GetTouchPosition;
        using raylib::Mouse::GetRay;
    }

    /**
     * @namespace raylib::Touch
     * @brief Input-related functions: touch
     */
    namespace Touch {
        using raylib::Touch::GetX;
        using raylib::Touch::GetY;
        using raylib::Touch::GetPosition;
        using raylib::Touch::GetPointId;
        using raylib::Touch::GetPointCount;
    }


} // namespace raylib

#ifdef RAYLIB_CPP_R_PREFIXES
export {
    using RAudioDevice = raylib::AudioDevice;
    using RAudioStream = raylib::AudioStream;
    using RAutomationEventList = raylib::AutomationEventList;
    using RBoundingBox = raylib::BoundingBox;
    using RCamera = raylib::Camera; // Alias for Camera3D
    using RCamera2D = raylib::Camera2D;
    using RCamera3D = raylib::Camera3D;
    using RColor = raylib::Color;
    using RFileData = raylib::FileData;
    using RFileText = raylib::FileText;
    using RFont = raylib::Font;
    using RGamepad = raylib::Gamepad;
    using RImage = raylib::Image;
    using RMaterial = raylib::Material;
    using RMatrix = raylib::Matrix;
    using RMesh = raylib::Mesh;
    using RModel = raylib::Model;
    using RModelAnimation = raylib::ModelAnimation;
    using RMusic = raylib::Music;
    using RRay = raylib::Ray;
    using RRayCollision = raylib::RayCollision;
    using RRaylibException = raylib::RaylibException;
    using RRectangle = raylib::Rectangle;
    using RRenderTexture = raylib::RenderTexture;
    using RRenderTexture2D = raylib::RenderTexture2D; // Alias for RenderTexture
    using RShader = raylib::Shader;
    using RSound = raylib::Sound;
    using RText = raylib::Text;
    using RTexture = raylib::Texture;
    using RTexture2D = raylib::Texture2D; // Alias for Texture
    using RTextureCubemap = raylib::TextureCubemap; // Alias for Texture
    using RTextureUnmanaged = raylib::TextureUnmanaged;
    using RTexture2DUnmanaged = raylib::Texture2DUnmanaged; // Alias for TextureUnmanaged
    using RTextureCubemapUnmanaged = raylib::TextureCubemapUnmanaged; // Alias for TextureUnmanaged
    using RVector2 = raylib::Vector2;
    using RVector3 = raylib::Vector3;
    using RVector4 = raylib::Vector4;
    using RQuaternion = raylib::Quaternion; // Alias for Vector4
    using RVrStereoConfig = raylib::VrStereoConfig;
    using RWave = raylib::Wave;
    using RWindow = raylib::Window;
}
#endif
