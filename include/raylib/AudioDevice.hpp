#ifndef RAYLIB_CPP_AUDIODEVICE_HPP_
#define RAYLIB_CPP_AUDIODEVICE_HPP_

#ifdef __cplusplus
extern "C"{
#endif
#include "raylib.h"
#ifdef __cplusplus
}
#endif

#include "utils.hpp"

namespace raylib {
	class AudioDevice {
	public:
		AudioDevice(bool lateInit = false) {
			if (!lateInit) {
				Init();
			}
		};

		~AudioDevice() {
			Close();
		};

		inline AudioDevice& Init() {
			::InitAudioDevice();
			return *this;
		}

		inline AudioDevice& Close() {
			::CloseAudioDevice();
			return *this;
		}

		inline bool IsReady() {
			return ::IsAudioDeviceReady();
		}

		inline AudioDevice& SetVolume(float volume) {
			::SetMasterVolume(volume);
			return *this;
		}
	};
}

#endif
