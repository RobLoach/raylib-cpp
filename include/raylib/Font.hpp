#ifndef RAYLIB_CPP_FONT_HPP_
#define RAYLIB_CPP_FONT_HPP_

#include <string>
#include <iostream>

#include "raylib.h"
#include "utils.hpp"

namespace raylib {
	class Font : public ::Font {
	public:
		Font() {
			set(GetFontDefault());
		}

		Font(const std::string& fileName) {
            std::cout << "std" << fileName << std::endl;
			set(LoadFont(fileName.c_str()));
            std::cout << "asdsadds()" << std::endl;
		}

		Font(const std::string& fileName, int fontSize, int* fontChars, int charCount)  {
			set(LoadFontEx(fileName.c_str(), fontSize, fontChars, charCount));
		}

		Font(::Image& image, ::Color key, int firstChar)  {
			set(LoadFontFromImage(image, key, firstChar));
		}

		~Font() {
			Unload();
		}

		void Unload() {
            std::cout << "UnloadFont()" << std::endl;
			UnloadFont(*this);
		}

		void set(const ::Font font) {
			baseSize = font.baseSize;
			charsCount = font.charsCount;
			texture = font.texture;
			recs = font.recs;
			chars = font.chars;
		}

		void set(const Font& font) {
            std::cout << "set()" << std::endl;
			baseSize = font.baseSize;
			charsCount = font.charsCount;
			texture = font.texture;
			recs = font.recs;
			chars = font.chars;
		}

		GETTERSETTER(int,BaseSize,baseSize)
		GETTERSETTER(int,CharsCount,charsCount)
		GETTERSETTER(Texture2D,Texture,texture)
		GETTERSETTER(Rectangle*,Recs,recs)
		GETTERSETTER(CharInfo*,Chars,chars)

		Font& operator=(const ::Font& font) {
			set(font);
			return *this;
		}

		Font& operator=(const Font& font) {
			set(font);
			return *this;
		}

		void DrawText(const std::string& text, ::Vector2 position, float fontSize, float spacing, ::Color tint) {
			DrawTextEx(*this, text.c_str(), position,  fontSize,  spacing,  tint);
		}
		void DrawText(const std::string& text, ::Rectangle rec, float fontSize, float spacing, bool wordWrap, ::Color tint) {
			DrawTextRec(*this, text.c_str(), rec,  fontSize,  spacing,  wordWrap,  tint);
		}
		void DrawText(const std::string& text, ::Rectangle rec, float fontSize, float spacing, bool wordWrap, Color tint, int selectStart, int selectLength, ::Color selectText, Color selectBack) {
			DrawTextRecEx(*this, text.c_str(), rec,  fontSize,  spacing,  wordWrap,  tint,  selectStart,  selectLength, selectText, selectBack);
		}
	};
}

#endif
