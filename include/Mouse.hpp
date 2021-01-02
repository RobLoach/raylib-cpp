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

#ifndef RAYLIB_CPP_INCLUDE_MOUSE_HPP_
#define RAYLIB_CPP_INCLUDE_MOUSE_HPP_

#include "./raylib.hpp"

#include "./Vector2.hpp"

namespace raylib {
/**
 * Input-related functions: mouse
 */
class Mouse {
 public:
    static inline bool IsButtonPressed(int button) {
        return ::IsMouseButtonPressed(button);
    }

    static inline bool IsButtonDown(int button) {
        return ::IsMouseButtonDown(button);
    }

    static inline bool IsButtonReleased(int button) {
        return ::IsMouseButtonReleased(button);
    }

    static inline bool IsButtonUp(int button) {
        return ::IsMouseButtonUp(button);
    }

    static inline int GetX() {
        return ::GetMouseX();
    }

    static inline int GetY() {
        return ::GetMouseY();
    }

    static inline void SetX(int x) {
        ::SetMousePosition(x, GetY());
    }

    static inline void SetY(int y) {
        ::SetMousePosition(GetX(), y);
    }

    static inline Vector2 GetPosition() {
        return ::GetMousePosition();
    }

    static inline void SetPosition(int x, int y) {
        ::SetMousePosition(x, y);
    }

    static inline void SetOffset(int offsetX, int offsetY) {
        ::SetMouseOffset(offsetX, offsetY);
    }

    static inline void SetScale(float scaleX, float scaleY) {
        ::SetMouseScale(scaleX, scaleY);
    }

    static inline float GetWheelMove() {
        return ::GetMouseWheelMove();
    }

    static inline int GetCursor() {
        return ::GetMouseCursor();
    }

    static inline void SetCursor(int cursor) {
        ::SetMouseCursor(cursor);
    }

    static inline int GetTouchX() {
        return ::GetTouchX();
    }

    static inline int GetTouchY() {
        return ::GetTouchY();
    }

    static inline Vector2 GetTouchPosition(int index) {
        return ::GetTouchPosition(index);
    }
};
}  // namespace raylib

#endif  // RAYLIB_CPP_INCLUDE_MOUSE_HPP_
