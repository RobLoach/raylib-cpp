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

        Rectangle& operator=(const ::Rectangle& rect) {
            set(rect);
            return *this;
        }

        Rectangle& operator=(const Rectangle& rect) {
            set(rect);
            return *this;
        }

		void Draw(::Color color) {
			DrawRectangle(x, y, width, height, color);
		}
		void Draw(::Vector2 origin, float rotation, ::Color color) {
			::DrawRectanglePro(*this, origin, rotation, color);
		}

		void DrawGradientV(::Color color1, ::Color color2){
			::DrawRectangleGradientH(x, y, width, height, color1, color2);
		}
		void DrawGradientH(::Color color1, ::Color color2) {
			::DrawRectangleGradientH(x, y, width, height, color1, color2);
		}
		void DrawGradient(::Color col1, ::Color col2, ::Color col3, ::Color col4) {
			::DrawRectangleGradientEx(*this, col1, col2, col3, col4);
		}
		void DrawLines(::Color color){
			::DrawRectangleLines(x, y, width, height, color);
		}
		void DrawLinesEx(int lineThick, ::Color color){
			::DrawRectangleLinesEx(*this, lineThick, color);
		}
		void DrawRounded(float roundness, int segments, ::Color color){
			::DrawRectangleRounded(*this, roundness, segments, color);
		}
		void DrawRoundedLines(float roundness, int segments, int lineThick, ::Color color) {
			::DrawRectangleRoundedLines(*this, roundness, segments, lineThick, color);
		}

		bool CheckCollision(::Rectangle rec2) {
			return ::CheckCollisionRecs(*this, rec2);
		}
		Rectangle GetCollisionRec(::Rectangle rec2) {
			return ::GetCollisionRec(*this, rec2);
		}
		bool CheckCollisionPointRec(::Vector2 point) {
			return ::CheckCollisionPointRec(point, *this);
		}
	};
}

#endif
