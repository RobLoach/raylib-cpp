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
        set(::GetMeshBoundingBox(mesh));
    }

    BoundingBox(::Vector3 minMax) : ::BoundingBox{minMax, minMax} {}
    BoundingBox(::Vector3 min, ::Vector3 max) : ::BoundingBox{min, max} {}

    GETTERSETTER(::Vector3, Min, min)
    GETTERSETTER(::Vector3, Max, max)

    BoundingBox& operator=(const ::BoundingBox& box) {
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
        return GetRayCollisionBox(ray, *this).hit;
    }

    /**
     * Get collision information between ray and bounding box
     */
    inline RayCollision GetCollision(const ::Ray& ray) const {
        return GetRayCollisionBox(ray, *this);
    }

 private:
    inline void set(const ::BoundingBox& box) {
        min = box.min;
        max = box.max;
    }
};
}  // namespace raylib

#endif  // RAYLIB_CPP_INCLUDE_BOUNDINGBOX_HPP_
