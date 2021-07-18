#ifndef RAYLIB_CPP_INCLUDE_AUDIODEVICE_HPP_
#define RAYLIB_CPP_INCLUDE_AUDIODEVICE_HPP_

#include "./raylib.hpp"
#include "./raylib-cpp-utils.hpp"

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
     */
    AudioDevice(bool lateInit = false) {
        if (!lateInit) {
            Init();
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
    inline AudioDevice& Init() {
        ::InitAudioDevice();
        return *this;
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
     */
    inline AudioDevice& SetVolume(float volume) {
        ::SetMasterVolume(volume);
        return *this;
    }
};
}  // namespace raylib

#endif  // RAYLIB_CPP_INCLUDE_AUDIODEVICE_HPP_
