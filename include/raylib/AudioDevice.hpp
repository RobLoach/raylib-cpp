#ifndef RAYLIB_CPP_AUDIODEVICE_HPP_
#define RAYLIB_CPP_AUDIODEVICE_HPP_

#include "raylib.h"
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

		inline void Init() {
			InitAudioDevice();
		}

		inline void Close() {
			CloseAudioDevice();
		}

		inline bool IsReady() {
			return IsAudioDeviceReady();
		}

		inline void SetVolume(float volume) {
			SetMasterVolume(volume);
		}
	};
}

#endif
