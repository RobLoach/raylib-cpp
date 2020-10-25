#ifndef RAYLIB_CPP_BOUNDINGBOX_HPP_
#define RAYLIB_CPP_BOUNDINGBOX_HPP_

#ifdef __cplusplus
extern "C"{
#endif
#include "raylib.h"
#ifdef __cplusplus
}
#endif

#include "./raylib-cpp-utils.hpp"

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

		inline BoundingBox& Draw(::Color color = WHITE) {
			DrawBoundingBox(*this, color);
			return *this;
		}

		inline bool CheckCollision(::BoundingBox box2) const {
			return CheckCollisionBoxes(*this, box2);
		}

		inline bool CheckCollision(::Vector3 center, float radius) const {
			return CheckCollisionBoxSphere(*this, center, radius);
		}

		inline bool CheckCollision(::Ray ray) const {
			return CheckCollisionRayBox(ray, *this);
		}

	protected:
		inline void set(::BoundingBox box) {
			min = box.min;
			max = box.max;
		}
	};
}

#endif
