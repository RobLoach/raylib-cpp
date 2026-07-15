#ifndef RAYLIB_CPP_INCLUDE_VECTOR4_HPP_
#define RAYLIB_CPP_INCLUDE_VECTOR4_HPP_


#include <string>

#include "./raylib-cpp-utils.hpp"
#include "./raylib.hpp"
#include "./raymath.hpp"

namespace raylib {
class Quaternion : public ::Quaternion {};

/**
 * Vector4 type
 */
class Vector4 : public ::Vector4 {
public:
    constexpr Vector4(const ::Vector4& vec) : ::Vector4{vec.x, vec.y, vec.z, vec.w} {}
    explicit constexpr Vector4(const raylib::Quaternion quat) : ::Vector4{quat.x, quat.y, quat.z, quat.w} {}

    explicit constexpr Vector4(const float x = 0, const float y = 0, const float z = 0, const float w = 0) : ::Vector4{x, y, z, w} {}
    explicit constexpr Vector4(const ::Rectangle rectangle) : ::Vector4{rectangle.x, rectangle.y, rectangle.width, rectangle.height} {}

    explicit Vector4(const ::Color color) { set(ColorNormalize(color)); }

    GETTERSETTER(float, X, x)
    GETTERSETTER(float, Y, y)
    GETTERSETTER(float, Z, z)
    GETTERSETTER(float, W, w)

    Vector4& operator=(const ::Vector4& vector4) {
        set(vector4);
        return *this;
    }

    /*
     * An exact value by value equality comparison.
     * Due to floating point inaccuracies consider using Equals instead.
     */
    constexpr bool operator==(const ::Vector4& other) const {
        return x == other.x && y == other.y && z == other.z && w == other.w;
    }

    /*
     * An exact value by value inequality comparison.
     * Due to floating point inaccuracies consider using Equals instead.
     */
    constexpr bool operator!=(const ::Vector4& other) const { return !(*this == other); }

    RLCPP_NODISCARD constexpr ::Rectangle ToRectangle() const { return {x, y, z, w}; }

    constexpr operator ::Rectangle() const { return {x, y, z, w}; }

    RLCPP_NODISCARD std::string ToString() const { return ::TextFormat("Vector4(%f, %f, %f, %f)", x, y, z, w); }

    operator std::string() const { return ToString(); }

#ifndef RAYLIB_CPP_NO_MATH
    static Vector4 Zero() { return ::Vector4Zero(); }

    static Vector4 One() { return ::Vector4One(); }

    /**
     * Add two vectors
     */
    RLCPP_NODISCARD Vector4 Add(const ::Vector4& vector4) const { return ::Vector4Add(*this, vector4); }

    /**
     * Add two vectors
     */
    Vector4 operator+(const ::Vector4& vector4) const { return ::Vector4Add(*this, vector4); }

    Vector4& operator+=(const ::Vector4& vector4) {
        set(::Vector4Add(*this, vector4));

        return *this;
    }

    /**
     * Add vector and float value
     */
    RLCPP_NODISCARD Vector4 Add(const float value) const {
        return ::Vector4AddValue(*this, value);
    }

    /**
     * Add vector and float value
     */
    Vector4 operator+(const float value) const {
        return ::Vector4AddValue(*this, value);
    }

    /**
     * Add vector and float value
     */
    Vector4& operator+=(const float value) {
        set(::Vector4AddValue(*this, value));

        return *this;
    }

    /**
     * Add vector and float value
     */
    friend Vector4 operator+(const float lhs, const Vector4& rhs) { return rhs + lhs; }

    /**
     * Subtract two vectors.
     */
    RLCPP_NODISCARD Vector4 Subtract(const ::Vector4& vector4) const { return ::Vector4Subtract(*this, vector4); }

    /**
     * Subtract two vectors.
     */
    Vector4 operator-(const ::Vector4& vector4) const { return ::Vector4Subtract(*this, vector4); }

    Vector4& operator-=(const ::Vector4& vector4) {
        set(::Vector4Subtract(*this, vector4));

        return *this;
    }

    /**
     * Subtract vector by float value
     */
    RLCPP_NODISCARD Vector4 Subtract(const float value) const {
        return ::Vector4SubtractValue(*this, value);
    }

    /**
     * Subtract vector by float value
     */
    Vector4 operator-(const float value) const {
        return ::Vector4SubtractValue(*this, value);
    }

    /**
     * Subtract vector by float value
     */
    Vector4& operator-=(const float value) {
        set(::Vector4SubtractValue(*this, value));

        return *this;
    }

    /**
     * Subtract vector by float value
     */
    friend Vector4 operator-(const float lhs, const Vector4& rhs) { return rhs - lhs; }

    /**
     * Negate provided vector
     */
    RLCPP_NODISCARD Vector4 Negate() const { return ::Vector4Negate(*this); }

