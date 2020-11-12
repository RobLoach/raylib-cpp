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
    Model(::Model model) {
        set(model);
    }

    Model(const std::string& fileName) {
        set(LoadModel(fileName.c_str()));
    }

    Model(::Mesh mesh) {
        set(LoadModelFromMesh(mesh));
    }

    ~Model() {
        Unload();
    }

    GETTERSETTER(::Matrix, Transform, transform)
    GETTERSETTER(int, MeshCount, meshCount)
    GETTERSETTER(int, MaterialCount, materialCount)
    GETTERSETTER(int, BoneCount, boneCount)

    Model& operator=(const ::Model& model) {
        set(model);
        return *this;
    }

    Model& operator=(const Model& model) {
        set(model);
        return *this;
    }

    inline void Unload() {
        ::UnloadModel(*this);
    }

    inline Model& SetMeshMaterial(int meshId, int materialId) {
        ::SetModelMeshMaterial(this, meshId, materialId);
        return *this;
    }

    inline RayHitInfo GetCollision(::Ray ray) const {
        return ::GetCollisionRayModel(ray, *this);
    }

    inline Model& UpdateModelAnimation(::ModelAnimation anim, int frame) {
        ::UpdateModelAnimation(*this, anim, frame);
        return *this;
    }

    inline bool IsModelAnimationValid(::ModelAnimation anim) const {
        return ::IsModelAnimationValid(*this, anim);
    }

 protected:
    inline void set(::Model model) {
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
