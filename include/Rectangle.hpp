#ifndef RAYLIB_CPP_INCLUDE_RECTANGLE_HPP_
#define RAYLIB_CPP_INCLUDE_RECTANGLE_HPP_

#include "./raylib.hpp"
#include "./raylib-cpp-utils.hpp"
#include "./Vector2.hpp"

namespace raylib {
/**
 * Rectangle type
 */
class Rectangle : public ::Rectangle {
 public:
    Rectangle(const ::Rectangle& vec) {
        set(vec);
    }

    Rectangle(float x, float y, float width, float height) : ::Rectangle{x, y, width, height} {}
    Rectangle(float x, float y, float width) : ::Rectangle{x, y, width, 0} {}
    Rectangle(float x, float y) : ::Rectangle{x, y, 0, 0} {}
    Rectangle(float x) : ::Rectangle{x, 0, 0, 0} {}
    Rectangle() : ::Rectangle{0, 0, 0, 0} {}

    Rectangle(::Vector2 position, ::Vector2 size)
            : ::Rectangle{position.x, position.y, size.x, size.y} {}
    Rectangle(::Vector2 size) : ::Rectangle{0, 0, size.x, size.y} {}

    GETTERSETTER(float, X, x)
    GETTERSETTER(float, Y, y)
    GETTERSETTER(float, Width, width)
    GETTERSETTER(float, Height, height)

    Rectangle& operator=(const ::Rectangle& rect) {
        set(rect);
        return *this;
    }

    inline ::Vector4 ToVector4() {
        return {x, y, width, height};
    }

    operator ::Vector4() const {
        return {x, y, width, height};
    }

    /**
     * Draw a color-filled rectangle
     */
    inline Rectangle& Draw(::Color color) {
        ::DrawRectangle(static_cast<int>(x), static_cast<int>(y), static_cast<int>(width),
            static_cast<int>(height), color);
        return *this;
    }

    inline Rectangle& Draw(::Vector2 origin, float rotation, ::Color color) {
        ::DrawRectanglePro(*this, origin, rotation, color);
        return *this;
    }

    inline Rectangle& DrawGradientV(::Color color1, ::Color color2) {
        ::DrawRectangleGradientV(static_cast<int>(x), static_cast<int>(y), static_cast<int>(width),
            static_cast<int>(height), color1, color2);
        return *this;
    }

    inline Rectangle& DrawGradientH(::Color color1, ::Color color2) {
        ::DrawRectangleGradientH(static_cast<int>(x), static_cast<int>(y), static_cast<int>(width),
            static_cast<int>(height), color1, color2);
        return *this;
    }

    inline Rectangle& DrawGradient(::Color col1, ::Color col2, ::Color col3, ::Color col4) {
        ::DrawRectangleGradientEx(*this, col1, col2, col3, col4);
        return *this;
    }

    inline Rectangle& DrawLines(::Color color) {
        ::DrawRectangleLines(static_cast<int>(x), static_cast<int>(y), static_cast<int>(width),
            static_cast<int>(height), color);
        return *this;
    }

    inline Rectangle& DrawLines(::Color color, int lineThick) {
        ::DrawRectangleLinesEx(*this, lineThick, color);
        return *this;
    }

    inline Rectangle& DrawRounded(float roundness, int segments, ::Color color) {
        ::DrawRectangleRounded(*this, roundness, segments, color);
        return *this;
    }

    inline Rectangle& DrawRoundedLines(float roundness, int segments, int lineThick,
            ::Color color) {
        ::DrawRectangleRoundedLines(*this, roundness, segments, lineThick, color);
        return *this;
    }

    /**
     * Check collision between two rectangles
     */
    inline bool CheckCollision(::Rectangle rec2) const {
        return ::CheckCollisionRecs(*this, rec2);
    }

    /**
     * Get collision rectangle for two rectangles collision
     */
    inline ::Rectangle GetCollision(::Rectangle rec2) const {
        return ::GetCollisionRec(*this, rec2);
    }

    /**
     * Check if point is inside rectangle
     */
    inline bool CheckCollision(::Vector2 point) const {
        return ::CheckCollisionPointRec(point, *this);
    }

    /**
     * Check collision between circle and rectangle
     */
    inline bool CheckCollision(::Vector2 center, float radius) {
        return ::CheckCollisionCircleRec(center, radius, *this);
    }

    inline ::Vector2 GetSize() {
        return {width, height};
    }

    inline Rectangle& SetSize(float newWidth, float newHeight) {
        width = newWidth;
        height = newHeight;
        return *this;
    }

    inline Rectangle& SetSize(const ::Vector2& size) {
        return SetSize(size.x, size.y);
    }

    inline ::Vector2 GetPosition() {
        return {x, y};
    }

    inline Rectangle& SetPosition(float newX, float newY) {
        x = newX;
        y = newY;
        return *this;
    }

    inline Rectangle& SetPosition(const ::Vector2& position) {
        return SetPosition(position.x, position.y);
    }

 private:
    inline void set(const ::Rectangle& rect) {
        x = rect.x;
        y = rect.y;
        width = rect.width;
        height = rect.height;
    }
};
}  // namespace raylib

#endif  // RAYLIB_CPP_INCLUDE_RECTANGLE_HPP_
