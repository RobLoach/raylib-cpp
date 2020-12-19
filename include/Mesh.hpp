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

#ifndef RAYLIB_CPP_INCLUDE_MESH_HPP_
#define RAYLIB_CPP_INCLUDE_MESH_HPP_

#include <string>
#include <vector>

#include "./raylib.hpp"
#include "./raylib-cpp-utils.hpp"
#include "./BoundingBox.hpp"
#include "./Model.hpp"

namespace raylib {
class Mesh : public ::Mesh {
 public:
    Mesh(::Mesh mesh) {
        set(mesh);
    }

    Mesh(int VertexCount = 0, int TriangleCount = 0) {
        vertexCount = VertexCount;
        triangleCount = TriangleCount;
    }

    /**
     * Load meshes from model file
     */
    static std::vector<Mesh> Load(const std::string fileName) {
        int count = 0;
        ::Mesh* meshes = LoadMeshes(fileName.c_str(), &count);
        return std::vector<Mesh>(meshes, meshes + count);
    }

    GETTERSETTER(int, VertexCount, vertexCount)
    GETTERSETTER(int, TriangleCount, triangleCount)

    Mesh& operator=(const ::Mesh& mesh) {
        set(mesh);
        return *this;
    }

    Mesh& operator=(const Mesh& mesh) {
        set(mesh);
        return *this;
    }

    ~Mesh() {
        Unload();
    }

    /**
     * Export mesh data to file
     */
    inline bool Export(const std::string& fileName) {
        // TODO(RobLoach): Switch to an exception when failed.
        return ExportMesh(*this, fileName.c_str());
    }

    inline void Unload() {
        ::UnloadMesh(*this);
    }

    inline raylib::BoundingBox BoundingBox() {
        return ::MeshBoundingBox(*this);
    }

    operator raylib::BoundingBox() {
        return BoundingBox();
    }

    /**
     * Compute mesh tangents
     */
    inline Mesh& Tangents() {
        ::MeshTangents(this);
        return *this;
    }

    /**
     * Compute mesh binormals (aka bitangent)
     */
    inline Mesh& Binormals() {
        ::MeshBinormals(this);
        return *this;
    }

    /**
     * Smooth (average) vertex normals
     */
    inline Mesh& NormalsSmooth() {
        ::MeshNormalsSmooth(this);
        return *this;
    }

    /**
     * Load model from generated mesh
     */
    inline raylib::Model LoadModelFrom() {
        return ::LoadModelFromMesh(*this);
    }

    /**
     * Load model from generated mesh
     */
    operator raylib::Model() {
        return ::LoadModelFromMesh(*this);
    }

 protected:
    inline void set(::Mesh mesh) {
        vertexCount = mesh.vertexCount;
        triangleCount = mesh.triangleCount;
        vertices = mesh.vertices;
        texcoords = mesh.texcoords;
        texcoords2 = mesh.texcoords2;
        normals = mesh.normals;
        tangents = mesh.tangents;
        colors = mesh.colors;
        indices = mesh.indices;
        animVertices = mesh.animVertices;
        animNormals = mesh.animNormals;
        boneIds = mesh.boneIds;
        boneWeights = mesh.boneWeights;
        vaoId = mesh.vaoId;
        vboId = mesh.vboId;
    }
};
}  // namespace raylib

#endif  // RAYLIB_CPP_INCLUDE_MESH_HPP_
