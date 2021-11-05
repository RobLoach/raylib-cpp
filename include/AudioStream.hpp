#ifndef RAYLIB_CPP_INCLUDE_AUDIOSTREAM_HPP_
#define RAYLIB_CPP_INCLUDE_AUDIOSTREAM_HPP_

#include "./raylib.hpp"
#include "./raylib-cpp-utils.hpp"

namespace raylib {
/**
 * AudioStream management functions
 */
class AudioStream : public ::AudioStream {
 public:
    AudioStream(const ::AudioStream& music) {
        set(music);
    }

    /**
     * Init audio stream (to stream raw audio pcm data)
     */
    AudioStream(unsigned int SampleRate, unsigned int SampleSize, unsigned int Channels = 2) {
        set(LoadAudioStream(SampleRate, SampleSize, Channels));
    }

    AudioStream(const AudioStream&) = delete;

    AudioStream(AudioStream&& other) {
        set(other);

        other.buffer = nullptr;
        other.sampleRate = 0;
        other.sampleSize = 0;
        other.channels = 0;
    }

    ~AudioStream() {
        Unload();
    }

    GETTERSETTER(rAudioBuffer *, Buffer, buffer)
    GETTERSETTER(unsigned int, SampleRate, sampleRate)
    GETTERSETTER(unsigned int, SampleSize, sampleSize)
    GETTERSETTER(unsigned int, Channels, channels)

    AudioStream& operator=(const ::AudioStream& stream) {
        set(stream);
        return *this;
    }

    AudioStream& operator=(const AudioStream&) = delete;

    AudioStream& operator=(AudioStream&& other) {
        if (this == &other) {
            return *this;
        }

        Unload();
        set(other);

        other.buffer = nullptr;
        other.sampleRate = 0;
        other.sampleSize = 0;
        other.channels = 0;

        return *this;
    }

    /**
     * Update audio stream buffers with data
     */
    inline AudioStream& Update(const void *data, int samplesCount) {
        ::UpdateAudioStream(*this, data, samplesCount);
        return *this;
    }

    /**
     * Unload audio stream and free memory
     */
    inline void Unload() {
        ::UnloadAudioStream(*this);
    }

    /**
     * Check if any audio stream buffers requires refill
     */
    inline bool IsProcessed() const {
        return ::IsAudioStreamProcessed(*this);
    }

    /**
     * Play audio stream
     */
    inline AudioStream& Play() {
        ::PlayAudioStream(*this);
        return *this;
    }

    /**
     * Pause audio stream
     */
    inline AudioStream& Pause() {
        ::PauseAudioStream(*this);
        return *this;
    }

    /**
     * Resume audio stream
     */
    inline AudioStream& Resume() {
        ::ResumeAudioStream(*this);
        return *this;
    }

    /**
     * Check if audio stream is playing
     */
    inline bool IsPlaying() const {
        return ::IsAudioStreamPlaying(*this);
    }

    /**
     * Stop audio stream
     */
    inline AudioStream& Stop() {
        ::StopAudioStream(*this);
        return *this;
    }

    /**
     * Set volume for audio stream (1.0 is max level)
     */
    inline AudioStream& SetVolume(float volume) {
        ::SetAudioStreamVolume(*this, volume);
        return *this;
    }

    /**
     * Set pitch for audio stream (1.0 is base level)
     */
    inline AudioStream& SetPitch(float pitch) {
        ::SetAudioStreamPitch(*this, pitch);
        return *this;
    }

    /**
     * Default size for new audio streams
     */
    inline static void SetBufferSizeDefault(int size) {
        ::SetAudioStreamBufferSizeDefault(size);
    }

 private:
    inline void set(const ::AudioStream& stream) {
        buffer = stream.buffer;
        sampleRate = stream.sampleRate;
        sampleSize = stream.sampleSize;
        channels = stream.channels;
    }
};
}  // namespace raylib

#endif  // RAYLIB_CPP_INCLUDE_AUDIOSTREAM_HPP_
