#ifndef RAYLIB_CPP_CAMERA3D_HPP_
#define RAYLIB_CPP_CAMERA3D_HPP_

#ifdef __cplusplus
extern "C"{
#endif
#include "raylib.h"
#ifdef __cplusplus
}
#endif

#include "./Vector3.hpp"
#include "./raylib-cpp-utils.hpp"

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

		Camera3D() {}

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

		Camera3D& BeginMode3D() {
			::BeginMode3D(*this);
			return *this;
		}
		Camera3D& EndMode3D() {
			::EndMode3D();
			return *this;
		}

		inline Matrix GetMatrix() const {
			return ::GetCameraMatrix(*this);
		}

		inline Camera3D& SetMode(int mode) {
			::SetCameraMode(*this, mode);
			return *this;
		}

		inline Camera3D& SetAltControl(int altKey) {
			::SetCameraAltControl(altKey);
			return *this;
		}

		inline Camera3D& SetSmoothZoomControl(int szKey) {
			::SetCameraSmoothZoomControl(szKey);
			return *this;
		}

		inline Camera3D& SetMoveControls(int frontKey, int backKey, int rightKey, int leftKey, int upKey, int downKey) {
			::SetCameraMoveControls(frontKey, backKey, rightKey, leftKey, upKey, downKey);
			return *this;
		}

		inline Camera3D& Update() {
			::UpdateCamera(this);
			return *this;
		}

		inline Camera3D& UpdateVrTracking() {
			::UpdateVrTracking(this);
			return *this;
		}

		inline Ray GetMouseRay(::Vector2 mousePosition) const {
			return ::GetMouseRay(mousePosition, *this);
		}

		inline Vector2 GetWorldToScreen(::Vector3 position) const {
			return ::GetWorldToScreen(position, *this);
		}

		inline Camera3D& DrawBillboard(::Texture2D texture, ::Vector3 center, float size, ::Color tint = WHITE) {
			::DrawBillboard(*this, texture, center, size, tint);
			return *this;
		}

		inline Camera3D& DrawBillboard(Texture2D texture, Rectangle sourceRec, Vector3 center, float size, ::Color tint = WHITE) {
			::DrawBillboardRec(*this, texture, sourceRec, center, size, tint);
			return *this;
		}
	};

	typedef Camera3D Camera;
}

#endif
