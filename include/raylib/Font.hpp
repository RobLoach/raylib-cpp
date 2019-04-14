#ifndef RAYLIB_CPP_FONT_HPP_
#define RAYLIB_CPP_FONT_HPP_

#include "raylib.h"
#include "utils.hpp"

namespace raylib {
	class Font : public ::Font {
	public:
		Font() {
			set(GetFontDefault());
		}

		Font(const std::string& fileName) {
			set(LoadFont(fileName.c_str()));
		}

		Font(const std::string& fileName, int fontSize, int* fontChars, int charCount)  {
			set(LoadFontEx(fileName.c_str(), fontSize, fontChars, charCount));
		}

		Font(Image image, Color key, int firstChar)  {
			set(LoadFontFromImage(image, key, firstChar));
		}

		~Font() {
			Unload();
		}

		void Unload() {
			UnloadFont(*this);
		}

		inline void set(const ::Font& font) {
			texture = font.texture;
			baseSize = font.baseSize;
			charsCount = font.charsCount;
			chars = font.chars;
		}

		inline void set(const Font& font) {
			texture = font.texture;
			baseSize = font.baseSize;
			charsCount = font.charsCount;
			chars = font.chars;
		}

		GETTERSETTER(Texture2D,Texture,texture)
		GETTERSETTER(int,BaseSize,baseSize)
		GETTERSETTER(int,CharsCount,charsCount)
		GETTERSETTER(CharInfo*,Chars,chars)

        Font& operator=(const ::Font& font) {
            set(font);
            return *this;
        }

        Font& operator=(const Font& font) {
            set(font);
            return *this;
        }

	};
}

#endif