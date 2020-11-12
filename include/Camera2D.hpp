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

#ifndef RAYLIB_CPP_INCLUDE_CAMERA2D_HPP_
#define RAYLIB_CPP_INCLUDE_CAMERA2D_HPP_

#include "./raylib.hpp"
#include "./Vector2.hpp"
#include "./raylib-cpp-utils.hpp"

namespace raylib {
class Camera2D : public ::Camera2D {
 public:
    Camera2D(::Vector2 offsetValue, ::Vector2 targetValue, float rotationValue = 0,
            float zoomValue = 1) {
        offset = offsetValue;
        target = targetValue;
        rotation = rotationValue;
        zoom = zoomValue;
    }

    inline Camera2D& BeginMode2D() {
        ::BeginMode2D(*this);
        return *this;
    }

    inline Camera2D& EndMode2D() {
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

    Camera2D& operator=(const Camera2D& camera) {
        set(camera);
        return *this;
    }

    inline Matrix GetMatrix() const {
        return ::GetCameraMatrix2D(*this);
    }

    inline Vector2 GetWorldToScreen2D(Vector2 position) const {
        return ::GetWorldToScreen2D(position, *this);
    }

    inline Vector2 GetScreenToWorld2D(Vector2 position) const {
        return ::GetScreenToWorld2D(position, *this);
    }

 protected:
    inline void set(const ::Camera2D& camera) {
        offset = camera.offset;
        target = camera.target;
        rotation = camera.rotation;
        zoom = camera.zoom;
    }

    inline void set(const Camera2D& camera) {
        offset = camera.offset;
        target = camera.target;
        rotation = camera.rotation;
        zoom = camera.zoom;
    }
};
}  // namespace raylib

#endif  // RAYLIB_CPP_INCLUDE_CAMERA2D_HPP_
