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

#ifndef RAYLIB_CPP_INCLUDE_CAMERA3D_HPP_
#define RAYLIB_CPP_INCLUDE_CAMERA3D_HPP_

#include "./raylib.hpp"
#include "./Vector3.hpp"
#include "./raylib-cpp-utils.hpp"

namespace raylib {
class Camera3D : public ::Camera3D {
 public:
    Camera3D(const ::Camera3D& camera) {
        set(camera);
    }

    Camera3D(::Vector3 positionValue, ::Vector3 targetValue, ::Vector3 upValue,
            float fovyValue = 0, int typeValue = 0) {
        position = positionValue;
        target = targetValue;
        up = upValue;
        fovy = fovyValue;
        type = typeValue;
    }

    Camera3D() {}

    GETTERSETTER(::Vector3, Position, position)
    GETTERSETTER(::Vector3, Target, target)
    GETTERSETTER(::Vector3, Up, up)
    GETTERSETTER(float, Fovy, fovy)
    GETTERSETTER(int, Type, type)

    Camera3D& operator=(const ::Camera3D& camera) {
        set(camera);
        return *this;
    }

    Camera3D& operator=(const Camera3D& camera) {
        set(camera);
        return *this;
    }

    /**
     * Initializes 3D mode with custom camera (3D)
     */
    Camera3D& BeginMode() {
        ::BeginMode3D(*this);
        return *this;
    }

    /**
     * Ends 3D mode and returns to default 2D orthographic mode
     */
    Camera3D& EndMode() {
        ::EndMode3D();
        return *this;
    }

    /**
     * Get transform matrix for camera
     */
    inline Matrix GetMatrix() const {
        return ::GetCameraMatrix(*this);
    }

    /**
     * Set camera mode (multiple camera modes available)
     */
    inline Camera3D& SetMode(int mode) {
        ::SetCameraMode(*this, mode);
        return *this;
    }

    /**
     * Set camera alt key to combine with mouse movement (free camera)
     */
    inline Camera3D& SetAltControl(int altKey) {
        ::SetCameraAltControl(altKey);
        return *this;
    }

    /**
     * Set camera smooth zoom key to combine with mouse (free camera)
     */
    inline Camera3D& SetSmoothZoomControl(int szKey) {
        ::SetCameraSmoothZoomControl(szKey);
        return *this;
    }

    /**
     * Set camera move controls (1st person and 3rd person cameras)
     */
    inline Camera3D& SetMoveControls(
            int frontKey, int backKey,
            int rightKey, int leftKey,
            int upKey, int downKey) {
        ::SetCameraMoveControls(frontKey, backKey, rightKey, leftKey, upKey, downKey);
        return *this;
    }

    /**
     * Update camera position for selected mode
     */
    inline Camera3D& Update() {
        ::UpdateCamera(this);
        return *this;
    }

    /**
     * Update VR tracking (position and orientation) and camera
     */
    inline Camera3D& UpdateVrTracking() {
        ::UpdateVrTracking(this);
        return *this;
    }

    /**
     * Returns a ray trace from mouse position
     */
    inline Ray GetMouseRay(::Vector2 mousePosition) const {
        return ::GetMouseRay(mousePosition, *this);
    }

    /**
     * Returns the screen space position for a 3d world space position
     */
    inline Vector2 GetWorldToScreen(::Vector3 position) const {
        return ::GetWorldToScreen(position, *this);
    }

    inline Camera3D& DrawBillboard(
            const ::Texture2D& texture,
            ::Vector3 center,
            float size,
            ::Color tint = {255, 255, 255, 255}) {
        ::DrawBillboard(*this, texture, center, size, tint);
        return *this;
    }

    inline Camera3D& DrawBillboard(
            const ::Texture2D& texture,
            ::Rectangle sourceRec,
            ::Vector3 center,
            float size,
            ::Color tint = {255, 255, 255, 255}) {
        ::DrawBillboardRec(*this, texture, sourceRec, center, size, tint);
        return *this;
    }

 protected:
    inline void set(const ::Camera3D& camera) {
        position = camera.position;
        target = camera.target;
        up = camera.up;
        fovy = camera.fovy;
        type = camera.type;
    }
};

typedef Camera3D Camera;
}  // namespace raylib

#endif  // RAYLIB_CPP_INCLUDE_CAMERA3D_HPP_
