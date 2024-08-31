#ifndef RAYLIB_CPP_INCLUDE_MESH_HPP_
#define RAYLIB_CPP_INCLUDE_MESH_HPP_

#include <string>
#include <vector>

#include "./BoundingBox.hpp"
#include "./MeshUnmanaged.hpp"
#include "./Model.hpp"
#include "./raylib-cpp-utils.hpp"
#include "./raylib.hpp"

namespace raylib {
/**
 * Vertex data defining a mesh
 *
 * The Mesh will be unloaded on object destruction.
 *
 * @see raylib::MeshUnmanaged
 */
class Mesh : public MeshUnmanaged {
public:
    using MeshUnmanaged::MeshUnmanaged;

    /**
     * Explicitly forbid the copy constructor.
     */
    Mesh(const Mesh&) = delete;

    /**
     * Explicitly forbid copy assignment.
     */
    Mesh& operator=(const Mesh&) = delete;

    /**
     * Move constructor.
     */
    Mesh(Mesh&& other) {
        set(other);

        other.vertexCount = 0;
        other.triangleCount = 0;
        other.vertices = nullptr;
        other.texcoords = nullptr;
        other.texcoords2 = nullptr;
        other.normals = nullptr;
        other.tangents = nullptr;
        other.colors = nullptr;
        other.indices = nullptr;
        other.animVertices = nullptr;
        other.animNormals = nullptr;
        other.boneIds = nullptr;
        other.boneWeights = nullptr;
        other.vaoId = 0;
        other.vboId = nullptr;
    }

    Mesh& operator=(Mesh&& other) noexcept {
        if (this == &other) {
            return *this;
        }

        Unload();
        set(other);

        other.vertexCount = 0;
        other.triangleCount = 0;
        other.vertices = nullptr;
        other.texcoords = nullptr;
        other.texcoords2 = nullptr;
        other.normals = nullptr;
        other.tangents = nullptr;
        other.colors = nullptr;
        other.indices = nullptr;
        other.animVertices = nullptr;
        other.animNormals = nullptr;
        other.boneIds = nullptr;
        other.boneWeights = nullptr;
        other.vaoId = 0;
        other.vboId = nullptr;

        return *this;
    }

    ~Mesh() { Unload(); }
};
} // namespace raylib

using RMesh = raylib::Mesh;

#endif // RAYLIB_CPP_INCLUDE_MESH_HPP_
