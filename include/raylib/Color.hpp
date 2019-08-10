#ifndef RAYLIB_CPP_COLOR_HPP_
#define RAYLIB_CPP_COLOR_HPP_

#include <string>

#include "raylib.h"
#include "Vector4.hpp"
#include "utils.hpp"

namespace raylib {
	class Color : public ::Color {
	public:
		Color() {
			r = 0;
			g = 0;
			b = 0;
			a = 255;
		}
		Color(::Color color) {
			r = color.r;
			g = color.g;
			b = color.b;
			a = color.a;
		}
		Color(unsigned char red, unsigned char green, unsigned char blue, unsigned char alpha = 255) {
			r = red;
			g = green;
			b = blue;
			a = alpha;
		};
		Color(::Vector3 hsv) {
			set(::ColorFromHSV(hsv));
		};
		Color(int hexValue) {
			set(::GetColor(hexValue));
		};

		inline void set(const ::Color& color) {
			r = color.r;
			g = color.g;
			b = color.b;
			a = color.a;
		}

		inline void set(const Color& color) {
			r = color.r;
			g = color.g;
			b = color.b;
			a = color.a;
		}

		int ToInt() {
			return ::ColorToInt(*this);
		}

		operator int() const { return ::ColorToInt(*this); }

		Color Fade(float alpha) {
			Color a;
			a.set(::Fade(*this, alpha));
			return a;
		}

		Vector4 Normalize() {
			return ::ColorNormalize(*this);
		}

		Vector3 ToHSV() {
			return ::ColorToHSV(*this);
		}

		GETTERSETTER(unsigned char,R,r)
		GETTERSETTER(unsigned char,G,g)
		GETTERSETTER(unsigned char,B,b)
		GETTERSETTER(unsigned char,A,a)

		Color& operator=(const ::Color& color) {
			set(color);
			return *this;
		}

		Color& operator=(const Color& color) {
			set(color);
			return *this;
		}

		void ClearBackground() {
			::ClearBackground(*this);
		}

		void DrawPixel(int x, int y) {
			::DrawPixel(x, y, *this);
		}

		void DrawPixel(::Vector2 pos) {
			::DrawPixelV(pos, *this);
		}

		void DrawText(const std::string& text, int posX, int posY, int fontSize) {
			::DrawText(text.c_str(), posX, posY, fontSize, *this);
		}
		void DrawText(::Font font, const std::string& text, ::Vector2 position, float fontSize, float spacing) {
			::DrawTextEx(font, text.c_str(), position, fontSize, spacing, *this);
		}

		void DrawText(::Font font, const std::string& text, ::Rectangle rec, float fontSize, float spacing, bool wordWrap = false) {
			::DrawTextRec(font, text.c_str(), rec, fontSize, spacing, wordWrap, *this);
		}

		void DrawRectangleLines(int posX, int posY, int width, int height) {
			::DrawRectangleLines(posX, posY, width, height, *this);
		}

		void DrawRectangleLines(Rectangle rec, int lineThick) {
			::DrawRectangleLinesEx(rec, lineThick, *this);
		}

	};
}

#endif
