#ifndef RAYLIB_CPP_INCLUDE_CAMERA2D_HPP_
#define RAYLIB_CPP_INCLUDE_CAMERA2D_HPP_

#include "./raylib.hpp"
#include "./Vector2.hpp"
#include "./raylib-cpp-utils.hpp"

namespace raylib {
/**
 * Camera2D type, defines a 2d camera
 */
class Camera2D : public ::Camera2D {
 public:
    Camera2D() {}
    Camera2D(const ::Camera2D& camera) {
        set(camera);
    }

    Camera2D(::Vector2 offsetValue, ::Vector2 targetValue, float rotationValue = 0,
            float zoomValue = 1) {
        offset = offsetValue;
        target = targetValue;
        rotation = rotationValue;
        zoom = zoomValue;
    }

    inline Camera2D& BeginMode() {
        ::BeginMode2D(*this);
        return *this;
    }

    inline Camera2D& EndMode() {
        ::EndMode2D();
        return *this;
    }

    GETTERSETTER(::Vector2, Offset, offset)
    GETTERSETTER(::Vector2, Target, target)
    GETTERSETTER(float, Rotation, rotation)
    GETTERSETTER(float, Zoom, zoom)

    Camera2D& operator=(const ::Camera2D& camera) {
        set(camera);
        return *this;
    }

    /**
     * Returns camera 2d transform matrix
     */
    inline Matrix GetMatrix() const {
        return ::GetCameraMatrix2D(*this);
    }

    /**
     * Returns the screen space position for a 3d world space position
     */
    inline Vector2 GetWorldToScreen(::Vector2 position) const {
        return ::GetWorldToScreen2D(position, *this);
    }

    /**
     * Returns the world space position for a 2d camera screen space position
     */
    inline Vector2 GetScreenToWorld(::Vector2 position) const {
        return ::GetScreenToWorld2D(position, *this);
    }

 private:
    inline void set(const ::Camera2D& camera) {
        offset = camera.offset;
        target = camera.target;
        rotation = camera.rotation;
        zoom = camera.zoom;
    }
};
}  // namespace raylib

#endif  // RAYLIB_CPP_INCLUDE_CAMERA2D_HPP_
