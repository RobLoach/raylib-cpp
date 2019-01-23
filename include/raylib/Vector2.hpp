#ifndef RAYLIB_CPP_VECTOR2_HPP_
#define RAYLIB_CPP_VECTOR2_HPP_

#include "raylib.h"
#include "utils.hpp"

namespace raylib {
	class Vector2 : public ::Vector2 {
	public:
		Vector2(float X = 0, float Y = 0) {
			x = X;
			y = Y;
		};

		GETTERSETTER(float,X,x)
		GETTERSETTER(float,Y,y)
	};
}

#endif