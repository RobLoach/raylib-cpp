#ifndef RAYLIB_CPP_INCLUDE_QUATERNION_HPP_
#define RAYLIB_CPP_INCLUDE_QUATERNION_HPP_

#ifndef RAYLIB_CPP_NO_MATH
#include <cmath>
#endif

#include <string>

#include "./raylib-cpp-utils.hpp"
#include "./raylib.hpp"
#include "./raymath.hpp"

namespace raylib {
class Vector4 : public ::Vector4 {};

/**
 * Quaternion type
 */
class Quaternion : public ::Quaternion {
public:
    constexpr Quaternion(const ::Quaternion& quat) : ::Quaternion{quat.x, quat.y, quat.z, quat.w} {}
    explicit constexpr Quaternion(const raylib::Vector4 vec4) : ::Quaternion{vec4.x, vec4.y, vec4.z, vec4.w} {}

    explicit constexpr Quaternion(const float x = 0, const float y = 0, const float z = 0, const float w = 1) : ::Quaternion{x, y, z, w} {}

    GETTERSETTER(float, X, x)
    GETTERSETTER(float, Y, y)
    GETTERSETTER(float, Z, z)
    GETTERSETTER(float, W, w)

    Quaternion& operator=(const ::Quaternion& quaternion) {
        set(quaternion);
        return *this;
    }

    /*
     * An exact value by value equality comparison.
     * Due to floating point inaccuracies consider using Equals instead.
     */
    constexpr bool operator==(const ::Quaternion& other) const {
        return x == other.x && y == other.y && z == other.z && w == other.w;
    }

    /*
     * An exact value by value inequality comparison.
     * Due to floating point inaccuracies consider using Equals instead.
     */
    constexpr bool operator!=(const ::Quaternion& other) const { return !(*this == other); }

    RLCPP_NODISCARD std::string ToString() const { return ::TextFormat("Quaternion(%f, %f, %f, %f)", x, y, z, w); }

    operator std::string() const { return ToString(); }

#ifndef RAYLIB_CPP_NO_MATH
    /**
     * Add two quaternions
     */
    RLCPP_NODISCARD Quaternion Add(const ::Quaternion& quaternion) const { return ::QuaternionAdd(*this, quaternion); }

    /**
     * Add two quaternions
     */
    Quaternion operator+(const ::Quaternion& quaternion) const { return ::QuaternionAdd(*this, quaternion); }

    Quaternion& operator+=(const ::Quaternion& quaternion) {
        set(::QuaternionAdd(*this, quaternion));

        return *this;
    }

    /**
     * Add quaternion and float value
     */
    RLCPP_NODISCARD Quaternion Add(const float value) const {
        return ::QuaternionAddValue(*this, value);
    }

    /**
     * Add quaternion and float value
     */
    Quaternion operator+(const float value) const {
        return ::QuaternionAddValue(*this, value);
    }

    /**
     * Add quaternion and float value
     */
    Quaternion& operator+=(const float value) {
        set(::QuaternionAddValue(*this, value));

        return *this;
    }

    /**
     * Add quaternion and float value
     */
    friend Quaternion operator+(const float lhs, const Quaternion& rhs) { return rhs + lhs; }

    /**
     * Subtract two quaternions.
     */
    RLCPP_NODISCARD Quaternion Subtract(const ::Quaternion& quaternion) const { return ::QuaternionSubtract(*this, quaternion); }

    /**
     * Subtract two quaternions.
     */
    Quaternion operator-(const ::Quaternion& quaternion) const { return ::QuaternionSubtract(*this, quaternion); }

    Quaternion& operator-=(const ::Quaternion& quaternion) {
        set(::QuaternionSubtract(*this, quaternion));

        return *this;
    }

    /**
     * Subtract quaternion by float value
     */
    RLCPP_NODISCARD Quaternion Subtract(const float value) const {
        return ::QuaternionSubtractValue(*this, value);
    }

    /**
     * Get identity quaternion
     */
    static RLCPP_NODISCARD Quaternion Identity() {
        return ::QuaternionIdentity();
    }

    RLCPP_NODISCARD float Length() const { return ::QuaternionLength(*this); }

    RLCPP_NODISCARD Quaternion Normalize() const { return ::QuaternionNormalize(*this); }

    RLCPP_NODISCARD Quaternion Invert() const { return ::QuaternionInvert(*this); }

    /**
     * Multiply quaternion by quaternion
     */
    RLCPP_NODISCARD Quaternion Multiply(const ::Quaternion& other) const { return ::QuaternionMultiply(*this, other); }

    /**
     * Multiply quaternion by quaternion
     */
    Quaternion operator*(const ::Quaternion& other) const { return ::QuaternionMultiply(*this, other); }

