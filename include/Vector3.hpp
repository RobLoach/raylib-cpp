#ifndef RAYLIB_CPP_INCLUDE_VECTOR3_HPP_
#define RAYLIB_CPP_INCLUDE_VECTOR3_HPP_

#ifndef RAYLIB_CPP_NO_MATH
#include <cmath>
#endif

#include <string>

#include "./raylib.hpp"
#include "./raymath.hpp"
#include "./raylib-cpp-utils.hpp"

namespace raylib {
/**
 * Vector3 type
 */
class Vector3 : public ::Vector3 {
 public:
    Vector3(const ::Vector3& vec) : ::Vector3{vec.x, vec.y, vec.z} {}

    Vector3(float x, float y, float z) : ::Vector3{x, y, z} {}
    Vector3(float x, float y) : ::Vector3{x, y, 0} {}
    Vector3(float x) : ::Vector3{x, 0, 0} {}
    Vector3() {}

    Vector3(::Color color) {
        set(ColorToHSV(color));
    }

    GETTERSETTER(float, X, x)
    GETTERSETTER(float, Y, y)
    GETTERSETTER(float, Z, z)

    Vector3& operator=(const ::Vector3& vector3) {
        set(vector3);
        return *this;
    }

    bool operator==(const ::Vector3& other) const {
        return x == other.x
            && y == other.y
            && z == other.z;
    }

    bool operator!=(const ::Vector3& other) const {
        return !(*this == other);
    }

    inline std::string ToString() const {
        return TextFormat("Vector3(%f, %f, %f)", x, y, z);
    }

    inline operator std::string() const {
        return ToString();
    }

#ifndef RAYLIB_CPP_NO_MATH
    /**
     * Add two vectors
     */
    inline Vector3 Add(const ::Vector3& vector3) const {
        return Vector3Add(*this, vector3);
    }

    /**
     * Add two vectors
     */
    inline Vector3 operator+(const ::Vector3& vector3) const {
        return Vector3Add(*this, vector3);
    }

    Vector3& operator+=(const ::Vector3& vector3) {
        set(Vector3Add(*this, vector3));

        return *this;
    }

    /**
     * Subtract two vectors.
     */
    inline Vector3 Subtract(const ::Vector3& vector3) const {
        return Vector3Subtract(*this, vector3);
    }

    /**
     * Subtract two vectors.
     */
    inline Vector3 operator-(const ::Vector3& vector3) const {
        return Vector3Subtract(*this, vector3);
    }

    Vector3& operator-=(const ::Vector3& vector3) {
        set(Vector3Subtract(*this, vector3));

        return *this;
    }

    /**
     * Negate provided vector (invert direction)
     */
    inline Vector3 Negate() const {
        return Vector3Negate(*this);
    }

    /**
     * Negate provided vector (invert direction)
     */
    inline Vector3 operator-() const {
        return Vector3Negate(*this);
    }

    /**
     * Multiply vector by vector
     */
    inline Vector3 Multiply(const ::Vector3& vector3) const {
        return Vector3Multiply(*this, vector3);
    }

    /**
     * Multiply vector by vector
     */
    inline Vector3 operator*(const ::Vector3& vector3) const {
        return Vector3Multiply(*this, vector3);
    }

    /**
     * Multiply vector by vector
     */
    Vector3& operator*=(const ::Vector3& vector3) {
        set(Vector3Multiply(*this, vector3));

        return *this;
    }

    /**
     * Multiply vector by scalar
     */
    inline Vector3 Scale(const float scaler) const {
        return Vector3Scale(*this, scaler);
    }

    /**
     * Multiply vector by scalar
     */
    inline Vector3 operator*(const float scaler) const {
        return Vector3Scale(*this, scaler);
    }

    /**
     * Multiply vector by scalar
     */
    Vector3& operator*=(const float scaler) {
        set(Vector3Scale(*this, scaler));

        return *this;
    }

    /**
     * Divide vector by vector
     */
    inline Vector3 Divide(const ::Vector3& vector3) const {
        return Vector3Divide(*this, vector3);
    }

    /**
     * Divide vector by vector
     */
    inline Vector3 operator/(const ::Vector3& vector3) const {
        return Vector3Divide(*this, vector3);
    }

    /**
     * Divide vector by vector
     */
    Vector3& operator/=(const ::Vector3& vector3) {
        x /= vector3.x;
        y /= vector3.y;
        z /= vector3.z;

        return *this;
    }

    /**
     * Divide a vector by a value.
     */
    inline Vector3 Divide(const float div) const {
        return ::Vector3{x / div, y / div, z / div};
    }

