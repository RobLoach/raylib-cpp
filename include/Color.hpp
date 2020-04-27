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
			set(::ColorFromHSV(hsv));
		};
		Color(int hexValue) {
			set(::GetColor(hexValue));
		};
		Color(Vector4 normalized) {
			set(::ColorFromNormalized(normalized));
		}

		static const Color LightGray;
		static const Color Gray;
		static const Color DarkGray;
		static const Color Yellow;
		static const Color Gold;
		static const Color Orange;
		static const Color Pink;
		static const Color Red;
		static const Color Maroon;
		static const Color Green;
		static const Color Lime;
		static const Color DarkGreen;
		static const Color SkyBlue;
		static const Color Blue;
		static const Color DarkBlue;
		static const Color Purple;
		static const Color Violet;
		static const Color DarkPurple;
		static const Color Beige;
		static const Color Brown;
		static const Color DarkBrown;
		static const Color White;
		static const Color Black;
		static const Color Blank;
		static const Color Magenta;
		static const Color RayWhite;

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

		inline const Color& ClearBackground() const {
			::ClearBackground(*this);
			return *this;
		}

		inline const Color& DrawPixel(int x, int y) const {
			::DrawPixel(x, y, *this);
			return *this;
		}

		inline const Color& DrawPixel(::Vector2 pos) const {
			::DrawPixelV(pos, *this);
			return *this;
		}

		inline const Color& DrawLine(int startPosX, int startPosY, int endPosX, int endPosY) const {
			::DrawLine(startPosX, startPosY, endPosX, endPosY, *this);
			return *this;
		}
		inline const Color& DrawLine(::Vector2 startPos, ::Vector2 endPos) const {
			::DrawLineV(startPos, endPos, *this);
			return *this;
		}
		inline const Color& DrawLine(::Vector2 startPos, ::Vector2 endPos, float thick) const {
			::DrawLineEx(startPos, endPos, thick, *this);
			return *this;
		}
		inline const Color& DrawLineBezier(::Vector2 startPos, Vector2 endPos, float thick) const {
			::DrawLineBezier(startPos, endPos, thick, *this);
			return *this;
		}
		inline const Color& DrawLineStrip(::Vector2 *points, int numPoints) const {
			::DrawLineStrip(points, numPoints, *this);
			return *this;
		}

		inline const Color& DrawText(const std::string& text, int posX, int posY, int fontSize) const {
			::DrawText(text.c_str(), posX, posY, fontSize, *this);
			return *this;
		}
		inline const Color& DrawText(::Font font, const std::string& text, ::Vector2 position, float fontSize, float spacing) const {
			::DrawTextEx(font, text.c_str(), position, fontSize, spacing, *this);
			return *this;
		}

		inline const Color& DrawText(::Font font, const std::string& text, ::Rectangle rec, float fontSize, float spacing, bool wordWrap = false) const {
			::DrawTextRec(font, text.c_str(), rec, fontSize, spacing, wordWrap, *this);
			return *this;
		}

		inline const Color& DrawRectangle(int posX, int posY, int width, int height) const {
			::DrawRectangle(posX, posY, width, height, *this);
			return *this;
		}

		inline const Color& DrawRectangle(Vector2 position, Vector2 size) const {
			::DrawRectangleV(position, size, *this);
			return *this;
		}

		inline const Color& DrawRectangle(Rectangle rec) const {
			::DrawRectangleRec(rec, *this);
			return *this;
		}

		inline const Color& DrawRectangle(Rectangle rec, Vector2 origin, float rotation) const {
			::DrawRectanglePro(rec, origin, rotation, *this);
			return *this;
		}

		inline const Color& DrawRectangleLines(int posX, int posY, int width, int height) const {
			::DrawRectangleLines(posX, posY, width, height, *this);
			return *this;
		}

		inline const Color& DrawRectangleLines(Rectangle rec, int lineThick) const {
			::DrawRectangleLinesEx(rec, lineThick, *this);
			return *this;
		}

	};

	const inline Color Color::LightGray{::LIGHTGRAY};
	const inline Color Color::Gray{::GRAY};
	const inline Color Color::DarkGray{::DARKGRAY};
	const inline Color Color::Yellow{::YELLOW};
	const inline Color Color::Gold{::GOLD};
	const inline Color Color::Orange{::ORANGE};
	const inline Color Color::Pink{::PINK};
	const inline Color Color::Red{::RED};
	const inline Color Color::Maroon{::MAROON};
	const inline Color Color::Green{::GREEN};
	const inline Color Color::Lime{::LIME};
	const inline Color Color::DarkGreen{::DARKGREEN};
	const inline Color Color::SkyBlue{::SKYBLUE};
	const inline Color Color::Blue{::BLUE};
	const inline Color Color::DarkBlue{::DARKBLUE};
	const inline Color Color::Purple{::PURPLE};
	const inline Color Color::Violet{::VIOLET};
	const inline Color Color::DarkPurple{::DARKPURPLE};
	const inline Color Color::Beige{::BEIGE};
	const inline Color Color::Brown{::BROWN};
	const inline Color Color::DarkBrown{::DARKBROWN};
	const inline Color Color::White{::WHITE};
	const inline Color Color::Black{::BLACK};
	const inline Color Color::Blank{::BLANK};
	const inline Color Color::Magenta{::MAGENTA};
	const inline Color Color::RayWhite{::RAYWHITE};

}

#endif
