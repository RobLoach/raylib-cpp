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

		inline void Init() {
			InitVrSimulator();
		}

		~VrSimulator() {
			Close();
		}

		inline bool IsReady() {
			return IsVrSimulatorReady();
		}

		inline void Update(Camera *camera) {
			UpdateVrTracking(camera);
		}
		inline void Set(VrDeviceInfo info, Shader distortion) {
			SetVrConfiguration(info, distortion);
		}
		inline void Toggle() {
			ToggleVrMode();
		}
		inline void Begin() {
			BeginVrDrawing();
		}
		inline void End() {
			EndVrDrawing();
		}
		inline void Close() {
			CloseVrSimulator();
		}
	};
}

#endif
