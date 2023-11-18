#ifndef RAYLIB_CPP_INCLUDE_VECTOR2_HPP_
#define RAYLIB_CPP_INCLUDE_VECTOR2_HPP_

#ifndef RAYLIB_CPP_NO_MATH
#include <cmath>
#endif

#include <string>

#include "./raylib.hpp"
#include "./raymath.hpp"
#include "./raylib-cpp-utils.hpp"

namespace raylib {
/**
 * Vector2 type
 */
class Vector2 : public ::Vector2 {
 public:
    Vector2(const ::Vector2& vec) : ::Vector2{vec.x, vec.y} {}

    Vector2(float x, float y) : ::Vector2{x, y} {}
    Vector2(float x) : ::Vector2{x, 0} {}
    Vector2() : ::Vector2{0, 0} {}

    GETTERSETTER(float, X, x)
    GETTERSETTER(float, Y, y)

    /**
     * Set the Vector2 to the same as the given Vector2.
     */
    Vector2& operator=(const ::Vector2& vector2) {
        set(vector2);
        return *this;
    }

    /**
     * Determine whether or not the vectors are equal.
     */
    bool operator==(const ::Vector2& other) const {
        return x == other.x
            && y == other.y;
    }

    /**
     * Determines if the vectors are not equal.
     */
    bool operator!=(const ::Vector2& other) const {
        return !(*this == other);
    }

    inline std::string ToString() const {
        return TextFormat("Vector2(%f, %f)", x, y);
    }

    inline operator std::string() const {
        return ToString();
    }

#ifndef RAYLIB_CPP_NO_MATH
    /**
     * Add two vectors (v1 + v2)
     */
    inline Vector2 Add(const ::Vector2& vector2) const {
        return Vector2Add(*this, vector2);
    }

    /**
     * Add two vectors (v1 + v2)
     */
    inline Vector2 operator+(const ::Vector2& vector2) const {
        return Vector2Add(*this, vector2);
    }

    /**
     * Add two vectors (v1 + v2)
     */
    Vector2& operator+=(const ::Vector2& vector2) {
        set(Vector2Add(*this, vector2));

        return *this;
    }

    /**
     * Subtract two vectors (v1 - v2)
     */
    inline Vector2 Subtract(const ::Vector2& vector2) const {
        return Vector2Subtract(*this, vector2);
    }

    /**
     * Subtract two vectors (v1 - v2)
     */
    inline Vector2 operator-(const ::Vector2& vector2) const {
        return Vector2Subtract(*this, vector2);
    }

    /**
     * Add two vectors (v1 + v2)
     */
    Vector2& operator-=(const ::Vector2& vector2) {
        set(Vector2Subtract(*this, vector2));

        return *this;
    }

    /**
     * Negate vector
     */
    inline Vector2 Negate() const {
        return Vector2Negate(*this);
    }

    /**
     * Negate vector
     */
    inline Vector2 operator-() const {
        return Vector2Negate(*this);
    }

    /**
     * Multiply vector by vector
     */
    inline Vector2 Multiply(const ::Vector2& vector2) const {
        return Vector2Multiply(*this, vector2);
    }

    /**
     * Multiply vector by vector
     */
    inline Vector2 operator*(const ::Vector2& vector2) const {
        return Vector2Multiply(*this, vector2);
    }

    /**
     * Multiply vector by vector
     */
    Vector2& operator*=(const ::Vector2& vector2) {
        set(Vector2Multiply(*this, vector2));

        return *this;
    }

    /**
     * Scale vector (multiply by value)
     */
    inline Vector2 Scale(const float scale) const {
        return Vector2Scale(*this, scale);
    }

    /**
     * Scale vector (multiply by value)
     */
    inline Vector2 operator*(const float scale) const {
        return Vector2Scale(*this, scale);
    }

    /**
     * Scale vector (multiply by value)
     */
    Vector2& operator*=(const float scale) {
        set(Vector2Scale(*this, scale));

        return *this;
    }

    /**
     * Divide vector by vector
     */
    inline Vector2 Divide(const ::Vector2& vector2) const {
        return Vector2Divide(*this, vector2);
    }

    /**
     * Divide vector by vector
     */
    inline Vector2 operator/(const ::Vector2& vector2) const {
        return Vector2Divide(*this, vector2);
    }

    /**
     * Divide vector by vector
     */
    Vector2& operator/=(const ::Vector2& vector2) {
        set(Vector2Divide(*this, vector2));

        return *this;
    }

    /**
     * Divide vector by value
     */
    inline Vector2 Divide(const float div) const {
        return ::Vector2{x / div, y / div};
    }

    /**
     * Divide vector by value
     */
    inline Vector2 operator/(const float div) const {
        return Divide(div);
    }

    /**
     * Divide vector by value
     */
    Vector2& operator/=(const float div) {
        this->x /= div;
        this->y /= div;

        return *this;
    }

    /**
     * Normalize provided vector
     */
    inline Vector2 Normalize() const {
        return Vector2Normalize(*this);
    }

    /**
     * Transforms a Vector2 by a given Matrix
     */
    inline Vector2 Transform(::Matrix mat) const {
        return ::Vector2Transform(*this, mat);
    }

    /**
     * Calculate linear interpolation between two vectors
     */
    inline Vector2 Lerp(const ::Vector2& vector2, float amount) const {
        return Vector2Lerp(*this, vector2, amount);
    }

    /**
     * Calculate reflected vector to normal
     */
    inline Vector2 Reflect(const ::Vector2& normal) const {
        return Vector2Reflect(*this, normal);
    }

