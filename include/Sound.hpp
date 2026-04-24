#ifndef RAYLIB_CPP_INCLUDE_SOUND_HPP_
#define RAYLIB_CPP_INCLUDE_SOUND_HPP_

#include "./SoundUnmanaged.hpp"

namespace raylib {
/**
 * Wave/Sound management functions.
 *
 * The sound will be unloaded on object destruction. Use raylib::SoundUnmanaged if you're looking to not unload.
 *
 * @code
 * raylib::Sound boom("boom.wav");
 * boom.Play();
 * @endcode
 *
 * @see raylib::SoundUnmanaged
 */
class Sound : public SoundUnmanaged {
public:
    using SoundUnmanaged::SoundUnmanaged;

    Sound(const Sound&) = delete;
    Sound& operator=(const Sound&) = delete;

    Sound(Sound&& other) noexcept {
        set(other);
        other.stream = {nullptr, nullptr, 0, 0, 0};
        other.frameCount = 0;
    }

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

    ~Sound() { Unload(); }

    void Load(const std::string& fileName) {
        Unload();
        SoundUnmanaged::Load(fileName);
    }

    void Load(const ::Wave& wave) {
        Unload();
        SoundUnmanaged::Load(wave);
    }
};
} // namespace raylib

using RSound = raylib::Sound;

#endif // RAYLIB_CPP_INCLUDE_SOUND_HPP_
