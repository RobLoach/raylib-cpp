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
    Rectangle(const ::Rectangle& rect) : ::Rectangle{rect.x, rect.y, rect.width, rect.height} {}

    Rectangle(float x, float y, float width, float height) : ::Rectangle{x, y, width, height} {}
    Rectangle(float x, float y, float width) : ::Rectangle{x, y, width, 0} {}
    Rectangle(float x, float y) : ::Rectangle{x, y, 0, 0} {}
    Rectangle(float x) : ::Rectangle{x, 0, 0, 0} {}
    Rectangle() : ::Rectangle{0, 0, 0, 0} {}

    Rectangle(::Vector2 position, ::Vector2 size)
            : ::Rectangle{position.x, position.y, size.x, size.y} {}
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

    inline ::Vector4 ToVector4() {
        return {x, y, width, height};
    }

    operator ::Vector4() const {
        return {x, y, width, height};
    }

    /**
     * Draw a color-filled rectangle
     */
    inline void Draw(::Color color) const {
        ::DrawRectangleRec(*this, color);
    }

    inline void Draw(::Vector2 origin, float rotation, ::Color color) const {
        ::DrawRectanglePro(*this, origin, rotation, color);
    }

    inline void DrawGradientV(::Color color1, ::Color color2) const {
        ::DrawRectangleGradientV(static_cast<int>(x), static_cast<int>(y), static_cast<int>(width),
            static_cast<int>(height), color1, color2);
    }

    inline void DrawGradientH(::Color color1, ::Color color2) const {
        ::DrawRectangleGradientH(static_cast<int>(x), static_cast<int>(y), static_cast<int>(width),
            static_cast<int>(height), color1, color2);
    }

    inline void DrawGradient(::Color col1, ::Color col2, ::Color col3, ::Color col4) const {
        ::DrawRectangleGradientEx(*this, col1, col2, col3, col4);
    }

    inline void DrawLines(::Color color) const {
        ::DrawRectangleLines(static_cast<int>(x), static_cast<int>(y), static_cast<int>(width),
            static_cast<int>(height), color);
    }

    inline void DrawLines(::Color color, float lineThick) const {
        ::DrawRectangleLinesEx(*this, lineThick, color);
    }

    inline void DrawRounded(float roundness, int segments, ::Color color) const {
        ::DrawRectangleRounded(*this, roundness, segments, color);
    }

    inline void DrawRoundedLines(float roundness, int segments,
            float lineThick, ::Color color) const {
        ::DrawRectangleRoundedLines(*this, roundness, segments, lineThick, color);
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
    inline bool CheckCollision(::Vector2 center, float radius) const {
        return ::CheckCollisionCircleRec(center, radius, *this);
    }

    inline Vector2 GetSize() const {
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

    inline Rectangle& SetShapesTexture(const ::Texture2D& texture) {
        ::SetShapesTexture(texture, *this);
        return *this;
    }

    inline Vector2 GetPosition() const {
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

 protected:
    void set(const ::Rectangle& rect) {
        x = rect.x;
        y = rect.y;
        width = rect.width;
        height = rect.height;
    }
};
}  // namespace raylib

using RRectangle = raylib::Rectangle;

#endif  // RAYLIB_CPP_INCLUDE_RECTANGLE_HPP_
