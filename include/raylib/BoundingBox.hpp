#ifndef RAYLIB_CPP_BOUNDINGBOX_HPP_
#define RAYLIB_CPP_BOUNDINGBOX_HPP_

#include "raylib.h"
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

		void Draw(::Color color) {
			DrawBoundingBox(*this, color);
		}

		bool CheckCollision(::BoundingBox box2) {
			CheckCollisionBoxes(*this, box2);
		}

		bool CheckCollision(::Vector3 center, float radius) {
			CheckCollisionBoxSphere(*this, center, radius);
		}
	};
}

#endif