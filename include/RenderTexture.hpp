#ifndef RAYLIB_CPP_INCLUDE_RENDERTEXTURE_HPP_
#define RAYLIB_CPP_INCLUDE_RENDERTEXTURE_HPP_

#include "./RaylibException.hpp"
#include "./TextureUnmanaged.hpp"
#include "./raylib-cpp-utils.hpp"
#include "./raylib.hpp"

namespace raylib {
/**
 * RenderTexture type, for texture rendering
 */
class RenderTexture : public ::RenderTexture {
public:
    /**
     * Default constructor to build an empty RenderTexture.
     */
    RenderTexture() { id = 0; }

    RenderTexture(const ::RenderTexture& renderTexture) { set(renderTexture); }

    RenderTexture(unsigned int id, const ::Texture& texture, const ::Texture& depth)
        : ::RenderTexture{id, texture, depth} {}

    /**
     * Load texture for rendering (framebuffer)
     */
    RenderTexture(int width, int height) { set(::LoadRenderTexture(width, height)); }

    RenderTexture(const RenderTexture&) = delete;

    RenderTexture(RenderTexture&& other) {
        set(other);

        other.id = 0;
        other.texture = {};
        other.depth = {};
    }

    GETTER(unsigned int, Id, id)

    /**
     * Get the color buffer attachment texture.
     */
    TextureUnmanaged GetTexture() { return texture; }

    void SetTexture(const ::Texture& newTexture) { texture = newTexture; }

    /**
     * Depth buffer attachment texture
     */
    TextureUnmanaged GetDepth() { return depth; }

    void SetDepth(const ::Texture& newDepth) { depth = newDepth; }

    RenderTexture& operator=(const ::RenderTexture& texture) {
        set(texture);
        return *this;
    }

    RenderTexture& operator=(const RenderTexture&) = delete;

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

    ~RenderTexture() { Unload(); }

    void Unload() { UnloadRenderTexture(*this); }

    /**
     * Initializes render texture for drawing
     */
    RenderTexture& BeginMode() {
        ::BeginTextureMode(*this);
        return *this;
    }

    /**
     * Ends drawing to render texture
     */
    RenderTexture& EndMode() {
        ::EndTextureMode();
        return *this;
    }

    /**
     * Load texture for rendering (framebuffer)
     */
    static RenderTexture Load(int width, int height) { return ::LoadRenderTexture(width, height); }

    /**
     * Retrieves whether or not the render texture is ready.
     */
    bool IsValid() const { return ::IsRenderTextureValid(*this); }
protected:
    void set(const ::RenderTexture& renderTexture) {
        id = renderTexture.id;
        texture = renderTexture.texture;
        depth = renderTexture.depth;
    }
};

using RenderTexture2D = RenderTexture;

} // namespace raylib

using RRenderTexture = raylib::RenderTexture;
using RRenderTexture2D = raylib::RenderTexture2D;

#endif // RAYLIB_CPP_INCLUDE_RENDERTEXTURE_HPP_
