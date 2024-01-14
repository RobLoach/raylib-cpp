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
    static bool IsButtonPressed(int button) {
        return ::IsMouseButtonPressed(button);
    }

    /**
     * Detect if a mouse button is being pressed
     */
    static bool IsButtonDown(int button) {
        return ::IsMouseButtonDown(button);
    }

    /**
     * Detect if a mouse button has been released once
     */
    static bool IsButtonReleased(int button) {
        return ::IsMouseButtonReleased(button);
    }

    static bool IsButtonUp(int button) {
        return ::IsMouseButtonUp(button);
    }

    static int GetX() {
        return ::GetMouseX();
    }

    static int GetY() {
        return ::GetMouseY();
    }

    static void SetX(int x) {
        ::SetMousePosition(x, GetY());
    }

    static void SetY(int y) {
        ::SetMousePosition(GetX(), y);
    }

    static Vector2 GetPosition() {
        return ::GetMousePosition();
    }

    static void SetPosition(int x, int y) {
        ::SetMousePosition(x, y);
    }

    static void SetPosition(::Vector2 position) {
        ::SetMousePosition(static_cast<int>(position.x), static_cast<int>(position.y));
    }

    /**
     * Get mouse delta between frames
     */
    static Vector2 GetDelta() {
        return ::GetMouseDelta();
    }

    static void SetOffset(int offsetX = 0, int offsetY = 0) {
        ::SetMouseOffset(offsetX, offsetY);
    }

    static void SetOffset(::Vector2 offset) {
        ::SetMouseOffset(static_cast<int>(offset.x), static_cast<int>(offset.y));
    }

    static void SetScale(float scaleX = 1.0f, float scaleY = 1.0f) {
        ::SetMouseScale(scaleX, scaleY);
    }

    static void SetScale(::Vector2 scale) {
        ::SetMouseScale(scale.x, scale.y);
    }

    /**
     * Get mouse wheel movement for X or Y, whichever is larger
     */
    static float GetWheelMove() {
        return ::GetMouseWheelMove();
    }

    /**
     * Get mouse wheel movement for both X and Y
     *
     * @see ::GetMouseWheelMoveV()
     */
    static Vector2 GetWheelMoveV() {
        return GetMouseWheelMoveV();
    }

    /**
     * Sets the current mouse cursor icon.
     *
     * @see ::MouseCursor
     */
    static void SetCursor(int cursor = MOUSE_CURSOR_DEFAULT) {
        ::SetMouseCursor(cursor);
    }

    /**
     * Get touch position X for touch point 0 (relative to screen size)
     */
    static int GetTouchX() {
        return ::GetTouchX();
    }

    /**
     * Get touch position Y for touch point 0 (relative to screen size)
     */
    static int GetTouchY() {
        return ::GetTouchY();
    }

    /**
     * Get touch position XY for a touch point index (relative to screen size)
     */
    static Vector2 GetTouchPosition(int index) {
        return ::GetTouchPosition(index);
    }

    /**
     * Get a ray trace from mouse position
     */
    static Ray GetRay(::Vector2 mousePosition, const ::Camera& camera) {
        return ::GetMouseRay(mousePosition, camera);
    }

    /**
     * Get a ray trace from mouse position
     */
    static Ray GetRay(const ::Camera& camera) {
        return ::GetMouseRay(::GetMousePosition(), camera);
    }
};
}  // namespace raylib

using RMouse = raylib::Mouse;

#endif  // RAYLIB_CPP_INCLUDE_MOUSE_HPP_
