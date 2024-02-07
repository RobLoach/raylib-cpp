#ifndef RAYLIB_CPP_INCLUDE_KEYBOARD_HPP_
#define RAYLIB_CPP_INCLUDE_KEYBOARD_HPP_

#include "./raylib.hpp"

namespace raylib {
/**
 * Input-related functions: keyboard
 */
class Keyboard {
 public:
    /**
     * Detect if a key has been pressed once
     */
    static bool IsKeyPressed(int key) {
        return ::IsKeyPressed(key);
    }

    /**
     * Detect if a key has been pressed again (Only PLATFORM_DESKTOP)
     */
    static bool IsKeyPressedRepeat(int key) {
        return ::IsKeyPressedRepeat(key);
    }

    /**
     * Detect if a key is being pressed
     */
    static bool IsKeyDown(int key) {
        return ::IsKeyDown(key);
    }

    /**
     * Detect if a key has been released once
     */
    static bool IsKeyReleased(int key) {
        return ::IsKeyReleased(key);
    }

    /**
     * Detect if a key is NOT being pressed
     */
    static bool IsKeyUp(int key) {
        return ::IsKeyUp(key);
    }

    /**
     * Get key pressed (keycode), call it multiple times for keys queued, returns 0 when the queue is empty
     */
    static bool GetKeyPressed() {
        return ::GetKeyPressed();
    }

    /**
     * Get char pressed (unicode), call it multiple times for chars queued, returns 0 when the queue is empty
     */
    static bool GetCharPressed() {
        return ::GetCharPressed();
    }
};
} // namespace raylib

using RKeyboard = raylib::Keyboard;

#endif // RAYLIB_CPP_INCLUDE_KEYBOARD_HPP_
