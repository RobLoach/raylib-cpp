#ifndef RAYLIB_CPP_INCLUDE_MODEL_HPP_
#define RAYLIB_CPP_INCLUDE_MODEL_HPP_

#include "./ModelUnmanaged.hpp"

namespace raylib {
class Mesh;
/**
 * Model type.
 *
 * The model will be unloaded on object destruction. Use raylib::ModelUnmanaged if you're looking to not unload.
 *
 * @see raylib::ModelUnmanaged
 */
class Model : public ModelUnmanaged {
public:
    using ModelUnmanaged::ModelUnmanaged;

    /**
     * The Model constructor with a Mesh() is removed.
     *
     * Use `raylib::MeshUnmanaged` or `::Mesh` instead, as raylib will take ownership of the data.
     *
     * @see raylib::MeshUnmanaged
     */
    Model(const raylib::Mesh& mesh) = delete;

    Model(const Model&) = delete;
    Model& operator=(const Model&) = delete;

    Model(Model&& other) noexcept {
        set(other);
        other.meshCount = 0;
        other.materialCount = 0;
        other.meshes = nullptr;
        other.materials = nullptr;
        other.meshMaterial = nullptr;
        other.skeleton.boneCount = 0;
        other.skeleton.bones = nullptr;
        other.skeleton.bindPose = nullptr;
        other.currentPose = nullptr;
        other.boneMatrices = nullptr;
    }

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
        other.skeleton.boneCount = 0;
        other.skeleton.bones = nullptr;
        other.skeleton.bindPose = nullptr;
        other.currentPose = nullptr;
        other.boneMatrices = nullptr;
        return *this;
    }

    Model& operator=(const ::Model& model) {
        Unload();
        set(model);
        return *this;
    }

    ~Model() { Unload(); }

    void Load(const std::string& fileName) {
        Unload();
        ModelUnmanaged::Load(fileName);
    }

    void Load(const ::Mesh& mesh) {
        Unload();
        ModelUnmanaged::Load(mesh);
    }
};
} // namespace raylib

using RModel = raylib::Model;

#endif // RAYLIB_CPP_INCLUDE_MODEL_HPP_
