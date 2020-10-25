#ifndef RAYLIB_CPP_FONT_HPP_
#define RAYLIB_CPP_FONT_HPP_

#include <string>

#ifdef __cplusplus
extern "C"{
#endif
#include "raylib.h"
#ifdef __cplusplus
}
#endif

#include "./raylib-cpp-utils.hpp"

namespace raylib {
	class Font : public ::Font {
	public:
		Font() {
			set(::GetFontDefault());
		}

		Font(const std::string& fileName) {
			set(::LoadFont(fileName.c_str()));
		}

		Font(const std::string& fileName, int fontSize, int* fontChars, int charCount)  {
			set(::LoadFontEx(fileName.c_str(), fontSize, fontChars, charCount));
		}

		Font(::Image& image, ::Color key, int firstChar)  {
			set(::LoadFontFromImage(image, key, firstChar));
		}

		Font(const std::string& fileType, const unsigned char *fileData, int dataSize, int fontSize, int *fontChars, int charsCount)  {
			set(::LoadFontFromMemory(fileType.c_str(), fileData, dataSize, fontSize, fontChars, charsCount));
		}

		~Font() {
			Unload();
		}

		void Unload() {
			UnloadFont(*this);
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

		inline Font& DrawText(const std::string& text, ::Vector2 position, float fontSize, float spacing, ::Color tint = WHITE) {
			::DrawTextEx(*this, text.c_str(), position,  fontSize,  spacing,  tint);
			return *this;
		}
		inline Font& DrawText(const std::string& text, ::Rectangle rec, float fontSize, float spacing, bool wordWrap, ::Color tint = WHITE) {
			::DrawTextRec(*this, text.c_str(), rec,  fontSize,  spacing,  wordWrap,  tint);
			return *this;
		}
		inline Font& DrawText(const std::string& text, ::Rectangle rec, float fontSize, float spacing, bool wordWrap, Color tint, int selectStart, int selectLength, ::Color selectText, Color selectBack) {
			::DrawTextRecEx(*this, text.c_str(), rec,  fontSize,  spacing,  wordWrap,  tint,  selectStart,  selectLength, selectText, selectBack);
			return *this;
		}

		inline Vector2 MeasureText(const std::string& text, float fontSize, float spacing) {
			return ::MeasureTextEx(*this, text.c_str(), fontSize, spacing);
		}

		inline int GetGlyphIndex(int character) {
			return ::GetGlyphIndex(*this, character);
		}

	protected:
		void set(const ::Font font) {
			baseSize = font.baseSize;
			charsCount = font.charsCount;
			texture = font.texture;
			recs = font.recs;
			chars = font.chars;
		}

		void set(const Font& font) {
			baseSize = font.baseSize;
			charsCount = font.charsCount;
			texture = font.texture;
			recs = font.recs;
			chars = font.chars;
		}
	};
}

#endif
