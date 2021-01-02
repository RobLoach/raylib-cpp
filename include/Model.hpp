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

#ifndef RAYLIB_CPP_INCLUDE_MODEL_HPP_
#define RAYLIB_CPP_INCLUDE_MODEL_HPP_

#include <string>

#include "./raylib.hpp"
#include "./raylib-cpp-utils.hpp"
#include "./Mesh.hpp"

namespace raylib {
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

    Model& operator=(const Model& model) {
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
    inline Model& UpdateModelAnimation(const ::ModelAnimation& anim, int frame) {
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

 protected:
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
