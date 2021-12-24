#ifndef RAYLIB_CPP_INCLUDE_VECTOR3_HPP_
#define RAYLIB_CPP_INCLUDE_VECTOR3_HPP_

#ifndef RAYLIB_CPP_NO_MATH
#include <cmath>
#endif

#include "./raylib.hpp"
#include "./raymath.hpp"
#include "./raylib-cpp-utils.hpp"

namespace raylib {
/**
 * Vector3 type
 */
class Vector3 : public ::Vector3 {
 public:
    Vector3(const ::Vector3& vec) {
        set(vec);
    }

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

    bool operator==(const ::Vector3& other) {
        return x == other.x
            && y == other.y
            && z == other.z;
    }

#ifndef RAYLIB_CPP_NO_MATH
    Vector3 Add(const ::Vector3& vector3) {
        return Vector3Add(*this, vector3);
    }

    Vector3 operator+(const ::Vector3& vector3) {
        return Vector3Add(*this, vector3);
    }

    Vector3 Subtract(const ::Vector3& vector3) {
        return Vector3Subtract(*this, vector3);
    }

    Vector3 operator-(const ::Vector3& vector3) {
        return Vector3Subtract(*this, vector3);
    }

    Vector3 Negate() {
        return Vector3Negate(*this);
    }

    Vector3 operator-() {
        return Vector3Negate(*this);
    }

    Vector3 Multiply(const ::Vector3& vector3) const {
        return Vector3Multiply(*this, vector3);
    }

    Vector3 operator*(const ::Vector3& vector3) const {
        return Vector3Multiply(*this, vector3);
    }

    Vector3 Scale(const float scale) const {
        return Vector3Scale(*this, scale);
    }

    Vector3 operator*(const float scale) const {
        return Vector3Scale(*this, scale);
    }

    Vector3 Divide(const ::Vector3& vector3) const {
        return Vector3Divide(*this, vector3);
    }

    Vector3 operator/(const ::Vector3& vector3) const {
        return Vector3Divide(*this, vector3);
    }

    Vector3 Divide(const float div) const {
        return ::Vector3{x / div, y / div, z / div};
    }

    Vector3 operator/(const float div) const {
        return Divide(div);
    }

    Vector3& operator+=(const ::Vector3& vector3) {
        set(Vector3Add(*this, vector3));

        return *this;
    }

    Vector3& operator-=(const ::Vector3& vector3) {
        set(Vector3Subtract(*this, vector3));

        return *this;
    }


    Vector3& operator*=(const ::Vector3& vector3) {
        set(Vector3Multiply(*this, vector3));

        return *this;
    }

    Vector3& operator*=(const float scale) {
        set(Vector3Scale(*this, scale));

        return *this;
    }

    Vector3& operator/=(const ::Vector3& vector3) {
        x /= vector3.x;
        y /= vector3.y;
        z /= vector3.z;

        return *this;
    }

    Vector3& operator/=(const float div) {
        x /= div;
        y /= div;
        z /= div;

        return *this;
    }

    float Length() const {
        return Vector3Length(*this);
    }

    Vector3 Normalize() const {
        return Vector3Normalize(*this);
    }

    float DotProduct(const ::Vector3& vector3) {
        return Vector3DotProduct(*this, vector3);
    }

    float Distance(const ::Vector3& vector3) const {
        return Vector3Distance(*this, vector3);
    }

    Vector3 Lerp(const ::Vector3& vector3, const float amount) const {
        return Vector3Lerp(*this, vector3, amount);
    }

    Vector3 CrossProduct(const ::Vector3& vector3) const {
        return Vector3CrossProduct(*this, vector3);
    }

    Vector3 Perpendicular() const {
        return Vector3Perpendicular(*this);
    }

    void OrthoNormalize(::Vector3* vector3) {
        Vector3OrthoNormalize(this, vector3);
    }

