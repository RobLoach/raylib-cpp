#ifndef RAYLIB_CPP_MUSIC_HPP_
#define RAYLIB_CPP_MUSIC_HPP_

#ifdef __cplusplus
extern "C"{
#endif
#include "raylib.h"
#ifdef __cplusplus
}
#endif

#include "./raylib-cpp-utils.hpp"

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

        inline Music& Play() {
        	::PlayMusicStream(*this);
        	return *this;
        }

		inline Music& Update() {
			::UpdateMusicStream(*this);
        	return *this;
		}

		inline Music& Stop() {
			::StopMusicStream(*this);
        	return *this;
		}

		inline Music& Pause() {
			::PauseMusicStream(*this);
        	return *this;
		}
		inline Music& Resume() {
			::ResumeMusicStream(*this);
        	return *this;
		}
		inline bool IsPlaying() {
			return ::IsMusicPlaying(*this);
		}
		inline Music& SetVolume(float volume) {
			::SetMusicVolume(*this, volume);
        	return *this;
		}
		inline Music& SetPitch(float pitch) {
			::SetMusicPitch(*this, pitch);
        	return *this;
		}
		inline Music& SetLoopCount(int count)  {
			::SetMusicLoopCount(*this, count);
        	return *this;
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
