#ifndef RAYLIB_CPP_RAYHITINFO_HPP_
#define RAYLIB_CPP_RAYHITINFO_HPP_

#include "raylib.h"
#include "utils.hpp"

namespace raylib {
	class RayHitInfo : public ::RayHitInfo {
	public:
		RayHitInfo(::RayHitInfo ray) {
			set(ray);
		};

		RayHitInfo(bool Hit, float Distance, ::Vector3 Position, ::Vector3 Normal) {
			hit = Hit;
			distance = Distance;
			position = Position;
			normal = Normal;
		};

        RayHitInfo& operator=(const ::RayHitInfo& ray) {
            set(ray);
            return *this;
        }

        RayHitInfo& operator=(const RayHitInfo& ray) {
            set(ray);
            return *this;
        }

		inline void set(::RayHitInfo ray) {
			hit = ray.hit;
			distance = ray.distance;
			position = ray.position;
			normal = ray.normal;
		}

		GETTERSETTER(bool,Hit,hit)
		GETTERSETTER(float,Distance,distance)
		GETTERSETTER(::Vector3,Position,position)
		GETTERSETTER(::Vector3,Normal,normal)
	};
}

#endif
