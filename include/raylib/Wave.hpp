#ifndef RAYLIB_CPP_WAVE_HPP_
#define RAYLIB_CPP_WAVE_HPP_

#ifdef __cplusplus
extern "C"{
#endif
#include "raylib.h"
#ifdef __cplusplus
}
#endif

#include "utils.hpp"

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

		GETTERSETTER(unsigned int,X,sampleCount)
		GETTERSETTER(unsigned int,Y,sampleRate)
		GETTERSETTER(unsigned int,Z,sampleSize)
		GETTERSETTER(unsigned int,W,channels)
		GETTERSETTER(void*,Data,data)

        Wave& operator=(const ::Wave& wave) {
            set(wave);
            return *this;
        }

        Wave& operator=(const Wave& wave) {
            set(wave);
            return *this;
        }

		inline void Format(int SampleRate = 0, int SampleSize = 0, int Channels = 2) {
			WaveFormat(this, SampleRate, SampleSize, Channels);
		}

		inline Wave Copy() {
			return WaveCopy(*this);
		}

		inline void Crop(int initSample, int finalSample) {
			::WaveCrop(this, initSample, finalSample);
		}

		inline void Export(const std::string& fileName) {
			::ExportWave(*this, fileName.c_str());
		}
		inline void ExportAsCode(const std::string& fileName) {
			::ExportWaveAsCode(*this, fileName.c_str());
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

		inline float* GetData() {
			return ::GetWaveData(*this);
		}
	};
}

#endif
