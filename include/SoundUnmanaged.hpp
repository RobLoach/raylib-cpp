#ifndef RAYLIB_CPP_INCLUDE_SOUNDUNMANAGED_HPP_
#define RAYLIB_CPP_INCLUDE_SOUNDUNMANAGED_HPP_

#include <string>

#include "./RaylibException.hpp"
#include "./raylib-cpp-utils.hpp"
#include "./raylib.hpp"

namespace raylib {
/**
 * A Sound that is not managed by C++ RAII.
 *
 * Make sure to Unload() this if needed, otherwise use raylib::Sound.
 *
 * @see raylib::Sound
 */
class SoundUnmanaged : public ::Sound {
public:
    /**
     * Default constructor, creates an empty Sound.
     */
    SoundUnmanaged() : ::Sound{{nullptr, nullptr, 0, 0, 0}, 0} {}

    /**
     * Creates a SoundUnmanaged from its components.
     */
    SoundUnmanaged(::AudioStream stream, unsigned int frameCount) : ::Sound{stream, frameCount} {}

    /**
     * Creates a SoundUnmanaged from an existing Sound struct.
     */
    SoundUnmanaged(const ::Sound& sound) : ::Sound(sound) {}

    /**
     * Loads a Sound from the given file.
     *
     * @throws raylib::RaylibException Throws if the Sound failed to load.
     */
    SoundUnmanaged(const std::string& fileName) { Load(fileName); }

    /**
     * Loads a Sound from the given Wave.
     *
     * @throws raylib::RaylibException Throws if the Sound failed to load.
     */
    SoundUnmanaged(const ::Wave& wave) { Load(wave); }

    GETTER(unsigned int, FrameCount, frameCount)
    GETTER(::AudioStream, Stream, stream)

    SoundUnmanaged& operator=(const ::Sound& sound) {
        set(sound);
        return *this;
    }

    [[nodiscard]] std::string ToString() const { return TextFormat("Sound(frameCount=%u)", frameCount); }

    operator std::string() const { return ToString(); }

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
     * Load a sound from the given Wave.
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
     * Unload sound.
     */
    void Unload() {
        // Protect against calling UnloadSound() twice.
        if (frameCount != 0) {
            ::UnloadSound(*this);
            frameCount = 0;
        }
    }

    /**
     * Update sound buffer with new data.
     */
    SoundUnmanaged& Update(const void* data, int samplesCount) {
        ::UpdateSound(*this, data, samplesCount);
        return *this;
    }

    /**
     * Update sound buffer with new data, assuming it's the same sample count.
     */
    SoundUnmanaged& Update(const void* data) {
        ::UpdateSound(*this, data, static_cast<int>(frameCount));
        return *this;
    }

    /**
     * Play a sound.
     */
    SoundUnmanaged& Play() {
        ::PlaySound(*this);
        return *this;
    }

    /**
     * Stop playing a sound.
     */
    SoundUnmanaged& Stop() {
        ::StopSound(*this);
        return *this;
    }

    /**
     * Pause a sound.
     */
    SoundUnmanaged& Pause() {
        ::PauseSound(*this);
        return *this;
    }

    /**
     * Resume a paused sound.
     */
    SoundUnmanaged& Resume() {
        ::ResumeSound(*this);
        return *this;
    }

    /**
     * Check if a sound is currently playing.
     */
    [[nodiscard]] bool IsPlaying() const { return ::IsSoundPlaying(*this); }

    /**
     * Set volume for a sound (1.0 is max level).
     */
    SoundUnmanaged& SetVolume(float volume) {
        ::SetSoundVolume(*this, volume);
        return *this;
    }

    /**
     * Set pitch for a sound (1.0 is base level).
     */
    SoundUnmanaged& SetPitch(float pitch) {
        ::SetSoundPitch(*this, pitch);
        return *this;
    }

    /**
     * Set pan for a sound (0.5 is center).
     */
    SoundUnmanaged& SetPan(float pan = 0.5f) {
        ::SetSoundPan(*this, pan);
        return *this;
    }

    /**
     * Retrieve whether or not the Sound buffer is loaded.
     *
     * @return True or false depending on whether the Sound buffer is loaded.
     */
    [[nodiscard]] bool IsValid() const { return ::IsSoundValid(*this); }

protected:
    void set(const ::Sound& sound) {
        stream = sound.stream;
        frameCount = sound.frameCount;
    }
};
} // namespace raylib

using RSoundUnmanaged = raylib::SoundUnmanaged;

#endif // RAYLIB_CPP_INCLUDE_SOUNDUNMANAGED_HPP_
