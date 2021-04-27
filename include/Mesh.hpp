#ifndef RAYLIB_CPP_INCLUDE_MESH_HPP_
#define RAYLIB_CPP_INCLUDE_MESH_HPP_

#include <string>
#include <vector>

#include "./raylib.hpp"
#include "./raylib-cpp-utils.hpp"
#include "./BoundingBox.hpp"
#include "./Model.hpp"

namespace raylib {
/**
 * Vertex data definning a mesh
 */
class Mesh : public ::Mesh {
 public:
    Mesh(const ::Mesh& mesh) {
        set(mesh);
    }

    Mesh(int VertexCount, int TriangleCount) {
        vertexCount = VertexCount;
        triangleCount = TriangleCount;
    }

    /**
     * Load meshes from model file
     */
    // static std::vector<Mesh> Load(const std::string& fileName) {
    //    int count = 0;
    //    ::Mesh* meshes = LoadMeshes(fileName.c_str(), &count);
    //    return std::vector<Mesh>(meshes, meshes + count);
    // }

    /**
     * Generate polygonal mesh
     */
    static ::Mesh Poly(int sides, float radius) {
        return ::GenMeshPoly(sides, radius);
    }

    /**
     * Generate plane mesh (with subdivisions)
     */
    static ::Mesh Plane(float width, float length, int resX, int resZ) {
        return ::GenMeshPlane(width, length, resX, resZ);
    }

    /**
     * Generate cuboid mesh
     */
    static ::Mesh Cube(float width, float height, float length) {
        return ::GenMeshCube(width, height, length);
    }

    /**
     * Generate sphere mesh (standard sphere)
     */
    static ::Mesh Sphere(float radius, int rings, int slices) {
        return ::GenMeshSphere(radius, rings, slices);
    }

    /**
     * Generate half-sphere mesh (no bottom cap)
     */
    static ::Mesh HemiSphere(float radius, int rings, int slices) {
        return ::GenMeshHemiSphere(radius, rings, slices);
    }

    /**
     * Generate cylinder mesh
     */
    static ::Mesh Cylinder(float radius, float height, int slices) {
        return ::GenMeshCylinder(radius, height, slices);
    }

    /**
     * Generate torus mesh
     */
    static ::Mesh Torus(float radius, float size, int radSeg, int sides) {
        return ::GenMeshTorus(radius, size, radSeg, sides);
    }

    /**
     * Generate trefoil knot mesh
     */
    static ::Mesh Knot(float radius, float size, int radSeg, int sides) {
        return ::GenMeshKnot(radius, size, radSeg, sides);
    }

    /**
     * Generate heightmap mesh from image data
     */
    static ::Mesh Heightmap(const ::Image& heightmap, ::Vector3 size) {
        return ::GenMeshHeightmap(heightmap, size);
    }

    /**
     * Generate cubes-based map mesh from image data
     */
    static ::Mesh Cubicmap(const ::Image& cubicmap, ::Vector3 cubeSize) {
        return ::GenMeshCubicmap(cubicmap, cubeSize);
    }

    GETTERSETTER(int, VertexCount, vertexCount)
    GETTERSETTER(int, TriangleCount, triangleCount)
    GETTERSETTER(float*, Vertices, vertices)
    GETTERSETTER(float *, TexCoords, texcoords)
    GETTERSETTER(float *, TexCoords2, texcoords2)
    GETTERSETTER(float *, Normals, normals)
    GETTERSETTER(float *, Tangents, tangents)
    GETTERSETTER(unsigned char *, Colors, colors)
    GETTERSETTER(unsigned short *, Indices, indices) // NOLINT
    GETTERSETTER(float *, AnimVertices, animVertices)
    GETTERSETTER(float *, AnimNormals, animNormals)
    GETTERSETTER(int *, BoneIds, boneIds)
    GETTERSETTER(float *, BoneWeights, boneWeights)
    GETTERSETTER(unsigned int, VaoId, vaoId)
    GETTERSETTER(unsigned int *, VboId, vboId)

    Mesh& operator=(const ::Mesh& mesh) {
        set(mesh);
        return *this;
    }

    ~Mesh() {
        Unload();
    }

    /**
     * Upload mesh vertex data to GPU (VRAM)
     */
    inline void Upload(bool dynamic = false) {
        ::UploadMesh(this, dynamic);
    }

    /**
     * Upload mesh vertex data to GPU (VRAM)
     */
    inline void UpdateBuffer(int index, void *data, int dataSize, int offset = 0) {
        ::UpdateMeshBuffer(*this, index, data, dataSize, offset);
    }

    inline void Draw(const ::Material& material, const ::Matrix& transform) {
        ::DrawMesh(*this, material, transform);
    }

    inline void DrawInstanced(const ::Material& material, ::Matrix* transforms, int instances) {
        ::DrawMeshInstanced(*this, material, transforms, instances);
    }

    /**
     * Export mesh data to file
     */
    inline bool Export(const std::string& fileName) {
        // TODO(RobLoach): Switch to an exception when failed.
        return ExportMesh(*this, fileName.c_str());
    }

    /**
     * Unload mesh from memory (RAM and/or VRAM)
     */
    inline void Unload() {
        if (vboId != NULL) {
            ::UnloadMesh(*this);
            vboId = NULL;
        }
    }

    /**
     * Compute mesh bounding box limits
     */
    inline raylib::BoundingBox BoundingBox() const {
        return ::MeshBoundingBox(*this);
    }

    /**
     * Compute mesh bounding box limits
     */
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
     * Load model from generated mesh
     */
    inline raylib::Model LoadModelFrom() const {
        return ::LoadModelFromMesh(*this);
    }

    /**
     * Load model from generated mesh
     */
    operator raylib::Model() {
        return ::LoadModelFromMesh(*this);
    }

 private:
    inline void set(const ::Mesh& mesh) {
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
