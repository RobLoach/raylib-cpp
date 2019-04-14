#ifndef RAYLIB_CPP_VECTOR4_HPP_
#define RAYLIB_CPP_VECTOR4_HPP_

#include "raylib.h"
#include "utils.hpp"

namespace raylib {
	class Vector4 : public ::Vector4 {
	public:
		Vector4(::Vector4 vec) {
			set(vec);
		};

		Vector4(float X = 0, float Y = 0, float Z = 0, float W = 0) {
			x = X;
			y = Y;
			z = Z;
			w = W;
		};

		inline void set(::Vector4 vec4) {
			x = vec4.x;
			y = vec4.y;
			z = vec4.z;
			w = vec4.w;
		}

		GETTERSETTER(float,X,x)
		GETTERSETTER(float,Y,y)
		GETTERSETTER(float,Z,z)
		GETTERSETTER(float,W,w)
	};
}

#endif
