#ifndef RAYLIB_CPP_CAMERA_HPP_
#define RAYLIB_CPP_CAMERA_HPP_

#include "raylib.h"
#include "Vector3.hpp"
#include "utils.hpp"

namespace raylib {
	class Camera3D : public ::Camera3D {
	public:
		Camera3D(::Vector3 positionValue, ::Vector3 targetValue, ::Vector3 upValue, float fovyValue = 0, int typeValue = 0) {
			position = positionValue;
			target = targetValue;
			up = upValue;
			fovy = fovyValue;
			type = typeValue;
		};

		inline void set(const ::Camera3D& camera) {
			position = camera.position;
			target = camera.target;
			up = camera.up;
			fovy = camera.fovy;
			type = camera.type;
		}

		inline void set(const Camera3D& camera) {
			position = camera.position;
			target = camera.target;
			up = camera.up;
			fovy = camera.fovy;
			type = camera.type;
		}

		void BeginMode3D() {
			::BeginMode3D(*this);
		}
		void EndMode3D() {
			::EndMode3D();
		}

		Matrix GetCameraMatrix() {
			return ::GetCameraMatrix(*this);
		}

		void SetCameraMode(int mode) {
			::SetCameraMode(*this, mode);
		}

		void UpdateCamera() {
			::UpdateCamera(this);
		}

		void UpdateVrTracking() {
			::UpdateVrTracking(this);
		}

		GETTERSETTER(Vector3,Position,position)
		GETTERSETTER(Vector3,Target,target)
		GETTERSETTER(Vector3,Up,up)
		GETTERSETTER(float,Fovy,fovy)
		GETTERSETTER(int,Type,type)

        Camera3D& operator=(const ::Camera3D& camera) {
            set(camera);
            return *this;
        }

        Camera3D& operator=(const Camera3D& camera) {
            set(camera);
            return *this;
        }

	};

	typedef Camera3D Camera;
}

#endif