    /**
     * Divide a vector by a value.
     */
    inline Vector3 operator/(const float div) const {
        return Divide(div);
    }

    /**
     * Divide a vector by a value.
     */
    Vector3& operator/=(const float div) {
        x /= div;
        y /= div;
        z /= div;

        return *this;
    }

    /**
     * Calculate vector length
     */
    inline float Length() const {
        return Vector3Length(*this);
    }

    inline Vector3 Normalize() const {
        return Vector3Normalize(*this);
    }

    inline float DotProduct(const ::Vector3& vector3) const {
        return Vector3DotProduct(*this, vector3);
    }

    inline float Distance(const ::Vector3& vector3) const {
        return Vector3Distance(*this, vector3);
    }

    inline Vector3 Lerp(const ::Vector3& vector3, const float amount) const {
        return Vector3Lerp(*this, vector3, amount);
    }

    inline Vector3 CrossProduct(const ::Vector3& vector3) const {
        return Vector3CrossProduct(*this, vector3);
    }

    inline Vector3 Perpendicular() const {
        return Vector3Perpendicular(*this);
    }

    inline void OrthoNormalize(::Vector3* vector3) {
        Vector3OrthoNormalize(this, vector3);
    }

    inline Vector3 Transform(const ::Matrix& matrix) const {
        return Vector3Transform(*this, matrix);
    }

    inline Vector3 RotateByQuaternion(const ::Quaternion& quaternion) const {
        return Vector3RotateByQuaternion(*this, quaternion);
    }

    inline Vector3 Reflect(const ::Vector3& normal) const {
        return Vector3Reflect(*this, normal);
    }

    inline Vector3 Min(const ::Vector3& vector3) const {
        return Vector3Min(*this, vector3);
    }

    inline Vector3 Max(const ::Vector3& vector3) const {
        return Vector3Max(*this, vector3);
    }

    inline Vector3 Barycenter(const ::Vector3& a, const ::Vector3& b, const ::Vector3& c) const {
        return Vector3Barycenter(*this, a, b, c);
    }

    static inline Vector3 Zero() {
        return Vector3Zero();
    }

    static inline Vector3 One() {
        return Vector3One();
    }
#endif

    inline void DrawLine3D(const ::Vector3& endPos, ::Color color) const {
        ::DrawLine3D(*this, endPos, color);
    }

    inline void DrawPoint3D(::Color color) const {
        ::DrawPoint3D(*this, color);
    }

    inline void DrawCircle3D(
            float radius,
            const ::Vector3& rotationAxis,
            float rotationAngle,
            Color color) const {
        ::DrawCircle3D(*this, radius, rotationAxis, rotationAngle, color);
    }

    inline void DrawCube(float width, float height, float length, ::Color color) const {
        ::DrawCube(*this, width, height, length, color);
    }

    inline void DrawCube(const ::Vector3& size, ::Color color) const {
        ::DrawCubeV(*this, size, color);
    }

    inline void DrawCubeWires(float width, float height, float length, ::Color color) const {
        ::DrawCubeWires(*this, width, height, length, color);
    }

    inline void DrawCubeWires(const ::Vector3& size, ::Color color) const {
        ::DrawCubeWiresV(*this, size, color);
    }

    inline void DrawSphere(float radius, ::Color color) const {
        ::DrawSphere(*this, radius, color);
    }

    inline void DrawSphere(float radius, int rings, int slices, ::Color color) const {
        ::DrawSphereEx(*this, radius, rings, slices, color);
    }

    inline void DrawSphereWires(float radius, int rings, int slices, ::Color color) const {
        ::DrawSphereWires(*this, radius, rings, slices, color);
    }

    inline void DrawCylinder(float radiusTop, float radiusBottom, float height,
            int slices, ::Color color) const {
        ::DrawCylinder(*this, radiusTop, radiusBottom, height, slices, color);
    }

    inline void DrawCylinderWires(float radiusTop, float radiusBottom, float height,
            int slices, ::Color color) const {
        ::DrawCylinderWires(*this, radiusTop, radiusBottom, height, slices, color);
    }

    inline void DrawPlane(const ::Vector2& size, ::Color color) const {
        ::DrawPlane(*this, size, color);
    }

    /**
     * Detect collision between two spheres
     */
    inline bool CheckCollision(float radius1, const ::Vector3& center2, float radius2) const {
        return CheckCollisionSpheres(*this, radius1, center2, radius2);
    }

 protected:
    void set(const ::Vector3& vec) {
        x = vec.x;
        y = vec.y;
        z = vec.z;
    }
};
}  // namespace raylib

using RVector3 = raylib::Vector3;

#endif  // RAYLIB_CPP_INCLUDE_VECTOR3_HPP_
