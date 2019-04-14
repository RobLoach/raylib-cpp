#ifndef RAYLIB_CPP_VECTOR3_HPP_
#define RAYLIB_CPP_VECTOR3_HPP_

#include "raylib.h"
#include "utils.hpp"

namespace raylib {
	class Vector3 : public ::Vector3 {
	public:
		Vector3(::Vector3 vec) {
			set(vec);
		};
		Vector3(float X = 0, float Y = 0, float Z = 0) {
			x = X;
			y = Y;
			z = Z;
		};
		inline void set(::Vector3 vec) {
			x = vec.x;
			y = vec.y;
			z = vec.z;
		}

		GETTERSETTER(float,X,x)
		GETTERSETTER(float,Y,y)
		GETTERSETTER(float,Z,z)
	};
}

#endif
