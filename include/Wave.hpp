#ifndef RAYLIB_CPP_WAVE_HPP_
#define RAYLIB_CPP_WAVE_HPP_

#ifdef __cplusplus
extern "C"{
#endif
#include "raylib.h"
#ifdef __cplusplus
}
#endif

#include "./raylib-cpp-utils.hpp"

namespace raylib {
	class Wave : public ::Wave {
	public:
		Wave(::Wave wave) {
			set(wave);
		};

		Wave(unsigned int SampleCount = 0, unsigned int SampleRate = 0, unsigned int SampleSize = 0, unsigned int Channels = 0) {
			sampleCount = SampleCount;
			sampleRate = SampleRate;
			sampleSize = SampleSize;
			channels = Channels;
		};

		Wave(const std::string& fileName) {
			set(LoadWave(fileName.c_str()));
		}

		~Wave() {
			Unload();
		}

		inline void set(::Wave wave) {
			sampleCount = wave.sampleCount;
			sampleRate = wave.sampleRate;
			sampleSize = wave.sampleSize;
			channels = wave.channels;
			data = wave.data;
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

		inline float* GetWaveData() {
			return ::GetWaveData(*this);
		}
	};
}

#endif
