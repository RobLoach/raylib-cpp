#ifndef RAYLIB_CPP_INCLUDE_TEXTURE_HPP_
#define RAYLIB_CPP_INCLUDE_TEXTURE_HPP_

#include <string>

#include "./raylib.hpp"
#include "./raylib-cpp-utils.hpp"
#include "./Vector2.hpp"
#include "./Material.hpp"
#include "./RaylibException.hpp"

namespace raylib {
/**
 * Texture type
 */
class Texture : public ::Texture {
 public:
    /**
     * Default constructor to create an empty Texture object.
     */
    Texture(unsigned int id = 0,
            int width = 0,
            int height = 0,
            int mipmaps = 0,
            int format = 0) : ::Texture{id, width, height, mipmaps, format} {
        // Nothing.
    }

    /**
     * Creates a texture object based on the given Texture struct data.
     */
    Texture(const ::Texture& texture) {
        set(texture);
    }

    /**
     * Creates a texture from the given Image.
     *
     * @throws raylib::RaylibException Throws if failed to create the texture from the given image.
     */
    Texture(const ::Image& image) {
        if (!Load(image)) {
            throw RaylibException("Failed to load Texture from Image");
        }
    }

    /**
     * Load cubemap from image, multiple image cubemap layouts supported.
     *
     * @throws raylib::RaylibException Throws if failed to create the texture from the given cubemap.
     *
     * @see LoadTextureCubemap()
     */
    Texture(const ::Image& image, int layout) {
        if (!Load(image, layout)) {
            throw RaylibException("Failed to load Texture from Cubemap");
        }
    }

    /**
     * Load texture from file into GPU memory (VRAM)
     *
     * @throws raylib::RaylibException Throws if failed to create the texture from the given file.
     */
    Texture(const std::string& fileName) {
        if (!Load(fileName)) {
            throw RaylibException(TextFormat("Failed to load Texture from file: %s", fileName.c_str()));
        }
    }

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

    GETTERSETTER(unsigned int, Id, id)
    GETTERSETTER(int, Width, width)
    GETTERSETTER(int, Height, height)
    GETTERSETTER(int, Mipmaps, mipmaps)
    GETTERSETTER(int, Format, format)

    Texture& operator=(const ::Texture& texture) {
        set(texture);
        return *this;
    }

    Texture& operator=(const Texture&) = delete;

