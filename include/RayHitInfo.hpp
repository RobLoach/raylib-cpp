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

#ifndef RAYLIB_CPP_INCLUDE_RAYHITINFO_HPP_
#define RAYLIB_CPP_INCLUDE_RAYHITINFO_HPP_

#include "./raylib.hpp"
#include "./raylib-cpp-utils.hpp"

namespace raylib {
/**
 * Raycast hit information
 */
class RayHitInfo : public ::RayHitInfo {
 public:
    RayHitInfo(const ::RayHitInfo& ray) {
        set(ray);
    }

    RayHitInfo(bool Hit, float Distance, ::Vector3 Position, ::Vector3 Normal) {
        hit = Hit;
        distance = Distance;
        position = Position;
        normal = Normal;
    }

    /**
     * Get collision info between ray and model
     */
    RayHitInfo(const ::Ray& ray, const ::Model& model) {
        set(::GetCollisionRayModel(ray, model));
    }

    /**
     * Get collision info between ray and triangle
     */
    RayHitInfo(const ::Ray& ray, ::Vector3 p1, ::Vector3 p2, ::Vector3 p3) {
        set(::GetCollisionRayTriangle(ray, p1, p2, p3));
    }

    /**
     * Get collision info between ray and ground plane (Y-normal plane)
     */
    RayHitInfo(const ::Ray& ray, float groundHeight) {
        set(::GetCollisionRayGround(ray, groundHeight));
    }

    RayHitInfo& operator=(const ::RayHitInfo& ray) {
        set(ray);
        return *this;
    }

    RayHitInfo& operator=(const RayHitInfo& ray) {
        set(ray);
        return *this;
    }

    GETTERSETTER(bool, Hit, hit)
    GETTERSETTER(float, Distance, distance)
    GETTERSETTER(::Vector3, Position, position)
    GETTERSETTER(::Vector3, Normal, normal)

 protected:
    inline void set(const ::RayHitInfo& ray) {
        hit = ray.hit;
        distance = ray.distance;
        position = ray.position;
        normal = ray.normal;
    }
};
}  // namespace raylib

#endif  // RAYLIB_CPP_INCLUDE_RAYHITINFO_HPP_
