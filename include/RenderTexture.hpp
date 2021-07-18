#ifndef RAYLIB_CPP_INCLUDE_RENDERTEXTURE_HPP_
#define RAYLIB_CPP_INCLUDE_RENDERTEXTURE_HPP_

#include "./raylib.hpp"
#include "./raylib-cpp-utils.hpp"

namespace raylib {
/**
 * RenderTexture type, for texture rendering
 */
class RenderTexture : public ::RenderTexture {
 public:
    RenderTexture(const ::RenderTexture& renderTexture) {
        set(renderTexture);
    }

    RenderTexture(unsigned int Id) {
        id = Id;
    }

    RenderTexture(int width, int height) {
        set(LoadRenderTexture(width, height));
    }

    GETTERSETTER(unsigned int, Id, id)
    GETTERSETTER(::Texture2D, Texture, texture)
    GETTERSETTER(::Texture2D, Depth, depth)

    RenderTexture& operator=(const ::RenderTexture& texture) {
        set(texture);
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
