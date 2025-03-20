#ifndef RAYLIB_CPP_INCLUDE_WINDOW_HPP_
#define RAYLIB_CPP_INCLUDE_WINDOW_HPP_

#include <string>

#include "./RaylibException.hpp"
#include "./Vector2.hpp"
#include "./raylib.hpp"

namespace raylib {
/**
 * Window and Graphics Device Functions.
 */
class Window {
public:
    /**
     * Build a Window object, but defer the initialization. Ensure you call Init() manually.
     *
     * @see Init()
     */
    Window() = default;

    /**
     * Initialize window and OpenGL context.
     *
     * @param width The width of the window.
     * @param height The height of the window.
     * @param title The desired title of the window.
     * @param flags The ConfigFlags to set prior to initializing the window. See SetConfigFlags for more details.
     *
     * @see ::SetConfigFlags()
     * @see ConfigFlags
     *
     * @throws raylib::RaylibException Thrown if the window failed to initiate.
     */
    Window(int width, int height, const std::string& title = "raylib", unsigned int flags = 0) {
        Init(width, height, title, flags);
    }

    /**
     * Close window and unload OpenGL context
     */
    ~Window() { Close(); }

    /**
     * Initializes the window.
     *
     * @param width The width of the window.
     * @param height The height of the window.
     * @param title The desired title of the window.
     * @param flags The ConfigFlags to set prior to initializing the window. See SetConfigFlags for more details.
     *
     * @see ::SetConfigFlags()
     * @see ConfigFlags
     *
     * @throws raylib::RaylibException Thrown if the window failed to initiate.
     */
    static void Init(int width = 800, int height = 450, const std::string& title = "raylib", unsigned int flags = 0) {
        if (flags != 0) {
            ::SetConfigFlags(flags);
        }
        ::InitWindow(width, height, title.c_str());
        if (!::IsWindowReady()) {
            throw RaylibException("Failed to create Window");
        }
    }

    /**
     * Check if KEY_ESCAPE pressed or Close icon pressed
     */
    static bool ShouldClose()  { return ::WindowShouldClose(); }

    /**
     * Set a custom key to exit program (default is ESC)
     */
    static void SetExitKey(int key) { ::SetExitKey(key); }

    /**
     * Close window and unload OpenGL context
     */
    static void Close() {
        if (::IsWindowReady()) {
            ::CloseWindow();
        }
    }

    /**
     * Check if cursor is on the current screen
     */
    static bool IsCursorOnScreen()  { return ::IsCursorOnScreen(); }

    /**
     * Check if window is currently fullscreen
     */
    static bool IsFullscreen()  { return ::IsWindowFullscreen(); }

    /**
     * Check if window is currently hidden
     */
    static bool IsHidden()  { return ::IsWindowHidden(); }

    /**
     * Check if window is currently minimized
     */
    static bool IsMinimized()  { return ::IsWindowMinimized(); }

    /**
     * Check if window is currently minimized
     */
    static bool IsMaximized()  { return ::IsWindowMaximized(); }

    /**
     * Check if window is currently focused
     */
    static bool IsFocused()  { return ::IsWindowFocused(); }

    /**
     * Check if window has been resized last frame
     */
    static bool IsResized()  { return ::IsWindowResized(); }

    /**
     * Check if one specific window flag is enabled
     */
    static bool IsState(unsigned int flag)  { return ::IsWindowState(flag); }

    /**
     * Set window configuration state using flags
     */
    Window& SetState(unsigned int flag) {
        ::SetWindowState(flag);
        return *this;
    }

    /**
     * Clear window configuration state flags
     */
    Window& ClearState(unsigned int flag) {
        ::ClearWindowState(flag);
        return *this;
    }

    /**
     * Clear window with given color.
     */
    Window& ClearBackground(const ::Color& color = BLACK) {
        ::ClearBackground(color);
        return *this;
    }

    /**
     * Toggle window state: fullscreen/windowed
     */
    Window& ToggleFullscreen() {
        ::ToggleFullscreen();
        return *this;
    }

    /**
     * Set whether or not the application should be fullscreen.
     */
    Window& SetFullscreen(bool fullscreen) {
        if (fullscreen) {
            if (!IsFullscreen()) {
                ToggleFullscreen();
            }
        }
        else {
            if (IsFullscreen()) {
                ToggleFullscreen();
            }
        }

        return *this;
    }

    /**
     * Toggle window state: borderless/windowed
     */
    Window& ToggleBorderless() {
        ::ToggleBorderlessWindowed();
        return *this;
    }

    /**
     * Set window state: maximized, if resizable (only PLATFORM_DESKTOP)
     */
    Window& Maximize() {
        ::MaximizeWindow();
        return *this;
    }

    /**
     * Set window state: minimized, if resizable (only PLATFORM_DESKTOP)
     */
    Window& Minimize() {
        ::MinimizeWindow();
        return *this;
    }

    /**
     * Set window state: not minimized/maximized (only PLATFORM_DESKTOP)
     */
    Window& Restore() {
        ::RestoreWindow();
        return *this;
    }

    /**
     * Set icon for window
     */
    Window& SetIcon(const ::Image& image) {
        ::SetWindowIcon(image);
        return *this;
    }

    /**
     * Set icon for window (multiple images, RGBA 32bit, only PLATFORM_DESKTOP)
     */
    Window& SetIcons(Image* images, int count) {
        ::SetWindowIcons(images, count);
        return *this;
    }

