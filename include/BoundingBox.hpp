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

#ifndef RAYLIB_CPP_INCLUDE_BOUNDINGBOX_HPP_
#define RAYLIB_CPP_INCLUDE_BOUNDINGBOX_HPP_

#include "./raylib.hpp"
#include "./raylib-cpp-utils.hpp"

namespace raylib {
/**
 * Bounding box type
 */
class BoundingBox : public ::BoundingBox {
 public:
    BoundingBox(const ::BoundingBox& box) {
        set(box);
    }

    /**
     * Compute mesh bounding box limits
     */
    BoundingBox(const ::Mesh& mesh) {
        set(::MeshBoundingBox(mesh));
    }

    BoundingBox(::Vector3 Min, ::Vector3 Max) {
        min = Min;
        max = Max;
    }

    GETTERSETTER(::Vector3, Min, min)
    GETTERSETTER(::Vector3, Max, max)

    BoundingBox& operator=(const ::BoundingBox& box) {
        set(box);
        return *this;
    }

    BoundingBox& operator=(const BoundingBox& box) {
        set(box);
        return *this;
    }

    /**
     * Draw a bounding box with wires
     */
    inline BoundingBox& Draw(::Color color = {255, 255, 255, 255}) {
        DrawBoundingBox(*this, color);
        return *this;
    }

    /**
     * Detect collision between two boxes
     */
    inline bool CheckCollision(const ::BoundingBox& box2) const {
        return CheckCollisionBoxes(*this, box2);
    }

    /**
     * Detect collision between box and sphere
     */
    inline bool CheckCollision(::Vector3 center, float radius) const {
        return CheckCollisionBoxSphere(*this, center, radius);
    }

    /**
     * Detect collision between ray and bounding box
     */
    inline bool CheckCollision(const ::Ray& ray) const {
        return CheckCollisionRayBox(ray, *this);
    }

 protected:
    inline void set(const ::BoundingBox& box) {
        min = box.min;
        max = box.max;
    }
};
}  // namespace raylib

#endif  // RAYLIB_CPP_INCLUDE_BOUNDINGBOX_HPP_
