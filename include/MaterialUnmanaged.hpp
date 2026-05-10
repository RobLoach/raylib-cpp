#ifndef RAYLIB_CPP_INCLUDE_MATERIALUNMANAGED_HPP_
#define RAYLIB_CPP_INCLUDE_MATERIALUNMANAGED_HPP_

#include <string>
#include <vector>

#include "./raylib-cpp-utils.hpp"
#include "./raylib.hpp"

namespace raylib {
/**
 * A Material that is not managed by C++ RAII.
 *
 * Make sure to Unload() this if needed, otherwise use raylib::Material.
 *
 * @see raylib::Material
 */
class MaterialUnmanaged : public ::Material {
public:
    /**
     * Creates a MaterialUnmanaged from an existing Material struct.
     */
    MaterialUnmanaged(const ::Material& material) : ::Material(material) {}

    /**
     * Load default material (Supports: DIFFUSE, SPECULAR, NORMAL maps).
     */
    MaterialUnmanaged() : ::Material(::LoadMaterialDefault()) {}

    /**
     * Load materials from model file.
     */
    static std::vector<MaterialUnmanaged> Load(const std::string& fileName) {
        int count = 0;
        ::Material* mats = ::LoadMaterials(fileName.c_str(), &count);
        return std::vector<MaterialUnmanaged>(mats, mats + count);
    }

    GETTERSETTER(::Shader, Shader, shader)
    GETTERSETTER(::MaterialMap*, Maps, maps)

    MaterialUnmanaged& operator=(const ::Material& material) {
        set(material);
        return *this;
    }

    /**
     * Unload material from memory.
     */
    void Unload() {
        if (maps != nullptr) {
            ::UnloadMaterial(*this);
            maps = nullptr;
        }
    }

    /**
     * Set texture for a material map type (MAP_DIFFUSE, MAP_SPECULAR...).
     */
    MaterialUnmanaged& SetTexture(int mapType, const ::Texture2D& texture) {
        ::SetMaterialTexture(this, mapType, texture);
        return *this;
    }

    /**
     * Draw a 3d mesh with material and transform.
     */
    void DrawMesh(const ::Mesh& mesh, ::Matrix transform) const { ::DrawMesh(mesh, *this, transform); }

    /**
     * Draw multiple mesh instances with material and different transforms.
     */
    void DrawMesh(const ::Mesh& mesh, ::Matrix* transforms, int instances) const {
        ::DrawMeshInstanced(mesh, *this, transforms, instances);
    }

    /**
     * Check if material is ready.
     */
    RLCPP_NODISCARD bool IsValid() const { return ::IsMaterialValid(*this); }

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
} // namespace raylib

using RMaterialUnmanaged = raylib::MaterialUnmanaged;

#endif // RAYLIB_CPP_INCLUDE_MATERIALUNMANAGED_HPP_
