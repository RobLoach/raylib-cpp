#ifndef RAYLIB_CPP_INCLUDE_IMAGE_HPP_
#define RAYLIB_CPP_INCLUDE_IMAGE_HPP_

#include <string>

#include "./raylib.hpp"
#include "./raylib-cpp-utils.hpp"
#include "./RaylibException.hpp"

namespace raylib {
/**
 * Image type, bpp always RGBA (32bit)
 *
 * Data stored in CPU memory (RAM)
 */
class Image : public ::Image {
 public:
    Image(void* data = nullptr,
            int width = 0,
            int height = 0,
            int mipmaps = 0,
            int format = 0) : ::Image{data, width, height, mipmaps, format} {
        // Nothing.
    }

    Image(const ::Image& image) {
        set(image);
    }

    /**
     * Load an image from the given file.
     *
     * @throws raylib::RaylibException Thrown if the image failed to load from the file.
     *
     * @see Load()
     */
    Image(const std::string& fileName) {
        if (!Load(fileName)) {
            throw RaylibException(TextFormat("Failed to load Image from file: %s", fileName.c_str()));
        }
    }

    /**
     * Load a raw image from the given file, with the provided width, height, and formats.
     *
     * @throws raylib::RaylibException Thrown if the image failed to load from the file.
     *
     * @see LoadRaw()
     */
    Image(const std::string& fileName, int width, int height, int format, int headerSize) {
        if (!Load(fileName, width, height, format, headerSize)) {
            throw RaylibException(TextFormat("Failed to load Image from file: %s", fileName.c_str()));
        }
    }

    /**
     * Load an animation image from the given file.
     *
     * @throws raylib::RaylibException Thrown if the image failed to load from the file.
     *
     * @see LoadAnim()
     */
    Image(const std::string& fileName, int* frames) {
        if (!Load(fileName, frames)) {
            throw RaylibException(TextFormat("Failed to load Image from animation: %s", fileName.c_str()));
        }
    }

    /**
     * Load an image from the given file.
     *
     * @throws raylib::RaylibException Thrown if the image failed to load from the file.
     */
    Image(const std::string& fileType, const unsigned char* fileData, int dataSize) {
        if (!Load(fileType, fileData, dataSize)) {
            throw RaylibException("Failed to load Image from memory");
        }
    }

    /**
     * Load an image from the given file.
     *
     * @throws raylib::RaylibException Thrown if the image failed to load from the file.
     */
    Image(const ::Texture2D& texture) {
        if (!Load(texture)) {
            throw RaylibException("Failed to load Image from Texture");
        }
    }

    Image(int width, int height, ::Color color = {255, 255, 255, 255}) {
        set(::GenImageColor(width, height, color));
    }

    Image(const std::string& text, int fontSize, ::Color color = {255, 255, 255, 255}) {
        set(::ImageText(text.c_str(), fontSize, color));
    }

    Image(const ::Font& font, const std::string& text, float fontSize, float spacing,
            ::Color tint = {255, 255, 255, 255}) {
        set(::ImageTextEx(font, text.c_str(), fontSize, spacing, tint));
    }

    Image(const Image& other) {
        set(other.Copy());
    }

    Image(Image&& other) {
        set(other);

        other.data = nullptr;
        other.width = 0;
        other.height = 0;
        other.mipmaps = 0;
        other.format = 0;
    }

    static ::Image Text(const std::string& text, int fontSize,
            ::Color color = {255, 255, 255, 255}) {
        return ::ImageText(text.c_str(), fontSize, color);
    }

    static ::Image Text(const ::Font& font, const std::string& text, float fontSize, float spacing,
            ::Color tint = {255, 255, 255, 255}) {
        return ::ImageTextEx(font, text.c_str(), fontSize, spacing, tint);
    }

    /**
     * Get pixel data from screen buffer and return an Image (screenshot)
     */
    static ::Image LoadFromScreen() {
        return ::LoadImageFromScreen();
    }

