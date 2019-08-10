#ifndef RAYLIB_CPP_SOUND_HPP_
#define RAYLIB_CPP_SOUND_HPP_

#include <string>

#include "raylib.h"
#include "utils.hpp"

namespace raylib {
	class Sound : public ::Sound {
	public:
		Sound(::Sound vec) {
			set(vec);
		};

		Sound(const std::string& fileName) {
			set(LoadSound(fileName.c_str()));
		};

		Sound(::Wave wave) {
			set(LoadSoundFromWave(wave));
		};

		~Sound() {
			Unload();
		}

		inline void set(::Sound sound) {
			sampleCount = sound.sampleCount;
			stream = sound.stream;
		}

		GETTERSETTER(unsigned int,SampleCount,sampleCount)
		GETTERSETTER(::AudioStream,Stream,stream)

        Sound& operator=(const ::Sound& sound) {
            set(sound);
            return *this;
        }

        Sound& operator=(const Sound& sound) {
            set(sound);
            return *this;
        }

		void Update(const void *data, int sampleCount) {
			UpdateSound(*this, data, sampleCount);
		}

		void Unload() {
			UnloadSound(*this);
		}

		void Play() {
			PlaySound(*this);
		}

		void Stop() {
			StopSound(*this);
		}
		void Pause() {
			PauseSound(*this);
		}
		void Resume() {
			ResumeSound(*this);
		}

		void PlayMulti() {
			PlaySoundMulti(*this);
		}

		void StopMulti() {
			StopSoundMulti();
		}

		bool IsPlaying() {
			return IsSoundPlaying(*this);
		}
		void SetVolume(float volume) {
			SetSoundVolume(*this, volume);
		}
		void SetPitch(float pitch) {
			SetSoundPitch(*this, pitch);
		}

	};
}

#endif
