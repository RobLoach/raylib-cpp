#ifndef RAYLIB_CPP_SOUND_HPP_
#define RAYLIB_CPP_SOUND_HPP_

#include <string>

#ifdef __cplusplus
extern "C"{
#endif
#include "raylib.h"
#ifdef __cplusplus
}
#endif

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

		inline void Update(const void *data, int sampleCount) {
			UpdateSound(*this, data, sampleCount);
		}

		inline void Unload() {
			UnloadSound(*this);
		}

		inline void Play() {
			PlaySound(*this);
		}

		inline void Stop() {
			StopSound(*this);
		}
		inline void Pause() {
			PauseSound(*this);
		}
		inline void Resume() {
			ResumeSound(*this);
		}

		inline void PlayMulti() {
			PlaySoundMulti(*this);
		}

		inline void StopMulti() {
			StopSoundMulti();
		}

		inline bool IsPlaying() {
			return IsSoundPlaying(*this);
		}
		inline void SetVolume(float volume) {
			SetSoundVolume(*this, volume);
		}
		inline void SetPitch(float pitch) {
			SetSoundPitch(*this, pitch);
		}

	};
}

#endif
