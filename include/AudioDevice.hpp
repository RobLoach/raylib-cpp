#ifndef RAYLIB_CPP_AUDIODEVICE_HPP_
#define RAYLIB_CPP_AUDIODEVICE_HPP_

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
	 * Audio device management functions.
	 */
	class AudioDevice {
	public:
		/**
		 * Initialize audio device and context.
		 *
		 * @param lateInit Whether or not to post-pone initializing the context.
		 */
		AudioDevice(bool lateInit = false) {
			if (!lateInit) {
				Init();
			}
		};

		~AudioDevice() {
			Close();
		};

		/**
		 * Initialize audio device and context.
		 */
		inline AudioDevice& Init() {
			::InitAudioDevice();
			return *this;
		}

		/**
		 * Close the audio device and context.
		 */
		inline AudioDevice& Close() {
			::CloseAudioDevice();
			return *this;
		}

		/**
		 * Check if audio device has been initialized successfully.
		 */
		inline bool IsReady() {
			return ::IsAudioDeviceReady();
		}

		/**
		 * Set master volume (listener).
		 */
		inline AudioDevice& SetVolume(float volume) {
			::SetMasterVolume(volume);
			return *this;
		}
	};
}

#endif
