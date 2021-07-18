#ifndef RAYLIB_CPP_INCLUDE_WAVE_HPP_
#define RAYLIB_CPP_INCLUDE_WAVE_HPP_

#include <string>

#include "./raylib.hpp"
#include "./raylib-cpp-utils.hpp"

namespace raylib {
/**
 * Wave type, defines audio wave data
 */
class Wave : public ::Wave {
 public:
    Wave(const ::Wave& wave) {
        set(wave);
    }

    Wave(
            unsigned int SampleCount = 0,
            unsigned int SampleRate = 0,
            unsigned int SampleSize = 0,
            unsigned int Channels = 0) {
        sampleCount = SampleCount;
        sampleRate = SampleRate;
        sampleSize = SampleSize;
        channels = Channels;
    }

    /**
     * Load wave data from file
     */
    Wave(const std::string& fileName) {
        set(::LoadWave(fileName.c_str()));
    }

    /**
     * Load wave from memory buffer, fileType refers to extension: i.e. "wav"
     */
    Wave(const std::string& fileType, const unsigned char *fileData, int dataSize) {
        set(::LoadWaveFromMemory(fileType.c_str(), fileData, dataSize));
    }

    /**
     * Unload wave data
     */
    ~Wave() {
        Unload();
    }

    GETTERSETTER(unsigned int, SampleCount, sampleCount)
    GETTERSETTER(unsigned int, SampleRate, sampleRate)
    GETTERSETTER(unsigned int, SampleSize, sampleSize)
    GETTERSETTER(unsigned int, Channels, channels)
    GETTERSETTER(void *, Data, data)

    Wave& operator=(const ::Wave& wave) {
        set(wave);
        return *this;
    }

    /**
     * Convert wave data to desired format
     */
    inline Wave& Format(int SampleRate, int SampleSize, int Channels = 2) {
        ::WaveFormat(this, SampleRate, SampleSize, Channels);
        return *this;
    }

    /**
     * Copy a wave to a new wave
     */
    inline ::Wave Copy() {
        return ::WaveCopy(*this);
    }

    /**
     * Crop a wave to defined samples range
     */
    inline Wave& Crop(int initSample, int finalSample) {
        ::WaveCrop(this, initSample, finalSample);
        return *this;
    }

    /**
     * Load samples data from wave as a floats array
     */
    inline float* LoadSamples() {
        return ::LoadWaveSamples(*this);
    }

    /**
     * Unload samples data loaded with LoadWaveSamples()
     */
    inline void UnloadSamples(float *samples) {
        ::UnloadWaveSamples(samples);
    }

    /**
     * Export wave data to file, returns true on success
     */
    inline bool Export(const std::string& fileName) {
        // TODO(RobLoach): Throw exception on error.
        return ::ExportWave(*this, fileName.c_str());
    }

    /**
     * Export wave sample data to code (.h), returns true on success
     */
    inline bool ExportAsCode(const std::string& fileName) {
        // TODO(RobLoach): Throw exception on error.
        return ::ExportWaveAsCode(*this, fileName.c_str());
    }

    /**
     * Unload wave data
     */
    void Unload() {
        if (data != NULL) {
            ::UnloadWave(*this);
            data = NULL;
        }
    }

    /**
     * Load sound from wave data
     */
    inline ::Sound LoadSound() {
        return ::LoadSoundFromWave(*this);
    }

    /**
     * Load sound from wave data
     */
    inline operator ::Sound() {
        return LoadSound();
    }

    /**
     * Load sound from wave data
     */
    inline operator Sound() {
        return LoadSound();
    }

 private:
    inline void set(const ::Wave& wave) {
        sampleCount = wave.sampleCount;
        sampleRate = wave.sampleRate;
        sampleSize = wave.sampleSize;
        channels = wave.channels;
        data = wave.data;
    }
};
}  // namespace raylib

#endif  // RAYLIB_CPP_INCLUDE_WAVE_HPP_
