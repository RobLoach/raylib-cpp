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

#include "./raylib-cpp-utils.hpp"

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

		inline Sound& Update(const void *data, int sampleCount) {
			::UpdateSound(*this, data, sampleCount);
			return *this;
		}

		inline void Unload() {
			::UnloadSound(*this);
		}

		inline Sound& Play() {
			::PlaySound(*this);
			return *this;
		}

		inline Sound& Stop() {
			::StopSound(*this);
			return *this;
		}
		inline Sound& Pause() {
			::PauseSound(*this);
			return *this;
		}
		inline Sound& Resume() {
			::ResumeSound(*this);
			return *this;
		}

		inline Sound& PlayMulti() {
			::PlaySoundMulti(*this);
			return *this;
		}

		inline Sound& StopMulti() {
			::StopSoundMulti();
			return *this;
		}

		inline bool IsPlaying() const {
			return ::IsSoundPlaying(*this);
		}
		inline Sound& SetVolume(float volume) {
			::SetSoundVolume(*this, volume);
			return *this;
		}
		inline Sound& SetPitch(float pitch) {
			::SetSoundPitch(*this, pitch);
			return *this;
		}

	};
}

#endif
