#ifndef RAYLIB_CPP_INCLUDE_TEXTUREUNMANAGED_HPP_
#define RAYLIB_CPP_INCLUDE_TEXTUREUNMANAGED_HPP_

#include <string>

#include "./raylib.hpp"
#include "./raylib-cpp-utils.hpp"
#include "./Vector2.hpp"
#include "./Material.hpp"
#include "./RaylibException.hpp"
#include "./Image.hpp"

namespace raylib {
/**
 * A Texture that is not managed by the C++ garbage collector.
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
    TextureUnmanaged(unsigned int id,
            int width, int height,
            int mipmaps = 1,
            int format = PIXELFORMAT_UNCOMPRESSED_R8G8B8A8)
            : ::Texture{id, width, height, mipmaps, format} {
        // Nothing.
    }

    /**
     * Creates a texture object based on the given Texture struct data.
     */
    TextureUnmanaged(const ::Texture& texture) :
            ::Texture{texture.id, texture.width, texture.height, texture.mipmaps, texture.format} {
        // Nothing.
    }

    /**
     * Creates a texture from the given Image.
     *
     * @throws raylib::RaylibException Throws if failed to create the texture from the given image.
     */
    TextureUnmanaged(const ::Image& image) {
        Load(image);
    }

    /**
     * Load cubemap from image, multiple image cubemap layouts supported.
     *
     * @throws raylib::RaylibException Throws if failed to create the texture from the given cubemap.
     *
     * @see LoadTextureCubemap()
     */
    TextureUnmanaged(const ::Image& image, int layout) {
        Load(image, layout);
    }

    /**
     * Load texture from file into GPU memory (VRAM)
     *
     * @throws raylib::RaylibException Throws if failed to create the texture from the given file.
     */
    TextureUnmanaged(const std::string& fileName) {
        Load(fileName);
    }

    TextureUnmanaged(::Texture&& other) :
            ::Texture{other.id, other.width, other.height, other.mipmaps, other.format} {
        // Nothing.
    }

    GETTERSETTER(unsigned int, Id, id)
    GETTERSETTER(int, Width, width)
    GETTERSETTER(int, Height, height)
    GETTERSETTER(int, Mipmaps, mipmaps)
    GETTERSETTER(int, Format, format)

