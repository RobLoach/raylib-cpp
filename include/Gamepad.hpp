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

#ifndef RAYLIB_CPP_INCLUDE_GAMEPAD_HPP_
#define RAYLIB_CPP_INCLUDE_GAMEPAD_HPP_

#include <string>

#include "./raylib.hpp"
#include "./raylib-cpp-utils.hpp"

namespace raylib {
class Gamepad {
 public:
    Gamepad(int gamepadNumber = 0) {
        set(gamepadNumber);
    }
    int number;

    GETTERSETTER(int, Number, number)

    Gamepad& operator=(const Gamepad& gamepad) {
        set(gamepad);
        return *this;
    }

    Gamepad& operator=(int gamepadNumber) {
        set(gamepadNumber);
        return *this;
    }

    operator int() const { return number; }

    inline bool IsAvailable() const {
        return ::IsGamepadAvailable(number);
    }
    inline bool IsName(const std::string& name) const {
        return ::IsGamepadName(number, name.c_str());
    }
    std::string GetName() const {
        return std::string(::GetGamepadName(number));
    }
    inline bool IsButtonPressed(int button) const {
        return ::IsGamepadButtonPressed(number, button);
    }

    inline bool IsButtonDown(int button) const {
        return ::IsGamepadButtonDown(number, button);
    }

    inline bool IsButtonReleased(int button) const {
        return ::IsGamepadButtonReleased(number, button);
    }

    inline bool IsButtonUp(int button) const {
        return ::IsGamepadButtonUp(number, button);
    }

    inline int GetButtonPressed() const {
        return ::GetGamepadButtonPressed();
    }

    inline int GetAxisCount() const {
        return ::GetGamepadAxisCount(number);
    }

    inline float GetAxisMovement(int axis) const {
        return ::GetGamepadAxisMovement(number, axis);
    }

 protected:
    inline void set(int gamepadNumber) {
        number = gamepadNumber;
    }
};
}  // namespace raylib

#endif  // RAYLIB_CPP_INCLUDE_GAMEPAD_HPP_
