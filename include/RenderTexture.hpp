#ifndef RAYLIB_CPP_INCLUDE_RENDERTEXTURE_HPP_
#define RAYLIB_CPP_INCLUDE_RENDERTEXTURE_HPP_

#include "./raylib.hpp"
#include "./raylib-cpp-utils.hpp"
#include "./RaylibException.hpp"

namespace raylib {
/**
 * RenderTexture type, for texture rendering
 */
class RenderTexture : public ::RenderTexture {
 public:
    /**
     * Default constructor to build an empty RenderTexture.
     */
    RenderTexture() {
        id = 0;
    }

    RenderTexture(const ::RenderTexture& renderTexture) {
        set(renderTexture);
    }

    RenderTexture(unsigned int id, ::Texture texture, ::Texture depth) : ::RenderTexture{id, texture, depth} {}

    RenderTexture(int width, int height) {
        if (!Load(width, height)) {
            throw RaylibException("Failed to create RenderTexture");
        }
    }

    RenderTexture(const RenderTexture&) = delete;

    RenderTexture(RenderTexture&& other) {
        set(other);

        other.id = 0;
        other.texture = {};
        other.depth = {};
    }

    GETTERSETTER(unsigned int, Id, id)
    GETTERSETTER(::Texture2D, Texture, texture)
    GETTERSETTER(::Texture2D, Depth, depth)

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

    ~RenderTexture() {
        Unload();
    }

    inline void Unload() {
        UnloadRenderTexture(*this);
    }

    /**
     * Initializes render texture for drawing
     */
    inline RenderTexture& BeginMode() {
        ::BeginTextureMode(*this);
        return *this;
    }

    /**
     * Ends drawing to render texture
     */
    inline RenderTexture& EndMode() {
        ::EndTextureMode();
        return *this;
    }

    /**
     * Loads a render texture at the given width and height.
     */
    bool Load(int width, int height) {
        set(::LoadRenderTexture(width, height));
        return IsReady();
    }

    /**
     * Retrieves whether or not the render texture is ready.
     */
    bool IsReady() const {
        return id != 0;
    }

 private:
    inline void set(const ::RenderTexture& renderTexture) {
        id = renderTexture.id;
        texture = renderTexture.texture;
        depth = renderTexture.depth;
    }
};
typedef RenderTexture RenderTexture2D;
}  // namespace raylib

#endif  // RAYLIB_CPP_INCLUDE_RENDERTEXTURE_HPP_
