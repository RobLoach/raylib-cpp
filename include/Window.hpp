#ifndef RAYLIB_CPP_INCLUDE_WINDOW_HPP_
#define RAYLIB_CPP_INCLUDE_WINDOW_HPP_

#include <string>

#include "./raylib.hpp"
#include "./RaylibException.hpp"

namespace raylib {
/**
 * Window and Graphics Device Functions.
 */
class Window {
 public:
    /**
     * Initialize window and OpenGL context.
     *
     * @throws raylib::RaylibException Thrown if the window failed to initiate.
     */
    Window(int width = 800, int height = 450, const std::string& title = "raylib",
            bool lateInit = false) {
        if (!lateInit) {
            if (!Init(width, height, title)) {
                throw RaylibException("Failed to create Window");
            }
        }
    }

    /**
     * Close window and unload OpenGL context
     */
    ~Window() {
        Close();
    }

    /**
     * Initializes the window.
     *
     * @return True or false, depending on if the Window initialized properly.
     */
    bool Init(int width = 800, int height = 450, const std::string& title = "raylib") {
        ::InitWindow(width, height, title.c_str());
        return IsWindowReady();
    }

    /**
     * Check if KEY_ESCAPE pressed or Close icon pressed
     */
    inline bool ShouldClose() const {
        return ::WindowShouldClose();
    }

    /**
     * Close window and unload OpenGL context
     */
    inline void Close() {
        ::CloseWindow();
    }

    /**
     * Check if cursor is on the current screen
     */
    inline bool IsCursorOnScreen() const {
        return ::IsCursorOnScreen();
    }

    /**
     * Check if window has been initialized successfully
     */
    inline static bool IsReady() {
        return ::IsWindowReady();
    }

    /**
     * Check if window is currently fullscreen
     */
    inline bool IsFullscreen() const {
        return ::IsWindowFullscreen();
    }

    /**
     * Check if window is currently hidden
     */
    inline bool IsHidden() const {
        return ::IsWindowHidden();
    }

    /**
     * Check if window is currently minimized
     */
    inline bool IsMinimized() const {
        return ::IsWindowMinimized();
    }

    /**
     * Check if window is currently minimized
     */
    inline bool IsMaximized() const {
        return ::IsWindowMaximized();
    }

    /**
     * Check if window is currently focused
     */
    inline bool IsFocused() const {
        return ::IsWindowFocused();
    }

    /**
     * Check if window has been resized last frame
     */
    inline bool IsResized() const {
        return ::IsWindowResized();
    }

    /**
     * Check if one specific window flag is enabled
     */
    inline bool IsState(unsigned int flag) const {
        return ::IsWindowState(flag);
    }

    /**
     * Set window configuration state using flags
     */
    inline Window& SetState(unsigned int flag) {
        ::SetWindowState(flag);
        return *this;
    }

    /**
     * Clear window configuration state flags
     */
    inline Window& ClearState(unsigned int flag) {
        ::ClearWindowState(flag);
        return *this;
    }

    /**
     * Clear window with given color.
     */
    inline Window& ClearBackground(const ::Color& color = BLACK) {
        ::ClearBackground(color);
        return *this;
    }

    /**
     * Toggle window state: fullscreen/windowed
     */
    inline Window& ToggleFullscreen() {
        ::ToggleFullscreen();
        return *this;
    }

    /**
     * Set whether or not the application should be fullscreen.
     */
    inline Window& SetFullscreen(bool fullscreen) {
        if (fullscreen) {
            if (!IsFullscreen()) {
                ToggleFullscreen();
            }
        } else {
            if (IsFullscreen()) {
                ToggleFullscreen();
            }
        }

        return *this;
    }

    /**
     * Set window state: maximized, if resizable (only PLATFORM_DESKTOP)
     */
    inline Window& Maximize() {
        ::MaximizeWindow();
        return *this;
    }

    /**
     * Set window state: minimized, if resizable (only PLATFORM_DESKTOP)
     */
    inline Window& Minimize() {
        ::MinimizeWindow();
        return *this;
    }

    /**
     * Set window state: not minimized/maximized (only PLATFORM_DESKTOP)
     */
    inline Window& Restore() {
        ::RestoreWindow();
        return *this;
    }

    /**
     * Set icon for window
     */
    inline Window& SetIcon(const ::Image& image) {
        ::SetWindowIcon(image);
        return *this;
    }

    /**
     * Set title for window
     */
    inline Window& SetTitle(const std::string& title) {
        ::SetWindowTitle(title.c_str());
        return *this;
    }

    /**
     * Set window position on screen
     */
    inline Window& SetPosition(int x, int y) {
        ::SetWindowPosition(x, y);
        return *this;
    }

    /**
     * Set window position on screen
     */
    inline Window& SetPosition(const ::Vector2& position) {
        return SetPosition(static_cast<int>(position.x), static_cast<int>(position.y));
    }

    /**
     * Set monitor for the current window
     */
    inline Window& SetMonitor(int monitor) {
        ::SetWindowMonitor(monitor);
        return *this;
    }

    /**
     * Set window minimum dimensions
     */
    inline Window& SetMinSize(int width, int height) {
        ::SetWindowMinSize(width, height);
        return *this;
    }

    /**
     * Set window minimum dimensions
     */
    inline Window& SetMinSize(const ::Vector2& size) {
        ::SetWindowMinSize(static_cast<int>(size.x), static_cast<int>(size.y));
        return *this;
    }

    /**
     * Set window dimensions
     */
    inline Window& SetSize(int width, int height) {
        ::SetWindowSize(width, height);
        return *this;
    }

    /**
     * Set window dimensions
     */
    inline Window& SetSize(const ::Vector2& size) {
        return SetSize(static_cast<int>(size.x), static_cast<int>(size.y));
    }

    /**
     * Get the screen's width and height.
     */
    inline Vector2 GetSize() {
        return {static_cast<float>(GetWidth()), static_cast<float>(GetHeight())};
    }

    /**
     * Get native window handle
     */
    inline void* GetHandle() const {
        return ::GetWindowHandle();
    }

    /**
     * Setup canvas (framebuffer) to start drawing
     */
    inline Window& BeginDrawing() {
        ::BeginDrawing();
        return *this;
    }

    /**
     * End canvas drawing and swap buffers (double buffering)
     */
    inline Window& EndDrawing() {
        ::EndDrawing();
        return *this;
    }

    /**
     * Get current screen width
     */
    inline int GetWidth() const {
        return ::GetScreenWidth();
    }

    /**
     * Get current screen height
     */
    inline int GetHeight() const {
        return ::GetScreenHeight();
    }

    /**
     * Get window position XY on monitor
     */
    inline ::Vector2 GetPosition() const {
        return ::GetWindowPosition();
    }

    /**
     * Get window scale DPI factor
     */
    inline ::Vector2 GetScaleDPI() const {
        return ::GetWindowScaleDPI();
    }

    /**
     * Set target FPS (maximum)
     */
    inline Window& SetTargetFPS(int fps) {
        ::SetTargetFPS(fps);
        return *this;
    }

    /**
     * Returns current FPS
     */
    inline int GetFPS() const {
        return ::GetFPS();
    }

    /**
     * Returns time in seconds for last frame drawn
     */
    inline float GetFrameTime() const {
        return ::GetFrameTime();
    }

    /**
     * Returns elapsed time in seconds since InitWindow()
     */
    inline double GetTime() const {
        return ::GetTime();
    }
};
}  // namespace raylib

#endif  // RAYLIB_CPP_INCLUDE_WINDOW_HPP_
