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
     * Get collision info between ray and mesh
     */
    RayHitInfo(const ::Ray& ray, const ::Mesh& mesh, const ::Matrix& transform) {
        set(::GetCollisionRayMesh(ray, mesh, transform));
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

    GETTERSETTER(bool, Hit, hit)
    GETTERSETTER(float, Distance, distance)
    GETTERSETTER(::Vector3, Position, position)
    GETTERSETTER(::Vector3, Normal, normal)

 private:
    inline void set(const ::RayHitInfo& ray) {
        hit = ray.hit;
        distance = ray.distance;
        position = ray.position;
        normal = ray.normal;
    }
};
}  // namespace raylib

#endif  // RAYLIB_CPP_INCLUDE_RAYHITINFO_HPP_
