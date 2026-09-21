#ifndef RAYLIB_CPP_INCLUDE_TEXTURE_HPP_
#define RAYLIB_CPP_INCLUDE_TEXTURE_HPP_

#include <string>

#include "./TextureUnmanaged.hpp"

namespace raylib {
/**
 * Texture type
 *
 * The texture will be unloaded on object destruction. Use raylib::TextureUnmanaged if you're looking to not unload.
 *
 * @see raylib::TextureUnmanaged
 */
class Texture : public TextureUnmanaged {
 public:
    using TextureUnmanaged::TextureUnmanaged;

    /**
     * Explicitly forbid the copy constructor.
     */
    Texture(const Texture&) = delete;

    /**
     * Explicitly forbid copy assignment.
     */
    Texture& operator=(const Texture&) = delete;

    /**
     * Move constructor.
     */
    Texture(Texture&& other)  noexcept {
        set(other);

        other.id = 0;
        other.width = 0;
        other.height = 0;
        other.mipmaps = 0;
        other.format = 0;
    }

    /**
     * On destruction, unload the Texture.
     */
    ~Texture() { Unload(); }

    /**
     * Move assignment.
     */
    Texture& operator=(Texture&& other) noexcept {
        if (this == &other) {
            return *this;
        }

        Unload();
        set(other);

        other.id = 0;
        other.width = 0;
        other.height = 0;
        other.mipmaps = 0;
        other.format = 0;

        return *this;
    }

    /**
    * Unload previous texture, then load texture from image data
    */
    void Load(const ::Image& image) {
        Unload();
        TextureUnmanaged::Load(image);
    }

    /**
    * Unload previous texture, then load cubemap from image.
    * Multiple image cubemap layouts supported
    */
    void Load(const ::Image& image, int layoutType) {
      Unload();
      TextureUnmanaged::Load(image, layoutType);
    }

    /**
    * Unload previous texture, then load texture from file into GPU memory (VRAM)
    */
    void Load(const std::string& fileName) {
      Unload();
      TextureUnmanaged::Load(fileName);
    }
};

// Create the Texture aliases.
using Texture2D = Texture;
using TextureCubemap = Texture;

}  // namespace raylib

using RTexture = raylib::Texture;
using RTexture2D = raylib::Texture2D;
using RTextureCubemap = raylib::TextureCubemap;

#endif  // RAYLIB_CPP_INCLUDE_TEXTURE_HPP_
