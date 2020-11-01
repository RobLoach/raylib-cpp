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
class Mouse {
 public:
    inline bool IsButtonPressed(int button) const {
        return ::IsMouseButtonPressed(button);
    }

    inline bool IsButtonDown(int button) const {
        return ::IsMouseButtonDown(button);
    }

    inline bool IsButtonReleased(int button) const {
        return ::IsMouseButtonReleased(button);
    }

    inline bool IsButtonUp(int button) const {
        return ::IsMouseButtonUp(button);
    }

    inline int GetX() const {
        return ::GetMouseX();
    }

    inline int GetY() const {
        return ::GetMouseY();
    }

    inline Mouse& SetX(int x) {
        ::SetMouseOffset(x, GetY());
        return *this;
    }

    inline Mouse& SetY(int y) {
        ::SetMouseOffset(GetX(), y);
        return *this;
    }

    inline Vector2 GetPosition() const {
        return ::GetMousePosition();
    }

    inline Mouse& SetPosition(int x, int y) {
        ::SetMousePosition(x, y);
        return *this;
    }

    inline Mouse& SetOffset(int offsetX, int offsetY) {
        ::SetMouseOffset(offsetX, offsetY);
        return *this;
    }

    inline Mouse& SetScale(float scaleX, float scaleY) {
        ::SetMouseScale(scaleX, scaleY);
        return *this;
    }

    inline float GetWheelMove() const {
        return ::GetMouseWheelMove();
    }

    inline int GetCursor() const {
        return ::GetMouseCursor();
    }

    inline Mouse& SetCursor(int cursor) {
        ::SetMouseCursor(cursor);
        return *this;
    }

    inline int GetTouchX() const {
        return ::GetTouchX();
    }

    inline int GetTouchY() const {
        return ::GetTouchY();
    }

    inline Vector2 GetTouchPosition(int index) const {
        return ::GetTouchPosition(index);
    }
};
}  // namespace raylib

#endif  // RAYLIB_CPP_INCLUDE_MOUSE_HPP_
