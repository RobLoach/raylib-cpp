#ifndef RAYLIB_CPP_VRSIMULATOR_HPP_
#define RAYLIB_CPP_VRSIMULATOR_HPP_

#ifdef __cplusplus
extern "C"{
#endif
#include "raylib.h"
#ifdef __cplusplus
}
#endif

#include "./raylib-cpp-utils.hpp"

namespace raylib {
	class VrSimulator {
	public:
		VrSimulator() {
			Init();
		};
		VrSimulator(::VrDeviceInfo info, ::Shader distortion) {
			Init();
			Set(info, distortion);
		};

		inline void Init() {
			InitVrSimulator();
		}

		~VrSimulator() {
			Close();
		}

		inline bool IsReady() const {
			return ::IsVrSimulatorReady();
		}

		inline VrSimulator& Update(Camera *camera) {
			::UpdateVrTracking(camera);
			return *this;
		}
		inline VrSimulator& Set(::VrDeviceInfo info, ::Shader distortion) {
			::SetVrConfiguration(info, distortion);
			return *this;
		}
		inline VrSimulator& Toggle() {
			::ToggleVrMode();
			return *this;
		}
		inline VrSimulator& Begin() {
			::BeginVrDrawing();
			return *this;
		}
		inline VrSimulator& End() {
			::EndVrDrawing();
			return *this;
		}
		inline void Close() {
			::CloseVrSimulator();
		}
	};
}

#endif
