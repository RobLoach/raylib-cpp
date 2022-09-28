#ifndef RAYLIB_CPP_INCLUDE_TEXTURE_HPP_
#define RAYLIB_CPP_INCLUDE_TEXTURE_HPP_

#include "./TextureUnmanaged.hpp"

namespace raylib {
/**
 * Texture type
 */
class Texture : public TextureUnmanaged {
 public:
    using TextureUnmanaged::TextureUnmanaged;

    Texture(const Texture&) = delete;

    Texture(Texture&& other) {
        set(other);

        other.id = 0;
        other.width = 0;
        other.height = 0;
        other.mipmaps = 0;
        other.format = 0;
    }

    ~Texture() {
        Unload();
    }

    Texture& operator=(const Texture&) = delete;

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
typedef Texture Texture2D;
typedef Texture TextureCubemap;

}  // namespace raylib

using RTexture = raylib::Texture;
using RTexture2D = raylib::Texture2D;
using RTextureCubemap = raylib::TextureCubemap;

#endif  // RAYLIB_CPP_INCLUDE_TEXTURE_HPP_
