#ifndef RAYLIB_CPP_RECTANGLE_HPP_
#define RAYLIB_CPP_RECTANGLE_HPP_

#ifdef __cplusplus
extern "C"{
#endif
#include "raylib.h"
#ifdef __cplusplus
}
#endif

#include "utils.hpp"

namespace raylib {
	class Rectangle : public ::Rectangle {
	public:
		Rectangle(::Rectangle vec) {
			set(vec);
		};
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

        Rectangle& operator=(const ::Rectangle& rect) {
            set(rect);
            return *this;
        }

        Rectangle& operator=(const Rectangle& rect) {
            set(rect);
            return *this;
        }

		inline Rectangle& Draw(::Color color) {
			::DrawRectangle(static_cast<int>(x), static_cast<int>(y), static_cast<int>(width), static_cast<int>(height), color);
			return *this;
		}
		inline Rectangle& Draw(::Vector2 origin, float rotation, ::Color color) {
			::DrawRectanglePro(*this, origin, rotation, color);
			return *this;
		}

		inline Rectangle& DrawGradientV(::Color color1, ::Color color2){
			::DrawRectangleGradientH(static_cast<int>(x), static_cast<int>(y), static_cast<int>(width), static_cast<int>(height), color1, color2);
			return *this;
		}
		inline Rectangle& DrawGradientH(::Color color1, ::Color color2) {
			::DrawRectangleGradientH(static_cast<int>(x), static_cast<int>(y), static_cast<int>(width), static_cast<int>(height), color1, color2);
			return *this;
		}
		inline Rectangle& DrawGradient(::Color col1, ::Color col2, ::Color col3, ::Color col4) {
			::DrawRectangleGradientEx(*this, col1, col2, col3, col4);
			return *this;
		}
		inline Rectangle& DrawLines(::Color color){
			::DrawRectangleLines(static_cast<int>(x), static_cast<int>(y), static_cast<int>(width), static_cast<int>(height), color);
			return *this;
		}
		inline Rectangle& DrawLinesEx(int lineThick, ::Color color){
			::DrawRectangleLinesEx(*this, lineThick, color);
			return *this;
		}
		inline Rectangle& DrawRounded(float roundness, int segments, ::Color color){
			::DrawRectangleRounded(*this, roundness, segments, color);
			return *this;
		}
		inline Rectangle& DrawRoundedLines(float roundness, int segments, int lineThick, ::Color color) {
			::DrawRectangleRoundedLines(*this, roundness, segments, lineThick, color);
			return *this;
		}

		inline bool CheckCollision(::Rectangle rec2) {
			return ::CheckCollisionRecs(*this, rec2);
		}
		inline Rectangle GetCollision(::Rectangle rec2) {
			return ::GetCollisionRec(*this, rec2);
		}
		inline bool CheckCollision(::Vector2 point) {
			return ::CheckCollisionPointRec(point, *this);
		}
	};
}

#endif
