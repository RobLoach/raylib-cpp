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

		inline void DrawPixel(::Color color) {
			::DrawPixelV(*this, color);
		}

		inline void DrawLine(::Vector2 endPos, ::Color color) {
			::DrawLineV(*this, endPos, color);
		}

		inline void DrawLine(::Vector2 endPos, float thick, ::Color color) {
			::DrawLineEx(*this, endPos, thick, color);
		}

		inline void DrawLineBezier(::Vector2 endPos, float thick, ::Color color) {
			::DrawLineBezier(*this, endPos, thick, color);
		}

		inline void DrawCircle(float radius, ::Color color) {
			::DrawCircleV(*this, radius, color);
		}

		inline void DrawRectangle(::Vector2 size, ::Color color) {
			::DrawRectangleV(*this, size, color);
		}

		inline void DrawPoly(int sides, float radius, float rotation, ::Color color) {
			::DrawPoly(*this, sides, radius, rotation, color);
		}
	};
}

#endif
