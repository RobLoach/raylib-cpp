#ifndef RAYLIB_CPP_INCLUDE_AUDIOSTREAM_HPP_
#define RAYLIB_CPP_INCLUDE_AUDIOSTREAM_HPP_

#include "./raylib.hpp"
#include "./raylib-cpp-utils.hpp"
#include "./RaylibException.hpp"

namespace raylib {
/**
 * AudioStream management functions
 */
class AudioStream : public ::AudioStream {
 public:
    AudioStream(const ::AudioStream& music) {
        set(music);
    }

    AudioStream(rAudioBuffer* buffer = nullptr,
            unsigned int sampleRate = 0,
            unsigned int sampleSize = 0,
            unsigned int channels = 0) : ::AudioStream{buffer, sampleRate, sampleSize, channels} {
        // Nothing.
    }

    /**
     * Init audio stream (to stream raw audio pcm data)
     *
     * @throws raylib::RaylibException Throws if the AudioStream failed to load.
     */
    AudioStream(unsigned int SampleRate, unsigned int SampleSize, unsigned int Channels = 2) {
        if (!Load(SampleRate, SampleSize, Channels)) {
            throw RaylibException("Failed to create AudioStream");
        }
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

    AudioStream& operator=(AudioStream&& other) noexcept {
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

    /**
     * Retrieve whether or not the audio stream is ready.
     */
    bool IsReady() {
        return channels > 0;
    }

    /**
     * Init audio stream (to stream raw audio pcm data)
     *
     * @return True or false depending on if the audio stream initialized properly.
     */
    bool Load(unsigned int SampleRate, unsigned int SampleSize, unsigned int Channels = 2) {
        set(::LoadAudioStream(SampleRate, SampleSize, Channels));
        return IsReady();
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
