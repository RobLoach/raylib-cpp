/*
*   LICENSE: zlib/libpng
*
*   raylib-cpp is licensed under an unmodified zlib/libpng license, which is an OSI-certified,
*   BSD-like license that allows static linking with closed source software:
*
*   Copyright (c) 2020 Rob Loach (@RobLoach)
*
*   This software is provided "as-is", without any express or implied warranty. In no event
*   will the authors be held liable for any damages arising from the use of this software.
*
*   Permission is granted to anyone to use this software for any purpose, including commercial
*   applications, and to alter it and redistribute it freely, subject to the following restrictions:
*
*     1. The origin of this software must not be misrepresented; you must not claim that you
*     wrote the original software. If you use this software in a product, an acknowledgment
*     in the product documentation would be appreciated but is not required.
*
*     2. Altered source versions must be plainly marked as such, and must not be misrepresented
*     as being the original software.
*
*     3. This notice may not be removed or altered from any source distribution.
*/

#ifndef RAYLIB_CPP_INCLUDE_FONT_HPP_
#define RAYLIB_CPP_INCLUDE_FONT_HPP_

#include <string>

#include "./raylib.hpp"
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

    Font(const ::Image& image, ::Color key, int firstChar) {
        set(::LoadFontFromImage(image, key, firstChar));
    }

    Font(const std::string& fileType, const unsigned char *fileData, int dataSize, int fontSize,
            int *fontChars, int charsCount)  {
        set(::LoadFontFromMemory(fileType.c_str(), fileData, dataSize, fontSize, fontChars,
            charsCount));
    }

    ~Font() {
        Unload();
    }

    void Unload() {
        UnloadFont(*this);
    }

    GETTERSETTER(int, BaseSize, baseSize)
    GETTERSETTER(int, CharsCount, charsCount)
    GETTERSETTER(::Texture2D, Texture, texture)
    GETTERSETTER(::Rectangle*, Recs, recs)
    GETTERSETTER(::CharInfo*, Chars, chars)

    Font& operator=(const ::Font& font) {
        set(font);
        return *this;
    }

    Font& operator=(const Font& font) {
        set(font);
        return *this;
    }

    inline Font& DrawText(const std::string& text, ::Vector2 position, float fontSize,
            float spacing, ::Color tint = WHITE) {
        ::DrawTextEx(*this, text.c_str(), position,  fontSize,  spacing,  tint);
        return *this;
    }

    inline Font& DrawText(const std::string& text, ::Rectangle rec, float fontSize, float spacing,
            bool wordWrap, ::Color tint = WHITE) {
        ::DrawTextRec(*this, text.c_str(), rec,  fontSize,  spacing,  wordWrap,  tint);
        return *this;
    }

    inline Font& DrawText(const std::string& text, ::Rectangle rec, float fontSize, float spacing,
            bool wordWrap, Color tint, int selectStart, int selectLength, ::Color selectText,
            Color selectBack) {
        ::DrawTextRecEx(*this, text.c_str(), rec, fontSize, spacing, wordWrap, tint,
            selectStart,  selectLength, selectText, selectBack);
        return *this;
    }

    inline Vector2 MeasureText(const std::string& text, float fontSize, float spacing) {
        return ::MeasureTextEx(*this, text.c_str(), fontSize, spacing);
    }

    inline int GetGlyphIndex(int character) const {
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
}  // namespace raylib

#endif  // RAYLIB_CPP_INCLUDE_FONT_HPP_
