#ifndef RAYLIB_CPP_RAY_HPP_
#define RAYLIB_CPP_RAY_HPP_

#include "raylib.h"
#include "utils.hpp"

#include "RayHitInfo.hpp"

namespace raylib {
	class Ray : public ::Ray {
	public:
		Ray(::Ray ray) {
			set(ray);
		};

		Ray(::Vector3 Position, ::Vector3 Direction) {
			position = Position;
			direction = Direction;
		};

		Ray(::Vector2 mousePosition, ::Camera camera) {
			set(GetMouseRay(mousePosition, camera));
		}

		inline void set(::Ray ray) {
			position = ray.position;
			direction = ray.direction;
		}

        Ray& operator=(const ::Ray& ray) {
            set(ray);
            return *this;
        }

        Ray& operator=(const Ray& ray) {
            set(ray);
            return *this;
        }

		GETTERSETTER(::Vector3,Position,position)
		GETTERSETTER(::Vector3,Direction,direction)

		void Draw(::Color color) {
			DrawRay(*this, color);
		}

		bool CheckCollisionSphere(::Vector3 center, float radius) {
			return CheckCollisionRaySphere(*this, center, radius);
		}

		bool CheckCollisionSphereEx(::Vector3 center, float radius, ::Vector3 *collisionPoint) {
			return CheckCollisionRaySphereEx(*this, center, radius, collisionPoint);
		}

		bool CheckCollisionBox(::BoundingBox box) {
			return CheckCollisionRayBox(*this, box);
		}

		RayHitInfo GetCollisionModel(::Model model) {
			return GetCollisionRayModel(*this, model);
		}

		RayHitInfo GetCollisionTriangle(::Vector3 p1, ::Vector3 p2, ::Vector3 p3) {
			return GetCollisionRayTriangle(*this, p1, p2, p3);
		}

		RayHitInfo GetCollisionGround(float groundHeight) {
			return GetCollisionRayGround(*this, groundHeight);
		}
	};
}

#endif
