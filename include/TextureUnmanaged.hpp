#ifndef RAYLIB_CPP_INCLUDE_TEXTUREUNMANAGED_HPP_
#define RAYLIB_CPP_INCLUDE_TEXTUREUNMANAGED_HPP_

#include <string>

#include "./Image.hpp"
#include "./Material.hpp"
#include "./RaylibException.hpp"
#include "./Vector2.hpp"
#include "./raylib-cpp-utils.hpp"
#include "./raylib.hpp"

namespace raylib {
/**
 * A Texture that is not managed by C++ RAII.
 *
 * Make sure to Unload() this if needed, otherwise use raylib::Texture.
 *
 * @see raylib::Texture
 */
class TextureUnmanaged : public ::Texture {
public:
    /**
     * Default texture constructor.
     */
    TextureUnmanaged() : ::Texture{0, 0, 0, 0, 0} {
        // Nothing.
    }

    /**
     * Move/Create a texture structure manually.
     */
    TextureUnmanaged(
        unsigned int id,
        int width,
        int height,
        int mipmaps = 1,
        int format = PIXELFORMAT_UNCOMPRESSED_R8G8B8A8)
        : ::Texture{id, width, height, mipmaps, format} {
        // Nothing.
    }

    /**
     * Creates a texture object based on the given Texture struct data.
     */
    TextureUnmanaged(const ::Texture& texture)
        : ::Texture{texture.id, texture.width, texture.height, texture.mipmaps, texture.format} {
        // Nothing.
    }

    /**
     * Creates a texture from the given Image.
     *
     * @throws raylib::RaylibException Throws if failed to create the texture from the given image.
     */
    TextureUnmanaged(const ::Image& image) { Load(image); }

    /**
     * Load cubemap from image, multiple image cubemap layouts supported.
     *
     * @throws raylib::RaylibException Throws if failed to create the texture from the given cubemap.
     *
     * @see LoadTextureCubemap()
     */
    TextureUnmanaged(const ::Image& image, int layout) { Load(image, layout); }

    /**
     * Load texture from file into GPU memory (VRAM)
     *
     * @throws raylib::RaylibException Throws if failed to create the texture from the given file.
     */
    TextureUnmanaged(const std::string& fileName) { Load(fileName); }

    TextureUnmanaged(::Texture&& other) : ::Texture{other.id, other.width, other.height, other.mipmaps, other.format} {
        // Nothing.
    }

    GETTER(unsigned int, Id, id)
    GETTER(int, Width, width)
    GETTER(int, Height, height)
    GETTER(int, Mipmaps, mipmaps)
    GETTER(int, Format, format)

    TextureUnmanaged& operator=(const ::Texture& texture) {
        set(texture);
        return *this;
    }

    /**
     * Retrieve the width and height of the texture.
     */
    ::Vector2 GetSize() const { return {static_cast<float>(width), static_cast<float>(height)}; }

    /**
     * Load texture from image data
     */
    void Load(const ::Image& image) {
        set(::LoadTextureFromImage(image));
        if (!IsValid()) {
            throw RaylibException("Failed to load Texture from Image");
        }
    }

    /**
     * Load cubemap from image, multiple image cubemap layouts supported
     */
    void Load(const ::Image& image, int layoutType) {
        set(::LoadTextureCubemap(image, layoutType));
        if (!IsValid()) {
            throw RaylibException("Failed to load Texture from Cubemap");
        }
    }

    /**
     * Load texture from file into GPU memory (VRAM)
     */
    void Load(const std::string& fileName) {
        set(::LoadTexture(fileName.c_str()));
        if (!IsValid()) {
            throw RaylibException("Failed to load Texture from file: " + fileName);
        }
    }

    /**
     * Unload texture from GPU memory (VRAM)
     */
    void Unload() {
        // Protect against calling UnloadTexture() twice.
        if (id != 0) {
            ::UnloadTexture(*this);
            id = 0;
        }
    }

    /**
     * Update GPU texture with new data
     */
    TextureUnmanaged& Update(const void* pixels) {
        ::UpdateTexture(*this, pixels);
        return *this;
    }

    /**
     * Update GPU texture rectangle with new data
     */
    TextureUnmanaged& Update(::Rectangle rec, const void* pixels) {
        UpdateTextureRec(*this, rec, pixels);
        return *this;
    }

    /**
     * Get pixel data from GPU texture and return an Image
     */
    ::Image GetData() const { return ::LoadImageFromTexture(*this); }

    /**
     * Get pixel data from GPU texture and return an Image
     */
    operator Image() { return GetData(); }

    /**
     * Generate GPU mipmaps for a texture
     */
    TextureUnmanaged& GenMipmaps() {
        ::GenTextureMipmaps(this);
        return *this;
    }

    /**
     * Set texture scaling filter mode
     */
    TextureUnmanaged& SetFilter(int filterMode) {
        ::SetTextureFilter(*this, filterMode);
        return *this;
    }

    /**
     * Set texture wrapping mode
     */
    TextureUnmanaged& SetWrap(int wrapMode) {
        ::SetTextureWrap(*this, wrapMode);
        return *this;
    }

