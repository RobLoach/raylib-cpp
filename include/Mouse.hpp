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

    static inline void SetPosition(::Vector2 position) {
        ::SetMousePosition(static_cast<int>(position.x), static_cast<int>(position.y));
    }

    static inline void SetOffset(int offsetX = 0, int offsetY = 0) {
        ::SetMouseOffset(offsetX, offsetY);
    }

    static inline void SetOffset(::Vector2 offset) {
        ::SetMouseOffset(static_cast<int>(offset.x), static_cast<int>(offset.y));
    }

    static inline void SetScale(float scaleX = 1.0f, float scaleY = 1.0f) {
        ::SetMouseScale(scaleX, scaleY);
    }

    static inline void SetScale(::Vector2 scale) {
        ::SetMouseScale(scale.x, scale.y);
    }

    static inline float GetWheelMove() {
        return ::GetMouseWheelMove();
    }

    /**
     * Sets the current mouse cursor icon.
     *
     * @see ::MouseCursor
     */
    static inline void SetCursor(int cursor = MOUSE_CURSOR_DEFAULT) {
        ::SetMouseCursor(cursor);
    }

    /**
     * Get touch position X for touch point 0 (relative to screen size)
     */
    static inline int GetTouchX() {
        return ::GetTouchX();
    }

    /**
     * Get touch position Y for touch point 0 (relative to screen size)
     */
    static inline int GetTouchY() {
        return ::GetTouchY();
    }

    /**
     * Get touch position XY for a touch point index (relative to screen size)
     */
    static inline Vector2 GetTouchPosition(int index) {
        return ::GetTouchPosition(index);
    }
};
}  // namespace raylib

#endif  // RAYLIB_CPP_INCLUDE_MOUSE_HPP_
