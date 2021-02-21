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

    ~Material() {
        Unload();
    }

    /**
     * Load materials from model file
     */
    static std::vector<Material> Load(const std::string& fileName) {
        int count = 0;
        ::Material* materials = ::LoadMaterials(fileName.c_str(), &count);
        return std::vector<Material>(materials, materials + count);
    }

    GETTERSETTER(::Shader, Shader, shader)
    GETTERSETTER(::MaterialMap*, Maps, maps)
    GETTERSETTER(float*, Params, params)

    Material& operator=(const ::Material& material) {
        set(material);
        return *this;
    }

    /**
     * Unload material from memory
     */
    inline void Unload() {
        if (maps != NULL) {
            ::UnloadMaterial(*this);
            maps = NULL;
        }
    }

    /**
     * Set texture for a material map type (MAP_DIFFUSE, MAP_SPECULAR...)
     */
    inline Material& SetTexture(int mapType, const ::Texture2D& texture) {
        ::SetMaterialTexture(this, mapType, texture);
        return *this;
    }

 private:
    inline void set(const ::Material& material) {
        shader = material.shader;
        maps = material.maps;
        params = material.params;
    }
};
}  // namespace raylib

#endif  // RAYLIB_CPP_INCLUDE_MATERIAL_HPP_
