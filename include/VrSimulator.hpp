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

#ifndef RAYLIB_CPP_INCLUDE_VRSIMULATOR_HPP_
#define RAYLIB_CPP_INCLUDE_VRSIMULATOR_HPP_

#include "./raylib.hpp"
#include "./raylib-cpp-utils.hpp"

namespace raylib {
class VrSimulator {
 public:
    VrSimulator() {
        Init();
    }

    VrSimulator(::VrDeviceInfo info, ::Shader distortion) {
        Init();
        Set(info, distortion);
    }

    /**
     * Init VR simulator for selected device parameters
     */
    inline void Init() {
        InitVrSimulator();
    }

    /**
     * Close VR simulator for current device
     */
    ~VrSimulator() {
        Close();
    }

    /**
     * Detect if VR simulator is ready
     */
    inline bool IsReady() const {
        return ::IsVrSimulatorReady();
    }

    /**
     * Update VR tracking (position and orientation) and camera
     */
    inline VrSimulator& Update(::Camera *camera) {
        ::UpdateVrTracking(camera);
        return *this;
    }

    /**
     * Update VR tracking (position and orientation) and camera
     */
    inline VrSimulator& Update(const ::Camera& camera) {
        const ::Camera* cameraPointer = reinterpret_cast<const Camera*>(&camera);
        ::UpdateVrTracking((::Camera*)cameraPointer);
        return *this;
    }

    /**
     * Set stereo rendering configuration parameters
     */
    inline VrSimulator& Set(::VrDeviceInfo info, ::Shader distortion) {
        ::SetVrConfiguration(info, distortion);
        return *this;
    }

    /**
     * Enable/Disable VR experience
     */
    inline VrSimulator& Toggle() {
        ::ToggleVrMode();
        return *this;
    }

    /**
     * Begin VR simulator stereo rendering
     */
    inline VrSimulator& BeginDrawing() {
        ::BeginVrDrawing();
        return *this;
    }

    /**
     * End VR simulator stereo rendering
     */
    inline VrSimulator& EndDrawing() {
        ::EndVrDrawing();
        return *this;
    }

    /**
     * Close VR simulator for current device
     */
    inline void Close() {
        ::CloseVrSimulator();
    }
};
}  // namespace raylib

#endif  // RAYLIB_CPP_INCLUDE_VRSIMULATOR_HPP_