    /**
     * Generate image: plain color
     */
    static ::Image Color(int width, int height, ::Color color = {255, 255, 255, 255}) {
        return ::GenImageColor(width, height, color);
    }

    /**
     * Generate image: vertical gradient
     */
    static ::Image GradientV(int width, int height, ::Color top, ::Color bottom) {
        return ::GenImageGradientV(width, height, top, bottom);
    }

    /**
     * Generate image: horizontal gradient
     */
    static ::Image GradientH(int width, int height, ::Color left, ::Color right) {
        return ::GenImageGradientH(width, height, left, right);
    }

    /**
     * Generate image: radial gradient
     */
    static ::Image GradientRadial(int width, int height, float density,
            ::Color inner, ::Color outer) {
        return ::GenImageGradientRadial(width, height, density, inner, outer);
    }

    /**
     * Generate image: checked
     */
    static ::Image Checked(int width, int height, int checksX, int checksY,
            ::Color col1 = {255, 255, 255, 255}, ::Color col2 = {0, 0, 0, 255}) {
        return ::GenImageChecked(width, height, checksX, checksY, col1, col2);
    }

    /**
     * Generate image: white noise
     */
    static ::Image WhiteNoise(int width, int height, float factor) {
        return ::GenImageWhiteNoise(width, height, factor);
    }

    /**
     * Generate image: cellular algorithm. Bigger tileSize means bigger cells
     */
    static ::Image Cellular(int width, int height, int tileSize) {
        return ::GenImageCellular(width, height, tileSize);
    }

    ~Image() {
        Unload();
    }

    Image& operator=(const ::Image& image) {
        set(image);
        return *this;
    }

    Image& operator=(const Image& other) {
        if (this == &other) {
            return *this;
        }

        Unload();
        set(other.Copy());

        return *this;
    }

    Image& operator=(Image&& other) {
        if (this == &other) {
            return *this;
        }

        Unload();
        set(other);

        other.data = nullptr;
        other.width = 0;
        other.height = 0;
        other.mipmaps = 0;
        other.format = 0;

        return *this;
    }

    /**
     * Load image from file into CPU memory (RAM)
     *
     * @return Whether or not the image was loaded successfully.
     *
     * @see ::LoadImage()
     */
    bool Load(const std::string& fileName) {
        set(::LoadImage(fileName.c_str()));
        return IsReady();
    }

    /**
     * Load image from RAW file data.
     *
     * @return Whether or not the raw image data was loaded successfully.
     *
     * @see ::LoadImageRaw()
     */
    bool Load(const std::string& fileName, int width, int height, int format, int headerSize) {
        set(::LoadImageRaw(fileName.c_str(), width, height, format, headerSize));
        return IsReady();
    }

    /**
     * Load image sequence from file (frames appended to image.data).
     *
     * @return Whether or not the image animation was loaded successfully.
     *
     * @see ::LoadImageAnim()
     */
    bool Load(const std::string& fileName, int* frames) {
        set(::LoadImageAnim(fileName.c_str(), frames));
        return IsReady();
    }

    /**
     * Load image from memory buffer, fileType refers to extension: i.e. "png".
     *
     * @return Whether or not the image data was loaded successfully.
     *
     * @see ::LoadImageFromMemory()
     */
    bool Load(
            const std::string& fileType,
            const unsigned char *fileData,
            int dataSize) {
        set(::LoadImageFromMemory(fileType.c_str(), fileData, dataSize));
        return IsReady();
    }

    /**
     * Load an image from the given file.
     *
     * @return True or false depending on whether or not the image was loaded from the texture.
     *
     * @see ::LoadImageFromTexture()
     */
    bool Load(const ::Texture2D& texture) {
        set(::LoadImageFromTexture(texture));
        return IsReady();
    }

    /**
     * Unload image from CPU memory (RAM)
     */
    inline void Unload() {
        if (data != nullptr) {
            ::UnloadImage(*this);
            data = nullptr;
        }
    }

