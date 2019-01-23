#ifndef RAYLIB_CPP_AUDIODEVICE_HPP_
#define RAYLIB_CPP_AUDIODEVICE_HPP_

#include <string>
#include "raylib.h"

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
	};
}

#endif
