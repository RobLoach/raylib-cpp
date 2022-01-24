#ifndef RAYLIB_CPP_INCLUDE_AUDIODEVICE_HPP_
#define RAYLIB_CPP_INCLUDE_AUDIODEVICE_HPP_

#include "./raylib.hpp"
#include "./raylib-cpp-utils.hpp"
#include "./RaylibException.hpp"

namespace raylib {
/**
 * Audio device management functions.
 */
class AudioDevice {
 public:
    /**
     * Initialize audio device and context.
     *
     * @param lateInit Whether or not to post-pone initializing the context.
     *
     * @throws raylib::RaylibException Throws if the AudioDevice failed to initialize.
     */
    AudioDevice(bool lateInit = false) {
        if (!lateInit) {
            if (!Init()) {
                throw RaylibException("Failed to initialize AudioDevice");
            }
        }
    }

    /**
     * Close the audio device and context.
     */
    ~AudioDevice() {
        Close();
    }

    /**
     * Initialize audio device and context.
     */
    inline bool Init() {
        ::InitAudioDevice();
        return IsReady();
    }

    /**
     * Close the audio device and context.
     */
    inline void Close() {
        ::CloseAudioDevice();
    }

    /**
     * Check if audio device has been initialized successfully.
     */
    inline bool IsReady() const {
        return ::IsAudioDeviceReady();
    }

    /**
     * Set master volume (listener).
     *
     * @param volume The desired volume to set.
     */
    inline AudioDevice& SetVolume(float volume) {
        ::SetMasterVolume(volume);
        return *this;
    }
};
}  // namespace raylib

#endif  // RAYLIB_CPP_INCLUDE_AUDIODEVICE_HPP_