    /**
     * Export image data to file, returns true on success
     */
    inline bool Export(const std::string& fileName) const {
        // TODO(RobLoach): Switch to an invalid loading exception on false.
        return ::ExportImage(*this, fileName.c_str());
    }

    /**
     * Export image as code file defining an array of bytes, returns true on success
     */
    inline bool ExportAsCode(const std::string& fileName) const {
        return ::ExportImageAsCode(*this, fileName.c_str());
    }

    GETTERSETTER(void*, Data, data)
    GETTERSETTER(int, Width, width)
    GETTERSETTER(int, Height, height)
    GETTERSETTER(int, Mipmaps, mipmaps)
    GETTERSETTER(int, Format, format)

    /**
     * Retrieve the width and height of the image.
     */
    inline ::Vector2 GetSize() const {
        return {static_cast<float>(width), static_cast<float>(height)};
    }

    /**
     * Create an image duplicate (useful for transformations)
     */
    inline ::Image Copy() const {
        return ::ImageCopy(*this);
    }

    /**
     * Create an image from another image piece
     */
    inline ::Image FromImage(::Rectangle rec) const {
        return ::ImageFromImage(*this, rec);
    }

    /**
     * Convert image to POT (power-of-two)
     */
    inline Image& ToPOT(::Color fillColor) {
        ::ImageToPOT(this, fillColor);
        return *this;
    }

    /**
     * Convert image data to desired format
     */
    inline Image& Format(int newFormat) {
        ::ImageFormat(this, newFormat);
        return *this;
    }

    /**
     * Crop image depending on alpha value
     */
    inline Image& AlphaCrop(float threshold) {
        ::ImageAlphaCrop(this, threshold);
        return *this;
    }

    /**
     * Clear alpha channel to desired color
     */
    inline Image& AlphaClear(::Color color, float threshold) {
        ::ImageAlphaClear(this, color, threshold);
        return *this;
    }

    /**
     * Apply alpha mask to image
     */
    inline Image& AlphaMask(const ::Image& alphaMask) {
        ::ImageAlphaMask(this, alphaMask);
        return *this;
    }

    /**
     * Premultiply alpha channel
     */
    inline Image& AlphaPremultiply() {
        ::ImageAlphaPremultiply(this);
        return *this;
    }

    /**
     * Crop an image to area defined by a rectangle
     */
    inline Image& Crop(::Rectangle crop) {
        ::ImageCrop(this, crop);
        return *this;
    }

    /**
     * Crop an image to a new given width and height.
     */
    inline Image& Crop(int newWidth, int newHeight) {
        return Crop(0, 0, newWidth, newHeight);
    }

    /**
     * Crop an image to a new given width and height based on a vector.
     */
    inline Image& Crop(::Vector2 size) {
        return Crop(0, 0, static_cast<int>(size.x), static_cast<int>(size.y));
    }

    /**
     * Crop an image to area defined by a rectangle
     */
    inline Image& Crop(int offsetX, int offsetY, int newWidth, int newHeight) {
        ::Rectangle rect{
            static_cast<float>(offsetX),
            static_cast<float>(offsetY),
            static_cast<float>(newWidth),
            static_cast<float>(newHeight)
        };
        ::ImageCrop(this, rect);
        return *this;
    }

    /**
     * Resize and image to new size
     */
    inline Image& Resize(int newWidth, int newHeight) {
        ::ImageResize(this, newWidth, newHeight);
        return *this;
    }

    /**
     * Resize and image to new size using Nearest-Neighbor scaling algorithm
     */
    inline Image& ResizeNN(int newWidth, int newHeight) {
        ::ImageResizeNN(this, newWidth, newHeight);
        return *this;
    }

    /**
     * Resize canvas and fill with color
     */
    inline Image& ResizeCanvas(int newWidth, int newHeight, int offsetX = 0, int offsetY = 0,
            ::Color color = {255, 255, 255, 255}) {
        ::ImageResizeCanvas(this, newWidth, newHeight, offsetX, offsetY, color);
        return *this;
    }

