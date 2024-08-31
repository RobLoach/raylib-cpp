#ifndef RAYLIB_CPP_INCLUDE_TEXTURE_HPP_
#define RAYLIB_CPP_INCLUDE_TEXTURE_HPP_

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
    Texture(Texture&& other) {
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
};

// Create the Texture aliases.
using Texture2D = Texture;
using TextureCubemap = Texture;

} // namespace raylib

using RTexture = raylib::Texture;
using RTexture2D = raylib::Texture2D;
using RTextureCubemap = raylib::TextureCubemap;

#endif // RAYLIB_CPP_INCLUDE_TEXTURE_HPP_
