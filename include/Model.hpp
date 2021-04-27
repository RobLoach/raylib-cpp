#ifndef RAYLIB_CPP_INCLUDE_MODEL_HPP_
#define RAYLIB_CPP_INCLUDE_MODEL_HPP_

#include <string>

#include "./raylib.hpp"
#include "./raylib-cpp-utils.hpp"
#include "./Mesh.hpp"

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
        set(::LoadModel(fileName.c_str()));
    }

    Model(const ::Mesh& mesh) {
        set(::LoadModelFromMesh(mesh));
    }

    ~Model() {
        Unload();
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

    /**
     * Unload model (including meshes) from memory (RAM and/or VRAM)
     */
    inline void Unload() {
        if (meshes != NULL || materials != NULL) {
            ::UnloadModel(*this);
            meshes = NULL;
            materials = NULL;
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
    inline RayHitInfo GetCollision(const ::Ray& ray) const {
        return ::GetCollisionRayModel(ray, *this);
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
