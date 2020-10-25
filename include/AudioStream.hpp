#ifndef RAYLIB_CPP_AUDIOSTREAM_HPP_
#define RAYLIB_CPP_AUDIOSTREAM_HPP_

#ifdef __cplusplus
extern "C"{
#endif
#include "raylib.h"
#ifdef __cplusplus
}
#endif

#include "./raylib-cpp-utils.hpp"

namespace raylib {
	/**
	 * AudioStream management functions
	 */
	class AudioStream : public ::AudioStream {
	public:
		AudioStream(::AudioStream music) {
			set(music);
		};

		/**
		 * Init audio stream (to stream raw audio pcm data)
		 */
		AudioStream(unsigned int SampleRate, unsigned int SampleSize, unsigned int Channels) {
			set(InitAudioStream(SampleRate, SampleSize, Channels));
		}

		~AudioStream() {
			Close();
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

        /**
         * Update audio stream buffers with data
         */
        inline AudioStream& Update(const void *data, int samplesCount) {
        	::UpdateAudioStream(*this, data, samplesCount);
        	return *this;
        }

        /**
         * Close audio stream and free memory
         */
        inline AudioStream& Close() {
        	::CloseAudioStream(*this);
        	return *this;
        }

        /**
         * Check if any audio stream buffers requires refill
         */
        inline bool IsProcessed() {
        	return ::IsAudioStreamProcessed(*this);
        }

        /**
         * Play audio stream
         */
		inline AudioStream& Play() {
			::PlayAudioStream(*this);
        	return *this;
		}

		/**
		 * Pause audio stream
		 */
		inline AudioStream& Pause() {
			::PauseAudioStream(*this);
        	return *this;
		}

		/**
		 * Resume audio stream
		 */
		inline AudioStream& Resume() {
			::ResumeAudioStream(*this);
        	return *this;
		}

		/**
		 * Check if audio stream is playing
		 */
		inline bool IsPlaying() {
			return ::IsAudioStreamPlaying(*this);
		}

		/**
		 * Stop audio stream
		 */
		inline AudioStream& Stop() {
			::StopAudioStream(*this);
        	return *this;
		}

		/**
		 * Set volume for audio stream (1.0 is max level)
		 */
		inline AudioStream& SetVolume(float volume) {
			::SetAudioStreamVolume(*this, volume);
        	return *this;
		}

		/**
		 * Set pitch for audio stream (1.0 is base level)
		 */
		inline AudioStream& SetPitch(float pitch) {
			::SetAudioStreamPitch(*this, pitch);
        	return *this;
		}

		/**
		 * Default size for new audio streams
		 */
		inline AudioStream& SetBufferSizeDefault(int size) {
			::SetAudioStreamBufferSizeDefault(size);
        	return *this;
		}

	protected:
		inline void set(::AudioStream stream) {
			sampleRate = stream.sampleRate;
			sampleSize = stream.sampleSize;
			channels = stream.channels;
			buffer = stream.buffer;
		}

	};
}

#endif
