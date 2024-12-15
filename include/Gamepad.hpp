#ifndef RAYLIB_CPP_INCLUDE_GAMEPAD_HPP_
#define RAYLIB_CPP_INCLUDE_GAMEPAD_HPP_

#include <string>

#include "./raylib-cpp-utils.hpp"
#include "./raylib.hpp"

namespace raylib {
/**
 * Input-related functions: gamepads
 */
class Gamepad {
public:
    Gamepad(int gamepadNumber = 0) { set(gamepadNumber); }
    int number;

    GETTERSETTER(int, Number, number)

    Gamepad& operator=(const Gamepad& gamepad) {
        if (this != &gamepad) {
            set(static_cast<int>(gamepad));
        }
        return *this;
    }

    Gamepad& operator=(int gamepadNumber) {
        if (this->number != gamepadNumber) {
            set(gamepadNumber);
        }
        return *this;
    }

    explicit operator int() const { return number; }

    /**
     * Detect if a gamepad is available
     */
    [[nodiscard]] bool IsAvailable() const { return ::IsGamepadAvailable(number); }

    /**
     * Detect if a gamepad is available
     */
    static bool IsAvailable(int number) { return ::IsGamepadAvailable(number); }

    /**
     * Return gamepad internal name id
     */
    [[nodiscard]] std::string GetName() const { return ::GetGamepadName(number); }

    /**
     * Return gamepad internal name id
     */
    explicit operator std::string() const { return GetName(); }

    /**
     * Detect if a gamepad button has been pressed once
     */
    [[nodiscard]] bool IsButtonPressed(int button) const { return ::IsGamepadButtonPressed(number, button); }

    /**
     * Detect if a gamepad button is being pressed
     */
    [[nodiscard]] bool IsButtonDown(int button) const { return ::IsGamepadButtonDown(number, button); }

    /**
     * Detect if a gamepad button has been released once
     */
    [[nodiscard]] bool IsButtonReleased(int button) const { return ::IsGamepadButtonReleased(number, button); }

    /**
     * Detect if a gamepad button is NOT being pressed
     */
    [[nodiscard]] bool IsButtonUp(int button) const { return ::IsGamepadButtonUp(number, button); }

    /**
     * Get the last gamepad button pressed
     */
    static int GetButtonPressed() { return ::GetGamepadButtonPressed(); }

    /**
     * Return gamepad axis count for a gamepad
     */
    [[nodiscard]] int GetAxisCount() const { return ::GetGamepadAxisCount(number); }

    /**
     * Return axis movement value for a gamepad axis
     */
    [[nodiscard]] float GetAxisMovement(int axis) const { return ::GetGamepadAxisMovement(number, axis); }

    static int SetMappings(const std::string& mappings) { return SetGamepadMappings(mappings.c_str()); }

    /**
     * Set gamepad vibration for both motors (duration in seconds)
     */
    void SetVibration(float leftMotor, float rightMotor, float duration) const {
        ::SetGamepadVibration(number, leftMotor, rightMotor, duration);
    }
protected:
    void set(int gamepadNumber) { number = gamepadNumber; }
};
} // namespace raylib

using RGamepad = raylib::Gamepad;

#endif // RAYLIB_CPP_INCLUDE_GAMEPAD_HPP_
