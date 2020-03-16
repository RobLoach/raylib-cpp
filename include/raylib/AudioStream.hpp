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

        inline void Update(const void *data, int samplesCount) {
        	::UpdateAudioStream(*this, data, samplesCount);
        }

        inline void Close() {
        	::CloseAudioStream(*this);
        }
        inline bool IsProcessed() {
        	return ::IsAudioStreamProcessed(*this);
        }
		inline void Play() {
			::PlayAudioStream(*this);
		}
		inline void Pause() {
			::PauseAudioStream(*this);
		}
		inline void Resume() {
			::ResumeAudioStream(*this);
		}
		inline bool IsPlaying() {
			return ::IsAudioStreamPlaying(*this);
		}
		inline void Stop() {
			::StopAudioStream(*this);
		}
		inline void SetVolume(float volume) {
			::SetAudioStreamVolume(*this, volume);
		}
		inline void SetPitch(float pitch) {
			::SetAudioStreamPitch(*this, pitch);
		}
		inline void SetBufferSizeDefault(int size) {
			::SetAudioStreamBufferSizeDefault(size);
		}

	};
}

#endif