    /**
     * Set title for window
     */
    Window& SetTitle(const std::string& title) {
        ::SetWindowTitle(title.c_str());
        return *this;
    }

    /**
     * Set window position on screen
     */
    Window& SetPosition(int x, int y) {
        ::SetWindowPosition(x, y);
        return *this;
    }

    /**
     * Set window position on screen
     */
    Window& SetPosition(const ::Vector2& position) {
        return SetPosition(static_cast<int>(position.x), static_cast<int>(position.y));
    }

    /**
     * Set monitor for the current window
     */
    Window& SetMonitor(int monitor) {
        ::SetWindowMonitor(monitor);
        return *this;
    }

    /**
     * Set window minimum dimensions
     */
    Window& SetMinSize(int width, int height) {
        ::SetWindowMinSize(width, height);
        return *this;
    }

    /**
     * Set window minimum dimensions
     */
    Window& SetMinSize(const ::Vector2& size) {
        ::SetWindowMinSize(static_cast<int>(size.x), static_cast<int>(size.y));
        return *this;
    }

    /**
     * Set window dimensions
     */
    Window& SetSize(int width, int height) {
        ::SetWindowSize(width, height);
        return *this;
    }

    /**
     * Set window opacity [0.0f..1.0f] (only PLATFORM_DESKTOP)
     */
    Window& SetOpacity(float opacity) {
        ::SetWindowOpacity(opacity);
        return *this;
    }

    /**
     * Set window focused (only PLATFORM_DESKTOP)
     */
    Window& SetFocused() {
        ::SetWindowFocused();
        return *this;
    }

    /**
     * Set window dimensions
     */
    Window& SetSize(const ::Vector2& size) { return SetSize(static_cast<int>(size.x), static_cast<int>(size.y)); }

    /**
     * Get the screen's width and height.
     */
    static Vector2 GetSize() { return {static_cast<float>(GetWidth()), static_cast<float>(GetHeight())}; }

    /**
     * Get native window handle
     */
    static void* GetHandle() { return ::GetWindowHandle(); }

    /**
     * Setup canvas (framebuffer) to start drawing
     */
    Window& BeginDrawing() {
        ::BeginDrawing();
        return *this;
    }

    /**
     * End canvas drawing and swap buffers (double buffering)
     */
    Window& EndDrawing() {
        ::EndDrawing();
        return *this;
    }

    /**
     * Get current screen width
     */
    static int GetWidth() { return ::GetScreenWidth(); }

    /**
     * Get current screen height
     */
    static int GetHeight() { return ::GetScreenHeight(); }

    /**
     * Get current render width (it considers HiDPI)
     */
    static int GetRenderWidth() { return ::GetRenderWidth(); }

    /**
     * Get current render height (it considers HiDPI)
     */
    static int GetRenderHeight() { return ::GetRenderHeight(); }

    /**
     * Get window position XY on monitor
     */
    static Vector2 GetPosition() { return ::GetWindowPosition(); }

    /*
     * Get current window monitor
     */
    static int GetMonitor() { return ::GetCurrentMonitor(); }

    /**
     * Get window scale DPI factor
     */
    static Vector2 GetScaleDPI() { return ::GetWindowScaleDPI(); }

    /**
     * Set clipboard text content
     */
    static void SetClipboardText(const std::string& text) { ::SetClipboardText(text.c_str()); }

    /**
     * Get clipboard text content
     */
    static std::string GetClipboardText() { return ::GetClipboardText(); }

    /**
     * Set target FPS (maximum)
     */
    Window& SetTargetFPS(int fps) {
        ::SetTargetFPS(fps);
        return *this;
    }

    /**
     * Returns current FPS
     */
    static int GetFPS()  { return ::GetFPS(); }

    /**
     * Draw current FPS
     */
    static void DrawFPS(int posX = 10, int posY = 10)  { ::DrawFPS(posX, posY); }

    /**
     * Returns time in seconds for last frame drawn
     */
    static float GetFrameTime()  { return ::GetFrameTime(); }

    /**
     * Returns elapsed time in seconds since InitWindow()
     */
    static double GetTime()  { return ::GetTime(); }

    /**
     * Check if window has been initialized successfully
     */
    static bool IsReady() { return ::IsWindowReady(); }

    /**
     * Sets the configuration flags for raylib.
     *
     * @param flags The ConfigFlags to apply to the configuration.
     *
     * @see ::SetConfigFlags
     */
    static void SetConfigFlags(unsigned int flags) { ::SetConfigFlags(flags); }

    /**
     * Alternates between calling `BeginDrawing()` and `EndDrawing()`.
     *
     * @code
     * while (window.Drawing()) {
     *     DrawRectangle();
     * }
     * @endcode
     *
     * @return True if we're within the `BeginDrawing()` scope.
     */
    bool Drawing() {
        if (m_drawing) {
            EndDrawing();
            m_drawing = false;
        }
        else {
            BeginDrawing();
            m_drawing = true;
        }

        return m_drawing;
    }

    protected:
        /**
         * Handles the internal drawing state for calling either `BeginDrawing()` or `EndDrawing()` from the `Drawing()` function.
         *
         * @see Drawing()
         */
        bool m_drawing = false;
};
} // namespace raylib

using RWindow = raylib::Window;

#endif // RAYLIB_CPP_INCLUDE_WINDOW_HPP_
