#ifndef RAYLIB_CPP_INCLUDE_SOUND_HPP_
#define RAYLIB_CPP_INCLUDE_SOUND_HPP_

#include <string>

#include "./RaylibException.hpp"
#include "./raylib-cpp-utils.hpp"
#include "./raylib.hpp"

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
        stream = {nullptr, nullptr, 0, 0, 0};
        frameCount = 0;
    }

    Sound(::AudioStream stream, unsigned int frameCount) : ::Sound{stream, frameCount} {
        // Nothing.
    }

    Sound(Sound&& other) {
        set(other);

        other.stream = {nullptr, nullptr, 0, 0, 0};
        other.frameCount = 0;
    }

    /**
     * Loads a sound from the given file.
     *
     * @throws raylib::RaylibException Throws if the Sound failed to load.
     */
    Sound(const std::string& fileName) { Load(fileName); }

    /**
     * Loads a sound from the given Wave.
     *
     * @throws raylib::RaylibException Throws if the Sound failed to load.
     */
    Sound(const ::Wave& wave) { Load(wave); }

    ~Sound() { Unload(); }

    GETTER(unsigned int, FrameCount, frameCount)
    GETTER(::AudioStream, Stream, stream)

    Sound& operator=(Sound&& other) noexcept {
        if (this == &other) {
            return *this;
        }

        Unload();
        set(other);
        other.frameCount = 0;
        other.stream = {nullptr, nullptr, 0, 0, 0};

        return *this;
    }

    /**
     * Update sound buffer with new data
     */
    Sound& Update(const void* data, int samplesCount) {
        ::UpdateSound(*this, data, samplesCount);
        return *this;
    }

    /**
     * Update sound buffer with new data, assuming it's the same sample count.
     */
    Sound& Update(const void* data) {
        ::UpdateSound(*this, data, static_cast<int>(frameCount));
        return *this;
    }

    /**
     * Unload sound
     */
    void Unload() {
        // Protect against calling UnloadSound() twice.
        if (frameCount != 0) {
            ::UnloadSound(*this);
            frameCount = 0;
        }
    }

    /**
     * Play a sound
     */
    Sound& Play() {
        ::PlaySound(*this);
        return *this;
    }

    /**
     * Stop playing a sound
     */
    Sound& Stop() {
        ::StopSound(*this);
        return *this;
    }

    /**
     * Pause a sound
     */
    Sound& Pause() {
        ::PauseSound(*this);
        return *this;
    }

    /**
     * Resume a paused sound
     */
    Sound& Resume() {
        ::ResumeSound(*this);
        return *this;
    }

    /**
     * Check if a sound is currently playing
     */
    bool IsPlaying() const { return ::IsSoundPlaying(*this); }

    /**
     * Set volume for a sound (1.0 is max level)
     */
    Sound& SetVolume(float volume) {
        ::SetSoundVolume(*this, volume);
        return *this;
    }

    /**
     * Set pitch for a sound (1.0 is base level)
     */
    Sound& SetPitch(float pitch) {
        ::SetSoundPitch(*this, pitch);
        return *this;
    }

    /**
     * Set pan for a sound (0.5 is center)
     */
    Sound& SetPan(float pan = 0.5f) {
        ::SetSoundPan(*this, pan);
        return *this;
    }

    /**
     * Load a sound from the given file.
     *
     * @throws raylib::RaylibException Throws if the Sound failed to load.
     */
    void Load(const std::string& fileName) {
        set(::LoadSound(fileName.c_str()));
        if (!IsValid()) {
            throw RaylibException("Failed to load Sound from file");
        }
    }

    /**
     * Loads the given Wave object into the Sound.
     *
     * @throws raylib::RaylibException Throws if the Sound failed to load.
     */
    void Load(const ::Wave& wave) {
        set(::LoadSoundFromWave(wave));
        if (!IsValid()) {
            throw RaylibException("Failed to load Wave");
        }
    }

    /**
     * Retrieve whether or not the Sound buffer is loaded.
     *
     * @return True or false depending on whether the Sound buffer is loaded.
     */
    bool IsValid() const { return ::IsSoundValid(*this); }
protected:
    void set(const ::Sound& sound) {
        frameCount = sound.frameCount;
        stream = sound.stream;
    }
};
} // namespace raylib

using RSound = raylib::Sound;

#endif // RAYLIB_CPP_INCLUDE_SOUND_HPP_
