#ifndef RAYLIB_CPP_RECTANGLE_HPP_
#define RAYLIB_CPP_RECTANGLE_HPP_

#include "raylib.h"
#include "utils.hpp"

namespace raylib {
	class Rectangle : public ::Rectangle {
	public:
		Rectangle(::Rectangle vec) {
			set(vec);
		};
		Rectangle() {};
		Rectangle(float X = 0, float Y = 0, float Width = 0, float Height = 0) {
			x = X;
			y = Y;
			width = Width;
			height = Height;
		};
		inline void set(::Rectangle rect) {
			x = rect.x;
			y = rect.y;
			width = rect.width;
			height = rect.height;
		}

		GETTERSETTER(float,X,x)
		GETTERSETTER(float,Y,y)
		GETTERSETTER(float,Width,width)
		GETTERSETTER(float,Height,height)

		void Draw(::Color color) {
			DrawRectangle(x, y, width, height, color);
		}
		void DrawLines(::Color color) {
			DrawRectangleLines(x, y, width, height, color);
		}
	};
}

#endif