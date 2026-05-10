#ifndef RAYLIB_CPP_INCLUDE_MODELUNMANAGED_HPP_
#define RAYLIB_CPP_INCLUDE_MODELUNMANAGED_HPP_

#include <string>

#include "./BoundingBox.hpp"
#include "./RaylibException.hpp"
#include "./raylib-cpp-utils.hpp"
#include "./raylib.hpp"

namespace raylib {
/**
 * A Model that is not managed by C++ RAII.
 *
 * Make sure to Unload() this if needed, otherwise use raylib::Model.
 *
 * @see raylib::Model
 */
class ModelUnmanaged : public ::Model {
public:
    /**
     * Default constructor.
     */
    ModelUnmanaged() {}

    /**
     * Creates a ModelUnmanaged from an existing Model struct.
     */
    ModelUnmanaged(const ::Model& model) : ::Model(model) {}

    /**
     * Loads a Model from the given file.
     *
     * @throws raylib::RaylibException Throws if failed to load the Model.
     */
    ModelUnmanaged(const std::string& fileName) { Load(fileName); }

    /**
     * Loads a Model from the given Mesh.
     *
     * @throws raylib::RaylibException Throws if failed to load the Model.
     */
    ModelUnmanaged(const ::Mesh& mesh) { Load(mesh); }

    GETTERSETTER(::Matrix, Transform, transform)
    GETTERSETTER(int, MeshCount, meshCount)
    GETTERSETTER(int, MaterialCount, materialCount)
    GETTERSETTER(::Mesh*, Meshes, meshes)
    GETTERSETTER(::Material*, Materials, materials)
    GETTERSETTER(int*, MeshMaterial, meshMaterial)
    GETTERSETTER(int, BoneCount, skeleton.boneCount)
    GETTERSETTER(::BoneInfo*, Bones, skeleton.bones)
    GETTERSETTER(::Transform*, BindPose, skeleton.bindPose)
    GETTERSETTER(::ModelAnimPose, CurrentPose, currentPose)
    GETTERSETTER(::Matrix*, BoneMatrices, boneMatrices)

    ModelUnmanaged& operator=(const ::Model& model) {
        set(model);
        return *this;
    }

    [[nodiscard]] std::string ToString() const { return TextFormat("Model(meshCount=%d, materialCount=%d)", meshCount, materialCount); }

    operator std::string() const { return ToString(); }

    /**
     * Loads a Model from the given file.
     *
     * @throws raylib::RaylibException Throws if failed to load the Model.
     */
    void Load(const std::string& fileName) {
        set(::LoadModel(fileName.c_str()));
        if (!IsValid()) {
            throw RaylibException("Failed to load Model from " + fileName);
        }
    }

    /**
     * Loads a Model from the given Mesh.
     *
     * @throws raylib::RaylibException Throws if failed to load the Model.
     */
    void Load(const ::Mesh& mesh) {
        set(::LoadModelFromMesh(mesh));
        if (!IsValid()) {
            throw RaylibException("Failed to load Model from Mesh");
        }
    }

    /**
     * Unload model (including meshes) from memory (RAM and/or VRAM).
     */
    void Unload() {
        if (meshes != nullptr || materials != nullptr) {
            ::UnloadModel(*this);
            meshes = nullptr;
            materials = nullptr;
        }
    }

    /**
     * Set material for a mesh.
     */
    ModelUnmanaged& SetMeshMaterial(int meshId, int materialId) {
        ::SetModelMeshMaterial(this, meshId, materialId);
        return *this;
    }

    /**
     * Update model animation pose.
     */
    ModelUnmanaged& UpdateAnimation(const ::ModelAnimation& anim, float frame) {
        ::UpdateModelAnimation(*this, anim, frame);
        return *this;
    }

    /**
     * Blend two model animation poses.
     */
    ModelUnmanaged& BlendAnimation(
        const ::ModelAnimation& animA,
        float frameA,
        const ::ModelAnimation& animB,
        float frameB,
        float blend) {
        ::UpdateModelAnimationEx(*this, animA, frameA, animB, frameB, blend);
        return *this;
    }

    /**
     * Check model animation skeleton match.
     */
    RLCPP_NODISCARD bool IsModelAnimationValid(const ::ModelAnimation& anim) const {
        return ::IsModelAnimationValid(*this, anim);
    }

    /**
     * Draw a model (with texture if set).
     */
    void Draw(::Vector3 position, float scale = 1.0f, ::Color tint = {255, 255, 255, 255}) const {
        ::DrawModel(*this, position, scale, tint);
    }

    /**
     * Draw a model with extended parameters.
     */
    void Draw(
        ::Vector3 position,
        ::Vector3 rotationAxis,
        float rotationAngle = 0.0f,
        ::Vector3 scale = {1.0f, 1.0f, 1.0f},
        ::Color tint = {255, 255, 255, 255}) const {
        ::DrawModelEx(*this, position, rotationAxis, rotationAngle, scale, tint);
    }

    /**
     * Draw a model wires (with texture if set).
     */
    void DrawWires(::Vector3 position, float scale = 1.0f, ::Color tint = {255, 255, 255, 255}) const {
        ::DrawModelWires(*this, position, scale, tint);
    }

    /**
     * Draw a model wires (with texture if set) with extended parameters.
     */
    void DrawWires(
        ::Vector3 position,
        ::Vector3 rotationAxis,
        float rotationAngle = 0.0f,
        ::Vector3 scale = {1.0f, 1.0f, 1.0f},
        ::Color tint = {255, 255, 255, 255}) const {
        ::DrawModelWiresEx(*this, position, rotationAxis, rotationAngle, scale, tint);
    }

    /**
     * Compute model bounding box limits (considers all meshes).
     */
    RLCPP_NODISCARD BoundingBox GetBoundingBox() const { return ::GetModelBoundingBox(*this); }

    /**
     * Compute model bounding box limits (considers all meshes).
     */
    explicit operator BoundingBox() const { return ::GetModelBoundingBox(*this); }

    /**
     * Determines whether or not the Model has data in it.
     */
    RLCPP_NODISCARD bool IsValid() const { return ::IsModelValid(*this); }

protected:
    void set(const ::Model& model) {
        transform = model.transform;

        meshCount = model.meshCount;
        materialCount = model.materialCount;
        meshes = model.meshes;
        materials = model.materials;
        meshMaterial = model.meshMaterial;

        skeleton.boneCount = model.skeleton.boneCount;
        skeleton.bones = model.skeleton.bones;
        skeleton.bindPose = model.skeleton.bindPose;
        currentPose = model.currentPose;
        boneMatrices = model.boneMatrices;
    }
};
} // namespace raylib

using RModelUnmanaged = raylib::ModelUnmanaged;

#endif // RAYLIB_CPP_INCLUDE_MODELUNMANAGED_HPP_
