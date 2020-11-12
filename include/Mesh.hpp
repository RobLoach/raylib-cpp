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

    inline Mesh& Export(const std::string& fileName) {
        ExportMesh(*this, fileName.c_str());
        return *this;
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

    inline Mesh& Tangents() {
        ::MeshTangents(this);
        return *this;
    }

    inline Mesh& Binormals() {
        ::MeshBinormals(this);
        return *this;
    }

    inline Mesh& NormalsSmooth() {
        ::MeshNormalsSmooth(this);
        return *this;
    }

    inline raylib::Model LoadModelFrom() {
        return ::LoadModelFromMesh(*this);
    }

    operator raylib::Model() {
        return LoadModelFrom();
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