    Texture& operator=(Texture&& other) {
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
     * Retrieve the width and height of the texture.
     */
    inline ::Vector2 GetSize() const {
        return {static_cast<float>(width), static_cast<float>(height)};
    }

    /**
     * Load texture from image data
     */
    bool Load(const ::Image& image) {
        set(::LoadTextureFromImage(image));
        return IsReady();
    }

    /**
     * Load cubemap from image, multiple image cubemap layouts supported
     */
    bool Load(const ::Image& image, int layoutType) {
        set(::LoadTextureCubemap(image, layoutType));
        return IsReady();
    }

    /**
     * Load texture from file into GPU memory (VRAM)
     */
    bool Load(const std::string& fileName) {
        set(::LoadTexture(fileName.c_str()));
        return IsReady();
    }

    /**
     * Unload texture from GPU memory (VRAM)
     */
    inline void Unload() {
        ::UnloadTexture(*this);
    }

    /**
     * Update GPU texture with new data
     */
    inline Texture& Update(const void *pixels) {
        ::UpdateTexture(*this, pixels);
        return *this;
    }

    /**
     * Update GPU texture rectangle with new data
     */
    inline Texture& Update(::Rectangle rec, const void *pixels) {
        UpdateTextureRec(*this, rec, pixels);
        return *this;
    }

    /**
     * Get pixel data from GPU texture and return an Image
     */
    inline ::Image GetData() const {
        return ::LoadImageFromTexture(*this);
    }

    /**
     * Get pixel data from GPU texture and return an Image
     */
    inline operator raylib::Image() {
        return GetData();
    }

    /**
     * Generate GPU mipmaps for a texture
     */
    inline Texture& GenMipmaps() {
        ::GenTextureMipmaps(this);
        return *this;
    }

    /**
     * Set texture scaling filter mode
     */
    inline Texture& SetFilter(int filterMode) {
        ::SetTextureFilter(*this, filterMode);
        return *this;
    }

    /**
     * Set texture wrapping mode
     */
    inline Texture& SetWrap(int wrapMode) {
        ::SetTextureWrap(*this, wrapMode);
        return *this;
    }

    /**
     * Draw a Texture2D
     */
    inline Texture& Draw(int posX = 0, int posY = 0, ::Color tint = {255, 255, 255, 255}) {
        ::DrawTexture(*this, posX, posY, tint);
        return *this;
    }

    inline Texture& Draw(::Vector2 position, ::Color tint = {255, 255, 255, 255}) {
        ::DrawTextureV(*this, position, tint);
        return *this;
    }

    inline Texture& Draw(::Vector2 position, float rotation, float scale = 1.0f,
            ::Color tint = {255, 255, 255, 255}) {
        ::DrawTextureEx(*this, position, rotation, scale, tint);
        return *this;
    }

    inline Texture& Draw(::Rectangle sourceRec, ::Vector2 position = {0, 0},
            ::Color tint = {255, 255, 255, 255}) {
        ::DrawTextureRec(*this, sourceRec, position, tint);
        return *this;
    }

    inline Texture& Draw(::Vector2 tiling, ::Vector2 offset, ::Rectangle quad,
            ::Color tint = {255, 255, 255, 255}) {
        ::DrawTextureQuad(*this, tiling, offset, quad, tint);
        return *this;
    }

    inline Texture& Draw(::Rectangle sourceRec, ::Rectangle destRec, ::Vector2 origin = {0, 0},
            float rotation = 0, ::Color tint = {255, 255, 255, 255}) {
        ::DrawTexturePro(*this, sourceRec, destRec, origin, rotation, tint);
        return *this;
    }

    inline Texture& Draw(::NPatchInfo nPatchInfo, ::Rectangle destRec, ::Vector2 origin = {0, 0},
            float rotation = 0, ::Color tint = {255, 255, 255, 255}) {
        ::DrawTextureNPatch(*this, nPatchInfo, destRec, origin, rotation, tint);
        return *this;
    }

    inline Texture& Draw(::Vector3 position, float width, float height, float length,
            ::Color tint = {255, 255, 255, 255}) {
        ::DrawCubeTexture(*this, position, width, height, length, tint);
        return *this;
    }

    inline Texture& DrawTiled(::Rectangle sourceRec, ::Rectangle destRec, ::Vector2 origin = {0, 0},
            float rotation = 0, float scale = 1, Color tint = {255, 255, 255, 255}) {
        ::DrawTextureTiled(*this, sourceRec, destRec, origin, rotation, scale, tint);
        return *this;
    }

    inline Texture& DrawPoly(Vector2 center, Vector2 *points,
            Vector2 *texcoords, int pointsCount,
            Color tint = {255, 255, 255, 255}) {
        ::DrawTexturePoly(*this, center, points, texcoords, pointsCount, tint);
        return *this;
    }

    /**
     * Set texture for a material map type (MAP_DIFFUSE, MAP_SPECULAR...)
     */
    inline Texture& SetMaterial(::Material *material, int mapType = MATERIAL_MAP_NORMAL) {
        ::SetMaterialTexture(material, mapType, *this);
        return *this;
    }

    inline Texture& SetMaterial(const ::Material& material, int mapType = MATERIAL_MAP_NORMAL) {
        ::SetMaterialTexture((::Material*)(&material), mapType, *this);
        return *this;
    }

    /**
     * Set texture and rectangle to be used on shapes drawing.
     */
    inline Texture& SetShapes(const ::Rectangle& source) {
        ::SetShapesTexture(*this, source);
        return *this;
    }

    /**
     * Set shader uniform value for texture (sampler2d)
     */
    inline Texture& SetShaderValue(const ::Shader& shader, int locIndex) {
        ::SetShaderValueTexture(shader, locIndex, *this);
        return *this;
    }

    /**
     * Determines whether or not the Texture has been loaded and is ready.
     *
     * @return True or false depending on whether the Texture has data.
     */
    bool IsReady() const {
        return id != 0;
    }

 private:
    inline void set(const ::Texture& texture) {
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