    /**
     * Generate all mipmap levels for a provided image
     */
    inline Image& Mipmaps() {
        ::ImageMipmaps(this);
        return *this;
    }

    /**
     * Dither image data to 16bpp or lower (Floyd-Steinberg dithering)
     */
    inline Image& Dither(int rBpp, int gBpp, int bBpp, int aBpp) {
        ::ImageDither(this, rBpp, gBpp, bBpp, aBpp);
        return *this;
    }

    /**
     * Flip image vertically
     */
    inline Image& FlipVertical() {
        ::ImageFlipVertical(this);
        return *this;
    }

    /**
     * Flip image horizontally
     */
    inline Image& FlipHorizontal() {
        ::ImageFlipHorizontal(this);
        return *this;
    }

    /**
     * Rotate image clockwise 90deg
     */
    inline Image& RotateCW() {
        ::ImageRotateCW(this);
        return *this;
    }

    /**
     * Rotate image counter-clockwise 90deg
     */
    inline Image& RotateCCW() {
        ::ImageRotateCCW(this);
        return *this;
    }

    /**
     * Modify image color: tint
     */
    inline Image& ColorTint(::Color color = {255, 255, 255, 255}) {
        ::ImageColorTint(this, color);
        return *this;
    }

    /**
     * Modify image color: invert
     */
    inline Image& ColorInvert() {
        ::ImageColorInvert(this);
        return *this;
    }

    /**
     * Modify image color: grayscale
     */
    inline Image& ColorGrayscale() {
        ::ImageColorGrayscale(this);
        return *this;
    }

    /**
     * Modify image color: contrast
     *
     * @param contrast Contrast values between -100 and 100
     */
    inline Image& ColorContrast(float contrast) {
        ::ImageColorContrast(this, contrast);
        return *this;
    }

    /**
     * Modify image color: brightness
     *
     * @param brightness Brightness values between -255 and 255
     */
    inline Image& ColorBrightness(int brightness) {
        ::ImageColorBrightness(this, brightness);
        return *this;
    }

    /**
     * Modify image color: replace color
     */
    inline Image& ColorReplace(::Color color, ::Color replace) {
        ::ImageColorReplace(this, color, replace);
        return *this;
    }

    /**
     * Get image alpha border rectangle
     *
     * @param threshold Threshold is defined as a percentatge: 0.0f -> 1.0f
     */
    inline Rectangle GetAlphaBorder(float threshold) const {
        return ::GetImageAlphaBorder(*this, threshold);
    }

    /**
     * Clear image background with given color
     */
    inline Image& ClearBackground(::Color color = {0, 0, 0, 255}) {
        ::ImageClearBackground(this, color);
        return *this;
    }

    /**
     * Draw pixel within an image
     */
    inline Image& DrawPixel(int posX, int posY, ::Color color = {255, 255, 255, 255}) {
        ::ImageDrawPixel(this, posX, posY, color);
        return *this;
    }

    inline Image& DrawPixel(::Vector2 position, ::Color color = {255, 255, 255, 255}) {
        ::ImageDrawPixelV(this, position, color);
        return *this;
    }

    inline Image& DrawLine(int startPosX, int startPosY, int endPosX, int endPosY,
            ::Color color = {255, 255, 255, 255}) {
        ::ImageDrawLine(this, startPosX, startPosY, endPosX, endPosY, color);
        return *this;
    }

    inline Image& DrawLine(::Vector2 start, ::Vector2 end, ::Color color = {255, 255, 255, 255}) {
        ::ImageDrawLineV(this, start, end, color);
        return *this;
    }

    inline Image& DrawCircle(int centerX, int centerY, int radius,
            ::Color color = {255, 255, 255, 255}) {
        ::ImageDrawCircle(this, centerX, centerY, radius, color);
        return *this;
    }

    inline Image& DrawCircle(::Vector2 center, int radius,
            ::Color color = {255, 255, 255, 255}) {
        ::ImageDrawCircleV(this, center, radius, color);
        return *this;
    }

