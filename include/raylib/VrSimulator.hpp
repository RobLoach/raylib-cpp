#ifndef RAYLIB_CPP_VRSIMULATOR_HPP_
#define RAYLIB_CPP_VRSIMULATOR_HPP_

#include "raylib.h"
#include "utils.hpp"

namespace raylib {
	class VrSimulator {
	public:
		VrSimulator() {
			Init();
		};
		VrSimulator(VrDeviceInfo info, Shader distortion) {
			Init();
			Set(info, distortion);
		};

		void Init() {
			InitVrSimulator();
		}

		~VrSimulator() {
			CloseVrSimulator();
		}

		bool IsReady() {
			return IsVrSimulatorReady();
		}

		void Update(Camera *camera) {
			UpdateVrTracking(camera);
		}
		void Set(VrDeviceInfo info, Shader distortion) {
			SetVrConfiguration(info, distortion);
		}
		void Toggle(void) {
			ToggleVrMode();
		}
		void Begin(void) {
			BeginVrDrawing();
		}
		void End() {
			EndVrDrawing();
		}
	};
}

#endif
