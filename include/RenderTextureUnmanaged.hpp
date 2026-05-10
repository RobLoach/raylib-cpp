#ifndef RAYLIB_CPP_INCLUDE_RENDERTEXTUREUNMANAGED_HPP_
#define RAYLIB_CPP_INCLUDE_RENDERTEXTUREUNMANAGED_HPP_

#include "./RaylibException.hpp"
#include "./TextureUnmanaged.hpp"
#include "./raylib-cpp-utils.hpp"

namespace raylib {
/**
 * A RenderTexture that is not managed by C++ RAII.
 *
 * Make sure to Unload() this if needed, otherwise use raylib::RenderTexture.
 *
 * @see raylib::RenderTexture
 */
class RenderTextureUnmanaged : public ::RenderTexture {
public:
    /**
     * Default constructor to build an empty RenderTexture.
     */
    RenderTextureUnmanaged() : ::RenderTexture{0, {}, {}} {}

    /**
     * Creates a RenderTexture from an existing RenderTexture struct.
     */
    RenderTextureUnmanaged(const ::RenderTexture& renderTexture) : ::RenderTexture(renderTexture) {}

    /**
     * Creates a RenderTexture from its components.
     */
    RenderTextureUnmanaged(unsigned int id, const ::Texture& texture, const ::Texture& depth)
        : ::RenderTexture{id, texture, depth} {}

    /**
     * Load texture for rendering (framebuffer).
     *
     * @throws raylib::RaylibException Throws if failed to create the render texture.
     */
    RenderTextureUnmanaged(int width, int height) { Load(width, height); }

    [[nodiscard]] std::string ToString() const { return TextFormat("RenderTexture(id=%u)", id); }

    operator std::string() const { return ToString(); }

    GETTER(unsigned int, Id, id)

    /**
     * Get the color buffer attachment texture.
     */
    TextureUnmanaged GetTexture() { return texture; }
    [[nodiscard]] TextureUnmanaged GetTexture() const { return texture; }
    void SetTexture(const ::Texture& newTexture) { texture = newTexture; }

    /**
     * Get the depth buffer attachment texture.
     */
    TextureUnmanaged GetDepth() { return depth; }
    void SetDepth(const ::Texture& newDepth) { depth = newDepth; }

    RenderTextureUnmanaged& operator=(const ::RenderTexture& other) {
        set(other);
        return *this;
    }

    /**
     * Load texture for rendering (framebuffer).
     *
     * @throws raylib::RaylibException Throws if failed to create the render texture.
     */
    void Load(int width, int height) {
        set(::LoadRenderTexture(width, height));
        if (!IsValid()) {
            throw RaylibException("Failed to create RenderTexture");
        }
    }

    /**
     * Unload render texture from GPU memory (VRAM).
     */
    void Unload() {
        if (IsValid()) {
            ::UnloadRenderTexture(*this);
            id = 0;
        }
    }

    /**
     * Initializes render texture for drawing.
     */
    RenderTextureUnmanaged& BeginMode() {
        ::BeginTextureMode(*this);
        return *this;
    }

    /**
     * Ends drawing to render texture.
     */
    RenderTextureUnmanaged& EndMode() {
        ::EndTextureMode();
        return *this;
    }

    /**
     * Retrieves whether or not the render texture is ready.
     */
    [[nodiscard]] bool IsValid() const { return ::IsRenderTextureValid(*this); }

protected:
    void set(const ::RenderTexture& renderTexture) {
        id = renderTexture.id;
        texture = renderTexture.texture;
        depth = renderTexture.depth;
    }
};

using RenderTexture2DUnmanaged = RenderTextureUnmanaged;

} // namespace raylib

using RRenderTextureUnmanaged = raylib::RenderTextureUnmanaged;
using RRenderTexture2DUnmanaged = raylib::RenderTexture2DUnmanaged;

#endif // RAYLIB_CPP_INCLUDE_RENDERTEXTUREUNMANAGED_HPP_
