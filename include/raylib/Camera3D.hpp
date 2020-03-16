#ifndef RAYLIB_CPP_CAMERA3D_HPP_
#define RAYLIB_CPP_CAMERA3D_HPP_

#ifdef __cplusplus
extern "C"{
#endif
#include "raylib.h"
#ifdef __cplusplus
}
#endif

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

		void BeginMode3D() {
			::BeginMode3D(*this);
		}
		void EndMode3D() {
			::EndMode3D();
		}

		inline Matrix GetMatrix() {
			return ::GetCameraMatrix(*this);
		}

		inline void SetMode(int mode) {
			::SetCameraMode(*this, mode);
		}

		inline void SetAltControl(int altKey) {
			::SetCameraAltControl(altKey);
		}

		inline void SetSmoothZoomControl(int szKey) {
			::SetCameraSmoothZoomControl(szKey);
		}

		inline void SetMoveControls(int frontKey, int backKey, int rightKey, int leftKey, int upKey, int downKey) {
			::SetCameraMoveControls(frontKey, backKey, rightKey, leftKey, upKey, downKey);
		}

		inline void Update() {
			::UpdateCamera(this);
		}

		inline void UpdateVrTracking() {
			::UpdateVrTracking(this);
		}

		inline Ray GetMouseRay(::Vector2 mousePosition) {
			return ::GetMouseRay(mousePosition, *this);
		}

		inline Vector2 GetWorldToScreen(::Vector3 position) {
			return ::GetWorldToScreen(position, *this);
		}

		inline void DrawBillboard(::Texture2D texture, ::Vector3 center, float size, ::Color tint = WHITE) {
			::DrawBillboard(*this, texture, center, size, tint);
		}

		inline void DrawBillboard(Texture2D texture, Rectangle sourceRec, Vector3 center, float size, ::Color tint = WHITE) {
			::DrawBillboardRec(*this, texture, sourceRec, center, size, tint);
		}
	};

	typedef Camera3D Camera;
}

#endif
