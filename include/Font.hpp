#ifndef RAYLIB_CPP_INCLUDE_FONT_HPP_
#define RAYLIB_CPP_INCLUDE_FONT_HPP_

#include <string>

#include "./raylib.hpp"
#include "./raylib-cpp-utils.hpp"

namespace raylib {
/**
 * Font type, includes texture and charSet array data
 */
class Font : public ::Font {
 public:
    Font() {
        set(::GetFontDefault());
    }

    Font(const ::Font& font) {
        set(font);
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

    Font(const std::string& fileType, const unsigned char* fileData, int dataSize, int fontSize,
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
    GETTERSETTER(int, CharsPadding, charsPadding)
    GETTERSETTER(::Texture2D, Texture, texture)
    GETTERSETTER(::Rectangle*, Recs, recs)
    GETTERSETTER(::CharInfo*, Chars, chars)

    Font& operator=(const ::Font& font) {
        set(font);
        return *this;
    }

    /**
     * Draw text using font and additional parameters.
     */
    inline Font& DrawText(const std::string& text, ::Vector2 position, float fontSize,
            float spacing, ::Color tint = WHITE) {
        ::DrawTextEx(*this, text.c_str(), position,  fontSize,  spacing,  tint);
        return *this;
    }

    inline Font& DrawText(const std::string& text, ::Rectangle rec, float fontSize, float spacing,
            bool wordWrap = false, ::Color tint = WHITE) {
        ::DrawTextRec(*this, text.c_str(), rec,  fontSize,  spacing,  wordWrap,  tint);
        return *this;
    }

    /**
     * Draw text using font inside rectangle limits with support for text selection.
     */
    inline Font& DrawText(const std::string& text, ::Rectangle rec, float fontSize, float spacing,
            bool wordWrap, ::Color tint, int selectStart, int selectLength, ::Color selectText,
            ::Color selectBack) {
        ::DrawTextRecEx(*this, text.c_str(), rec, fontSize, spacing, wordWrap, tint,
            selectStart,  selectLength, selectText, selectBack);
        return *this;
    }

    /**
     * Draw one character (codepoint)
     */
    inline Font& DrawText(int codepoint,
            ::Vector2 position,
            float fontSize,
            ::Color tint = { 255, 255, 255, 255 }) {
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
    inline ::Image ImageText(const std::string& text, float fontSize,
            float spacing, ::Color tint) const {
        return ::ImageTextEx(*this, text.c_str(), fontSize, spacing, tint);
    }

 private:
    void set(const ::Font& font) {
        baseSize = font.baseSize;
        charsCount = font.charsCount;
        charsPadding = font.charsPadding;
        texture = font.texture;
        recs = font.recs;
        chars = font.chars;
    }
};
}  // namespace raylib

#endif  // RAYLIB_CPP_INCLUDE_FONT_HPP_
