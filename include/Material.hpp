#ifndef RAYLIB_CPP_INCLUDE_MATERIAL_HPP_
#define RAYLIB_CPP_INCLUDE_MATERIAL_HPP_

#include <string>
#include <vector>

#include "./raylib.hpp"
#include "./raylib-cpp-utils.hpp"

namespace raylib {
/**
 * Material type (generic)
 */
class Material : public ::Material {
 public:
    Material(const ::Material& material) {
        set(material);
    }

    /**
     * Load default material (Supports: DIFFUSE, SPECULAR, NORMAL maps)
     */
    Material() {
        set(LoadMaterialDefault());
    }

    Material(const Material&) = delete;

    Material(Material&& other) {
        set(other);

        other.maps = nullptr;
        other.shader = {};
        other.params[0] = 0.0f;
        other.params[1] = 0.0f;
        other.params[2] = 0.0f;
        other.params[3] = 0.0f;
    }

    ~Material() {
        Unload();
    }

    /**
     * Load materials from model file
     */
    static std::vector<Material> Load(const std::string& fileName) {
        int count = 0;
        // TODO(RobLoach): Material::Load() possibly leaks the materials array.
        ::Material* materials = ::LoadMaterials(fileName.c_str(), &count);
        return std::vector<Material>(materials, materials + count);
    }

    GETTERSETTER(::Shader, Shader, shader)
    GETTERSETTER(::MaterialMap*, Maps, maps)
    // TODO(RobLoach): Resolve the Material params being a float[4].
    // GETTERSETTER(float[4], Params, params)

    Material& operator=(const ::Material& material) {
        set(material);
        return *this;
    }

    Material& operator=(const Material&) = delete;

    Material& operator=(Material&& other) noexcept {
        if (this == &other) {
            return *this;
        }

        Unload();
        set(other);

        other.maps = nullptr;
        other.shader = {};

        return *this;
    }

    /**
     * Unload material from memory
     */
    void Unload() {
        if (maps != nullptr) {
            ::UnloadMaterial(*this);
            maps = nullptr;
        }
    }

    /**
     * Set texture for a material map type (MAP_DIFFUSE, MAP_SPECULAR...)
     */
    Material& SetTexture(int mapType, const ::Texture2D& texture) {
        ::SetMaterialTexture(this, mapType, texture);
        return *this;
    }

    /**
     * Draw a 3d mesh with material and transform
     */
    void DrawMesh(const ::Mesh& mesh, ::Matrix transform) const {
        ::DrawMesh(mesh, *this, transform);
    }

    /**
     * Draw multiple mesh instances with material and different transforms
     */
    void DrawMesh(const ::Mesh& mesh, ::Matrix* transforms, int instances) const {
        ::DrawMeshInstanced(mesh, *this, transforms, instances);
    }

    /**
     * Check if material is ready
     */
    bool IsReady() const {
        return ::IsMaterialReady(*this);
    }

 protected:
    void set(const ::Material& material) {
        shader = material.shader;
        maps = material.maps;
        params[0] = material.params[0];
        params[1] = material.params[1];
        params[2] = material.params[2];
        params[3] = material.params[3];
    }
};
}  // namespace raylib

using RMaterial = raylib::Material;

#endif  // RAYLIB_CPP_INCLUDE_MATERIAL_HPP_
