#ifndef RAYLIB_CPP_BOUNDINGBOX_HPP_
#define RAYLIB_CPP_BOUNDINGBOX_HPP_

#ifdef __cplusplus
extern "C"{
#endif
#include "raylib.h"
#ifdef __cplusplus
}
#endif

#include "utils.hpp"

namespace raylib {
	class BoundingBox : public ::BoundingBox {
	public:
		BoundingBox(::BoundingBox box) {
			set(box);
		};
		BoundingBox(::Mesh mesh) {
			set(MeshBoundingBox(mesh));
		}
		BoundingBox(::Vector3 Min, ::Vector3 Max) {
			min = Min;
			max = Max;
		};
		inline void set(::BoundingBox box) {
			min = box.min;
			max = box.max;
		}

		GETTERSETTER(::Vector3,Min,min)
		GETTERSETTER(::Vector3,Max,max)

        BoundingBox& operator=(const ::BoundingBox& box) {
            set(box);
            return *this;
        }

        BoundingBox& operator=(const BoundingBox& box) {
            set(box);
            return *this;
        }

		inline void Draw(::Color color = WHITE) {
			DrawBoundingBox(*this, color);
		}

		inline bool CheckCollision(::BoundingBox box2) {
			return CheckCollisionBoxes(*this, box2);
		}

		inline bool CheckCollision(::Vector3 center, float radius) {
			return CheckCollisionBoxSphere(*this, center, radius);
		}

		inline bool CheckCollision(::Ray ray) {
			return CheckCollisionRayBox(ray, *this);
		}
	};
}

#endif
