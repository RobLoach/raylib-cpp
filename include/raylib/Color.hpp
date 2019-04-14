#ifndef RAYLIB_CPP_COLOR_HPP_
#define RAYLIB_CPP_COLOR_HPP_

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
		Color(unsigned char red, unsigned char green, unsigned char blue, unsigned char alpha = 255) {
			r = red;
			g = green;
			b = blue;
			a = alpha;
		};
		Color(Vector3 hsv) {
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

	};
}

#endif