    /**
     * Multiply quaternion by quaternion
     */
    Quaternion& operator*=(const ::Quaternion& other) {
        set(::QuaternionMultiply(*this, other));

        return *this;
    }

    /**
     * Scale quaternion components by value (multiply)
     */
    RLCPP_NODISCARD Quaternion Scale(const float scale) const { return ::QuaternionScale(*this, scale); }

    /**
     * Divide quaternion by quaternion
     */
    RLCPP_NODISCARD Quaternion Divide(const ::Quaternion& quaternion) const { return ::QuaternionDivide(*this, quaternion); }

    /**
     * Divide quaternion by quaternion
     */
    Quaternion operator/(const ::Quaternion& quaternion) const { return ::QuaternionDivide(*this, quaternion); }

    /**
     * Divide quaternion by quaternion
     */
    Quaternion& operator/=(const ::Quaternion& quaternion) {
        set(::QuaternionDivide(*this, quaternion));

        return *this;
    }

    /**
     * Divide quaternion components by value
     */
    RLCPP_NODISCARD constexpr Quaternion Divide(const float div) const { return ::Quaternion{x / div, y / div, z / div, w / div}; }

    RLCPP_NODISCARD Quaternion Lerp(const ::Quaternion& v2, const float amount) const
    {
        return ::QuaternionLerp(*this, v2, amount);
    }

    /**
     * Calculate normalized linear interpolation between two quaternions
     */
    RLCPP_NODISCARD Quaternion Nlerp(const ::Quaternion& v2, const float amount) const {
        return ::QuaternionNlerp(*this, v2, amount);
    }

    /**
     * Calculates spherical linear interpolation between two quaternions
     */
    RLCPP_NODISCARD Quaternion Slerp(const ::Quaternion& v2, const float amount) const {
        return ::QuaternionSlerp(*this, v2, amount);
    }

    /**
     * Calculate quaternion cubic spline interpolation using Cubic Hermite Spline
     */
    RLCPP_NODISCARD Quaternion CubicHermiteSpline(
        const ::Quaternion& outTangent1,
        const ::Quaternion& q2,
        const ::Quaternion& inTangent2,
        const float t
    ) const {
        return ::QuaternionCubicHermiteSpline(*this, outTangent1, q2, inTangent2, t);
    }

    /**
     * Calculate quaternion based on the rotation from one vector to another
     */
    static RLCPP_NODISCARD Quaternion FromVector3ToVector3(const ::Vector3& from, const ::Vector3& to) {
        return ::QuaternionFromVector3ToVector3(from, to);
    }

    /**
     * Get a quaternion for a given rotation matrix
     */
    static RLCPP_NODISCARD Quaternion FromMatrix(const ::Matrix& mat) {
        return ::QuaternionFromMatrix(mat);
    }

    /**
     * Get a matrix for this quaternion
     */
    RLCPP_NODISCARD ::Matrix ToMatrix() const {
        return ::QuaternionToMatrix(*this);
    }

    /**
     * Get rotation quaternion for an angle and axis
     * NOTE: Angle must be provided in radians
     */
    static RLCPP_NODISCARD Quaternion FromAxisAngle(const ::Vector3& axis, const float angle) {
        return ::QuaternionFromAxisAngle(axis, angle);
    }

    /**
     * Get the rotation angle and axis for this quaternion
     */
    void ToAxisAngle(::Vector3* outAxis, float* outAngle) const {
        ::QuaternionToAxisAngle(*this, outAxis, outAngle);
    }

    /**
     * Get the quaternion equivalent to Euler angles
     * NOTE: Rotation order is ZYX
     */
    static RLCPP_NODISCARD Quaternion FromEuler(const float pitch, const float yaw, const float roll) {
        return ::QuaternionFromEuler(pitch, yaw, roll);
    }

    /**
     * Get the Euler angles equivalent to quaternion
     * NOTE: Angles are returned in radians
     */
    RLCPP_NODISCARD ::Vector3 ToEuler() const {
        return ::QuaternionToEuler(*this);
    }

    /**
     * Transform quaternion given transformation matrix
     */
    RLCPP_NODISCARD Quaternion Transform(const ::Matrix& mat) const {
        return ::QuaternionTransform(*this, mat);
    }

    /*
     * Check whether two given quaternions are almost equal
     */
    RLCPP_NODISCARD bool Equals(const ::Quaternion& other) const {
        return static_cast<bool>(::QuaternionEquals(*this, other));
    }
#endif
protected:
    void set(const ::Quaternion& quat) {
        x = quat.x;
        y = quat.y;
        z = quat.z;
        w = quat.w;
    }
};

} // namespace raylib

using RQuaternion = raylib::Quaternion;

#endif // RAYLIB_CPP_INCLUDE_QUATERNION_HPP_

