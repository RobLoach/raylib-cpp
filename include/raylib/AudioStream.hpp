#ifndef RAYLIB_CPP_AUDIOSTREAM_HPP_
#define RAYLIB_CPP_AUDIOSTREAM_HPP_

#ifdef __cplusplus
extern "C"{
#endif
#include "raylib.h"
#ifdef __cplusplus
}
#endif

#include "utils.hpp"

namespace raylib {
	class AudioStream : public ::AudioStream {
	public:
		AudioStream(::AudioStream music) {
			set(music);
		};

		AudioStream(unsigned int SampleRate, unsigned int SampleSize, unsigned int Channels) {
			set(InitAudioStream(SampleRate, SampleSize, Channels));
		}

		~AudioStream() {
			Close();
		}

		inline void set(::AudioStream stream) {
			sampleRate = stream.sampleRate;
			sampleSize = stream.sampleSize;
			channels = stream.channels;
			buffer = stream.buffer;
		}

		GETTERSETTER(unsigned int,SampleRate,sampleRate)
		GETTERSETTER(unsigned int,SampleSize,sampleSize)
		GETTERSETTER(unsigned int,Channels,channels)

        AudioStream& operator=(const ::AudioStream& stream) {
            set(stream);
            return *this;
        }

        AudioStream& operator=(const AudioStream& stream) {
            set(stream);
            return *this;
        }

        inline AudioStream& Update(const void *data, int samplesCount) {
        	::UpdateAudioStream(*this, data, samplesCount);
        	return *this;
        }

        inline AudioStream& Close() {
        	::CloseAudioStream(*this);
        	return *this;
        }
        inline bool IsProcessed() {
        	return ::IsAudioStreamProcessed(*this);
        }
		inline AudioStream& Play() {
			::PlayAudioStream(*this);
        	return *this;
		}
		inline AudioStream& Pause() {
			::PauseAudioStream(*this);
        	return *this;
		}
		inline AudioStream& Resume() {
			::ResumeAudioStream(*this);
        	return *this;
		}
		inline bool IsPlaying() {
			return ::IsAudioStreamPlaying(*this);
		}
		inline AudioStream& Stop() {
			::StopAudioStream(*this);
        	return *this;
		}
		inline AudioStream& SetVolume(float volume) {
			::SetAudioStreamVolume(*this, volume);
        	return *this;
		}
		inline AudioStream& SetPitch(float pitch) {
			::SetAudioStreamPitch(*this, pitch);
        	return *this;
		}
		inline AudioStream& SetBufferSizeDefault(int size) {
			::SetAudioStreamBufferSizeDefault(size);
        	return *this;
		}

	};
}

#endif
