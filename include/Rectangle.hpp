#ifndef RAYLIB_CPP_INCLUDE_RECTANGLE_HPP_
#define RAYLIB_CPP_INCLUDE_RECTANGLE_HPP_

#include "./Vector2.hpp"
#include "./raylib-cpp-utils.hpp"
#include "./raylib.hpp"

namespace raylib {
/**
 * Rectangle type
 */
class Rectangle : public ::Rectangle {
public:
    Rectangle(const ::Rectangle& rect) : ::Rectangle{rect.x, rect.y, rect.width, rect.height} {}

    Rectangle(float x, float y, float width, float height) : ::Rectangle{x, y, width, height} {}
    Rectangle(float x, float y, float width) : ::Rectangle{x, y, width, 0} {}
    Rectangle(float x, float y) : ::Rectangle{x, y, 0, 0} {}
    Rectangle(float x) : ::Rectangle{x, 0, 0, 0} {}
    Rectangle() : ::Rectangle{0, 0, 0, 0} {}

    Rectangle(::Vector2 position, ::Vector2 size) : ::Rectangle{position.x, position.y, size.x, size.y} {}
    Rectangle(::Vector2 size) : ::Rectangle{0, 0, size.x, size.y} {}
    Rectangle(::Vector4 rect) : ::Rectangle{rect.x, rect.y, rect.z, rect.w} {}

    GETTERSETTER(float, X, x)
    GETTERSETTER(float, Y, y)
    GETTERSETTER(float, Width, width)
    GETTERSETTER(float, Height, height)

    Rectangle& operator=(const ::Rectangle& rect) {
        set(rect);
        return *this;
    }

    ::Vector4 ToVector4() { return {x, y, width, height}; }

    operator ::Vector4() const { return {x, y, width, height}; }

    /**
     * Draw a color-filled rectangle
     */
    void Draw(::Color color) const { ::DrawRectangleRec(*this, color); }

    void Draw(::Vector2 origin, float rotation, ::Color color) const {
        ::DrawRectanglePro(*this, origin, rotation, color);
    }

    void DrawGradientV(::Color color1, ::Color color2) const {
        ::DrawRectangleGradientV(
            static_cast<int>(x),
            static_cast<int>(y),
            static_cast<int>(width),
            static_cast<int>(height),
            color1,
            color2);
    }

    void DrawGradientH(::Color color1, ::Color color2) const {
        ::DrawRectangleGradientH(
            static_cast<int>(x),
            static_cast<int>(y),
            static_cast<int>(width),
            static_cast<int>(height),
            color1,
            color2);
    }

    void DrawGradient(::Color topLeft, ::Color bottomLeft, ::Color topRight, ::Color bottomRight) const {
        ::DrawRectangleGradientEx(*this, topLeft, bottomLeft, topRight, bottomRight);
    }

    void DrawLines(::Color color) const {
        ::DrawRectangleLines(
            static_cast<int>(x),
            static_cast<int>(y),
            static_cast<int>(width),
            static_cast<int>(height),
            color);
    }

    void DrawLines(::Color color, float lineThick) const { ::DrawRectangleLinesEx(*this, lineThick, color); }

    void DrawRounded(float roundness, int segments, ::Color color) const {
        ::DrawRectangleRounded(*this, roundness, segments, color);
    }

    void DrawRoundedLines(float roundness, int segments, ::Color color) const {
        ::DrawRectangleRoundedLines(*this, roundness, segments, color);
    }

    void DrawRoundedLines(float roundness, int segments, float lineThick, ::Color color) const {
        DrawRectangleRoundedLinesEx(*this, roundness, segments, lineThick, color);
    }

    /**
     * Check collision between two rectangles
     */
    bool CheckCollision(::Rectangle rec2) const { return ::CheckCollisionRecs(*this, rec2); }

    /**
     * Get collision rectangle for two rectangles collision
     */
    ::Rectangle GetCollision(::Rectangle rec2) const { return ::GetCollisionRec(*this, rec2); }

    /**
     * Check if point is inside rectangle
     */
    bool CheckCollision(::Vector2 point) const { return ::CheckCollisionPointRec(point, *this); }

    /**
     * Check collision between circle and rectangle
     */
    bool CheckCollision(::Vector2 center, float radius) const {
        return ::CheckCollisionCircleRec(center, radius, *this);
    }

    Vector2 GetSize() const { return {width, height}; }

    Rectangle& SetSize(float newWidth, float newHeight) {
        width = newWidth;
        height = newHeight;
        return *this;
    }

    Rectangle& SetSize(const ::Vector2& size) { return SetSize(size.x, size.y); }

    Rectangle& SetShapesTexture(const ::Texture2D& texture) {
        ::SetShapesTexture(texture, *this);
        return *this;
    }

    Vector2 GetPosition() const { return {x, y}; }

    Rectangle& SetPosition(float newX, float newY) {
        x = newX;
        y = newY;
        return *this;
    }

    Rectangle& SetPosition(const ::Vector2& position) { return SetPosition(position.x, position.y); }
protected:
    void set(const ::Rectangle& rect) {
        x = rect.x;
        y = rect.y;
        width = rect.width;
        height = rect.height;
    }
};
} // namespace raylib

using RRectangle = raylib::Rectangle;

#endif // RAYLIB_CPP_INCLUDE_RECTANGLE_HPP_