    TextureUnmanaged& operator=(const ::Texture& texture) {
        set(texture);
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
    void Load(const ::Image& image) {
        set(::LoadTextureFromImage(image));
        if (!IsReady()) {
            throw RaylibException("Failed to load Texture from Image");
        }
    }

    /**
     * Load cubemap from image, multiple image cubemap layouts supported
     */
    void Load(const ::Image& image, int layoutType) {
        set(::LoadTextureCubemap(image, layoutType));
        if (!IsReady()) {
            throw RaylibException("Failed to load Texture from Cubemap");
        }
    }

    /**
     * Load texture from file into GPU memory (VRAM)
     */
    void Load(const std::string& fileName) {
        set(::LoadTexture(fileName.c_str()));
        if (!IsReady()) {
            throw RaylibException("Failed to load Texture from file: " + fileName);
        }
    }

    /**
     * Unload texture from GPU memory (VRAM)
     */
    inline void Unload() {
        // Protect against calling UnloadTexture() twice.
        if (id != 0) {
            ::UnloadTexture(*this);
            id = 0;
        }
    }

    /**
     * Update GPU texture with new data
     */
    inline TextureUnmanaged& Update(const void *pixels) {
        ::UpdateTexture(*this, pixels);
        return *this;
    }

    /**
     * Update GPU texture rectangle with new data
     */
    inline TextureUnmanaged& Update(::Rectangle rec, const void *pixels) {
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
    inline operator Image() {
        return GetData();
    }

    /**
     * Generate GPU mipmaps for a texture
     */
    inline TextureUnmanaged& GenMipmaps() {
        ::GenTextureMipmaps(this);
        return *this;
    }

    /**
     * Set texture scaling filter mode
     */
    inline TextureUnmanaged& SetFilter(int filterMode) {
        ::SetTextureFilter(*this, filterMode);
        return *this;
    }

    /**
     * Set texture wrapping mode
     */
    inline TextureUnmanaged& SetWrap(int wrapMode) {
        ::SetTextureWrap(*this, wrapMode);
        return *this;
    }

    /**
     * Draw a Texture2D
     *
     * @see ::DrawTexture()
     */
    inline void Draw(int posX = 0, int posY = 0, ::Color tint = {255, 255, 255, 255}) const {
        ::DrawTexture(*this, posX, posY, tint);
    }

    /**
     * Draw a Texture2D with position defined as Vector2
     *
     * @see ::DrawTextureV()
     */
    inline void Draw(::Vector2 position, ::Color tint = {255, 255, 255, 255}) const {
        ::DrawTextureV(*this, position, tint);
    }

    /**
     * Draw a Texture2D with extended parameters
     *
     * @see ::DrawTextureEx()
     */
    inline void Draw(::Vector2 position, float rotation, float scale = 1.0f,
            ::Color tint = {255, 255, 255, 255}) const {
        ::DrawTextureEx(*this, position, rotation, scale, tint);
    }

    /**
     * Draw a part of a texture defined by a rectangle
     *
     * @see ::DrawTextureRec()
     */
    inline void Draw(::Rectangle sourceRec, ::Vector2 position = {0, 0},
            ::Color tint = {255, 255, 255, 255}) const {
        ::DrawTextureRec(*this, sourceRec, position, tint);
    }

    /**
     * Draw texture quad with tiling and offset parameters
     *
     * @see ::DrawTextureQuad()
     */
    inline void Draw(::Vector2 tiling, ::Vector2 offset, ::Rectangle quad,
            ::Color tint = {255, 255, 255, 255}) const {
        ::DrawTextureQuad(*this, tiling, offset, quad, tint);
    }

    /**
     * Draw a part of a texture defined by a rectangle with 'pro' parameters
     *
     * @see ::DrawTexturePro()
     */
    inline void Draw(::Rectangle sourceRec, ::Rectangle destRec, ::Vector2 origin = {0, 0},
            float rotation = 0, ::Color tint = {255, 255, 255, 255}) const {
        ::DrawTexturePro(*this, sourceRec, destRec, origin, rotation, tint);
    }

    /**
     * Draws a texture (or part of it) that stretches or shrinks nicely
     *
     * @see ::DrawTextureNPatch()
     */
    inline void Draw(::NPatchInfo nPatchInfo, ::Rectangle destRec, ::Vector2 origin = {0, 0},
            float rotation = 0, ::Color tint = {255, 255, 255, 255}) const {
        ::DrawTextureNPatch(*this, nPatchInfo, destRec, origin, rotation, tint);
    }

    /**
     * Draw part of a texture (defined by a rectangle) with rotation and scale tiled into dest.
     *
     * @see ::DrawTextureTiled()
     */
    inline void DrawTiled(::Rectangle sourceRec, ::Rectangle destRec, ::Vector2 origin = {0, 0},
            float rotation = 0, float scale = 1, Color tint = {255, 255, 255, 255}) const {
        ::DrawTextureTiled(*this, sourceRec, destRec, origin, rotation, scale, tint);
    }

    /**
     * Draw a textured polygon
     *
     * @see ::DrawTexturePoly()
     */
    inline void DrawPoly(::Vector2 center, ::Vector2 *points,
            ::Vector2 *texcoords, int pointsCount,
            ::Color tint = {255, 255, 255, 255}) const {
        ::DrawTexturePoly(*this, center, points, texcoords, pointsCount, tint);
    }

    /**
     * Draw a billboard texture
     *
     * @see ::DrawBillboard()
     */
    inline void DrawBillboard(const ::Camera& camera,
            ::Vector3 position, float size,
            ::Color tint = {255, 255, 255, 255}) const {
        ::DrawBillboard(camera, *this, position, size, tint);
    }

    /**
     * Draw a billboard texture defined by source
     *
     * @see ::DrawBillboardRec()
     */
    inline void DrawBillboard(const ::Camera& camera,
            ::Rectangle source, ::Vector3 position, ::Vector2 size,
            ::Color tint = {255, 255, 255, 255}) const {
        DrawBillboardRec(camera, *this, source, position, size, tint);
    }

    /**
     * Draw a billboard texture defined by source and rotation
     *
     * @see ::DrawBillboardPro()
     */
    inline void DrawBillboard(const ::Camera& camera,
            ::Rectangle source, Vector3 position,
            ::Vector3 up, Vector2 size, Vector2 origin, float rotation = 0.0f,
            ::Color tint = {255, 255, 255, 255}) const {
        DrawBillboardPro(camera, *this, source, position, up, size, origin, rotation, tint);
    }

    /**
     * Draw cube textured
     *
     * @see ::DrawCubeTexture()
     */
    inline void DrawCube(::Vector3 position, float width, float height, float length,
            ::Color color = {255, 255, 255, 255}) const {
        ::DrawCubeTexture(*this, position, width, height, length, color);
    }

    /**
     * Draw cube textured, with dimensions
     *
     * @see ::DrawCubeTexture()
     */
    inline void DrawCube(::Vector3 position, ::Vector3 dimensions,
            ::Color color = {255, 255, 255, 255}) const {
        ::DrawCubeTexture(*this, position, dimensions.x, dimensions.y, dimensions.z, color);
    }

    /**
     * Draw cube with a region of a texture
     *
     * @see ::DrawCubeTextureRec()
     */
    inline void DrawCube(::Rectangle source, ::Vector3 position, float width, float height, float length,
            ::Color color = {255, 255, 255, 255}) const {
        ::DrawCubeTextureRec(*this, source, position, width, height, length, color);
    }

    /**
     * Draw cube with a region of a texture, with dimensions
     *
     * @see ::DrawCubeTextureRec()
     */
    inline void DrawCube(::Rectangle source, ::Vector3 position, ::Vector3 dimensions,
            ::Color color = {255, 255, 255, 255}) const {
        ::DrawCubeTextureRec(*this, source, position, dimensions.x, dimensions.y, dimensions.z, color);
    }

    /**
     * Set texture for a material map type (MAP_DIFFUSE, MAP_SPECULAR...)
     */
    inline TextureUnmanaged& SetMaterial(::Material *material, int mapType = MATERIAL_MAP_NORMAL) {
        ::SetMaterialTexture(material, mapType, *this);
        return *this;
    }

    inline TextureUnmanaged& SetMaterial(const ::Material& material, int mapType = MATERIAL_MAP_NORMAL) {
        ::SetMaterialTexture((::Material*)(&material), mapType, *this);
        return *this;
    }

    /**
     * Set texture and rectangle to be used on shapes drawing.
     */
    inline TextureUnmanaged& SetShapes(const ::Rectangle& source) {
        ::SetShapesTexture(*this, source);
        return *this;
    }

    /**
     * Set shader uniform value for texture (sampler2d)
     */
    inline TextureUnmanaged& SetShaderValue(const ::Shader& shader, int locIndex) {
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
typedef TextureUnmanaged Texture2DUnmanaged;
typedef TextureUnmanaged TextureCubemapUnmanaged;

}  // namespace raylib

using RTextureUnmanaged = raylib::TextureUnmanaged;
using RTexture2DUnmanaged = raylib::Texture2DUnmanaged;
using RTextureCubemapUnmanaged = raylib::TextureCubemapUnmanaged;

#endif  // RAYLIB_CPP_INCLUDE_TEXTUREUNMANAGED_HPP_
