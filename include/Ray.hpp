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

#ifndef RAYLIB_CPP_INCLUDE_RAY_HPP_
#define RAYLIB_CPP_INCLUDE_RAY_HPP_

#include "./raylib.hpp"

#include "./raylib-cpp-utils.hpp"

#include "./RayHitInfo.hpp"

namespace raylib {
class Ray : public ::Ray {
 public:
    Ray(::Ray ray) {
        set(ray);
    }

    Ray(::Vector3 Position, ::Vector3 Direction) {
        position = Position;
        direction = Direction;
    }

    Ray(::Vector2 mousePosition, ::Camera camera) {
        set(GetMouseRay(mousePosition, camera));
    }

    Ray& operator=(const ::Ray& ray) {
        set(ray);
        return *this;
    }

    Ray& operator=(const Ray& ray) {
        set(ray);
        return *this;
    }

    GETTERSETTER(::Vector3, Position, position)
    GETTERSETTER(::Vector3, Direction, direction)

    inline Ray& Draw(::Color color) {
        DrawRay(*this, color);
        return *this;
    }

    inline bool CheckCollisionSphere(::Vector3 center, float radius) const {
        return CheckCollisionRaySphere(*this, center, radius);
    }

    inline bool CheckCollisionSphereEx(::Vector3 center, float radius,
            ::Vector3 *collisionPoint) const {
        return CheckCollisionRaySphereEx(*this, center, radius, collisionPoint);
    }

    inline bool CheckCollisionBox(::BoundingBox box) const {
        return CheckCollisionRayBox(*this, box);
    }

    inline RayHitInfo GetCollisionModel(::Model model) {
        return GetCollisionRayModel(*this, model);
    }

    inline RayHitInfo GetCollisionTriangle(::Vector3 p1, ::Vector3 p2, ::Vector3 p3) {
        return GetCollisionRayTriangle(*this, p1, p2, p3);
    }

    inline RayHitInfo GetCollisionGround(float groundHeight) {
        return GetCollisionRayGround(*this, groundHeight);
    }

 protected:
    inline void set(::Ray ray) {
        position = ray.position;
        direction = ray.direction;
    }
};
}  // namespace raylib

#endif  // RAYLIB_CPP_INCLUDE_RAY_HPP_
