#ifndef RAYLIB_CPP_INCLUDE_COLOR_HPP_
#define RAYLIB_CPP_INCLUDE_COLOR_HPP_

#include <string>

#include "./Vector4.hpp"
#include "./raylib-cpp-utils.hpp"
#include "./raylib.hpp"

namespace raylib {
/**
 * Color type, RGBA (32bit)
 */
class Color : public ::Color {
public:
    Color(const ::Color& color) : ::Color{color.r, color.g, color.b, color.a} {}

    Color(unsigned char red, unsigned char green, unsigned char blue, unsigned char alpha = 255)
        : ::Color{red, green, blue, alpha} {};

    /**
     * Black.
     */
    Color() : ::Color{0, 0, 0, 255} {};

    /**
     * Returns a Color from HSV values
     */
    Color(::Vector3 hsv) { set(::ColorFromHSV(hsv.x, hsv.y, hsv.z)); }

    /**
     * Returns a Color from HSV values
     */
    static ::Color FromHSV(float hue, float saturation, float value) { return ::ColorFromHSV(hue, saturation, value); }

    /**
     * Get Color structure from hexadecimal value
     */
    Color(unsigned int hexValue) { set(::GetColor(hexValue)); }

    Color(void* srcPtr, int format) { set(::GetPixelColor(srcPtr, format)); }

    /**
     * Returns hexadecimal value for a Color
     */
    int ToInt() const { return ::ColorToInt(*this); }

    /**
     * Returns hexadecimal value for a Color
     */
    operator int() const { return ::ColorToInt(*this); }

    std::string ToString() const { return TextFormat("Color(%d, %d, %d, %d)", r, g, b, a); }

    operator std::string() const { return ToString(); }

    /**
     * Returns color with alpha applied, alpha goes from 0.0f to 1.0f
     */
    Color Fade(float alpha) const { return ::Fade(*this, alpha); }

    /**
     * Returns Color normalized as float [0..1]
     */
    Vector4 Normalize() const { return ::ColorNormalize(*this); }

    /**
     * Returns Color from normalized values [0..1]
     */
    Color(::Vector4 normalized) { set(::ColorFromNormalized(normalized)); }

    /**
     * Returns HSV values for a Color
     */
    Vector3 ToHSV() const { return ::ColorToHSV(*this); }

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
    Color& ClearBackground() {
        ::ClearBackground(*this);
        return *this;
    }

    void DrawPixel(int x, int y) const { ::DrawPixel(x, y, *this); }

    /**
     * Draw a pixel
     */
    void DrawPixel(::Vector2 pos) const { ::DrawPixelV(pos, *this); }

    /**
     * Draw a line
     */
    void DrawLine(int startPosX, int startPosY, int endPosX, int endPosY) const {
        ::DrawLine(startPosX, startPosY, endPosX, endPosY, *this);
    }

    /**
     * Draw a line using Vector points
     */
    void DrawLine(::Vector2 startPos, ::Vector2 endPos) const { ::DrawLineV(startPos, endPos, *this); }

    /**
     * Draw a line using Vector points, with a given thickness
     */
    void DrawLine(::Vector2 startPos, ::Vector2 endPos, float thick) const {
        ::DrawLineEx(startPos, endPos, thick, *this);
    }

    void DrawLineBezier(::Vector2 startPos, ::Vector2 endPos, float thick = 1.0f) const {
        ::DrawLineBezier(startPos, endPos, thick, *this);
    }

    void DrawLineStrip(::Vector2* points, int numPoints) const { ::DrawLineStrip(points, numPoints, *this); }

    void DrawText(const char* text, int posX = 0, int posY = 0, int fontSize = 10.0f) const {
        ::DrawText(text, posX, posY, fontSize, *this);
    }

    void DrawText(const std::string& text, int posX = 0, int posY = 0, int fontSize = 10.0f) const {
        ::DrawText(text.c_str(), posX, posY, fontSize, *this);
    }

    void DrawText(const ::Font& font, const char* text, ::Vector2 position, float fontSize, float spacing) const {
        ::DrawTextEx(font, text, position, fontSize, spacing, *this);
    }

    void
    DrawText(const ::Font& font, const std::string& text, ::Vector2 position, float fontSize, float spacing) const {
        ::DrawTextEx(font, text.c_str(), position, fontSize, spacing, *this);
    }

