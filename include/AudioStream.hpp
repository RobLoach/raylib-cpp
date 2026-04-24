#ifndef RAYLIB_CPP_INCLUDE_AUDIOSTREAM_HPP_
#define RAYLIB_CPP_INCLUDE_AUDIOSTREAM_HPP_

#include "./AudioStreamUnmanaged.hpp"

namespace raylib {
/**
 * AudioStream management functions.
 *
 * The audio stream will be unloaded on object destruction. Use raylib::AudioStreamUnmanaged if you're looking to not unload.
 *
 * @see raylib::AudioStreamUnmanaged
 */
class AudioStream : public AudioStreamUnmanaged {
public:
    using AudioStreamUnmanaged::AudioStreamUnmanaged;

    AudioStream(const AudioStream&) = delete;
    AudioStream& operator=(const AudioStream&) = delete;

    AudioStream(AudioStream&& other) noexcept {
        set(other);
        other.buffer = nullptr;
        other.processor = nullptr;
        other.sampleRate = 0;
        other.sampleSize = 0;
        other.channels = 0;
    }

    AudioStream& operator=(AudioStream&& other) noexcept {
        if (this == &other) {
            return *this;
        }
        Unload();
        set(other);
        other.buffer = nullptr;
        other.processor = nullptr;
        other.sampleRate = 0;
        other.sampleSize = 0;
        other.channels = 0;
        return *this;
    }

    ~AudioStream() { Unload(); }

    void Load(unsigned int sampleRate, unsigned int sampleSize, unsigned int channels = 2) {
        Unload();
        AudioStreamUnmanaged::Load(sampleRate, sampleSize, channels);
    }
};
} // namespace raylib

using RAudioStream = raylib::AudioStream;

#endif // RAYLIB_CPP_INCLUDE_AUDIOSTREAM_HPP_
