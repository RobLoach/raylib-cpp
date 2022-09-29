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
    Model() {
        // Nothing.
    }

    /*
     * Copy a model from another model.
     */
    Model(const ::Model& model) {
        set(model);
    }

    /*
     * Load a model from a file.
     *
     * @throws raylib::RaylibException Throws if failed to load the Modal.
     */
    Model(const std::string& fileName) {
        Load(fileName);
    }

    /*
     * Load a model from a mesh.
     *
     * @throws raylib::RaylibException Throws if failed to load the Modal.
     */
    Model(const ::Mesh& mesh) {
        Load(mesh);
    }

    ~Model() {
        Unload();
    }

    Model(const Model&) = delete;

    Model(Model&& other) {
        set(other);

        other.meshCount = 0;
        other.materialCount = 0;
        other.meshes = nullptr;
        other.materials = nullptr;
        other.meshMaterial = nullptr;
        other.boneCount = 0;
        other.bones = nullptr;
        other.bindPose = nullptr;
    }

    GETTERSETTER(::Matrix, Transform, transform)
    GETTERSETTER(int, MeshCount, meshCount)
    GETTERSETTER(int, MaterialCount, materialCount)
    GETTERSETTER(::Mesh*, Meshes, meshes)
    GETTERSETTER(::Material*, Materials, materials)
    GETTERSETTER(int*, MeshMaterial, meshMaterial)
    GETTERSETTER(int, BoneCount, boneCount)
    GETTERSETTER(::BoneInfo*, Bones, bones)
    GETTERSETTER(::Transform*, BindPose, bindPose)

    Model& operator=(const ::Model& model) {
        set(model);
        return *this;
    }

    Model& operator=(const Model&) = delete;

    Model& operator=(Model&& other) noexcept {
        if (this == &other) {
            return *this;
        }

        Unload();
        set(other);

        other.meshCount = 0;
        other.materialCount = 0;
        other.meshes = nullptr;
        other.materials = nullptr;
        other.meshMaterial = nullptr;
        other.boneCount = 0;
        other.bones = nullptr;
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
    inline void Draw(::Vector3 position,
            float scale = 1.0f,
            ::Color tint = {255, 255, 255, 255}) const {
        ::DrawModel(*this, position, scale, tint);
    }

    /**
     * Draw a model with extended parameters
     */
    inline void Draw(
            ::Vector3 position,
            ::Vector3 rotationAxis,
            float rotationAngle = 0.0f,
            ::Vector3 scale = {1.0f, 1.0f, 1.0f},
            ::Color tint = {255, 255, 255, 255}) const {
        ::DrawModelEx(*this, position, rotationAxis, rotationAngle, scale, tint);
    }

    /**
     * Draw a model wires (with texture if set)
     */
    inline void DrawWires(::Vector3 position,
            float scale = 1.0f,
            ::Color tint = {255, 255, 255, 255}) const {
        ::DrawModelWires(*this, position, scale, tint);
    }

    /**
     * Draw a model wires (with texture if set) with extended parameters
     */
    inline void DrawWires(
            ::Vector3 position,
            ::Vector3 rotationAxis,
            float rotationAngle = 0.0f,
            ::Vector3 scale = {1.0f, 1.0f, 1.0f},
            ::Color tint = {255, 255, 255, 255}) const {
        ::DrawModelWiresEx(*this, position, rotationAxis, rotationAngle, scale, tint);
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
     * @throws raylib::RaylibException Throws if failed to load the Modal.
     */
    void Load(const std::string& fileName) {
        set(::LoadModel(fileName.c_str()));
        if (!IsReady()) {
            throw RaylibException("Failed to load Model from " + fileName);
        }
    }

    /**
     * Loads a Model from the given Mesh.
     *
     * @throws raylib::RaylibException Throws if failed to load the Modal.
     */
    void Load(const ::Mesh& mesh) {
        set(::LoadModelFromMesh(mesh));
        if (!IsReady()) {
            throw RaylibException("Failed to load Model from Mesh");
        }
    }

 private:
    void set(const ::Model& model) {
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

using RModel = raylib::Model;

#endif  // RAYLIB_CPP_INCLUDE_MODEL_HPP_
