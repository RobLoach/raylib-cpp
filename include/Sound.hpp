#ifndef RAYLIB_CPP_INCLUDE_SOUND_HPP_
#define RAYLIB_CPP_INCLUDE_SOUND_HPP_

#include <string>

#include "./raylib.hpp"
#include "./raylib-cpp-utils.hpp"
#include "./RaylibException.hpp"

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
    Sound(const Sound&) = delete;
    Sound& operator=(const Sound&) = delete;

    Sound() {
        frameCount = 0;
        stream.buffer = nullptr;
    }

    Sound(::AudioStream stream, unsigned int frameCount) : ::Sound{stream, frameCount} {
        // Nothing.
    }

    Sound(Sound&& other) {
        set(other);

        other.frameCount = 0;
        other.stream = { 0, 0, 0, 0 };
    }

    /**
     * Loads a sound from the given file.
     *
     * @throws raylib::RaylibException Throws if the Sound failed to load.
     */
    Sound(const std::string& fileName) {
        if (!Load(fileName)) {
            throw RaylibException(TextFormat("Failed to load Sound from file: %s", fileName.c_str()));
        }
    }

    /**
     * Loads a sound from the given Wave.
     *
     * @throws raylib::RaylibException Throws if the Sound failed to load.
     */
    Sound(const ::Wave& wave) {
        if (!Load(wave)) {
            throw RaylibException("Failed to load Sound from Wave");
        }
    }

    ~Sound() {
        Unload();
    }

    GETTERSETTER(unsigned int, FrameCount, frameCount)
    GETTERSETTER(::AudioStream, Stream, stream)

    Sound& operator=(Sound&& other) {
        if (this == &other) {
            return *this;
        }

        Unload();
        set(other);
        other.frameCount = 0;
        other.stream = { 0, 0, 0, 0 };

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
        ::UpdateSound(*this, data, static_cast<int>(frameCount));
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

    /**
     * Load a sound from the given file.
     *
     * @return True or false depending on loading worked.
     */
    bool Load(const std::string& fileName) {
        set(::LoadSound(fileName.c_str()));
        return IsReady();
    }

    /**
     * Loads the given Wave object into the Sound.
     */
    bool Load(const ::Wave& wave) {
        set(::LoadSoundFromWave(wave));
        return IsReady();
    }


    /**
     * Retrieve whether or not the Sound buffer is loaded.
     *
     * @return True or false depending on whether the Sound buffer is loaded.
     */
    bool IsReady() const {
        return stream.buffer != nullptr;
    }

 private:
    inline void set(const ::Sound& sound) {
        frameCount = sound.frameCount;
        stream = sound.stream;
    }
};
}  // namespace raylib

#endif  // RAYLIB_CPP_INCLUDE_SOUND_HPP_
