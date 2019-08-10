#ifndef RAYLIB_CPP_MUSIC_HPP_
#define RAYLIB_CPP_MUSIC_HPP_

#include "raylib.h"
#include "utils.hpp"

namespace raylib {
	class Music : public ::Music {
	public:
		Music(::Music music) {
			set(music);
		};

		Music(const std::string& fileName) {
			set(LoadMusicStream(fileName.c_str()));
		}

		~Music() {
			Unload();
		}

		inline void set(::Music music) {
			ctxType = music.ctxType;
			ctxData = music.ctxData;
			sampleCount = music.sampleCount;
			sampleLeft = music.sampleLeft;
			loopCount = music.loopCount;
			stream = music.stream;
		}

		GETTERSETTER(int,CtxType,ctxType)
		GETTERSETTER(unsigned int,SampleCount,sampleCount)
		GETTERSETTER(unsigned int,SampleLeft,sampleLeft)
		GETTERSETTER(unsigned int,LoopCount,loopCount)

        Music& operator=(const ::Music& music) {
            set(music);
            return *this;
        }

        Music& operator=(const Music& music) {
            set(music);
            return *this;
        }

        void Unload() {
        	UnloadMusicStream(*this);
        }

        void Play() {
        	PlayMusicStream(*this);
        }

		void Update() {
			UpdateMusicStream(*this);
		}

		void Stop() {
			StopMusicStream(*this);
		}

		void Pause() {
			PauseMusicStream(*this);
		}
		void Resume() {
			ResumeMusicStream(*this);
		}
		bool IsPlaying() {
			return IsMusicPlaying(*this);
		}
		void SetVolume(float volume) {
			SetMusicVolume(*this, volume);
		}
		void SetPitch(float pitch) {
			SetMusicPitch(*this, pitch);
		}
		void SetLoopCount(int count)  {
			SetMusicLoopCount(*this, count);
		}
		float GetTimeLength() {
			return GetMusicTimeLength(*this);
		}
		float GetTimePlayed() {
			return GetMusicTimePlayed(*this);
		}


	};
}

#endif
