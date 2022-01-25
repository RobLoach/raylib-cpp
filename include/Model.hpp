#ifndef RAYLIB_CPP_INCLUDE_MODEL_HPP_
#define RAYLIB_CPP_INCLUDE_MODEL_HPP_

#include <string>

#include "./raylib.hpp"
#include "./raylib-cpp-utils.hpp"
#include "./Mesh.hpp"
#include "./RaylibException.hpp"

namespace raylib {
/**
 * Model type
 */
class Model : public ::Model {
 public:
    Model(const ::Model& model) {
        set(model);
    }

    Model(const std::string& fileName) {
        if (!Load(fileName)) {
            throw RaylibException("Failed to load Model from filename");
        }
    }

    Model(const ::Mesh& mesh) {
        if (!Load(mesh)) {
            throw RaylibException("Failed to load Model from Mesh");
        }
    }

    ~Model() {
        Unload();
    }

    Model(const Model&) = delete;

    Model(Model&& other) {
        set(other);

        other.bones = nullptr;
        other.boneCount = 0;
        other.materials = nullptr;
        other.materialCount = 0;
        other.meshes = nullptr;
        other.meshCount = 0;
        other.bindPose = nullptr;
    }

    GETTERSETTER(::Matrix, Transform, transform)
    GETTERSETTER(int, MeshCount, meshCount)
    GETTERSETTER(int, MaterialCount, materialCount)
    GETTERSETTER(::Mesh *, Meshes, meshes)
    GETTERSETTER(::Material *, Materials, materials)
    GETTERSETTER(int *, MeshMaterial, meshMaterial)
    GETTERSETTER(int, BoneCount, boneCount)
    GETTERSETTER(::BoneInfo *, Bones, bones)
    GETTERSETTER(::Transform *, BindPoe, bindPose)

    Model& operator=(const ::Model& model) {
        set(model);
        return *this;
    }

    Model& operator=(const Model&) = delete;

    Model& operator=(Model&& other) {
        if (this != &other) {
            return *this;
        }

        Unload();
        set(other);

        other.bones = nullptr;
        other.boneCount = 0;
        other.materials = nullptr;
        other.materialCount = 0;
        other.meshes = nullptr;
        other.meshCount = 0;
        other.bindPose = nullptr;

        return *this;
    }

    /**
     * Unload model (including meshes) from memory (RAM and/or VRAM)
     */
    inline void Unload() {
        if (meshes != nullptr || materials != nullptr) {
            ::UnloadModel(*this);
            meshes = nullptr;
            materials = nullptr;
        }
    }

    /**
     * Unload model (but not meshes) from memory (RAM and/or VRAM)
     */
    inline Model& UnloadKeepMeshes() {
        ::UnloadModelKeepMeshes(*this);
        return *this;
    }

    /**
     * Set material for a mesh
     */
    inline Model& SetMeshMaterial(int meshId, int materialId) {
        ::SetModelMeshMaterial(this, meshId, materialId);
        return *this;
    }

    /**
     * Get collision info between ray and model
     */
    inline RayCollision GetCollision(const ::Ray& ray) const {
        return ::GetRayCollisionModel(ray, *this);
    }

    /**
     * Update model animation pose
     */
    inline Model& UpdateAnimation(const ::ModelAnimation& anim, int frame) {
        ::UpdateModelAnimation(*this, anim, frame);
        return *this;
    }

    /**
     * Check model animation skeleton match
     */
    inline bool IsModelAnimationValid(const ::ModelAnimation& anim) const {
        return ::IsModelAnimationValid(*this, anim);
    }

    /**
     * Draw a model (with texture if set)
     */
    inline Model& Draw(::Vector3 position,
            float scale = 1.0f,
            ::Color tint = {255, 255, 255, 255}) {
        ::DrawModel(*this, position, scale, tint);
        return *this;
    }

    /**
     * Draw a model with extended parameters
     */
    inline Model& Draw(
            ::Vector3 position,
            ::Vector3 rotationAxis,
            float rotationAngle = 0.0f,
            ::Vector3 scale = {1.0f, 1.0f, 1.0f},
            ::Color tint = {255, 255, 255, 255}) {
        ::DrawModelEx(*this, position, rotationAxis, rotationAngle, scale, tint);
        return *this;
    }

    /**
     * Draw a model wires (with texture if set)
     */
    inline Model& DrawWires(::Vector3 position,
            float scale = 1.0f,
            ::Color tint = {255, 255, 255, 255}) {
        ::DrawModelWires(*this, position, scale, tint);
        return *this;
    }

    /**
     * Draw a model wires (with texture if set) with extended parameters
     */
    inline Model& DrawWires(
            ::Vector3 position,
            ::Vector3 rotationAxis,
            float rotationAngle = 0.0f,
            ::Vector3 scale = {1.0f, 1.0f, 1.0f},
            ::Color tint = {255, 255, 255, 255}) {
        ::DrawModelWiresEx(*this, position, rotationAxis, rotationAngle, scale, tint);
        return *this;
    }

    /**
     * Compute model bounding box limits (considers all meshes)
     */
    inline BoundingBox GetBoundingBox() const {
        return ::GetModelBoundingBox(*this);
    }

    /**
     * Compute model bounding box limits (considers all meshes)
     */
    operator BoundingBox() const {
        return ::GetModelBoundingBox(*this);
    }

    /**
     * Determines whether or not the Model has data in it.
     */
    bool IsReady() const {
        return meshCount > 0 || materialCount > 0 || boneCount > 0;
    }

    /**
     * Loads a Model from the given file.
     *
     * @return True of false depending on whether or not the model was successfully loaded.
     */
    bool Load(const std::string& fileName) {
        set(::LoadModel(fileName.c_str()));
        return IsReady();
    }

    /**
     * Loads a Model from the given Mesh.
     *
     * @return True of false depending on whether or not the model was successfully loaded.
     */
    bool Load(const ::Mesh& mesh) {
        set(::LoadModelFromMesh(mesh));
        return IsReady();
    }

 private:
    inline void set(const ::Model& model) {
        transform = model.transform;

        meshCount = model.meshCount;
        materialCount = model.materialCount;
        meshes = model.meshes;
        materials = model.materials;
        meshMaterial = model.meshMaterial;

        boneCount = model.boneCount;
        bones = model.bones;
        bindPose = model.bindPose;
    }
};

}  // namespace raylib

#endif  // RAYLIB_CPP_INCLUDE_MODEL_HPP_
