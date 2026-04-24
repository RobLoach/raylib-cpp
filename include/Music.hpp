#ifndef RAYLIB_CPP_INCLUDE_MUSIC_HPP_
#define RAYLIB_CPP_INCLUDE_MUSIC_HPP_

#include "./MusicUnmanaged.hpp"

namespace raylib {
/**
 * Music stream type (audio file streaming from memory).
 *
 * The music stream will be unloaded on object destruction. Use raylib::MusicUnmanaged if you're looking to not unload.
 *
 * @see raylib::MusicUnmanaged
 */
class Music : public MusicUnmanaged {
public:
    using MusicUnmanaged::MusicUnmanaged;

    Music(const Music&) = delete;
    Music& operator=(const Music&) = delete;

    Music(Music&& other) noexcept {
        set(other);
        other.stream = {};
        other.frameCount = 0;
        other.looping = false;
        other.ctxType = 0;
        other.ctxData = nullptr;
    }

    Music& operator=(Music&& other) noexcept {
        if (this == &other) {
            return *this;
        }
        Unload();
        set(other);
        other.ctxType = 0;
        other.ctxData = nullptr;
        other.looping = false;
        other.frameCount = 0;
        other.stream = {};
        return *this;
    }

    Music& operator=(const ::Music& music) {
        Unload();
        set(music);
        return *this;
    }

    ~Music() { Unload(); }

    void Load(const std::string& fileName) {
        Unload();
        MusicUnmanaged::Load(fileName);
    }

    void Load(const std::string& fileType, unsigned char* data, int dataSize) {
        Unload();
        MusicUnmanaged::Load(fileType, data, dataSize);
    }
};
} // namespace raylib

using RMusic = raylib::Music;

#endif // RAYLIB_CPP_INCLUDE_MUSIC_HPP_
