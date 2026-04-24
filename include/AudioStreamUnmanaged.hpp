#ifndef RAYLIB_CPP_INCLUDE_AUDIOSTREAMUNMANAGED_HPP_
#define RAYLIB_CPP_INCLUDE_AUDIOSTREAMUNMANAGED_HPP_

#include "./RaylibException.hpp"
#include "./raylib-cpp-utils.hpp"
#include "./raylib.hpp"

namespace raylib {
/**
 * An AudioStream that is not managed by C++ RAII.
 *
 * Make sure to Unload() this if needed, otherwise use raylib::AudioStream.
 *
 * @see raylib::AudioStream
 */
class AudioStreamUnmanaged : public ::AudioStream {
public:
    /**
     * Creates an AudioStreamUnmanaged from an existing AudioStream struct.
     */
    AudioStreamUnmanaged(const ::AudioStream& stream) : ::AudioStream(stream) {}

    /**
     * Creates an AudioStreamUnmanaged from its components.
     */
    AudioStreamUnmanaged(
        rAudioBuffer* buffer = nullptr,
        rAudioProcessor* processor = nullptr,
        unsigned int sampleRate = 0,
        unsigned int sampleSize = 0,
        unsigned int channels = 0)
        : ::AudioStream{buffer, processor, sampleRate, sampleSize, channels} {}

    /**
     * Init audio stream (to stream raw audio PCM data).
     *
     * @throws raylib::RaylibException Throws if the AudioStream failed to load.
     */
    AudioStreamUnmanaged(unsigned int sampleRate, unsigned int sampleSize, unsigned int channels = 2) {
        Load(sampleRate, sampleSize, channels);
    }

    GETTER(rAudioBuffer*, Buffer, buffer)
    GETTER(rAudioProcessor*, Processor, processor)
    GETTER(unsigned int, SampleRate, sampleRate)
    GETTER(unsigned int, SampleSize, sampleSize)
    GETTER(unsigned int, Channels, channels)

    AudioStreamUnmanaged& operator=(const ::AudioStream& stream) {
        set(stream);
        return *this;
    }

    /**
     * Load audio stream (to stream raw audio PCM data).
     *
     * Does NOT call Unload() first — that is the responsibility of the managed class.
     *
     * @throws raylib::RaylibException Throws if the AudioStream failed to load.
     */
    void Load(unsigned int sampleRate, unsigned int sampleSize, unsigned int channels = 2) {
        set(::LoadAudioStream(sampleRate, sampleSize, channels));
        if (!IsValid()) {
            throw RaylibException("Failed to load audio stream");
        }
    }

    /**
     * Unload audio stream and free memory.
     */
    void Unload() {
        // Protect against calling UnloadAudioStream() twice.
        if (buffer != nullptr) {
            ::UnloadAudioStream(*this);
            buffer = nullptr;
        }
    }

    /**
     * Update audio stream buffers with data.
     */
    AudioStreamUnmanaged& Update(const void* data, int samplesCount) {
        ::UpdateAudioStream(*this, data, samplesCount);
        return *this;
    }

    /**
     * Check if any audio stream buffers require refill.
     */
    [[nodiscard]] bool IsProcessed() const { return ::IsAudioStreamProcessed(*this); }

    /**
     * Play audio stream.
     */
    AudioStreamUnmanaged& Play() {
        ::PlayAudioStream(*this);
        return *this;
    }

    /**
     * Pause audio stream.
     */
    AudioStreamUnmanaged& Pause() {
        ::PauseAudioStream(*this);
        return *this;
    }

    /**
     * Resume audio stream.
     */
    AudioStreamUnmanaged& Resume() {
        ::ResumeAudioStream(*this);
        return *this;
    }

    /**
     * Check if audio stream is playing.
     */
    [[nodiscard]] bool IsPlaying() const { return ::IsAudioStreamPlaying(*this); }

    /**
     * Stop audio stream.
     */
    AudioStreamUnmanaged& Stop() {
        ::StopAudioStream(*this);
        return *this;
    }

    /**
     * Set volume for audio stream (1.0 is max level).
     */
    AudioStreamUnmanaged& SetVolume(float volume = 1.0f) {
        ::SetAudioStreamVolume(*this, volume);
        return *this;
    }

    /**
     * Set pitch for audio stream (1.0 is base level).
     */
    AudioStreamUnmanaged& SetPitch(float pitch) {
        ::SetAudioStreamPitch(*this, pitch);
        return *this;
    }

    /**
     * Set pan for audio stream (0.5 is centered).
     */
    AudioStreamUnmanaged& SetPan(float pan = 0.5f) {
        ::SetAudioStreamPan(*this, pan);
        return *this;
    }

    /**
     * Default size for new audio streams.
     */
    static void SetBufferSizeDefault(int size) { ::SetAudioStreamBufferSizeDefault(size); }

    /**
     * Audio thread callback to request new data.
     */
    AudioStreamUnmanaged& SetCallback(::AudioCallback callback) {
        ::SetAudioStreamCallback(*this, callback);
        return *this;
    }

    /**
     * Attach audio stream processor to stream.
     */
    AudioStreamUnmanaged& AttachProcessor(::AudioCallback processor) {
        ::AttachAudioStreamProcessor(*this, processor);
        return *this;
    }

    /**
     * Detach audio stream processor from stream.
     */
    AudioStreamUnmanaged& DetachProcessor(::AudioCallback processor) {
        ::DetachAudioStreamProcessor(*this, processor);
        return *this;
    }

    /**
     * Retrieve whether or not the audio stream is ready.
     */
    [[nodiscard]] bool IsValid() const { return ::IsAudioStreamValid(*this); }

protected:
    void set(const ::AudioStream& stream) {
        buffer = stream.buffer;
        processor = stream.processor;
        sampleRate = stream.sampleRate;
        sampleSize = stream.sampleSize;
        channels = stream.channels;
    }
};
} // namespace raylib

using RAudioStreamUnmanaged = raylib::AudioStreamUnmanaged;

#endif // RAYLIB_CPP_INCLUDE_AUDIOSTREAMUNMANAGED_HPP_
