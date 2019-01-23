#ifndef RAYLIB_CPP_COLOR_HPP_
#define RAYLIB_CPP_COLOR_HPP_

#include "raylib.h"
#include "utils.hpp"

namespace raylib {
	class Color : public ::Color {
	public:
		Color(unsigned char red = 0, unsigned char green = 0, unsigned char blue = 0, unsigned char alpha = 255) {
			r = red;
			g = green;
			b = blue;
			a = alpha;
		};

		void set(::Color color) {
			r = color.r;
			g = color.g;
			b = color.b;
			a = color.a;
		}

		GETTERSETTER(unsigned char,R,r)
		GETTERSETTER(unsigned char,G,g)
		GETTERSETTER(unsigned char,B,b)
		GETTERSETTER(unsigned char,A,a)
	};
}

#endif