#ifndef RAYLIB_CPP_INCLUDE_VRSIMULATOR_HPP_
#define RAYLIB_CPP_INCLUDE_VRSIMULATOR_HPP_

#include "./raylib.hpp"
#include "./raylib-cpp-utils.hpp"

namespace raylib {
/**
 * VR control functions
 */
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
