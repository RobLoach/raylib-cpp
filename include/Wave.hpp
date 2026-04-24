#ifndef RAYLIB_CPP_INCLUDE_WAVE_HPP_
#define RAYLIB_CPP_INCLUDE_WAVE_HPP_

#include "./WaveUnmanaged.hpp"

namespace raylib {
/**
 * Wave type, defines audio wave data.
 *
 * The wave will be unloaded on object destruction. Use raylib::WaveUnmanaged if you're looking to not unload.
 * Unlike other resource types, Wave supports value-copy semantics via WaveCopy().
 *
 * @see raylib::WaveUnmanaged
 */
class Wave : public WaveUnmanaged {
public:
    using WaveUnmanaged::WaveUnmanaged;

    Wave(const Wave& other) { set(other.Copy()); }

    Wave(Wave&& other) noexcept {
        set(other);
        other.frameCount = 0;
        other.sampleRate = 0;
        other.sampleSize = 0;
        other.channels = 0;
        other.data = nullptr;
    }

    Wave& operator=(const ::Wave& wave) {
        Unload();
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
        if (this == &other) {
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

    ~Wave() { Unload(); }

    void Load(const std::string& fileName) {
        Unload();
        WaveUnmanaged::Load(fileName);
    }

    void Load(const std::string& fileType, const unsigned char* fileData, int dataSize) {
        Unload();
        WaveUnmanaged::Load(fileType, fileData, dataSize);
    }
};
} // namespace raylib

using RWave = raylib::Wave;

#endif // RAYLIB_CPP_INCLUDE_WAVE_HPP_
