#ifndef RAYLIB_CPP_INCLUDE_TEXT_HPP_
#define RAYLIB_CPP_INCLUDE_TEXT_HPP_

#include <string>

#include "./raylib.hpp"
#include "./RaylibException.hpp"
#include "./raylib-cpp-utils.hpp"

namespace raylib {
/**
 * Text Functions.
 */
class Text {
 public:
    /**
     * The internal text.
     */
    std::string text;

    /**
     * The size of the text.
     */
    float fontSize;

    /**
     * The color of the text.
     */
    ::Color color;

    /**
     * The internal raylib font to use for the text.
     */
    ::Font font;

    /**
     * The character spacing for the text.
     */
    float spacing;

    /**
     * Initializes a new Text object.
     *
     * @param text Text to initialize.
     * @param fontSize The size of the text.
     * @param color The color of the font.
     * @param font Font to initialize.
     * @param spacing The spacing of the text.
     */
    Text(
            const std::string& text = "",
            float fontSize = 10,
            const ::Color& color = WHITE,
            const ::Font& font = ::GetFontDefault(),
            float spacing = 0) :
            text(text),
            fontSize(fontSize),
            color(color),
            font(font),
            spacing(spacing) {
        // Nothing.
    }

    /**
     * Initializes a new Text object with a custom font.
     *
     * @param font Font to initialize.
     * @param text Text to initialize.
     * @param fontSize The size of the text.
     * @param spacing The spacing of the text.
     * @param color The color of the font.
     */
    Text(
            const ::Font& font,
            const std::string& text = "",
            float fontSize = 10,
            float spacing = 0,
            const ::Color& color = WHITE) :
            text(text),
            fontSize(fontSize),
            color(color),
            font(font),
            spacing(spacing) {
        // Nothing.
    }

    GETTERSETTER(std::string, Text, text)
    GETTERSETTER(float, FontSize, fontSize)
    GETTERSETTER(::Font, Font, font)
    GETTERSETTER(::Color, Color, color)
    GETTERSETTER(float, Spacing, spacing)

    /**
     * Draw text with values in class.
     */
    inline void Draw(const ::Vector2& position) const {
        ::DrawTextEx(font, text.c_str(), position, fontSize, spacing, color);
    }

    /**
     * Draw text with values in class.
     */
    inline void Draw(int posX, int posY) const {
        ::DrawTextEx(font,
            text.c_str(),
            { static_cast<float>(posX), static_cast<float>(posY) },
            fontSize,
            spacing,
            color);
    }

    /**
     * Draw text using Font and pro parameters (rotation).
     *
     * @see DrawTextPro()
     */
    inline void Draw(const ::Vector2& position, float rotation, const ::Vector2& origin = {0, 0}) const {
        ::DrawTextPro(font, text.c_str(), position, origin, rotation, fontSize, spacing, color);
    }

    /**
     * Measure string width for default font
     */
    inline int Measure() {
        return ::MeasureText(text.c_str(), static_cast<int>(fontSize));
    }

    /**
     * Measure string size for Font
     */
    inline Vector2 MeasureEx() {
        return ::MeasureTextEx(font, text.c_str(), fontSize, spacing);
    }

    Text& operator=(const Text& other) {
        if (this == &other) {
            return *this;
        }

        text = other.text;
        fontSize = other.fontSize;
        color = other.color;
        font = other.font;
        spacing = other.spacing;

        return *this;
    }

    /**
     * Draw text using font and color
     *
     * @see ::DrawText
     */
    static inline void Draw(
            const std::string& text,
            const int posX,
            const int posY,
            const int fontSize,
            const ::Color& color) {
        ::DrawText(text.c_str(), posX, posY, fontSize, color);
    }

    /**
     * Draw text using font and color, with position defined as Vector2
     *
     * @see ::DrawText
     */
    static inline void Draw(
            const std::string& text,
            const ::Vector2& pos,
            const int fontSize,
            const ::Color& color) {
        ::DrawText(text.c_str(), static_cast<int>(pos.x), static_cast<int>(pos.y), fontSize, color);
    }

    /**
     * Draw text using font, color, position, font size and spacing
     *
     * @see ::DrawTextEx
     */
    static inline void Draw(
            const ::Font& font,
            const std::string& text,
            const ::Vector2& position,
            const float fontSize,
            const float spacing,
            const ::Color& color) {
        ::DrawTextEx(font, text.c_str(), position, fontSize, spacing, color);
    }

    /**
     * Draw text using font, color, position, origin, font size and spacing
     *
     * @see ::DrawTextPro
     */
    static inline void Draw(
            const ::Font& font,
            const std::string& text,
            const ::Vector2& position,
            const ::Vector2& origin,
            const float rotation,
            const float fontSize,
            const float spacing,
            const ::Color& color) {
        ::DrawTextPro(font, text.c_str(), position, origin, rotation, fontSize, spacing, color);
    }
};
}  // namespace raylib

using RText = raylib::Text;

#endif  // RAYLIB_CPP_INCLUDE_TEXT_HPP_