    /**
     * Draw a Texture2D
     *
     * @see ::DrawTexture()
     */
    void Draw(int posX = 0, int posY = 0, ::Color tint = {255, 255, 255, 255}) const {
        ::DrawTexture(*this, posX, posY, tint);
    }

    /**
     * Draw a Texture2D with position defined as Vector2
     *
     * @see ::DrawTextureV()
     */
    void Draw(::Vector2 position, ::Color tint = {255, 255, 255, 255}) const { ::DrawTextureV(*this, position, tint); }

    /**
     * Draw a Texture2D with extended parameters
     *
     * @see ::DrawTextureEx()
     */
    void Draw(::Vector2 position, float rotation, float scale = 1.0f, ::Color tint = {255, 255, 255, 255}) const {
        ::DrawTextureEx(*this, position, rotation, scale, tint);
    }

    /**
     * Draw a part of a texture defined by a rectangle
     *
     * @see ::DrawTextureRec()
     */
    void Draw(::Rectangle sourceRec, ::Vector2 position = {0, 0}, ::Color tint = {255, 255, 255, 255}) const {
        ::DrawTextureRec(*this, sourceRec, position, tint);
    }

    /**
     * Draw a part of a texture defined by a rectangle with 'pro' parameters
     *
     * @see ::DrawTexturePro()
     */
    void Draw(
        ::Rectangle sourceRec,
        ::Rectangle destRec,
        ::Vector2 origin = {0, 0},
        float rotation = 0,
        ::Color tint = {255, 255, 255, 255}) const {
        ::DrawTexturePro(*this, sourceRec, destRec, origin, rotation, tint);
    }

    /**
     * Draws a texture (or part of it) that stretches or shrinks nicely
     *
     * @see ::DrawTextureNPatch()
     */
    void Draw(
        ::NPatchInfo nPatchInfo,
        ::Rectangle destRec,
        ::Vector2 origin = {0, 0},
        float rotation = 0,
        ::Color tint = {255, 255, 255, 255}) const {
        ::DrawTextureNPatch(*this, nPatchInfo, destRec, origin, rotation, tint);
    }

    /**
     * Draw a billboard texture
     *
     * @see ::DrawBillboard()
     */
    void
    DrawBillboard(const ::Camera& camera, ::Vector3 position, float size, ::Color tint = {255, 255, 255, 255}) const {
        ::DrawBillboard(camera, *this, position, size, tint);
    }

    /**
     * Draw a billboard texture defined by source
     *
     * @see ::DrawBillboardRec()
     */
    void DrawBillboard(
        const ::Camera& camera,
        ::Rectangle source,
        ::Vector3 position,
        ::Vector2 size,
        ::Color tint = {255, 255, 255, 255}) const {
        DrawBillboardRec(camera, *this, source, position, size, tint);
    }

    /**
     * Draw a billboard texture defined by source and rotation
     *
     * @see ::DrawBillboardPro()
     */
    void DrawBillboard(
        const ::Camera& camera,
        ::Rectangle source,
        Vector3 position,
        ::Vector3 up,
        Vector2 size,
        Vector2 origin,
        float rotation = 0.0f,
        ::Color tint = {255, 255, 255, 255}) const {
        DrawBillboardPro(camera, *this, source, position, up, size, origin, rotation, tint);
    }

    /**
     * Set texture for a material map type (MAP_DIFFUSE, MAP_SPECULAR...)
     */
    TextureUnmanaged& SetMaterial(::Material* material, int mapType = MATERIAL_MAP_NORMAL) {
        ::SetMaterialTexture(material, mapType, *this);
        return *this;
    }

    TextureUnmanaged& SetMaterial(const ::Material& material, int mapType = MATERIAL_MAP_NORMAL) {
        ::SetMaterialTexture((::Material*)(&material), mapType, *this);
        return *this;
    }

    /**
     * Set texture and rectangle to be used on shapes drawing.
     */
    TextureUnmanaged& SetShapes(const ::Rectangle& source) {
        ::SetShapesTexture(*this, source);
        return *this;
    }

    /**
     * Set shader uniform value for texture (sampler2d)
     */
    TextureUnmanaged& SetShaderValue(const ::Shader& shader, int locIndex) {
        ::SetShaderValueTexture(shader, locIndex, *this);
        return *this;
    }

    /**
     * Determines whether or not the Texture has been loaded and is ready.
     *
     * @return True or false depending on whether the Texture has data.
     */
    bool IsValid() const { return IsTextureValid(*this); }
protected:
    void set(const ::Texture& texture) {
        id = texture.id;
        width = texture.width;
        height = texture.height;
        mipmaps = texture.mipmaps;
        format = texture.format;
    }
};

// Create the TextureUnmanaged aliases.
using Texture2DUnmanaged = TextureUnmanaged;
using TextureCubemapUnmanaged = TextureUnmanaged;

} // namespace raylib

using RTextureUnmanaged = raylib::TextureUnmanaged;
using RTexture2DUnmanaged = raylib::Texture2DUnmanaged;
using RTextureCubemapUnmanaged = raylib::TextureCubemapUnmanaged;

#endif // RAYLIB_CPP_INCLUDE_TEXTUREUNMANAGED_HPP_
