/*
*   LICENSE: zlib/libpng
*
*   raylib-cpp is licensed under an unmodified zlib/libpng license, which is an OSI-certified,
*   BSD-like license that allows static linking with closed source software:
*
*   Copyright (c) 2020 Rob Loach (@RobLoach)
*
*   This software is provided "as-is", without any express or implied warranty. In no event
*   will the authors be held liable for any damages arising from the use of this software.
*
*   Permission is granted to anyone to use this software for any purpose, including commercial
*   applications, and to alter it and redistribute it freely, subject to the following restrictions:
*
*     1. The origin of this software must not be misrepresented; you must not claim that you
*     wrote the original software. If you use this software in a product, an acknowledgment
*     in the product documentation would be appreciated but is not required.
*
*     2. Altered source versions must be plainly marked as such, and must not be misrepresented
*     as being the original software.
*
*     3. This notice may not be removed or altered from any source distribution.
*/

#ifndef RAYLIB_CPP_INCLUDE_WINDOW_HPP_
#define RAYLIB_CPP_INCLUDE_WINDOW_HPP_

#include <string>

#include "./raylib.hpp"

namespace raylib {
/**
 * Window and Graphics Device Functions.
 *
 * @code
 *
 * raylib::Window w(640, 480, "raylib-cpp");
 * while (!w.ShouldClose()) {
 *     // Update
 * }
 * @endcode
 */
class Window {
 public:
    /**
     * Initialize window and OpenGL context.
     */
    Window(int width = 800, int height = 450, const std::string& title = "raylib",
            bool lateInit = false) {
        if (!lateInit) {
            Init(width, height, title);
        }
    }

    ~Window() {
        Close();
    }

    void Init(int width = 800, int height = 450, const std::string& title = "raylib") {
        ::InitWindow(width, height, title.c_str());
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
    inline ::Vector2 GetSize() {
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
