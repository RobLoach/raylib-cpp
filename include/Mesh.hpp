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

    /**
     * Load meshes from model file
     */
    // static std::vector<Mesh> Load(const std::string& fileName) {
    //    int count = 0;
    //    ::Mesh* meshes = LoadMeshes(fileName.c_str(), &count);
    //    return std::vector<Mesh>(meshes, meshes + count);
    // }

    Mesh(const Mesh&) = delete;

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
     * Generate cone/pyramid mesh
     */
    static ::Mesh Cone(float radius, float height, int slices) {
        return ::GenMeshCone(radius, height, slices);
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
    GETTERSETTER(unsigned char *, BoneIds, boneIds)
    GETTERSETTER(float *, BoneWeights, boneWeights)
    GETTERSETTER(unsigned int, VaoId, vaoId)
    GETTERSETTER(unsigned int *, VboId, vboId)

    Mesh& operator=(const ::Mesh& mesh) {
        set(mesh);
        return *this;
    }

    Mesh& operator=(const Mesh&) = delete;

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

    ~Mesh() {
        Unload();
    }

    /**
     * Upload mesh vertex data to GPU (VRAM)
     */
    void Upload(bool dynamic = false) {
        ::UploadMesh(this, dynamic);
    }

    /**
     * Upload mesh vertex data to GPU (VRAM)
     */
    void UpdateBuffer(int index, void *data, int dataSize, int offset = 0) {
        ::UpdateMeshBuffer(*this, index, data, dataSize, offset);
    }

    /**
     * Draw a 3d mesh with material and transform
     */
    void Draw(const ::Material& material, const ::Matrix& transform) const {
        ::DrawMesh(*this, material, transform);
    }

    /**
     * Draw multiple mesh instances with material and different transforms
     */
    void Draw(const ::Material& material, ::Matrix* transforms, int instances) const {
        ::DrawMeshInstanced(*this, material, transforms, instances);
    }

    /**
     * Export mesh data to file
     *
     * @throws raylib::RaylibException Throws if failed to export the Mesh.
     */
    void Export(const char* fileName) {
        if (!::ExportMesh(*this, fileName)) {
            throw new RaylibException("Failed to export the Mesh ", fileName);
        }
    }

    /**
     * Unload mesh from memory (RAM and/or VRAM)
     */
    void Unload() {
        if (vboId != nullptr) {
            ::UnloadMesh(*this);
            vboId = nullptr;
        }
    }

    /**
     * Compute mesh bounding box limits
     */
    raylib::BoundingBox BoundingBox() const {
        return ::GetMeshBoundingBox(*this);
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
    Mesh& GenTangents() {
        ::GenMeshTangents(this);
        return *this;
    }

    /**
     * Load model from generated mesh
     */
    raylib::Model LoadModelFrom() const {
        return ::LoadModelFromMesh(*this);
    }

    /**
     * Load model from generated mesh
     */
    operator raylib::Model() {
        return ::LoadModelFromMesh(*this);
    }

 protected:
    void set(const ::Mesh& mesh) {
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

using RMesh = raylib::Mesh;

#endif  // RAYLIB_CPP_INCLUDE_MESH_HPP_
