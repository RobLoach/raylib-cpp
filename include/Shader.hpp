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

#ifndef RAYLIB_CPP_INCLUDE_SHADER_HPP_
#define RAYLIB_CPP_INCLUDE_SHADER_HPP_

#include <string>

#include "./raylib.hpp"
#include "./raylib-cpp-utils.hpp"
#include "Texture.hpp"

namespace raylib {
class Shader : public ::Shader {
 public:
    Shader(::Shader shader) {
        set(shader);
    }

    Shader(unsigned int Id, int* Locs) {
        id = Id;
        locs = Locs;
    }

    Shader() {
        set(GetShaderDefault());
    }

    GETTERSETTER(unsigned int, Id, id)
    GETTERSETTER(int*, Locs, locs)

    Shader& operator=(const ::Shader& shader) {
        set(shader);
        return *this;
    }

    Shader& operator=(const Shader& shader) {
        set(shader);
        return *this;
    }

    ~Shader() {
        Unload();
    }

    void Unload() {
        ::UnloadShader(*this);
    }

    static Shader Load(const std::string& vsFileName, const std::string& fsFileName) {
        return ::LoadShader(vsFileName.c_str(), fsFileName.c_str());
    }

    static Shader LoadCode(const std::string& vsCode, const std::string& fsCode) {
        return ::LoadShaderCode(vsCode.c_str(), fsCode.c_str());
    }

    inline Shader& BeginShaderMode() {
        ::BeginShaderMode(*this);
        return *this;
    }

    inline Shader& EndShaderMode() {
        ::EndShaderMode();
        return *this;
    }

    inline int GetLocation(const std::string& uniformName) const {
        return ::GetShaderLocation(*this, uniformName.c_str());
    }

    inline int GetLocationAttrib(const std::string& attribName) const {
        return ::GetShaderLocationAttrib(*this, attribName.c_str());
    }

    inline Shader& SetValue(int uniformLoc, const std::string& value, int uniformType) {
        ::SetShaderValue(*this, uniformLoc, value.c_str(), uniformType);
        return *this;
    }

    /**
     * @see SetShaderValueV
     */
    inline Shader& SetValue(int uniformLoc, const std::string& value, int uniformType, int count) {
        ::SetShaderValueV(*this, uniformLoc, value.c_str(), uniformType, count);
        return *this;
    }

    /**
     * @see ::SetShaderValueMatrix
     */
    inline Shader& SetValue(int uniformLoc, Matrix mat) {
        ::SetShaderValueMatrix(*this, uniformLoc, mat);
        return *this;
    }

    /**
     * @see ::SetShaderValueTexture
     */
    inline Shader& SetValue(int uniformLoc, Texture2D texture) {
        ::SetShaderValueTexture(*this, uniformLoc, texture);
        return *this;
    }

    ::TextureCubemap GenTextureCubemap(Texture2D panorama, int size, int format) {
        return ::GenTextureCubemap(*this, panorama, size, format);
    }

    ::TextureCubemap GenTextureIrradiance(Texture2D panorama, int size) {
        return ::GenTextureIrradiance(*this, panorama, size);
    }

    ::TextureCubemap GenTexturePrefilter(Texture2D panorama, int size) {
        return ::GenTexturePrefilter(*this, panorama, size);
    }

    ::Texture2D GenTextureBRDF(int size) {
        return ::GenTextureBRDF(*this, size);
    }

 protected:
    inline void set(::Shader shader) {
        id = shader.id;
        locs = shader.locs;
    }
};
}  // namespace raylib

#endif  // RAYLIB_CPP_INCLUDE_SHADER_HPP_