    /**
     * Rotate Vector by float in Degrees
     */
    inline Vector2 Rotate(float degrees) const {
        return Vector2Rotate(*this, degrees);
    }

    /**
     * Move Vector towards target
     */
    inline Vector2 MoveTowards(const ::Vector2& target, float maxDistance) const {
        return Vector2MoveTowards(*this, target, maxDistance);
    }

    /**
     * Invert the given vector
     */
    inline Vector2 Invert() const {
        return ::Vector2Invert(*this);
    }

    /**
     * Clamp the components of the vector between
     */
    inline Vector2 Clamp(::Vector2 min, ::Vector2 max) const {
        return ::Vector2Clamp(*this, min, max);
    }

    /**
     * // Clamp the magnitude of the vector between two min and max values
     */
    inline Vector2 Clamp(float min, float max) const {
        return ::Vector2ClampValue(*this, min, max);
    }

    /**
     * Check whether two given vectors are almost equal
     */
    inline int Equals(::Vector2 q) const {
        return ::Vector2Equals(*this, q);
    }

    /**
     * Calculate vector length
     */
    inline float Length() const {
        return Vector2Length(*this);
    }

    /**
     * Calculate vector square length
     */
    inline float LengthSqr() const {
        return Vector2LengthSqr(*this);
    }

    /**
     * Calculate two vectors dot product
     */
    inline float DotProduct(const ::Vector2& vector2) const {
        return Vector2DotProduct(*this, vector2);
    }

    /**
     * Calculate distance between two vectors
     */
    inline float Distance(const ::Vector2& vector2) const {
        return Vector2Distance(*this, vector2);
    }

    /**
     * Calculate square distance between two vectors
     */
    inline float DistanceSqr(::Vector2 v2) const {
        return ::Vector2DistanceSqr(*this, v2);
    }

    /**
     * Calculate angle from two vectors in X-axis
     */
    inline float Angle(const ::Vector2& vector2) const {
        return Vector2Angle(*this, vector2);
    }

    /**
     * Vector with components value 0.0f
     */
    static inline Vector2 Zero() {
        return Vector2Zero();
    }

    /**
     * Vector with components value 1.0f
     */
    static inline Vector2 One() {
        return Vector2One();
    }
#endif

    inline void DrawPixel(::Color color = {0, 0, 0, 255}) const {
        ::DrawPixelV(*this, color);
    }

    inline void DrawLine(::Vector2 endPos, ::Color color = {0, 0, 0, 255}) const {
        ::DrawLineV(*this, endPos, color);
    }

    inline void DrawLine(::Vector2 endPos, float thick, ::Color color = {0, 0, 0, 255}) const {
        ::DrawLineEx(*this, endPos, thick, color);
    }

    inline void DrawLineBezier(::Vector2 endPos, float thick, ::Color color = {0, 0, 0, 255}) const {
        ::DrawLineBezier(*this, endPos, thick, color);
    }

    /**
     * Draw a color-filled circle (Vector version)
     */
    inline void DrawCircle(float radius, ::Color color = {0, 0, 0, 255}) const {
        ::DrawCircleV(*this, radius, color);
    }

    inline void DrawRectangle(::Vector2 size, ::Color color = {0, 0, 0, 255}) const {
        ::DrawRectangleV(*this, size, color);
    }

    inline void DrawPoly(int sides, float radius, float rotation, ::Color color = {0, 0, 0, 255}) const {
        ::DrawPoly(*this, sides, radius, rotation, color);
    }

    /**
     * Check collision between two circles
     */
    inline bool CheckCollisionCircle(float radius1, ::Vector2 center2, float radius2) const {
        return ::CheckCollisionCircles(*this, radius1, center2, radius2);
    }

    /**
     * Check collision between circle and rectangle
     */
    inline bool CheckCollisionCircle(float radius, ::Rectangle rec) const {
        return ::CheckCollisionCircleRec(*this, radius, rec);
    }

    /**
     * Check if point is inside rectangle
     */
    inline bool CheckCollision(::Rectangle rec) const {
        return ::CheckCollisionPointRec(*this, rec);
    }

    /**
     * Check if point is inside circle
     */
    inline bool CheckCollision(::Vector2 center, float radius) const {
        return ::CheckCollisionPointCircle(*this, center, radius);
    }

    /**
     * Check if point is inside a triangle
     */
    inline bool CheckCollision(::Vector2 p1, ::Vector2 p2, ::Vector2 p3) const {
        return ::CheckCollisionPointTriangle(*this, p1, p2, p3);
    }

    /**
     * Check the collision between two lines defined by two points each, returns collision point by reference
     */
    inline bool CheckCollisionLines(
            ::Vector2 endPos1,
            ::Vector2 startPos2, ::Vector2 endPos2,
            ::Vector2 *collisionPoint) const {
        return ::CheckCollisionLines(*this, endPos1, startPos2, endPos2, collisionPoint);
    }

    /**
     * Check if point belongs to line created between two points [p1] and [p2] with defined margin in pixels [threshold]
     */
    inline bool CheckCollisionPointLine(::Vector2 p1, ::Vector2 p2, int threshold = 1) const {
        return ::CheckCollisionPointLine(*this, p1, p2, threshold);
    }

 protected:
    void set(const ::Vector2& vec) {
        x = vec.x;
        y = vec.y;
    }
};

}  // namespace raylib

using RVector2 = raylib::Vector2;

#endif  // RAYLIB_CPP_INCLUDE_VECTOR2_HPP_
