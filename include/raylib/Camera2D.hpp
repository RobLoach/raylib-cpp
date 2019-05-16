#ifndef RAYLIB_CPP_CAMERA_HPP_
#define RAYLIB_CPP_CAMERA_HPP_

#include "raylib.h"
#include "Vector2.hpp"
#include "utils.hpp"

namespace raylib {
	class Camera2D : public ::Camera2D {
	public:
		Camera2D(Vector2 offsetValue, Vector2 targetValue, float rotationValue, float zoomValue) {
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

		void BeginMode2D() {
			::BeginMode2D(*this);
		}
		void EndMode2D() {
			::EndMode2D();
		}

		GETTERSETTER(Vector2,Offset,offset)
		GETTERSETTER(Vector2,Target,target)
		GETTERSETTER(float,Rotation,rotation)
		GETTERSETTER(float,Zoom,zoom)

        Camera2D& operator=(const ::Camera2D& camera) {
            set(color);
            return *this;
        }

        Camera2D& operator=(const Camera2D& camera) {
            set(camera);
            return *this;
        }

	};
}

#endif