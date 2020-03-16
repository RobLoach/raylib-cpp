#ifndef RAYLIB_CPP_MUSIC_HPP_
#define RAYLIB_CPP_MUSIC_HPP_

#ifdef __cplusplus
extern "C"{
#endif
#include "raylib.h"
#ifdef __cplusplus
}
#endif

#include "utils.hpp"

namespace raylib {
	class Music : public ::Music {
	public:
		Music(::Music music) {
			set(music);
		};

		Music(const std::string& fileName) {
			set(::LoadMusicStream(fileName.c_str()));
		}

		~Music() {
			Unload();
		}

		inline void set(::Music music) {
			ctxType = music.ctxType;
			ctxData = music.ctxData;
			sampleCount = music.sampleCount;
			loopCount = music.loopCount;
			stream = music.stream;
		}

		GETTERSETTER(int,CtxType,ctxType)
		GETTERSETTER(unsigned int,SampleCount,sampleCount)
		GETTERSETTER(unsigned int,LoopCount,loopCount)

        Music& operator=(const ::Music& music) {
            set(music);
            return *this;
        }

        Music& operator=(const Music& music) {
            set(music);
            return *this;
        }

        inline void Unload() {
        	::UnloadMusicStream(*this);
        }

        inline void Play() {
        	::PlayMusicStream(*this);
        }

		inline void Update() {
			::UpdateMusicStream(*this);
		}

		inline void Stop() {
			::StopMusicStream(*this);
		}

		inline void Pause() {
			::PauseMusicStream(*this);
		}
		inline void Resume() {
			::ResumeMusicStream(*this);
		}
		inline bool IsPlaying() {
			return ::IsMusicPlaying(*this);
		}
		inline void SetVolume(float volume) {
			::SetMusicVolume(*this, volume);
		}
		inline void SetPitch(float pitch) {
			::SetMusicPitch(*this, pitch);
		}
		inline void SetLoopCount(int count)  {
			::SetMusicLoopCount(*this, count);
		}
		inline float GetTimeLength() {
			return ::GetMusicTimeLength(*this);
		}
		inline float GetTimePlayed() {
			return ::GetMusicTimePlayed(*this);
		}


	};
}

#endif
