#ifndef RAYLIB_CPP_WAVE_HPP_
#define RAYLIB_CPP_WAVE_HPP_

#include "raylib.h"
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

		void Format(int SampleRate = 0, int SampleSize = 0, int Channels = 2) {
			WaveFormat(this, SampleRate, SampleSize, Channels);
		}

		Wave Copy() {
			return WaveCopy(*this);
		}

		void Crop(int initSample, int finalSample) {
			WaveCrop(this, initSample, finalSample);
		}

		void Export(const std::string& fileName) {
			ExportWave(*this, fileName.c_str());
		}
		void ExportAsCode(const std::string& fileName) {
			ExportWaveAsCode(*this, fileName.c_str());
		}

		void Unload() {
			if (data != NULL) {
				UnloadWave(*this);
				data = NULL;
			}
		}

		Sound LoadSound() {
			return LoadSoundFromWave(*this);
		}

		float* GetData() {
			return GetWaveData(*this);
		}
	};
}

#endif
