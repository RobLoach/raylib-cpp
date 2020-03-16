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

		inline void Draw(::Color color) {
			::DrawRectangle(static_cast<int>(x), static_cast<int>(y), static_cast<int>(width), static_cast<int>(height), color);
		}
		inline void Draw(::Vector2 origin, float rotation, ::Color color) {
			::DrawRectanglePro(*this, origin, rotation, color);
		}

		inline void DrawGradientV(::Color color1, ::Color color2){
			::DrawRectangleGradientH(static_cast<int>(x), static_cast<int>(y), static_cast<int>(width), static_cast<int>(height), color1, color2);
		}
		inline void DrawGradientH(::Color color1, ::Color color2) {
			::DrawRectangleGradientH(static_cast<int>(x), static_cast<int>(y), static_cast<int>(width), static_cast<int>(height), color1, color2);
		}
		inline void DrawGradient(::Color col1, ::Color col2, ::Color col3, ::Color col4) {
			::DrawRectangleGradientEx(*this, col1, col2, col3, col4);
		}
		inline void DrawLines(::Color color){
			::DrawRectangleLines(static_cast<int>(x), static_cast<int>(y), static_cast<int>(width), static_cast<int>(height), color);
		}
		inline void DrawLinesEx(int lineThick, ::Color color){
			::DrawRectangleLinesEx(*this, lineThick, color);
		}
		inline void DrawRounded(float roundness, int segments, ::Color color){
			::DrawRectangleRounded(*this, roundness, segments, color);
		}
		inline void DrawRoundedLines(float roundness, int segments, int lineThick, ::Color color) {
			::DrawRectangleRoundedLines(*this, roundness, segments, lineThick, color);
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
