#ifndef RAYLIB_CPP_INCLUDE_MOUSE_HPP_
#define RAYLIB_CPP_INCLUDE_MOUSE_HPP_

#include "./Functions.hpp"
#include "./Vector2.hpp"
#include "./raylib.hpp"

namespace raylib {
/**
 * Input-related functions: mouse
 */
namespace Mouse {
/**
 * Detect if a mouse button has been pressed once
 */
RLCPP_MAYBEUNUSED RLCPPAPI inline bool IsButtonPressed(int button) {
    return ::IsMouseButtonPressed(button);
}

/**
 * Detect if a mouse button is being pressed
 */
RLCPP_MAYBEUNUSED RLCPPAPI inline bool IsButtonDown(int button) {
    return ::IsMouseButtonDown(button);
}

/**
 * Detect if a mouse button has been released once
 */
RLCPP_MAYBEUNUSED RLCPPAPI inline bool IsButtonReleased(int button) {
    return ::IsMouseButtonReleased(button);
}

RLCPP_MAYBEUNUSED RLCPPAPI inline bool IsButtonUp(int button) {
    return ::IsMouseButtonUp(button);
}

RLCPP_MAYBEUNUSED RLCPPAPI inline int GetX() {
    return ::GetMouseX();
}

RLCPP_MAYBEUNUSED RLCPPAPI inline int GetY() {
    return ::GetMouseY();
}

RLCPP_MAYBEUNUSED RLCPPAPI inline void SetX(int x) {
    ::SetMousePosition(x, GetY());
}

RLCPP_MAYBEUNUSED RLCPPAPI inline void SetY(int y) {
    ::SetMousePosition(GetX(), y);
}

RLCPP_MAYBEUNUSED RLCPPAPI inline Vector2 GetPosition() {
    return ::GetMousePosition();
}

RLCPP_MAYBEUNUSED RLCPPAPI inline void SetPosition(int x, int y) {
    ::SetMousePosition(x, y);
}

RLCPP_MAYBEUNUSED RLCPPAPI inline void SetPosition(::Vector2 position) {
    ::SetMousePosition(static_cast<int>(position.x), static_cast<int>(position.y));
}

/**
 * Get mouse delta between frames
 */
RLCPP_MAYBEUNUSED RLCPPAPI inline Vector2 GetDelta() {
    return ::GetMouseDelta();
}

RLCPP_MAYBEUNUSED RLCPPAPI inline void SetOffset(int offsetX = 0, int offsetY = 0) {
    ::SetMouseOffset(offsetX, offsetY);
}

RLCPP_MAYBEUNUSED RLCPPAPI inline void SetOffset(::Vector2 offset) {
    ::SetMouseOffset(static_cast<int>(offset.x), static_cast<int>(offset.y));
}

RLCPP_MAYBEUNUSED RLCPPAPI inline void SetScale(float scaleX = 1.0f, float scaleY = 1.0f) {
    ::SetMouseScale(scaleX, scaleY);
}

RLCPP_MAYBEUNUSED RLCPPAPI inline void SetScale(::Vector2 scale) {
    ::SetMouseScale(scale.x, scale.y);
}

/**
 * Get mouse wheel movement for X or Y, whichever is larger
 */
RLCPP_MAYBEUNUSED RLCPPAPI inline float GetWheelMove() {
    return ::GetMouseWheelMove();
}

/**
 * Get mouse wheel movement for both X and Y
 *
 * @see ::GetMouseWheelMoveV()
 */
RLCPP_MAYBEUNUSED RLCPPAPI inline Vector2 GetWheelMoveV() {
    return GetMouseWheelMoveV();
}

/**
 * Sets the current mouse cursor icon.
 *
 * @see ::MouseCursor
 */
RLCPP_MAYBEUNUSED RLCPPAPI inline void SetCursor(int cursor = MOUSE_CURSOR_DEFAULT) {
    ::SetMouseCursor(cursor);
}

/**
 * Get touch position X for touch point 0 (relative to screen size)
 */
RLCPP_MAYBEUNUSED RLCPPAPI inline int GetTouchX() {
    return ::GetTouchX();
}

/**
 * Get touch position Y for touch point 0 (relative to screen size)
 */
RLCPP_MAYBEUNUSED RLCPPAPI inline int GetTouchY() {
    return ::GetTouchY();
}

/**
 * Get touch position XY for a touch point index (relative to screen size)
 */
RLCPP_MAYBEUNUSED RLCPPAPI inline Vector2 GetTouchPosition(int index) {
    return ::GetTouchPosition(index);
}

/**
 * Get a ray trace from mouse position
 */
RLCPP_MAYBEUNUSED RLCPPAPI inline Ray GetRay(::Vector2 mousePosition, const ::Camera& camera) {
    return ::GetMouseRay(mousePosition, camera);
}

/**
 * Get a ray trace from mouse position
 */
RLCPP_MAYBEUNUSED RLCPPAPI inline Ray GetRay(const ::Camera& camera) {
    return ::GetMouseRay(::GetMousePosition(), camera);
}
} // namespace Mouse
} // namespace raylib

namespace RMouse = raylib::Mouse;

#endif // RAYLIB_CPP_INCLUDE_MOUSE_HPP_
