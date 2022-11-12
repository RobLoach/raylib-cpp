#ifndef RAYLIB_CPP_INCLUDE_WAVE_HPP_
#define RAYLIB_CPP_INCLUDE_WAVE_HPP_

#include <string>

#include "./raylib.hpp"
#include "./raylib-cpp-utils.hpp"
#include "./RaylibException.hpp"

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
            unsigned int frameCount = 0,
            unsigned int sampleRate = 0,
            unsigned int sampleSize = 0,
            unsigned int channels = 0,
            void *data = nullptr) : ::Wave{frameCount, sampleRate, sampleSize, channels, data} {
        // Nothing.
    }

    /**
     * Load wave data from file
     *
     * @throws raylib::RaylibException Throws if the Wave failed to load.
     */
    Wave(const std::string& fileName) {
        Load(fileName);
    }

    /**
     * Load wave from memory buffer, fileType refers to extension: i.e. "wav"
     *
     * @throws raylib::RaylibException Throws if the Wave failed to load.
     */
    Wave(const std::string& fileType, const unsigned char *fileData, int dataSize) {
        Load(fileType, fileData, dataSize);
    }

    Wave(const Wave& other) {
        set(other.Copy());
    }

    Wave(Wave&& other) {
        set(other);

        other.frameCount = 0;
        other.sampleRate = 0;
        other.sampleSize = 0;
        other.channels = 0;
        other.data = nullptr;
    }

    /**
     * Unload wave data
     */
    ~Wave() {
        Unload();
    }

    GETTERSETTER(unsigned int, FrameCount, frameCount)
    GETTERSETTER(unsigned int, SampleRate, sampleRate)
    GETTERSETTER(unsigned int, SampleSize, sampleSize)
    GETTERSETTER(unsigned int, Channels, channels)
    GETTERSETTER(void *, Data, data)

    Wave& operator=(const ::Wave& wave) {
        set(wave);
        return *this;
    }

    Wave& operator=(const Wave& other) {
        if (this == &other) {
            return *this;
        }

        Unload();
        set(other.Copy());

        return *this;
    }

    Wave& operator=(Wave&& other) noexcept {
        if (this != &other) {
            return *this;
        }

        Unload();
        set(other);

        other.frameCount = 0;
        other.sampleRate = 0;
        other.sampleSize = 0;
        other.channels = 0;
        other.data = nullptr;

        return *this;
    }

    /**
     * Copy a wave to a new wave
     */
    inline ::Wave Copy() const {
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
     * Convert wave data to desired format
     */
    inline Wave& Format(int SampleRate, int SampleSize, int Channels = 2) {
        ::WaveFormat(this, SampleRate, SampleSize, Channels);
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
    inline static void UnloadSamples(float *samples) {
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
        // Protect against calling UnloadWave() twice.
        if (data != nullptr) {
            ::UnloadWave(*this);
            data = nullptr;
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
     * Load wave data from file.
     *
     * @throws raylib::RaylibException Throws if the Wave failed to load.
     */
    void Load(const std::string& fileName) {
        set(::LoadWave(fileName.c_str()));
        if (!IsReady()) {
            throw RaylibException("Failed to load Wave from file: " + fileName);
        }
    }

    /**
     * Load wave from memory buffer, fileType refers to extension: i.e. "wav"
     *
     * @throws raylib::RaylibException Throws if the Wave failed to load.
     */
    void Load(const std::string& fileType, const unsigned char *fileData, int dataSize) {
        set(::LoadWaveFromMemory(fileType.c_str(), fileData, dataSize));
        if (!IsReady()) {
            throw RaylibException("Failed to load Wave from file data of type: " + fileType);
        }
    }

    /**
     * Retrieve whether or not the Wave data has been loaded.
     *
     * @return True or false depending on whether the wave data has been loaded.
     */
    inline bool IsReady() const {
        return data != nullptr;
    }

 private:
    void set(const ::Wave& wave) {
        frameCount = wave.frameCount;
        sampleRate = wave.sampleRate;
        sampleSize = wave.sampleSize;
        channels = wave.channels;
        data = wave.data;
    }
};

}  // namespace raylib

using RWave = raylib::Wave;

#endif  // RAYLIB_CPP_INCLUDE_WAVE_HPP_
