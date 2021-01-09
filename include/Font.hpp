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
#include <memory>

#include "./raylib.hpp"
#include "./raylib-cpp-utils.hpp"

namespace raylib {
class Font : public ::Font {
 public:
    /**
     * The default font.
     */
    Font() {
        printf("Font()\n");
        set(::GetFontDefault());
    }

    /**
     * Move constructor
     */
    Font(Font&& other) {
        printf("Font(Font&& font)\n");
        set(other);

        other.baseSize = 0;
        other.charsCount = 0;
        other.charsPadding = 0;
        other.texture = { 0 };
        other.recs = nullptr;
        other.chars = nullptr;
    }

    /**
     * Move assignment
     */
    Font& operator=(Font&& other) noexcept {
        printf("Font& operator=(Font&& other)\n");
        if (this != &other) {
            Unload();
            set(other);

            other.baseSize = 0;
            other.charsCount = 0;
            other.charsPadding = 0;
            other.texture = { 0 };
            other.recs = nullptr;
            other.chars = nullptr;
        }
        return *this;
    }

    /**
     * Copy constructor
     */
    Font(const Font& other) {
        printf("Font(const Font& other)\n");
        CopyFrom(other);
    }

    /**
     * Copy assignment
     */
    Font& operator=(const Font& other) {
        if (this != &other) {
            Unload();
            CopyFrom(other);
        }
        return *this;
    }

    Font(const ::Font& font) {
        printf("Font(const ::Font& font)\n");
        set(font);
    }

    Font(const std::string& fileName) {
        printf("Font(const std::string& fileName)\n");
        set(::LoadFont(fileName.c_str()));
    }

    Font(const std::string& fileName, int fontSize, int* fontChars, int charCount)  {
        printf("Font(const std::string& fileName, int fontSize, int* fontChars, int charCount)\n");
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

    /**
     * Implicit conversion between ::Font*.
     */
    operator ::Font*() { return this; }

    /**
     * Implicit conversion between :const :Font*.
     */
    operator const ::Font*() const { return this; }

    void Unload() {
        if (baseSize >= 0) {
            UnloadFont(*this);
            baseSize = 0;
            charsCount = 0;
            charsPadding = 0;
            texture = {0};
            recs = nullptr;
            chars = nullptr;
        }
    }

    GETTERSETTER(int, BaseSize, baseSize)
    GETTERSETTER(int, CharsCount, charsCount)
    GETTERSETTER(int, CharsPadding, charsPadding)
    GETTERSETTER(::Texture2D, Texture, texture)
    GETTERSETTER(::Rectangle*, Recs, recs)
    GETTERSETTER(::CharInfo*, Chars, chars)

    Font& operator=(const ::Font& other) {
        set(other);
        return *this;
    }

    /**
     * Draw text using font and additional parameters
     */
    inline Font& DrawText(const std::string& text, ::Vector2 position, float fontSize,
            float spacing, ::Color tint = {255, 255, 255, 255}) {
        ::DrawTextEx(*this, text.c_str(), position,  fontSize,  spacing,  tint);
        return *this;
    }

    /**
     * Draw text using font inside rectangle limits
     */
    inline Font& DrawText(const std::string& text, ::Rectangle rec, float fontSize, float spacing,
            bool wordWrap = false, ::Color tint = {255, 255, 255, 255}) {
        ::DrawTextRec(*this, text.c_str(), rec,  fontSize,  spacing,  wordWrap,  tint);
        return *this;
    }

    /**
     * Draw text using font inside rectangle limits with support for text selection
     */
    inline Font& DrawText(const std::string& text, ::Rectangle rec, float fontSize, float spacing,
            bool wordWrap, Color tint, int selectStart, int selectLength, ::Color selectText,
            ::Color selectBack) {
        ::DrawTextRecEx(*this, text.c_str(), rec, fontSize, spacing, wordWrap, tint,
            selectStart,  selectLength, selectText, selectBack);
        return *this;
    }

    /**
     * Draw one character (codepoint)
     */
    inline Font& DrawText(int codepoint, ::Vector2 position, float fontSize, ::Color tint = {255, 255, 255, 255}) {
        ::DrawTextCodepoint(*this, codepoint, position, fontSize, tint);
        return *this;
    }

    /**
     * Measure string size for Font
     */
    inline Vector2 MeasureText(const std::string& text, float fontSize, float spacing) const {
        return ::MeasureTextEx(*this, text.c_str(), fontSize, spacing);
    }

    /**
     * Get index position for a unicode character on font
     */
    inline int GetGlyphIndex(int character) const {
        return ::GetGlyphIndex(*this, character);
    }

    /**
     * Create an image from text (custom sprite font)
     */
    inline Image ImageText(const std::string& text, float fontSize,
            float spacing, ::Color tint = {255, 255, 255, 255}) const {
        return ::ImageTextEx(*this, text.c_str(), fontSize, spacing, tint);
    }

 protected:
    void set(const ::Font& font) {
        baseSize = font.baseSize;
        charsCount = font.charsCount;
        texture = font.texture;
        recs = font.recs;
        chars = font.chars;
    }

    void CopyFrom(const Font& other) {
        printf("Font::CopyFrom()\n");
        baseSize = other.baseSize;
        charsCount = other.charsCount;
        charsPadding = other.charsPadding;
        ::Image texturedata = ::GetTextureData(other.texture);
        texture = ::LoadTextureFromImage(texturedata);
        UnloadImage(texturedata);
        if (other.recs != nullptr) {
            recs = new ::Rectangle[sizeof(other.recs) + 1];
            for (int i = 0; i < sizeof(other.recs); i++) {
                recs[i] = other.recs[i];
            }
        }
        if (other.chars != nullptr) {
            chars = new ::CharInfo[charsCount];
            for (int i = 0; i < charsCount; i++) {
                chars[i] = other.chars[i];
                chars[i].image = ImageCopy(other.chars[i].image);
            }
        }
    }
};
}  // namespace raylib

#endif  // RAYLIB_CPP_INCLUDE_FONT_HPP_
