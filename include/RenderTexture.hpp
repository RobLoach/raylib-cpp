#ifndef RAYLIB_CPP_INCLUDE_RENDERTEXTURE_HPP_
#define RAYLIB_CPP_INCLUDE_RENDERTEXTURE_HPP_

#include "./RenderTextureUnmanaged.hpp"

namespace raylib {
/**
 * RenderTexture type, for texture rendering.
 *
 * The render texture will be unloaded on object destruction. Use raylib::RenderTextureUnmanaged
 * if you're looking to not unload.
 *
 * @see raylib::RenderTextureUnmanaged
 */
class RenderTexture : public RenderTextureUnmanaged {
public:
    using RenderTextureUnmanaged::RenderTextureUnmanaged;

    RenderTexture(const RenderTexture&) = delete;
    RenderTexture& operator=(const RenderTexture&) = delete;

    RenderTexture(RenderTexture&& other) noexcept {
        set(other);
        other.id = 0;
        other.texture = {};
        other.depth = {};
    }

    RenderTexture& operator=(RenderTexture&& other) noexcept {
        if (this == &other) {
            return *this;
        }
        Unload();
        set(other);
        other.id = 0;
        other.texture = {};
        other.depth = {};
        return *this;
    }

    RenderTexture& operator=(const ::RenderTexture& other) {
        Unload();
        set(other);
        return *this;
    }

    ~RenderTexture() { Unload(); }

    /**
     * Unload previous render texture, then load a new one.
     */
    void Load(int width, int height) {
        Unload();
        RenderTextureUnmanaged::Load(width, height);
    }
};

using RenderTexture2D = RenderTexture;

} // namespace raylib

using RRenderTexture = raylib::RenderTexture;
using RRenderTexture2D = raylib::RenderTexture2D;

#endif // RAYLIB_CPP_INCLUDE_RENDERTEXTURE_HPP_
