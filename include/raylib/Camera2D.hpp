#ifndef RAYLIB_CPP_CAMERA_HPP_
#define RAYLIB_CPP_CAMERA_HPP_

#ifdef __cplusplus
extern "C"{
#endif
#include "raylib.h"
#ifdef __cplusplus
}
#endif

#include "Vector2.hpp"
#include "utils.hpp"

namespace raylib {
	class Camera2D : public ::Camera2D {
	public:
		Camera2D(::Vector2 offsetValue, ::Vector2 targetValue, float rotationValue = 0, float zoomValue = 1) {
			offset = offsetValue;
			target = targetValue;
			rotation = rotationValue;
			zoom = zoomValue;
		};

		inline void set(const ::Camera2D& camera) {
			offset = camera.offset;
			target = camera.target;
			rotation = camera.rotation;
			zoom = camera.zoom;
		}

		inline void set(const Camera2D& camera) {
			offset = camera.offset;
			target = camera.target;
			rotation = camera.rotation;
			zoom = camera.zoom;
		}

		inline Camera2D& BeginMode2D() {
			::BeginMode2D(*this);
			return *this;
		}
		inline Camera2D& EndMode2D() {
			::EndMode2D();
			return *this;
		}

		GETTERSETTER(Vector2,Offset,offset)
		GETTERSETTER(Vector2,Target,target)
		GETTERSETTER(float,Rotation,rotation)
		GETTERSETTER(float,Zoom,zoom)

		Camera2D& operator=(const ::Camera2D& camera) {
			set(camera);
			return *this;
		}

		Camera2D& operator=(const Camera2D& camera) {
			set(camera);
			return *this;
		}

		inline Matrix GetMatrix() {
			return ::GetCameraMatrix2D(*this);
		}
		inline Vector2 GetWorldToScreen2D(Vector2 position) {
			return ::GetWorldToScreen2D(position, *this);
		}
		inline Vector2 GetScreenToWorld2D(Vector2 position) {
			return ::GetScreenToWorld2D(position, *this);
		}
	};
}

#endif
