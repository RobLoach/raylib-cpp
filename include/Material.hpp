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

#ifndef RAYLIB_CPP_INCLUDE_MATERIAL_HPP_
#define RAYLIB_CPP_INCLUDE_MATERIAL_HPP_

#include <string>
#include <vector>

#include "./raylib.hpp"
#include "./raylib-cpp-utils.hpp"

namespace raylib {
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

    Material& operator=(const Material& material) {
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

 protected:
    inline void set(const ::Material& material) {
        shader = material.shader;
        maps = material.maps;
        params = material.params;
    }
};
}  // namespace raylib

#endif  // RAYLIB_CPP_INCLUDE_MATERIAL_HPP_
