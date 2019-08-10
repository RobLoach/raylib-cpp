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

		void Init() {
			InitAudioDevice();
		}

		void Close() {
			CloseAudioDevice();
		}

		static bool IsReady() {
			return IsAudioDeviceReady();
		}

		void SetVolume(float volume) {
			SetMasterVolume(volume);
		}
	};
}

#endif
