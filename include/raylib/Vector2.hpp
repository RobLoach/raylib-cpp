#ifndef RAYLIB_CPP_VECTOR2_HPP_
#define RAYLIB_CPP_VECTOR2_HPP_

#ifdef __cplusplus
extern "C"{
#endif
#include "raylib.h"
#ifdef __cplusplus
}
#endif

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

        Vector2& operator=(const ::Vector2& vector2) {
            set(vector2);
            return *this;
        }

        Vector2& operator=(const Vector2& vector2) {
            set(vector2);
            return *this;
        }

		inline Vector2& DrawPixel(::Color color) {
			::DrawPixelV(*this, color);
			return *this;
		}

		inline Vector2& DrawLine(::Vector2 endPos, ::Color color) {
			::DrawLineV(*this, endPos, color);
			return *this;
		}

		inline Vector2& DrawLine(::Vector2 endPos, float thick, ::Color color) {
			::DrawLineEx(*this, endPos, thick, color);
			return *this;
		}

		inline Vector2& DrawLineBezier(::Vector2 endPos, float thick, ::Color color) {
			::DrawLineBezier(*this, endPos, thick, color);
			return *this;
		}

		inline Vector2& DrawCircle(float radius, ::Color color) {
			::DrawCircleV(*this, radius, color);
			return *this;
		}

		inline Vector2& DrawRectangle(::Vector2 size, ::Color color) {
			::DrawRectangleV(*this, size, color);
			return *this;
		}

		inline Vector2& DrawPoly(int sides, float radius, float rotation, ::Color color) {
			::DrawPoly(*this, sides, radius, rotation, color);
			return *this;
		}
	};
}

#endif
