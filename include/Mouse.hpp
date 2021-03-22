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
    /**
     * Detect if a mouse button has been pressed once
     */
    static inline bool IsButtonPressed(int button) {
        return ::IsMouseButtonPressed(button);
    }

    /**
     * Detect if a mouse button is being pressed
     */
    static inline bool IsButtonDown(int button) {
        return ::IsMouseButtonDown(button);
    }

    /**
     * Detect if a mouse button has been released once
     */
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
