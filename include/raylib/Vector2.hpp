#ifndef RAYLIB_CPP_VECTOR2_HPP_
#define RAYLIB_CPP_VECTOR2_HPP_

#include "raylib.h"
#include "utils.hpp"

namespace raylib {
	class Vector2 : public ::Vector2 {
	public:
		Vector2(::Vector2 vec) {
			set(vec);
		};
		Vector2(float X = 0, float Y = 0) {
			x = X;
			y = Y;
		};
		inline void set(::Vector2 vec) {
			x = vec.x;
			y = vec.y;
		}

		GETTERSETTER(float,X,x)
		GETTERSETTER(float,Y,y)
	};
}

#endif