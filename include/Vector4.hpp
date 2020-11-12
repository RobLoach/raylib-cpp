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

#ifndef RAYLIB_CPP_INCLUDE_VECTOR4_HPP_
#define RAYLIB_CPP_INCLUDE_VECTOR4_HPP_

#ifndef RAYLIB_CPP_NO_MATH
#include <cmath>
#include <utility>
#endif

#include "./raylib.hpp"
#include "./raymath.hpp"
#include "./raylib-cpp-utils.hpp"

namespace raylib {
class Vector4 : public ::Vector4 {
 public:
    Vector4(::Vector4 vec) {
        set(vec);
    }

    Vector4(float x, float y, float z, float w) : ::Vector4{x, y, z, w} {};
    Vector4(float x, float y, float z) : ::Vector4{x, y, z, 0} {};
    Vector4(float x, float y) : ::Vector4{x, y, 0, 0} {};
    Vector4(float x) : ::Vector4{x, 0, 0, 0} {};
    Vector4() {};

    Vector4(::Color color) {
        set(ColorNormalize(color));
    }

    GETTERSETTER(float, X, x)
    GETTERSETTER(float, Y, y)
    GETTERSETTER(float, Z, z)
    GETTERSETTER(float, W, w)

    Vector4& operator=(const ::Vector4& vector4) {
        set(vector4);
        return *this;
    }

    Vector4& operator=(const Vector4& vector4) {
        set(vector4);
        return *this;
    }

    bool operator==(const Vector4& other) {
        return x == other.x
            && y == other.y
            && z == other.z
            && w == other.w;
    }

#ifndef RAYLIB_CPP_NO_MATH
    Vector4 Multiply(const Vector4& vector4) {
        return QuaternionMultiply(*this, vector4);
    }

    Vector4 operator*(const Vector4& vector4) {
        return QuaternionMultiply(*this, vector4);
    }

    Vector4 Lerp(const Vector4& vector4, float amount) {
        return QuaternionLerp(*this, vector4, amount);
    }

    Vector4 Nlerp(const Vector4& vector4, float amount) {
        return QuaternionNlerp(*this, vector4, amount);
    }

    Vector4 Slerp(const Vector4& vector4, float amount) {
        return QuaternionSlerp(*this, vector4, amount);
    }

    Matrix ToMatrix() {
        return QuaternionToMatrix(*this);
    }

    float Length() const {
        return QuaternionLength(*this);
    }

    Vector4 Normalize() {
        return QuaternionNormalize(*this);
    }

    Vector4 Invert() {
        return QuaternionInvert(*this);
    }

    void ToAxisAngle(Vector3 *outAxis, float *outAngle) {
        return QuaternionToAxisAngle(*this, outAxis, outAngle);
    }

    std::pair<Vector3, float> ToAxisAngle() {
        Vector3 outAxis;
        float outAngle;

        QuaternionToAxisAngle(*this, &outAxis, &outAngle);

        std::pair<Vector3, float> out(outAxis, outAngle);

        return out;
    }

    Vector4 Transform(const ::Matrix& matrix) {
        return ::QuaternionTransform(*this, matrix);
    }

    static Vector4 Identity() {
        return ::QuaternionIdentity();
    }

    static Vector4 FromVector3ToVector3(const Vector3& from , const Vector3& to) {
        return ::QuaternionFromVector3ToVector3(from , to);
    }

    static Vector4 FromMatrix(const ::Matrix& matrix) {
        return ::QuaternionFromMatrix(matrix);
    }

    static Vector4 FromAxisAngle(const Vector3& axis, const float angle) {
        return ::QuaternionFromAxisAngle(axis, angle);
    }

    static Vector4 FromEuler(const float roll, const float pitch, const float yaw) {
        return ::QuaternionFromEuler(roll, pitch, yaw);
    }

    static Vector4 FromEuler(const Vector3& vector3) {
        return ::QuaternionFromEuler(vector3.x, vector3.y, vector3.z);
    }

    Vector3 ToEuler() {
        return ::QuaternionToEuler(*this);
    }
#endif

    inline Color ColorFromNormalized() {
        return ::ColorFromNormalized(*this);
    }

    operator Color() {
        return ColorFromNormalized();
    }

 protected:
    inline void set(::Vector4 vec4) {
        x = vec4.x;
        y = vec4.y;
        z = vec4.z;
        w = vec4.w;
    }
};

// Alias the Vector4 as Quaternion.
typedef Vector4 Quaternion;
}  // namespace raylib

#endif  // RAYLIB_CPP_INCLUDE_VECTOR4_HPP_
