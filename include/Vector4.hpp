#ifndef RAYLIB_CPP_INCLUDE_VECTOR4_HPP_
#define RAYLIB_CPP_INCLUDE_VECTOR4_HPP_

#ifndef RAYLIB_CPP_NO_MATH
#include <cmath>
#include <utility>
#endif

#include <string>

#include "./raylib-cpp-utils.hpp"
#include "./raylib.hpp"
#include "./raymath.hpp"

namespace raylib {
/**
 * Vector4 type
 */
class Vector4 : public ::Vector4 {
public:
    Vector4(const ::Vector4& vec) : ::Vector4{vec.x, vec.y, vec.z, vec.w} {}

    Vector4(float x, float y, float z, float w) : ::Vector4{x, y, z, w} {}
    Vector4(float x, float y, float z) : ::Vector4{x, y, z, 0} {}
    Vector4(float x, float y) : ::Vector4{x, y, 0, 0} {}
    Vector4(float x) : ::Vector4{x, 0, 0, 0} {}
    Vector4() : ::Vector4{0, 0, 0, 0} {}
    Vector4(::Rectangle rectangle) : ::Vector4{rectangle.x, rectangle.y, rectangle.width, rectangle.height} {}

    Vector4(::Color color) { set(ColorNormalize(color)); }

    GETTERSETTER(float, X, x)
    GETTERSETTER(float, Y, y)
    GETTERSETTER(float, Z, z)
    GETTERSETTER(float, W, w)

    Vector4& operator=(const ::Vector4& vector4) {
        set(vector4);
        return *this;
    }

    bool operator==(const ::Vector4& other) const {
        return x == other.x && y == other.y && z == other.z && w == other.w;
    }

    bool operator!=(const ::Vector4& other) const { return !(*this == other); }

    ::Rectangle ToRectangle() const { return {x, y, z, w}; }

    operator ::Rectangle() const { return {x, y, z, w}; }

    std::string ToString() const { return TextFormat("Vector4(%f, %f, %f, %f)", x, y, z, w); }

    operator std::string() const { return ToString(); }

#ifndef RAYLIB_CPP_NO_MATH
    Vector4 Multiply(const ::Vector4& vector4) const { return QuaternionMultiply(*this, vector4); }

    Vector4 operator*(const ::Vector4& vector4) const { return QuaternionMultiply(*this, vector4); }

    Vector4 Lerp(const ::Vector4& vector4, float amount) const { return QuaternionLerp(*this, vector4, amount); }

    Vector4 Nlerp(const ::Vector4& vector4, float amount) const { return QuaternionNlerp(*this, vector4, amount); }

    Vector4 Slerp(const ::Vector4& vector4, float amount) const { return QuaternionSlerp(*this, vector4, amount); }

    Matrix ToMatrix() const { return QuaternionToMatrix(*this); }

    float Length() const { return QuaternionLength(*this); }

    Vector4 Normalize() const { return QuaternionNormalize(*this); }

    Vector4 Invert() const { return QuaternionInvert(*this); }

    void ToAxisAngle(::Vector3* outAxis, float* outAngle) const { QuaternionToAxisAngle(*this, outAxis, outAngle); }

    /**
     * Get the rotation angle and axis for a given quaternion
     */
    std::pair<Vector3, float> ToAxisAngle() const {
        Vector3 outAxis;
        float outAngle;
        QuaternionToAxisAngle(*this, &outAxis, &outAngle);

        return std::pair<Vector3, float>(outAxis, outAngle);
    }

    Vector4 Transform(const ::Matrix& matrix) const { return ::QuaternionTransform(*this, matrix); }

    static Vector4 Identity() { return ::QuaternionIdentity(); }

    static Vector4 FromVector3ToVector3(const ::Vector3& from, const ::Vector3& to) {
        return ::QuaternionFromVector3ToVector3(from, to);
    }

    static Vector4 FromMatrix(const ::Matrix& matrix) { return ::QuaternionFromMatrix(matrix); }

    static Vector4 FromAxisAngle(const ::Vector3& axis, const float angle) {
        return ::QuaternionFromAxisAngle(axis, angle);
    }

    static Vector4 FromEuler(const float pitch, const float yaw, const float roll) {
        return ::QuaternionFromEuler(pitch, yaw, roll);
    }

    static Vector4 FromEuler(const ::Vector3& vector3) {
        return ::QuaternionFromEuler(vector3.x, vector3.y, vector3.z);
    }

    Vector3 ToEuler() const { return ::QuaternionToEuler(*this); }
#endif

    Color ColorFromNormalized() const { return ::ColorFromNormalized(*this); }

    operator Color() const { return ColorFromNormalized(); }
protected:
    void set(const ::Vector4& vec4) {
        x = vec4.x;
        y = vec4.y;
        z = vec4.z;
        w = vec4.w;
    }
};

// Alias the Vector4 as Quaternion.
using Quaternion = Vector4;

} // namespace raylib

using RVector4 = raylib::Vector4;
using RQuaternion = raylib::Quaternion;

#endif // RAYLIB_CPP_INCLUDE_VECTOR4_HPP_
