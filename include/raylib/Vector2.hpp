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

		void DrawPixel(::Color color) {
			DrawPixelV(*this, color);
		}

		void DrawLine(::Vector2 endPos, ::Color color) {
			DrawLineV(*this, endPos, color);
		}

		void DrawLine(::Vector2 endPos, float thick, ::Color color) {
			DrawLineEx(*this, endPos, thick, color);
		}

		void DrawCircle(float radius, ::Color color) {
			DrawCircleV(*this, radius, color);
		}

		void DrawRectangle(::Vector2 size, ::Color color) {
			DrawRectangleV(*this, size, color);
		}

		void DrawPoly(int sides, float radius, float rotation, ::Color color) {
			::DrawPoly(*this, sides, radius, rotation, color);
		}
	};
}

#endif
