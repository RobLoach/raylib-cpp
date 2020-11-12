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

#ifndef RAYLIB_CPP_INCLUDE_VECTOR2_HPP_
#define RAYLIB_CPP_INCLUDE_VECTOR2_HPP_

#ifndef RAYLIB_CPP_NO_MATH
#include <cmath>
#endif

#include "./raylib.hpp"
#include "./raymath.hpp"
#include "./raylib-cpp-utils.hpp"

namespace raylib {
class Vector2 : public ::Vector2 {
 public:
    Vector2(::Vector2 vec) {
        set(vec);
    }

    Vector2(float x, float y) : ::Vector2{x, y} {};
    Vector2(float x) : ::Vector2{x, 0} {};
    Vector2() : ::Vector2{0, 0} {};

    GETTERSETTER(float, X, x)
    GETTERSETTER(float, Y, y)

    Vector2& operator=(const ::Vector2& vector2) {
        set(vector2);
        return *this;
    }

    Vector2& operator=(const Vector2& vector2) {
        set(vector2);
        return *this;
    }

    bool operator==(const Vector2& other) {
        return x == other.x
            && y == other.y;
    }

#ifndef RAYLIB_CPP_NO_MATH
    Vector2 Add(const Vector2& vector2) {
        return Vector2Add(*this, vector2);
    }

    Vector2 operator+(const Vector2& vector2) {
        return Vector2Add(*this, vector2);
    }

    Vector2 Subtract(const Vector2& vector2) {
        return Vector2Subtract(*this, vector2);
    }

    Vector2 operator-(const Vector2& vector2) {
        return Vector2Subtract(*this, vector2);
    }

    Vector2 Negate() {
        return Vector2Negate(*this);
    }

    Vector2 operator-() {
        return Vector2Negate(*this);
    }

    Vector2 Multiply(const Vector2& vector2) {
        return Vector2Multiply(*this, vector2);
    }

    Vector2 operator*(const Vector2& vector2) {
        return Vector2Multiply(*this, vector2);
    }

    Vector2 Scale(const float scale) {
        return Vector2Scale(*this, scale);
    }

    Vector2 operator*(const float scale) {
        return Vector2Scale(*this, scale);
    }

    Vector2 Divide(const Vector2& vector2) {
        return Vector2Divide(*this, vector2);
    }

    Vector2 operator/(const Vector2& vector2) {
        return Vector2Divide(*this, vector2);
    }

    Vector2& Divide(const float div) {
        x /= div;
        y /= div;

        return *this;
    }

    Vector2& operator/(const float div) {
        x /= div;
        y /= div;

        return *this;
    }

    Vector2& operator+=(const Vector2& vector2) {
        set(Vector2Add(*this, vector2));

        return *this;
    }

    Vector2& operator-=(const Vector2& vector2) {
        set(Vector2Subtract(*this, vector2));

        return *this;
    }


    Vector2& operator*=(const Vector2& vector2) {
        set(Vector2Multiply(*this, vector2));

        return *this;
    }

    Vector2& operator*=(const float scale) {
        set(Vector2Scale(*this, scale));

        return *this;
    }

    Vector2& operator/=(const Vector2& vector2) {
        set(Vector2Divide(*this, vector2));

        return *this;
    }

    Vector2& operator/=(const float div) {
        this->x /= div;
        this->y /= div;

        return *this;
    }

    float Length() const {
        return Vector2Length(*this);
    }

    Vector2 Normalize() {
        return Vector2Normalize(*this);
    }

    float DotProduct(const Vector2& vector2) {
        return Vector2DotProduct(*this, vector2);
    }

    float Angle(const Vector2& vector2) {
        return Vector2Angle(*this, vector2);
    }

    float Distance(const Vector2& vector2) {
        return Vector2Distance(*this, vector2);
    }

    Vector2 Lerp(const Vector2& vector2, const float amount) {
        return Vector2Lerp(*this, vector2, amount);
    }

    Vector2 Reflect(const Vector2& normal) {
        return Vector2Reflect(*this, normal);
    }

    Vector2 Rotate(float degrees) {
        return Vector2Rotate(*this, degrees);
    }

    static Vector2 Zero() {
        return Vector2Zero();
    }

    static Vector2 One() {
        return Vector2One();
    }
#endif

    inline Vector2& DrawPixel(::Color color) {
        ::DrawPixelV(*this, color);
        return *this;
    }

    inline Vector2& DrawLine(::Vector2 endPos, ::Color color) {
        ::DrawLineV(*this, endPos, color);
        return *this;
    }

    inline Vector2& DrawLine(::Vector2 endPos, float thick, ::Color color) {
        ::DrawLineEx(*this, endPos, thick, color);
        return *this;
    }

    inline Vector2& DrawLineBezier(::Vector2 endPos, float thick, ::Color color) {
        ::DrawLineBezier(*this, endPos, thick, color);
        return *this;
    }

    inline Vector2& DrawCircle(float radius, ::Color color) {
        ::DrawCircleV(*this, radius, color);
        return *this;
    }

    inline Vector2& DrawRectangle(::Vector2 size, ::Color color) {
        ::DrawRectangleV(*this, size, color);
        return *this;
    }

    inline Vector2& DrawPoly(int sides, float radius, float rotation, ::Color color) {
        ::DrawPoly(*this, sides, radius, rotation, color);
        return *this;
    }

 protected:
    inline void set(::Vector2 vec) {
        x = vec.x;
        y = vec.y;
    }
};

}  // namespace raylib

#endif  // RAYLIB_CPP_INCLUDE_VECTOR2_HPP_