    /**
     * Negate provided vector
     */
    Vector4 operator-() const { return ::Vector4Negate(*this); }

    /**
     * Multiply vector by vector
     */
    RLCPP_NODISCARD Vector4 Multiply(const ::Vector4& other) const { return ::Vector4Multiply(*this, other); }

    /**
     * Multiply vector by vector
     */
    Vector4 operator*(const ::Vector4& other) const { return ::Vector4Multiply(*this, other); }

    /**
     * Multiply vector by vector
     */
    Vector4& operator*=(const ::Vector4& other) {
        set(::Vector4Multiply(*this, other));

        return *this;
    }

    /**
     * Scale vector components by value (multiply)
     */
    RLCPP_NODISCARD Vector4 Scale(const float scale) const { return ::Vector4Scale(*this, scale); }

    /**
     * Scale vector components by value (multiply)
     */
    Vector4 operator*(const float scale) const { return ::Vector4Scale(*this, scale); }

    /**
     * Scale vector components by value (multiply)
     */
    Vector4& operator*=(const float scale) {
        set(::Vector4Scale(*this, scale));

        return *this;
    }

    /**
     * Scale vector components by value (multiply)
     */
    friend Vector4 operator*(const float lhs, const Vector4& rhs) { return rhs * lhs; }

    /**
     * Divide vector by vector
     */
    RLCPP_NODISCARD Vector4 Divide(const ::Vector4& vector4) const { return ::Vector4Divide(*this, vector4); }

    /**
     * Divide vector by vector
     */
    Vector4 operator/(const ::Vector4& vector4) const { return ::Vector4Divide(*this, vector4); }

    /**
     * Divide vector by vector
     */
    Vector4& operator/=(const ::Vector4& vector4) {
        set(::Vector4Divide(*this, vector4));

        return *this;
    }

    /**
     * Divide vector components by value
     */
    RLCPP_NODISCARD constexpr Vector4 Divide(const float div) const { return ::Vector4{x / div, y / div, z / div, w / div}; }

    /**
     * Divide vector components by value
     */
    Vector4 operator/(const float div) const { return Divide(div); }

    /**
     * Divide vector components by value
     */
    Vector4& operator/=(const float div) {
        x /= div;
        y /= div;
        z /= div;
        w /= div;

        return *this;
    }

    /**
     * Divide vector components by value
     */
    constexpr friend Vector4 operator/(const float lhs, const Vector4& rhs) {
        return Vector4{
            lhs / rhs.x,
            lhs / rhs.y,
            lhs / rhs.z,
            lhs / rhs.w
        };
    }

    RLCPP_NODISCARD float Length() const { return ::Vector4Length(*this); }

    RLCPP_NODISCARD float LengthSqr() const { return ::Vector4LengthSqr(*this); }

    RLCPP_NODISCARD float DotProduct(const ::Vector4& v2) const { return ::Vector4DotProduct(*this, v2); }

    RLCPP_NODISCARD float Distance(const ::Vector4& v2) const { return ::Vector4Distance(*this, v2); }

    RLCPP_NODISCARD float DistanceSqr(const ::Vector4& v2) const { return ::Vector4DistanceSqr(*this, v2); }

    RLCPP_NODISCARD Vector4 Normalize() const { return ::Vector4Normalize(*this); }

    RLCPP_NODISCARD Vector4 Min(const ::Vector4& v2) const { return ::Vector4Min(*this, v2); }

    RLCPP_NODISCARD Vector4 Max(const ::Vector4& v2) const { return ::Vector4Max(*this, v2); }

    RLCPP_NODISCARD Vector4 Lerp(const ::Vector4& v2, const float amount) const { return ::Vector4Lerp(*this, v2, amount); }

    RLCPP_NODISCARD Vector4 MoveTowards(const ::Vector4& target, const float maxDistance) const { return ::Vector4MoveTowards(*this, target, maxDistance); }

    RLCPP_NODISCARD Vector4 Invert() const { return ::Vector4Invert(*this); }

    /*
     * Check whether two given vectors are almost equal
     */
    RLCPP_NODISCARD bool Equals(const ::Vector4& other) const {
        return static_cast<bool>(::Vector4Equals(*this, other));
    }
#endif

    RLCPP_NODISCARD Color ColorFromNormalized() const { return ::ColorFromNormalized(*this); }

    operator Color() const { return ColorFromNormalized(); }
protected:
    void set(const ::Vector4& vec4) {
        x = vec4.x;
        y = vec4.y;
        z = vec4.z;
        w = vec4.w;
    }
};

} // namespace raylib

using RVector4 = raylib::Vector4;

#endif // RAYLIB_CPP_INCLUDE_VECTOR4_HPP_
