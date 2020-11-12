/*
*   LICENSE: zlib/libpng
*
*   raylib-cpp is licensed under an unmodified zlib/libpng license, which is an OSI-certified,
*   BSD-like license that allows static linking with closed source software:
*
*   Copyright (c) 2020 Rob Loach (@RobLoach)
*
*   This software is provided "as-is", without any express or implied warranty. In no event
*   will the authors be held liable for any damages arising from the use of this software.
*
*   Permission is granted to anyone to use this software for any purpose, including commercial
*   applications, and to alter it and redistribute it freely, subject to the following restrictions:
*
*     1. The origin of this software must not be misrepresented; you must not claim that you
*     wrote the original software. If you use this software in a product, an acknowledgment
*     in the product documentation would be appreciated but is not required.
*
*     2. Altered source versions must be plainly marked as such, and must not be misrepresented
*     as being the original software.
*
*     3. This notice may not be removed or altered from any source distribution.
*/

#ifndef RAYLIB_CPP_INCLUDE_WAVE_HPP_
#define RAYLIB_CPP_INCLUDE_WAVE_HPP_

#include <string>

#include "./raylib.hpp"
#include "./raylib-cpp-utils.hpp"

namespace raylib {
class Wave : public ::Wave {
 public:
    Wave(::Wave wave) {
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

    Wave(const std::string& fileName) {
        set(LoadWave(fileName.c_str()));
    }

    Wave(const std::string& fileType, const unsigned char *fileData, int dataSize) {
        set(LoadWaveFromMemory(fileType.c_str(), fileData, dataSize));
    }

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

    Wave& operator=(const Wave& wave) {
        set(wave);
        return *this;
    }

    inline Wave& Format(int SampleRate = 0, int SampleSize = 0, int Channels = 2) {
        ::WaveFormat(this, SampleRate, SampleSize, Channels);
        return *this;
    }

    inline Wave Copy() {
        return ::WaveCopy(*this);
    }

    inline Wave& Crop(int initSample, int finalSample) {
        ::WaveCrop(this, initSample, finalSample);
        return *this;
    }

    inline Wave& Export(const std::string& fileName) {
        ::ExportWave(*this, fileName.c_str());
        return *this;
    }

    inline Wave& ExportAsCode(const std::string& fileName) {
        ::ExportWaveAsCode(*this, fileName.c_str());
        return *this;
    }

    void Unload() {
        if (data != NULL) {
            ::UnloadWave(*this);
            data = NULL;
        }
    }

    inline Sound LoadSound() {
        return ::LoadSoundFromWave(*this);
    }

    inline operator Sound() {
        return LoadSound();
    }

    inline float* GetData() {
        return ::GetWaveData(*this);
    }

 protected:
    inline void set(::Wave wave) {
        sampleCount = wave.sampleCount;
        sampleRate = wave.sampleRate;
        sampleSize = wave.sampleSize;
        channels = wave.channels;
        data = wave.data;
    }
};
}  // namespace raylib

#endif  // RAYLIB_CPP_INCLUDE_WAVE_HPP_
