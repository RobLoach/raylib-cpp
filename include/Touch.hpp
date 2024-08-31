#ifndef RAYLIB_CPP_INCLUDE_TOUCH_HPP_
#define RAYLIB_CPP_INCLUDE_TOUCH_HPP_

#include "./raylib.hpp"

namespace raylib {
/**
 * Input-related functions: touch
 */
namespace Touch {
/**
 * Get touch position X for touch point 0 (relative to screen size)
 */
[[maybe_unused]] RLCPPAPI inline int GetX() {
    return ::GetTouchX();
}

/**
 * Get touch position Y for touch point 0 (relative to screen size)
 */
[[maybe_unused]] RLCPPAPI inline int GetY() {
    return ::GetTouchY();
}

/**
 * Get touch position XY for a touch point index (relative to screen size)
 */
[[maybe_unused]] RLCPPAPI inline Vector2 GetPosition(int index) {
    return ::GetTouchPosition(index);
}

/**
 * Get touch point identifier for given index
 */
[[maybe_unused]] RLCPPAPI inline int GetPointId(int index) {
    return ::GetTouchPointId(index);
}

/**
 * Get number of touch points
 */
[[maybe_unused]] RLCPPAPI inline int GetPointCount() {
    return ::GetTouchPointCount();
}
} // namespace Touch
} // namespace raylib

namespace RTouch = raylib::Touch;

#endif // RAYLIB_CPP_INCLUDE_TOUCH_HPP_
