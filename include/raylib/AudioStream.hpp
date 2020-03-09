#ifndef RAYLIB_CPP_AUDIOSTREAM_HPP_
#define RAYLIB_CPP_AUDIOSTREAM_HPP_

#include "raylib.h"
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

        void Update(const void *data, int samplesCount) {
        	UpdateAudioStream(*this, data, samplesCount);
        }

        void Close() {
        	CloseAudioStream(*this);
        }
        bool IsProcessed() {
        	return ::IsAudioStreamProcessed(*this);
        }
		void Play() {
			PlayAudioStream(*this);
		}
		void Pause() {
			PauseAudioStream(*this);
		}
		void Resume() {
			ResumeAudioStream(*this);
		}
		bool IsPlaying() {
			return IsAudioStreamPlaying(*this);
		}
		void Stop() {
			StopAudioStream(*this);
		}
		void SetVolume(float volume) {
			SetAudioStreamVolume(*this, volume);
		}
		void SetPitch(float pitch) {
			SetAudioStreamPitch(*this, pitch);
		}

	};
}

#endif
