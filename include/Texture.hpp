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

#ifndef RAYLIB_CPP_INCLUDE_TEXTURE_HPP_
#define RAYLIB_CPP_INCLUDE_TEXTURE_HPP_

#include <string>

#include "./raylib.hpp"
#include "./raylib-cpp-utils.hpp"
#include "./Vector2.hpp"
#include "./Material.hpp"

namespace raylib {
class Texture : public ::Texture {
 public:
    Texture() {
        set(::GetTextureDefault());
    }

    Texture(const ::Image& image) {
        LoadFromImage(image);
    }

    Texture(const std::string& fileName) {
        Load(fileName);
    }

    ~Texture() {
        Unload();
    }

    GETTERSETTER(unsigned int, Id, id)
    GETTERSETTER(int, Width, width)
    GETTERSETTER(int, Height, height)
    GETTERSETTER(int, Mipmaps, mipmaps)
    GETTERSETTER(int, Format, format)

    Texture& operator=(const ::Texture& texture) {
        set(texture);
        return *this;
    }

    Texture& operator=(const Texture& texture) {
        set(texture);
        return *this;
    }

    void LoadFromImage(const ::Image& image) {
        set(::LoadTextureFromImage(image));
    }

    void LoadTextureCubemap(const ::Image& image, int layoutType) {
        set(::LoadTextureCubemap(image, layoutType));
    }

    void Load(const std::string& fileName) {
        set(::LoadTexture(fileName.c_str()));
    }

    inline void Unload() {
        ::UnloadTexture(*this);
    }

    inline Texture& Update(const void *pixels) {
        ::UpdateTexture(*this, pixels);
        return *this;
    }

    inline Texture& UpdateRec(Rectangle rec, const void *pixels) {
        UpdateTextureRec(*this, rec, pixels);
        return *this;
    }

    inline Image GetTextureData() const {
        return ::GetTextureData(*this);
    }

    inline operator raylib::Image() {
        return GetTextureData();
    }

    inline Texture& GenMipmaps() {
        ::GenTextureMipmaps(this);
        return *this;
    }

    inline Texture& SetFilter(int filterMode) {
        ::SetTextureFilter(*this, filterMode);
        return *this;
    }

    inline Texture& SetWrap(int wrapMode) {
        ::SetTextureWrap(*this, wrapMode);
        return *this;
    }

    inline Texture& Draw(int posX, int posY, ::Color tint = WHITE) {
        ::DrawTexture(*this, posX, posY, tint);
        return *this;
    }

    inline Texture& Draw(::Vector2 position, ::Color tint = WHITE) {
        ::DrawTextureV(*this, position, tint);
        return *this;
    }

    inline Texture& Draw(::Vector2 position, float rotation, float scale = 1.0f,
            ::Color tint = WHITE) {
        ::DrawTextureEx(*this, position, rotation, scale, tint);
        return *this;
    }

    inline Texture& Draw(::Rectangle sourceRec, ::Vector2 position, ::Color tint = WHITE) {
        ::DrawTextureRec(*this, sourceRec, position, tint);
        return *this;
    }

    inline Texture& Draw(::Vector2 tiling, ::Vector2 offset, ::Rectangle quad,
            ::Color tint = WHITE) {
        ::DrawTextureQuad(*this, tiling, offset, quad, tint);
        return *this;
    }

    inline Texture& Draw(::Rectangle sourceRec, ::Rectangle destRec, ::Vector2 origin,
            float rotation = 0, ::Color tint = WHITE) {
        ::DrawTexturePro(*this, sourceRec, destRec, origin, rotation, tint);
        return *this;
    }

    inline Texture& Draw(::NPatchInfo nPatchInfo, ::Rectangle destRec, ::Vector2 origin,
            float rotation = 0, ::Color tint = WHITE) {
        ::DrawTextureNPatch(*this, nPatchInfo, destRec, origin, rotation, tint);
        return *this;
    }

    inline Texture& Draw(::Vector3 position, float width, float height, float length,
            ::Color color = WHITE) {
        ::DrawCubeTexture(*this, position, width, height, length, color);
        return *this;
    }

    inline Texture& DrawTiled(Rectangle sourceRec, Rectangle destRec, Vector2 origin,
            float rotation, float scale, Color tint = WHITE) {
        ::DrawTextureTiled(*this, sourceRec, destRec, origin, rotation, scale, tint);
        return *this;
    }

    inline Texture& SetMaterialTexture(Material *material, int mapType) {
        ::SetMaterialTexture(material, mapType, *this);
        return *this;
    }

    static int GetPixelDataSize(int width, int height, int format) {
        return ::GetPixelDataSize(width, height, format);
    }

 protected:
    inline void set(::Texture texture) {
        id = texture.id;
        width = texture.width;
        height = texture.height;
        mipmaps = texture.mipmaps;
        format = texture.format;
    }
};

// Create the Texture aliases.
typedef Texture Texture2D;
typedef Texture TextureCubemap;
}  // namespace raylib

#endif  // RAYLIB_CPP_INCLUDE_TEXTURE_HPP_
