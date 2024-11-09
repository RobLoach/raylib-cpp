#ifndef RAYLIB_CPP_INCLUDE_UNMANAGEDSHADER_HPP_
#define RAYLIB_CPP_INCLUDE_UNMANAGEDSHADER_HPP_

#include <rlgl.h>
#include <string>

#include "Texture.hpp"
#include "./raylib-cpp-utils.hpp"
#include "./raylib.hpp"

namespace raylib {

/**
 * Shader type (generic), not managed by C++ RAII.
 */
class ShaderUnmanaged : public ::Shader {
public:
    ShaderUnmanaged() : ::Shader{rlGetShaderIdDefault(), rlGetShaderLocsDefault()} {}

    ShaderUnmanaged(const ::Shader& shader) { set(shader); }

    ShaderUnmanaged(unsigned int id, int* locs = nullptr) : ::Shader{id, locs} {}

    ShaderUnmanaged(const std::string& vsFileName, const std::string& fsFileName) {
        set(::LoadShader(vsFileName.c_str(), fsFileName.c_str()));
    }
    ShaderUnmanaged(const char* vsFileName, const char* fsFileName) { set(::LoadShader(vsFileName, fsFileName)); }

    /**
     * Load shader from files and bind default locations.
     *
     * @see ::LoadShader
     */
    static ::Shader Load(const std::string& vsFileName, const std::string& fsFileName) {
        return ::LoadShader(vsFileName.c_str(), fsFileName.c_str());
    }
    static ::Shader Load(const char* vsFileName, const char* fsFileName) {
        return ::LoadShader(vsFileName, fsFileName);
    }

    /**
     * Load a shader from memory.
     *
     * @see ::LoadShaderFromMemory
     */
    static ::Shader LoadFromMemory(const std::string& vsCode, const std::string& fsCode) {
        return ::LoadShaderFromMemory(vsCode.c_str(), fsCode.c_str());
    }
    static ::Shader LoadFromMemory(const char* vsCode, const char* fsCode) {
        return ::LoadShaderFromMemory(vsCode, fsCode);
    }

    GETTER(unsigned int, Id, id)
    GETTER(int*, Locs, locs)

    ShaderUnmanaged& operator=(const ::Shader& shader) {
        set(shader);
        return *this;
    }

    /**
     * Begin custom shader drawing.
     */
    ShaderUnmanaged& BeginMode() {
        ::BeginShaderMode(*this);
        return *this;
    }

    /**
     * End custom shader drawing (use default shader).
     */
    ShaderUnmanaged& EndMode() {
        ::EndShaderMode();
        return *this;
    }

    /**
     * Get shader uniform location
     *
     * @see GetShaderLocation()
     */
    int GetLocation(const std::string& uniformName) const { return ::GetShaderLocation(*this, uniformName.c_str()); }

    /**
     * Get shader attribute location
     *
     * @see GetShaderLocationAttrib()
     */
    int GetLocationAttrib(const std::string& attribName) const {
        return ::GetShaderLocationAttrib(*this, attribName.c_str());
    }

    /**
     * Set shader uniform value
     *
     * @see SetShaderValue()
     */
    ShaderUnmanaged& SetValue(int uniformLoc, const void* value, int uniformType) {
        ::SetShaderValue(*this, uniformLoc, value, uniformType);
        return *this;
    }

    /**
     * Set shader uniform value vector
     *
     * @see SetShaderValueV()
     */
    ShaderUnmanaged& SetValue(int uniformLoc, const void* value, int uniformType, int count) {
        ::SetShaderValueV(*this, uniformLoc, value, uniformType, count);
        return *this;
    }

    /**
     * Set shader uniform value (matrix 4x4)
     *
     * @see SetShaderValueMatrix()
     */
    ShaderUnmanaged& SetValue(int uniformLoc, const ::Matrix& mat) {
        ::SetShaderValueMatrix(*this, uniformLoc, mat);
        return *this;
    }

    /**
     * Set shader uniform value for texture
     *
     * @see SetShaderValueTexture()
     */
    ShaderUnmanaged& SetValue(int uniformLoc, const ::Texture2D& texture) {
        ::SetShaderValueTexture(*this, uniformLoc, texture);
        return *this;
    }

    /**
     * Retrieves whether or not the shader is ready.
     */
    bool IsValid() const { return ::IsShaderValid(*this); }
protected:
    void set(const ::Shader& shader) {
        id = shader.id;
        locs = shader.locs;
    }
};
} // namespace raylib

using RShaderUnmanaged = raylib::ShaderUnmanaged;

#endif // RAYLIB_CPP_INCLUDE_UNMANAGEDSHADER_HPP_