    void DrawText(
        const ::Font& font,
        const char* text,
        ::Vector2 position,
        ::Vector2 origin,
        float rotation,
        float fontSize,
        float spacing) const {
        ::DrawTextPro(font, text, position, origin, rotation, fontSize, spacing, *this);
    }

    void DrawText(
        const ::Font& font,
        const std::string& text,
        ::Vector2 position,
        ::Vector2 origin,
        float rotation,
        float fontSize,
        float spacing) const {
        ::DrawTextPro(font, text.c_str(), position, origin, rotation, fontSize, spacing, *this);
    }

    void DrawRectangle(int posX, int posY, int width, int height) const {
        ::DrawRectangle(posX, posY, width, height, *this);
    }

    void DrawRectangle(::Vector2 position, ::Vector2 size) const { ::DrawRectangleV(position, size, *this); }

    void DrawRectangle(::Rectangle rec) const { ::DrawRectangleRec(rec, *this); }

    void DrawRectangle(::Rectangle rec, ::Vector2 origin, float rotation) const {
        ::DrawRectanglePro(rec, origin, rotation, *this);
    }

    void DrawRectangleLines(int posX, int posY, int width, int height) const {
        ::DrawRectangleLines(posX, posY, width, height, *this);
    }

    void DrawRectangleLines(::Rectangle rec, float lineThick) const { ::DrawRectangleLinesEx(rec, lineThick, *this); }

    bool IsEqual(::Color color) {
        return ::ColorIsEqual(*this, color);
    }

    bool operator==(const ::Color& other) const { return ::ColorIsEqual(*this, other); }
    bool operator!=(const ::Color& other) const { return !::ColorIsEqual(*this, other); }

    /**
     * Get color multiplied with another color
     */
    Color Tint(::Color tint) { return ::ColorTint(*this, tint); }

    /**
     * Get color with brightness correction, brightness factor goes from -1.0f to 1.0f
     */
    Color Brightness(float factor) { return ::ColorBrightness(*this, factor); }

    /**
     * Get color with contrast correction, contrast values between -1.0f and 1.0f
     */
    Color Contrast(float contrast) { return ::ColorContrast(*this, contrast); }

    /**
     * Returns color with alpha applied, alpha goes from 0.0f to 1.0f
     */
    Color Alpha(float alpha) const { return ::ColorAlpha(*this, alpha); }

    Color Lerp(::Color color2, float factor) {
        return ::ColorLerp(*this, color2, factor);
    }

    /**
     * Returns src alpha-blended into dst color with tint
     */
    Color AlphaBlend(::Color dst, ::Color tint) const { return ::ColorAlphaBlend(dst, *this, tint); }

    static Color LightGray() { return LIGHTGRAY; }
    static Color Gray() { return GRAY; }
    static Color DarkGray() { return DARKGRAY; }
    static Color Yellow() { return YELLOW; }
    static Color Gold() { return GOLD; }
    static Color Orange() { return ORANGE; }
    static Color Pink() { return PINK; }
    static Color Red() { return RED; }
    static Color Maroon() { return MAROON; }
    static Color Green() { return GREEN; }
    static Color Lime() { return LIME; }
    static Color DarkGreen() { return DARKGREEN; }
    static Color SkyBlue() { return SKYBLUE; }
    static Color Blue() { return BLUE; }
    static Color DarkBlue() { return DARKBLUE; }
    static Color Purple() { return PURPLE; }
    static Color Violet() { return VIOLET; }
    static Color DarkPurple() { return DARKPURPLE; }
    static Color Beige() { return BEIGE; }
    static Color Brown() { return BROWN; }
    static Color DarkBrown() { return DARKBROWN; }
    static Color White() { return WHITE; }
    static Color Black() { return BLACK; }
    static Color Blank() { return BLANK; }
    static Color Magenta() { return MAGENTA; }
    static Color RayWhite() { return RAYWHITE; }
protected:
    void set(const ::Color& color) {
        r = color.r;
        g = color.g;
        b = color.b;
        a = color.a;
    }
};

} // namespace raylib

using RColor = raylib::Color;

#endif // RAYLIB_CPP_INCLUDE_COLOR_HPP_
