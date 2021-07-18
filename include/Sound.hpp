#ifndef RAYLIB_CPP_INCLUDE_SOUND_HPP_
#define RAYLIB_CPP_INCLUDE_SOUND_HPP_

#include <string>

#include "./raylib.hpp"
#include "./raylib-cpp-utils.hpp"

namespace raylib {
/**
 * Wave/Sound management functions
 *
 * @code
 * raylib::Sound boom("boom.wav");
 * boom.Play();
 * @endcode
 */
class Sound : public ::Sound {
 public:
    Sound(const ::Sound& vec) {
        set(vec);
    }

    Sound(const std::string& fileName) {
        set(LoadSound(fileName.c_str()));
    }

    Sound(const ::Wave& wave) {
        set(LoadSoundFromWave(wave));
    }

    ~Sound() {
        Unload();
    }

    GETTERSETTER(unsigned int, SampleCount, sampleCount)
    GETTERSETTER(::AudioStream, Stream, stream)

    Sound& operator=(const ::Sound& sound) {
        set(sound);
        return *this;
    }

    /**
     * Update sound buffer with new data
     */
    inline Sound& Update(const void *data, int samplesCount) {
        ::UpdateSound(*this, data, samplesCount);
        return *this;
    }

    /**
     * Update sound buffer with new data, assuming it's the same sample count.
     */
    inline Sound& Update(const void *data) {
        ::UpdateSound(*this, data, static_cast<int>(sampleCount));
        return *this;
    }

    /**
     * Unload sound
     */
    inline void Unload() {
        ::UnloadSound(*this);
    }

    /**
     * Play a sound
     */
    inline Sound& Play() {
        ::PlaySound(*this);
        return *this;
    }

    /**
     * Stop playing a sound
     */
    inline Sound& Stop() {
        ::StopSound(*this);
        return *this;
    }

    /**
     * Pause a sound
     */
    inline Sound& Pause() {
        ::PauseSound(*this);
        return *this;
    }

    /**
     * Resume a paused sound
     */
    inline Sound& Resume() {
        ::ResumeSound(*this);
        return *this;
    }

    /**
     * Play a sound (using multichannel buffer pool)
     */
    inline Sound& PlayMulti() {
        ::PlaySoundMulti(*this);
        return *this;
    }

    /**
     * Stop any sound playing (using multichannel buffer pool)
     */
    inline Sound& StopMulti() {
        ::StopSoundMulti();
        return *this;
    }

    /**
     * Check if a sound is currently playing
     */
    inline bool IsPlaying() const {
        return ::IsSoundPlaying(*this);
    }

    /**
     * Set volume for a sound (1.0 is max level)
     */
    inline Sound& SetVolume(float volume) {
        ::SetSoundVolume(*this, volume);
        return *this;
    }

    /**
     * Set pitch for a sound (1.0 is base level)
     */
    inline Sound& SetPitch(float pitch) {
        ::SetSoundPitch(*this, pitch);
        return *this;
    }

 private:
    inline void set(const ::Sound& sound) {
        sampleCount = sound.sampleCount;
        stream = sound.stream;
    }
};
}  // namespace raylib

#endif  // RAYLIB_CPP_INCLUDE_SOUND_HPP_