    inline Image& DrawRectangle(int posX, int posY, int width, int height,
            ::Color color = {255, 255, 255, 255}) {
        ::ImageDrawRectangle(this, posX, posY, width, height, color);
        return *this;
    }

    inline Image& DrawRectangle(Vector2 position, Vector2 size,
            ::Color color = {255, 255, 255, 255}) {
        ::ImageDrawRectangleV(this, position, size, color);
        return *this;
    }

    inline Image& DrawRectangle(::Rectangle rec, ::Color color = {255, 255, 255, 255}) {
        ::ImageDrawRectangleRec(this, rec, color);
        return *this;
    }

    inline Image& DrawRectangleLines(::Rectangle rec, int thick = 1,
            ::Color color = {255, 255, 255, 255}) {
        ::ImageDrawRectangleLines(this, rec, thick, color);
        return *this;
    }

    inline Image& Draw(const ::Image& src, ::Rectangle srcRec, ::Rectangle dstRec,
            ::Color tint = {255, 255, 255, 255}) {
        ::ImageDraw(this, src, srcRec, dstRec, tint);
        return *this;
    }

    inline Image& DrawText(const std::string& text, ::Vector2 position, int fontSize,
            ::Color color = {255, 255, 255, 255}) {
        ::ImageDrawText(this,
            text.c_str(),
            static_cast<int>(position.x),
            static_cast<int>(position.y),
            fontSize,
            color);
        return *this;
    }

    inline Image& DrawText(const std::string& text, int x, int y, int fontSize,
            ::Color color = {255, 255, 255, 255}) {
        ::ImageDrawText(this, text.c_str(), x, y, fontSize, color);
        return *this;
    }

    inline Image& DrawText(const ::Font& font, const std::string& text, ::Vector2 position,
            float fontSize, float spacing, ::Color tint = {255, 255, 255, 255}) {
        ::ImageDrawTextEx(this, font, text.c_str(), position, fontSize, spacing, tint);
        return *this;
    }

    /**
     * Load color data from image as a Color array (RGBA - 32bit)
     */
    inline ::Color* LoadColors() const {
        return ::LoadImageColors(*this);
    }

    /**
     * Load colors palette from image as a Color array (RGBA - 32bit)
     */
    inline ::Color* LoadPalette(int maxPaletteSize, int *colorsCount) const {
        return ::LoadImagePalette(*this, maxPaletteSize, colorsCount);
    }

    /**
     * Unload color data loaded with LoadImageColors()
     */
    inline void UnloadColors(::Color* colors) const {
        ::UnloadImageColors(colors);
    }

    /**
     * Unload colors palette loaded with LoadImagePalette()
     */
    inline void UnloadPalette(::Color* colors) const {
        ::UnloadImagePalette(colors);
    }

    /**
     * Load texture from image data.
     */
    inline ::Texture2D LoadTexture() const {
        return ::LoadTextureFromImage(*this);
    }

    /**
     * Loads a texture from the image data.
     *
     * @see LoadTexture()
     */
    inline operator ::Texture2D() {
        return LoadTexture();
    }

    /**
     * Get pixel data size in bytes for certain format
     */
    static int GetPixelDataSize(int width, int height, int format = PIXELFORMAT_UNCOMPRESSED_R32G32B32A32) {
        return ::GetPixelDataSize(width, height, format);
    }

    /**
     * Returns the pixel data size based on the current image.
     *
     * @return The pixel data size of the image.
     */
    int GetPixelDataSize() const {
        return ::GetPixelDataSize(width, height, format);
    }

    /**
     * Retrieve whether or not the Image has been loaded.
     *
     * @return True or false depending on whether the Image has been loaded.
     */
    inline bool IsReady() const {
        return data != nullptr;
    }

 private:
    inline void set(const ::Image& image) {
        data = image.data;
        width = image.width;
        height = image.height;
        mipmaps = image.mipmaps;
        format = image.format;
    }
};
}  // namespace raylib

#endif  // RAYLIB_CPP_INCLUDE_IMAGE_HPP_