    Vector3 Transform(const ::Matrix& matrix) const {
        return Vector3Transform(*this, matrix);
    }

    Vector3 RotateByQuaternion(const ::Quaternion& quaternion) {
        return Vector3RotateByQuaternion(*this, quaternion);
    }

    Vector3 Reflect(const ::Vector3& normal) const {
        return Vector3Reflect(*this, normal);
    }

    Vector3 Min(const ::Vector3& vector3) {
        return Vector3Min(*this, vector3);
    }

    Vector3 Max(const ::Vector3& vector3) {
        return Vector3Max(*this, vector3);
    }

    Vector3 Barycenter(const ::Vector3& a, const ::Vector3& b, const ::Vector3& c) {
        return Vector3Barycenter(*this, a, b, c);
    }

    static Vector3 Zero() {
        return Vector3Zero();
    }

    static Vector3 One() {
        return Vector3One();
    }
#endif

    inline Vector3& DrawLine3D(const ::Vector3& endPos, ::Color color) {
        ::DrawLine3D(*this, endPos, color);
        return *this;
    }

    inline Vector3& DrawPoint3D(::Color color) {
        ::DrawPoint3D(*this, color);
        return *this;
    }

    inline Vector3& DrawCircle3D(
            float radius,
            const ::Vector3& rotationAxis,
            float rotationAngle,
            Color color) {
        ::DrawCircle3D(*this, radius, rotationAxis, rotationAngle, color);
        return *this;
    }

    inline Vector3& DrawCube(float width, float height, float length, ::Color color) {
        ::DrawCube(*this, width, height, length, color);
        return *this;
    }

    inline Vector3& DrawCube(const ::Vector3& size, ::Color color) {
        ::DrawCubeV(*this, size, color);
        return *this;
    }

    inline Vector3& DrawCubeWires(float width, float height, float length, ::Color color) {
        ::DrawCubeWires(*this, width, height, length, color);
        return *this;
    }

    inline Vector3& DrawCubeWires(const ::Vector3& size, ::Color color) {
        ::DrawCubeWiresV(*this, size, color);
        return *this;
    }

    inline Vector3& DrawCubeTexture(
            const ::Texture2D& texture,
            float width,
            float height,
            float length,
            ::Color color) {
        ::DrawCubeTexture(texture, *this, width, height, length, color);
        return *this;
    }

    inline Vector3& DrawSphere(float radius, ::Color color) {
        ::DrawSphere(*this, radius, color);
        return *this;
    }

    inline Vector3& DrawSphere(float radius, int rings, int slices, ::Color color) {
        ::DrawSphereEx(*this, radius, rings, slices, color);
        return *this;
    }

    inline Vector3& DrawSphereWires(float radius, int rings, int slices, ::Color color) {
        ::DrawSphereWires(*this, radius, rings, slices, color);
        return *this;
    }

    inline Vector3& DrawCylinder(float radiusTop, float radiusBottom, float height,
            int slices, Color color) {
        ::DrawCylinder(*this, radiusTop, radiusBottom, height, slices, color);
        return *this;
    }

    inline Vector3& DrawCylinderWires(float radiusTop, float radiusBottom, float height,
            int slices, Color color) {
        ::DrawCylinderWires(*this, radiusTop, radiusBottom, height, slices, color);
        return *this;
    }

    inline Vector3& DrawPlane(const ::Vector2& size, ::Color color) {
        ::DrawPlane(*this, size, color);
        return *this;
    }

    /**
     * Detect collision between two spheres
     */
    inline bool CheckCollision(float radius1, const ::Vector3& center2, float radius2) {
        return CheckCollisionSpheres(*this, radius1, center2, radius2);
    }

 private:
    inline void set(const ::Vector3& vec) {
        x = vec.x;
        y = vec.y;
        z = vec.z;
    }
};
}  // namespace raylib

#endif  // RAYLIB_CPP_INCLUDE_VECTOR3_HPP_
