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
    VrSimulator(::VrDeviceInfo& info) {
        Init(info);
    }

    /**
     * Init VR simulator for selected device parameters
     */
    inline void Init(::VrDeviceInfo info) {
        InitVrSimulator(info);
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
     * Begin VR simulator stereo rendering
     */
    inline VrSimulator& BeginDrawing(::RenderTexture2D& target) {
        ::BeginVrDrawing(target);
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

    /**
     * Get stereo rendering configuration parameters
     */
    inline VrStereoConfig GetConfig(VrDeviceInfo& device) {
        return GetVrConfig(device);
    }
};
}  // namespace raylib

#endif  // RAYLIB_CPP_INCLUDE_VRSIMULATOR_HPP_
