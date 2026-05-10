#ifndef RAYLIB_CPP_INCLUDE_WAVEUNMANAGED_HPP_
#define RAYLIB_CPP_INCLUDE_WAVEUNMANAGED_HPP_

#include <string>

#include "./RaylibException.hpp"
#include "./raylib-cpp-utils.hpp"
#include "./raylib.hpp"

namespace raylib {
/**
 * A Wave that is not managed by C++ RAII.
 *
 * Make sure to Unload() this if needed, otherwise use raylib::Wave.
 *
 * @see raylib::Wave
 */
class WaveUnmanaged : public ::Wave {
public:
    /**
     * Creates a WaveUnmanaged from an existing Wave struct.
     */
    WaveUnmanaged(const ::Wave& wave) : ::Wave(wave) {}

    /**
     * Creates a WaveUnmanaged from its components.
     */
    WaveUnmanaged(
        unsigned int frameCount = 0,
        unsigned int sampleRate = 0,
        unsigned int sampleSize = 0,
        unsigned int channels = 0,
        void* data = nullptr)
        : ::Wave{frameCount, sampleRate, sampleSize, channels, data} {}

    /**
     * Load wave data from file.
     *
     * @throws raylib::RaylibException Throws if the Wave failed to load.
     */
    WaveUnmanaged(const std::string& fileName) { Load(fileName); }

    /**
     * Load wave from memory buffer; fileType refers to extension: i.e. "wav".
     *
     * @throws raylib::RaylibException Throws if the Wave failed to load.
     */
    WaveUnmanaged(const std::string& fileType, const unsigned char* fileData, int dataSize) {
        Load(fileType, fileData, dataSize);
    }

    GETTER(unsigned int, FrameCount, frameCount)
    GETTER(unsigned int, SampleRate, sampleRate)
    GETTER(unsigned int, SampleSize, sampleSize)
    GETTER(unsigned int, Channels, channels)
    GETTER(void*, Data, data)

    WaveUnmanaged& operator=(const ::Wave& wave) {
        set(wave);
        return *this;
    }

    /**
     * Load wave data from file.
     *
     * @throws raylib::RaylibException Throws if the Wave failed to load.
     */
    void Load(const std::string& fileName) {
        set(::LoadWave(fileName.c_str()));
        if (!IsValid()) {
            throw RaylibException("Failed to load Wave from file: " + fileName);
        }
    }

    /**
     * Load wave from memory buffer; fileType refers to extension: i.e. "wav".
     *
     * @throws raylib::RaylibException Throws if the Wave failed to load.
     */
    void Load(const std::string& fileType, const unsigned char* fileData, int dataSize) {
        set(::LoadWaveFromMemory(fileType.c_str(), fileData, dataSize));
        if (!IsValid()) {
            throw RaylibException("Failed to load Wave from file data of type: " + fileType);
        }
    }

    /**
     * Unload wave data.
     */
    void Unload() {
        // Protect against calling UnloadWave() twice.
        if (data != nullptr) {
            ::UnloadWave(*this);
            data = nullptr;
        }
    }

    /**
     * Copy a wave to a new wave.
     */
    RLCPP_NODISCARD ::Wave Copy() const { return ::WaveCopy(*this); }

    /**
     * Crop a wave to defined samples range.
     */
    WaveUnmanaged& Crop(int initSample, int finalSample) {
        ::WaveCrop(this, initSample, finalSample);
        return *this;
    }

    /**
     * Convert wave data to desired format.
     */
    WaveUnmanaged& Format(int sampleRate, int sampleSize, int channels = 2) {
        ::WaveFormat(this, sampleRate, sampleSize, channels);
        return *this;
    }

    /**
     * Load samples data from wave as a floats array.
     */
    float* LoadSamples() { return ::LoadWaveSamples(*this); }

    /**
     * Unload samples data loaded with LoadWaveSamples().
     */
    static void UnloadSamples(float* samples) { ::UnloadWaveSamples(samples); }

    /**
     * Export wave data to file, returns true on success.
     */
    bool Export(const std::string& fileName) { return ::ExportWave(*this, fileName.c_str()); }

    /**
     * Export wave sample data to code (.h), returns true on success.
     */
    bool ExportAsCode(const std::string& fileName) { return ::ExportWaveAsCode(*this, fileName.c_str()); }

    /**
     * Load sound from wave data.
     */
    ::Sound LoadSound() { return ::LoadSoundFromWave(*this); }

    /**
     * Load sound from wave data.
     */
    operator ::Sound() { return LoadSound(); }

    /**
     * Retrieve whether or not the Wave data has been loaded.
     *
     * @return True or false depending on whether the wave data has been loaded.
     */
    RLCPP_NODISCARD bool IsValid() const { return ::IsWaveValid(*this); }

protected:
    void set(const ::Wave& wave) {
        frameCount = wave.frameCount;
        sampleRate = wave.sampleRate;
        sampleSize = wave.sampleSize;
        channels = wave.channels;
        data = wave.data;
    }
};
} // namespace raylib

using RWaveUnmanaged = raylib::WaveUnmanaged;

#endif // RAYLIB_CPP_INCLUDE_WAVEUNMANAGED_HPP_
