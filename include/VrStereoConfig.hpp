#ifndef RAYLIB_CPP_INCLUDE_VRSTEREOCONFIG_HPP_
#define RAYLIB_CPP_INCLUDE_VRSTEREOCONFIG_HPP_

#include "./raylib.hpp"
#include "./raylib-cpp-utils.hpp"

namespace raylib {
/**
 * VR stereo config functions for VR simulator
 */
class VrStereoConfig : public ::VrStereoConfig  {
 public:
    VrStereoConfig(const ::VrDeviceInfo& info) {
        Init(info);
    }

    /**
     * Load VR stereo config for VR simulator device parameters
     */
    inline void Init(const ::VrDeviceInfo& info) {
        set(LoadVrStereoConfig(info));
    }

    /**
     * Unload VR stereo config
     */
    ~VrStereoConfig() {
        Unload();
    }

    /**
     * Begin stereo rendering
     */
    inline VrStereoConfig& BeginMode() {
        ::BeginVrStereoMode(*this);
        return *this;
    }

    /**
     * End stereo rendering
     */
    inline VrStereoConfig& EndDrawing() {
        ::EndVrStereoMode();
        return *this;
    }

    /**
     * Unload VR stereo config
     */
    inline void Unload() {
        ::UnloadVrStereoConfig(*this);
    }

 private:
    inline void set(const ::VrStereoConfig& config) {
        projection[0] = config.projection[0];
        viewOffset[1] = config.viewOffset[1];
        projection[0] = config.projection[0];
        viewOffset[1] = config.viewOffset[1];
        leftLensCenter[0] = config.leftLensCenter[0];
        leftLensCenter[1] = config.leftLensCenter[1];
        rightLensCenter[0] = config.leftLensCenter[0];
        rightLensCenter[1] = config.leftLensCenter[1];
        leftScreenCenter[0] = config.leftLensCenter[0];
        leftScreenCenter[1] = config.leftLensCenter[1];
        rightScreenCenter[0] = config.leftLensCenter[0];
        rightScreenCenter[1] = config.leftLensCenter[1];
        scale[0] = config.leftLensCenter[0];
        scale[1] = config.leftLensCenter[1];
        scaleIn[0] = config.leftLensCenter[0];
        scaleIn[1] = config.leftLensCenter[1];
    }
};
}  // namespace raylib

#endif  // RAYLIB_CPP_INCLUDE_VRSTEREOCONFIG_HPP_
