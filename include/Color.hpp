#ifndef RAYLIB_CPP_INCLUDE_COLOR_HPP_
#define RAYLIB_CPP_INCLUDE_COLOR_HPP_

#include <string>

#include "./raylib.hpp"
#include "./Vector4.hpp"
#include "./raylib-cpp-utils.hpp"

namespace raylib {
/**
 * Color type, RGBA (32bit)
 */
class Color : public ::Color {
 public:
    Color(const ::Color& color) {
        set(color);
    }

    Color(
            unsigned char red,
            unsigned char green,
            unsigned char blue,
            unsigned char alpha = 255) :
        ::Color{red, green, blue, alpha} {};

    /**
     * Black.
     */
    Color() : ::Color{0, 0, 0, 255} {};

    /**
     * Returns a Color from HSV values
     */
    Color(::Vector3 hsv) {
        set(::ColorFromHSV(hsv.x, hsv.y, hsv.z));
    }

    /**
     * Returns a Color from HSV values
     */
    static ::Color FromHSV(float hue, float saturation, float value) {
        return ::ColorFromHSV(hue, saturation, value);
    }

    /**
     * Get Color structure from hexadecimal value
     */
    Color(int hexValue) {
        set(::GetColor(hexValue));
    }

    /**
     * Returns Color from normalized values [0..1]
     */
    Color(::Vector4 normalized) {
        set(::ColorFromNormalized(normalized));
    }

    /**
     * Returns hexadecimal value for a Color
     */
    int ToInt() const {
        return ::ColorToInt(*this);
    }

    /**
     * Returns hexadecimal value for a Color
     */
    operator int() const {
        return ::ColorToInt(*this);
    }

    /**
     * Returns color with alpha applied, alpha goes from 0.0f to 1.0f
     */
    Color Fade(float alpha) const {
        return ::Fade(*this, alpha);
    }

    /**
     * Returns Color normalized as float [0..1]
     */
    Vector4 Normalize() const {
        return ::ColorNormalize(*this);
    }

    /**
     * Returns HSV values for a Color
     */
    Vector3 ToHSV() const {
        return ::ColorToHSV(*this);
    }

    GETTERSETTER(unsigned char, R, r)
    GETTERSETTER(unsigned char, G, g)
    GETTERSETTER(unsigned char, B, b)
    GETTERSETTER(unsigned char, A, a)

    Color& operator=(const ::Color& color) {
        set(color);
        return *this;
    }

    /**
     * Set background color (framebuffer clear color)
     */
    inline Color& ClearBackground() {
        ::ClearBackground(*this);
        return *this;
    }

    inline Color& DrawPixel(int x, int y) {
        ::DrawPixel(x, y, *this);
        return *this;
    }

    /**
     * Draw a pixel
     */
    inline Color& DrawPixel(::Vector2 pos) {
        ::DrawPixelV(pos, *this);
        return *this;
    }

    /**
     * Draw a line
     */
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

    inline Color& DrawLineBezier(::Vector2 startPos, ::Vector2 endPos, float thick) {
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

    inline Color& DrawText(const ::Font& font, const std::string& text, ::Vector2 position,
            float fontSize, float spacing) {
        ::DrawTextEx(font, text.c_str(), position, fontSize, spacing, *this);
        return *this;
    }

    inline Color& DrawText(
            const ::Font& font,
            const std::string& text,
            ::Rectangle rec,
            float fontSize,
            float spacing,
            bool wordWrap = false) {
        ::DrawTextRec(font, text.c_str(), rec, fontSize, spacing, wordWrap, *this);
        return *this;
    }

    inline Color& DrawRectangle(int posX, int posY, int width, int height) {
        ::DrawRectangle(posX, posY, width, height, *this);
        return *this;
    }

    inline Color& DrawRectangle(::Vector2 position, ::Vector2 size) {
        ::DrawRectangleV(position, size, *this);
        return *this;
    }

    inline Color& DrawRectangle(::Rectangle rec) {
        ::DrawRectangleRec(rec, *this);
        return *this;
    }

    inline Color& DrawRectangle(::Rectangle rec, ::Vector2 origin, float rotation) {
        ::DrawRectanglePro(rec, origin, rotation, *this);
        return *this;
    }

    inline Color& DrawRectangleLines(int posX, int posY, int width, int height) {
        ::DrawRectangleLines(posX, posY, width, height, *this);
        return *this;
    }

    inline Color& DrawRectangleLines(::Rectangle rec, int lineThick) {
        ::DrawRectangleLinesEx(rec, lineThick, *this);
        return *this;
    }

    /**
     * Returns color with alpha applied, alpha goes from 0.0f to 1.0f
     */
    Color Alpha(float alpha) const {
        return ::ColorAlpha(*this, alpha);
    }

    /**
     * Returns src alpha-blended into dst color with tint
     */
    Color AlphaBlend(::Color dst, ::Color tint) const {
        return ::ColorAlphaBlend(dst, *this, tint);
    }

    inline static Color LightGray() { return LIGHTGRAY; }
    inline static Color Gray() { return GRAY; }
    inline static Color DarkGray() { return DARKGRAY; }
    inline static Color Yellow() { return YELLOW; }
    inline static Color Gold() { return GOLD; }
    inline static Color Orange() { return ORANGE; }
    inline static Color Pink() { return PINK; }
    inline static Color Red() { return RED; }
    inline static Color Maroon() { return MAROON; }
    inline static Color Green() { return GREEN; }
    inline static Color Lime() { return LIME; }
    inline static Color DarkGreen() { return DARKGREEN; }
    inline static Color SkyBlue() { return SKYBLUE; }
    inline static Color Blue() { return BLUE; }
    inline static Color DarkBlue() { return DARKBLUE; }
    inline static Color Purple() { return PURPLE; }
    inline static Color Violet() { return VIOLET; }
    inline static Color DarkPurple() { return DARKPURPLE; }
    inline static Color Beige() { return BEIGE; }
    inline static Color Brown() { return BROWN; }
    inline static Color DarkBrown() { return DARKBROWN; }
    inline static Color White() { return WHITE; }
    inline static Color Black() { return BLACK; }
    inline static Color Blank() { return BLANK; }
    inline static Color Magenta() { return MAGENTA; }
    inline static Color RayWhite() { return RAYWHITE; }

 private:
    inline void set(const ::Color& color) {
        r = color.r;
        g = color.g;
        b = color.b;
        a = color.a;
    }
};

}  // namespace raylib

#endif  // RAYLIB_CPP_INCLUDE_COLOR_HPP_
