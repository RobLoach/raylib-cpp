#ifndef RAYLIB_CPP_INCLUDE_RAY_HPP_
#define RAYLIB_CPP_INCLUDE_RAY_HPP_

#include "./raylib.hpp"
#include "./raylib-cpp-utils.hpp"
#include "./RayHitInfo.hpp"

namespace raylib {
/**
 * Ray type (useful for raycast)
 */
class Ray : public ::Ray {
 public:
    Ray(const ::Ray& ray) {
        set(ray);
    }

    Ray(::Vector3 Position, ::Vector3 Direction) {
        position = Position;
        direction = Direction;
    }

    Ray(::Vector2 mousePosition, ::Camera camera) {
        set(::GetMouseRay(mousePosition, camera));
    }

    Ray& operator=(const ::Ray& ray) {
        set(ray);
        return *this;
    }

    GETTERSETTER(::Vector3, Position, position)
    GETTERSETTER(::Vector3, Direction, direction)

    /**
     * Draw a ray line
     */
    inline Ray& Draw(::Color color) {
        DrawRay(*this, color);
        return *this;
    }

    /**
     * Detect collision between ray and sphere
     */
    inline bool CheckCollisionSphere(::Vector3 center, float radius) const {
        return CheckCollisionRaySphere(*this, center, radius);
    }

    /**
     * Detect collision between ray and sphere, returns collision point
     */
    inline bool CheckCollisionSphere(::Vector3 center, float radius,
            ::Vector3 *collisionPoint) const {
        return CheckCollisionRaySphereEx(*this, center, radius, collisionPoint);
    }

    /**
     * Detect collision between ray and box
     */
    inline bool CheckCollision(const ::BoundingBox& box) const {
        return CheckCollisionRayBox(*this, box);
    }

    /**
     * Get collision info between ray and model
     */
    inline RayHitInfo GetCollision(const ::Model& model) const {
        return GetCollisionRayModel(*this, model);
    }

    /**
     * Get collision info between ray and triangle
     */
    inline RayHitInfo GetCollisionTriangle(::Vector3 p1, ::Vector3 p2, ::Vector3 p3) const {
        return GetCollisionRayTriangle(*this, p1, p2, p3);
    }

    /**
     * Get collision info between ray and ground plane (Y-normal plane)
     */
    inline RayHitInfo GetCollisionGround(float groundHeight) const {
        return GetCollisionRayGround(*this, groundHeight);
    }

 private:
    inline void set(const ::Ray& ray) {
        position = ray.position;
        direction = ray.direction;
    }
};
}  // namespace raylib

#endif  // RAYLIB_CPP_INCLUDE_RAY_HPP_
