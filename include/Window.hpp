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

    void Init(int width, int height, const std::string& title) {
        ::InitWindow(width, height, title.c_str());
    }

    /**
     * Check if KEY_ESCAPE pressed or Close icon pressed
     */
    inline bool ShouldClose() {
        return ::WindowShouldClose();
    }

    /**
     * Close window and unload OpenGL context
     */
    inline void Close() {
        ::CloseWindow();
    }

    inline bool IsCursorOnScreen() {
        return ::IsCursorOnScreen();
    }

    /**
     * Check if window has been initialized successfully
     */
    inline static bool IsReady() {
        return ::IsWindowReady();
    }

    inline bool IsMinimized() const {
        return ::IsWindowMinimized();
    }

    inline bool IsFocused() const {
        return ::IsWindowFocused();
    }

    inline bool IsResized() const {
        return ::IsWindowResized();
    }

    inline bool IsHidden() const {
        return ::IsWindowHidden();
    }

    inline bool IsFullscreen() const {
        return ::IsWindowFullscreen();
    }

    inline Window& ToggleFullscreen() {
        ::ToggleFullscreen();
        return *this;
    }

    inline Window& Unhide() {
        ::UnhideWindow();
        return *this;
    }

    inline Window& Hide() {
        ::HideWindow();
        return *this;
    }

    inline Window& SetIcon(Image image) {
        ::SetWindowIcon(image);
        return *this;
    }

    inline Window& SetTitle(const std::string& title) {
        ::SetWindowTitle(title.c_str());
        return *this;
    }

    inline Window& SetPosition(int x, int y) {
        ::SetWindowPosition(x, y);
        return *this;
    }

    inline Window& SetMonitor(int monitor) {
        ::SetWindowMonitor(monitor);
        return *this;
    }

    inline Window& SetMinSize(int width, int height) {
        ::SetWindowMinSize(width, height);
        return *this;
    }

    inline Window& SetSize(int width, int height) {
        ::SetWindowSize(width, height);
        return *this;
    }

    inline void* GetHandle() const {
        return ::GetWindowHandle();
    }

    inline Window& BeginDrawing() {
        ::BeginDrawing();
        return *this;
    }

    inline Window& EndDrawing() {
        ::EndDrawing();
        return *this;
    }

    inline int GetScreenWidth() const {
        return ::GetScreenWidth();
    }

    inline int GetScreenHeight() const {
        return ::GetScreenHeight();
    }

    inline Vector2 GetPosition() const {
        return ::GetWindowPosition();
    }

    inline Vector2 GetScaleDPI() const {
        return ::GetWindowScaleDPI();
    }

    std::string GetMonitorName(int monitor) const {
        return std::string(::GetMonitorName(monitor));
    }

    std::string GetClipboardText() const {
        return std::string(::GetClipboardText());
    }

    inline Window& SetClipboardText(const std::string& text) {
        ::SetClipboardText(text.c_str());
        return *this;
    }

    inline Window& SetTargetFPS(int fps) {
        ::SetTargetFPS(fps);
        return *this;
    }

    inline int GetFPS() const {
        return ::GetFPS();
    }

    inline float GetFrameTime() const {
        return ::GetFrameTime();
    }

    inline double GetTime() const {
        return ::GetTime();
    }
};
}  // namespace raylib

#endif  // RAYLIB_CPP_INCLUDE_WINDOW_HPP_
