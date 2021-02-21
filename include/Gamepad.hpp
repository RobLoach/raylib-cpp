#ifndef RAYLIB_CPP_INCLUDE_GAMEPAD_HPP_
#define RAYLIB_CPP_INCLUDE_GAMEPAD_HPP_

#include <string>

#include "./raylib.hpp"
#include "./raylib-cpp-utils.hpp"

namespace raylib {
/**
 * Input-related functions: gamepads
 */
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

    /**
     * Detect if a gamepad is available
     */
    inline bool IsAvailable() const {
        return ::IsGamepadAvailable(number);
    }

    /**
     * Detect if a gamepad is available
     */
    static inline bool IsAvailable(int number) {
        return ::IsGamepadAvailable(number);
    }

    /**
     * Check gamepad name (if available)
     */
    inline bool IsName(const std::string& name) const {
        return ::IsGamepadName(number, name.c_str());
    }

    /**
     * Return gamepad internal name id
     */
    std::string GetName() const {
        return ::GetGamepadName(number);
    }

    /**
     * Return gamepad internal name id
     */
    operator std::string() const {
        return GetName();
    }

    /**
     * Detect if a gamepad button has been pressed once
     */
    inline bool IsButtonPressed(int button) const {
        return ::IsGamepadButtonPressed(number, button);
    }

    /**
     * Detect if a gamepad button is being pressed
     */
    inline bool IsButtonDown(int button) const {
        return ::IsGamepadButtonDown(number, button);
    }

    /**
     * Detect if a gamepad button has been released once
     */
    inline bool IsButtonReleased(int button) const {
        return ::IsGamepadButtonReleased(number, button);
    }

    /**
     * Detect if a gamepad button is NOT being pressed
     */
    inline bool IsButtonUp(int button) const {
        return ::IsGamepadButtonUp(number, button);
    }

    /**
     * Get the last gamepad button pressed
     */
    inline int GetButtonPressed() const {
        return ::GetGamepadButtonPressed();
    }

    /**
     * Return gamepad axis count for a gamepad
     */
    inline int GetAxisCount() const {
        return ::GetGamepadAxisCount(number);
    }

    /**
     * Return axis movement value for a gamepad axis
     */
    inline float GetAxisMovement(int axis) const {
        return ::GetGamepadAxisMovement(number, axis);
    }

 private:
    inline void set(int gamepadNumber) {
        number = gamepadNumber;
    }
};
}  // namespace raylib

#endif  // RAYLIB_CPP_INCLUDE_GAMEPAD_HPP_
