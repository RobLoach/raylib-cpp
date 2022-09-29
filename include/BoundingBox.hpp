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
    /*
     * Copy a bounding box from another bounding box.
     */
    BoundingBox(const ::BoundingBox& box) : ::BoundingBox{box.min, box.max} {
        // Nothing.
    }

    /**
     * Compute mesh bounding box limits
     */
    BoundingBox(const ::Mesh& mesh) {
        set(::GetMeshBoundingBox(mesh));
    }

    BoundingBox(::Vector3 minMax = ::Vector3{0.0f, 0.0f, 0.0f}) : ::BoundingBox{minMax, minMax} {}
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
    inline void Draw(::Color color = {255, 255, 255, 255}) const {
        ::DrawBoundingBox(*this, color);
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
    void set(const ::BoundingBox& box) {
        min = box.min;
        max = box.max;
    }
    void set(const ::Vector3& _min, const ::Vector3& _max) {
        min = _min;
        max = _max;
    }
};
}  // namespace raylib

using RBoundingBox = raylib::BoundingBox;

#endif  // RAYLIB_CPP_INCLUDE_BOUNDINGBOX_HPP_
