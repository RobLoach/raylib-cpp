#ifndef RAYLIB_CPP_COLOR_HPP_
#define RAYLIB_CPP_COLOR_HPP_

#include <string>

#ifdef __cplusplus
extern "C"{
#endif
#include "raylib.h"
#ifdef __cplusplus
}
#endif

#include "./Vector4.hpp"
#include "./raylib-cpp-utils.hpp"

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
			set(::ColorFromHSV(hsv.x, hsv.y, hsv.z));
		};
		static Color FromHSV(float hue, float saturation, float value) {
			::Color color = ::ColorFromHSV(hue, saturation, value);
			return color;
		};
		Color(int hexValue) {
			set(::GetColor(hexValue));
		};
		Color(Vector4 normalized) {
			set(::ColorFromNormalized(normalized));
		}

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

		static Color LightGray;
		static Color Gray;
		static Color DarkGray;
		static Color Yellow;
		static Color Gold;
		static Color Orange;
		static Color Pink;
		static Color Red;
		static Color Maroon;
		static Color Green;
		static Color Lime;
		static Color DarkGreen;
		static Color SkyBlue;
		static Color Blue;
		static Color DarkBlue;
		static Color Purple;
		static Color Violet;
		static Color DarkPurple;
		static Color Beige;
		static Color Brown;
		static Color DarkBrown;
		static Color White;
		static Color Black;
		static Color Blank;
		static Color Magenta;
		static Color RayWhite;

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

		inline Color& ClearBackground() {
			::ClearBackground(*this);
			return *this;
		}

		inline Color& DrawPixel(int x, int y) {
			::DrawPixel(x, y, *this);
			return *this;
		}

		inline Color& DrawPixel(::Vector2 pos) {
			::DrawPixelV(pos, *this);
			return *this;
		}

		inline Color& DrawLine(int startPosX, int startPosY, int endPosX, int endPosY) {
			::DrawLine(startPosX, startPosY, endPosX, endPosY, *this);
			return *this;
		}
		inline Color& DrawLine(::Vector2 startPos, ::Vector2 endPos) {
			::DrawLineV(startPos, endPos, *this);
			return *this;
		}
		inline Color& DrawLine(::Vector2 startPos, ::Vector2 endPos, float thick) {
			::DrawLineEx(startPos, endPos, thick, *this);
			return *this;
		}
		inline Color& DrawLineBezier(::Vector2 startPos, Vector2 endPos, float thick) {
			::DrawLineBezier(startPos, endPos, thick, *this);
			return *this;
		}
		inline Color& DrawLineStrip(::Vector2 *points, int numPoints) {
			::DrawLineStrip(points, numPoints, *this);
			return *this;
		}

		inline Color& DrawText(const std::string& text, int posX, int posY, int fontSize) {
			::DrawText(text.c_str(), posX, posY, fontSize, *this);
			return *this;
		}
		inline Color& DrawText(::Font font, const std::string& text, ::Vector2 position, float fontSize, float spacing) {
			::DrawTextEx(font, text.c_str(), position, fontSize, spacing, *this);
			return *this;
		}

		inline Color& DrawText(::Font font, const std::string& text, ::Rectangle rec, float fontSize, float spacing, bool wordWrap = false) {
			::DrawTextRec(font, text.c_str(), rec, fontSize, spacing, wordWrap, *this);
			return *this;
		}

		inline Color& DrawRectangle(int posX, int posY, int width, int height) {
			::DrawRectangle(posX, posY, width, height, *this);
			return *this;
		}

		inline Color& DrawRectangle(Vector2 position, Vector2 size) {
			::DrawRectangleV(position, size, *this);
			return *this;
		}

		inline Color& DrawRectangle(Rectangle rec) {
			::DrawRectangleRec(rec, *this);
			return *this;
		}

		inline Color& DrawRectangle(Rectangle rec, Vector2 origin, float rotation) {
			::DrawRectanglePro(rec, origin, rotation, *this);
			return *this;
		}

		inline Color& DrawRectangleLines(int posX, int posY, int width, int height) {
			::DrawRectangleLines(posX, posY, width, height, *this);
			return *this;
		}

		inline Color& DrawRectangleLines(Rectangle rec, int lineThick) {
			::DrawRectangleLinesEx(rec, lineThick, *this);
			return *this;
		}

	};

	inline Color Color::LightGray = ::LIGHTGRAY;
	inline Color Color::Gray = ::GRAY;
	inline Color Color::DarkGray = ::DARKGRAY;
	inline Color Color::Yellow = ::YELLOW;
	inline Color Color::Gold = ::GOLD;
	inline Color Color::Orange = ::ORANGE;
	inline Color Color::Pink = ::PINK;
	inline Color Color::Red = ::RED;
	inline Color Color::Maroon = ::MAROON;
	inline Color Color::Green = ::GREEN;
	inline Color Color::Lime = ::LIME;
	inline Color Color::DarkGreen = ::DARKGREEN;
	inline Color Color::SkyBlue = ::SKYBLUE;
	inline Color Color::Blue = ::BLUE;
	inline Color Color::DarkBlue = ::DARKBLUE;
	inline Color Color::Purple = ::PURPLE;
	inline Color Color::Violet = ::VIOLET;
	inline Color Color::DarkPurple = ::DARKPURPLE;
	inline Color Color::Beige = ::BEIGE;
	inline Color Color::Brown = ::BROWN;
	inline Color Color::DarkBrown = ::DARKBROWN;
	inline Color Color::White = ::WHITE;
	inline Color Color::Black = ::BLACK;
	inline Color Color::Blank = ::BLANK;
	inline Color Color::Magenta = ::MAGENTA;
	inline Color Color::RayWhite = ::RAYWHITE;
}

#endif
