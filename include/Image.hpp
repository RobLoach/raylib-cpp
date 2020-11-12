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

#ifndef RAYLIB_CPP_INCLUDE_IMAGE_HPP_
#define RAYLIB_CPP_INCLUDE_IMAGE_HPP_

#include <string>

#include "./raylib.hpp"
#include "./raylib-cpp-utils.hpp"

namespace raylib {
class Image : public ::Image {
 public:
    Image() {}
    Image(::Image image) {
        set(image);
    }
    Image(const std::string& fileName) {
        Load(fileName);
    }
    Image(const std::string& fileName, int width, int height, int format, int headerSize) {
        LoadRaw(fileName, width, height, format, headerSize);
    }
    Image(const std::string& fileName, int* frames) {
        LoadAnim(fileName, frames);
    }
    Image(const std::string& fileType, const unsigned char* fileData, int dataSize) {
        LoadFromMemory(fileType, fileData, dataSize);
    }
    Image(::Texture2D texture) {
        set(::GetTextureData(texture));
    }
    Image(int width, int height, Color color = WHITE) {
        set(::GenImageColor(width, height, color));
    }

    static Image Text(std::string text, int fontSize, Color color) {
        return ::ImageText(text.c_str(), fontSize, color);
    }

    static Image Text(Font font, std::string text, float fontSize, float spacing, Color tint) {
        return ::ImageTextEx(font, text.c_str(), fontSize, spacing, tint);
    }

    static Image GetScreenData() {
        return Image(::GetScreenData());
    }

    static Image GenColor(int width, int height, Color color) {
        return ::GenImageColor(width, height, color);
    }

    static Image GenGradientV(int width, int height, Color top, Color bottom) {
        return ::GenImageGradientV(width, height, top, bottom);
    }

    static Image GenGradientH(int width, int height, Color left, Color right) {
        return ::GenImageGradientH(width, height, left, right);
    }

    static Image GenGradientRadial(int width, int height, float density,
            Color inner, Color outer) {
        return ::GenImageGradientRadial(width, height, density, inner, outer);
    }

    static Image GenChecked(int width, int height, int checksX, int checksY,
            Color col1, Color col2) {
        return ::GenImageChecked(width, height, checksX, checksY, col1, col2);
    }

    static Image GenWhiteNoise(int width, int height, float factor) {
        return ::GenImageWhiteNoise(width, height, factor);
    }

    static Image GenPerlinNoise(int width, int height, int offsetX, int offsetY, float scale) {
        return ::GenImagePerlinNoise(width, height, offsetX, offsetY, scale);
    }

    static Image GenCellular(int width, int height, int tileSize) {
        return ::GenImageCellular(width, height, tileSize);
    }

    ~Image() {
        Unload();
    }

    Image& operator=(const ::Image& image) {
        set(image);
        return *this;
    }

    Image& operator=(const Image& image) {
        set(image);
        return *this;
    }

    void Load(const std::string& fileName) {
        set(::LoadImage(fileName.c_str()));
    }

    void LoadRaw(const std::string& fileName, int width, int height, int format, int headerSize) {
        set(::LoadImageRaw(fileName.c_str(), width, height, format, headerSize));
    }

    void LoadAnim(const std::string& fileName, int* frames) {
        set(::LoadImageAnim(fileName.c_str(), frames));
    }

    void LoadFromMemory(const std::string& fileType, const unsigned char *fileData, int dataSize) {
        set(::LoadImageFromMemory(fileType.c_str(), fileData, dataSize));
    }

    inline void Unload() {
        ::UnloadImage(*this);
    }

    inline Image& Export(const std::string& fileName) {
        ::ExportImage(*this, fileName.c_str());
        return *this;
    }

    inline Image& ExportAsCode(const std::string& fileName) {
        ::ExportImageAsCode(*this, fileName.c_str());
        return *this;
    }

    GETTERSETTER(void*, Data, data)
    GETTERSETTER(int, Width, width)
    GETTERSETTER(int, Height, height)
    GETTERSETTER(int, Mipmaps, mipmaps)
    GETTERSETTER(int, Format, format)

    inline Image Copy() {
        return ::ImageCopy(*this);
    }
    inline Image FromImage(::Rectangle rec) {
        return ::ImageFromImage(*this, rec);
    }

    inline Image& ToPOT(Color fillColor) {
        ::ImageToPOT(this, fillColor);
        return *this;
    }

    inline Image& Format(int newFormat) {
        ::ImageFormat(this, newFormat);
        return *this;
    }

    inline Image& AlphaMask(Image alphaMask) {
        ::ImageAlphaMask(this, alphaMask);
        return *this;
    }

    inline Image& AlphaCrop(float threshold) {
        ::ImageAlphaCrop(this, threshold);
        return *this;
    }

    inline Image& AlphaPremultiply() {
        ::ImageAlphaPremultiply(this);
        return *this;
    }

    inline Image& Crop(::Rectangle crop) {
        ::ImageCrop(this, crop);
        return *this;
    }
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

    inline Image& Resize(int newWidth, int newHeight) {
        ::ImageResize(this, newWidth, newHeight);
        return *this;
    }

    inline Image& ResizeNN(int newWidth, int newHeight) {
        ::ImageResizeNN(this, newWidth, newHeight);
        return *this;
    }

    inline Image& ResizeCanvas(int newWidth, int newHeight, int offsetX, int offsetY, Color color) {
        ::ImageResizeCanvas(this, newWidth, newHeight, offsetX, offsetY, color);
        return *this;
    }

    inline Image& Mipmaps() {
        ::ImageMipmaps(this);
        return *this;
    }

    inline Image& Dither(int rBpp, int gBpp, int bBpp, int aBpp) {
        ::ImageDither(this, rBpp, gBpp, bBpp, aBpp);
        return *this;
    }

    inline Image& FlipVertical() {
        ::ImageFlipVertical(this);
        return *this;
    }
    inline Image& FlipHorizontal() {
        ::ImageFlipHorizontal(this);
        return *this;
    }

    inline Image& RotateCW() {
        ::ImageRotateCW(this);
        return *this;
    }

    inline Image& RotateCCW() {
        ::ImageRotateCCW(this);
        return *this;
    }

    inline Image& ColorTint(::Color color = WHITE) {
        ::ImageColorTint(this, color);
        return *this;
    }

    inline Image& ColorInvert() {
        ::ImageColorInvert(this);
        return *this;
    }

    inline Image& ColorGrayscale() {
        ::ImageColorGrayscale(this);
        return *this;
    }
    inline Image& ColorContrast(float contrast) {
        ::ImageColorContrast(this, contrast);
        return *this;
    }
    inline Image& ColorBrightness(int brightness) {
        ::ImageColorBrightness(this, brightness);
        return *this;
    }
    inline Image& ColorReplace(::Color color, ::Color replace) {
        ::ImageColorReplace(this, color, replace);
        return *this;
    }

    inline ::Color* GetPalette(int maxPaletteSize, int *extractCount) {
        return ::GetImagePalette(*this, maxPaletteSize, extractCount);
    }

    inline Rectangle GetAlphaBorder(float threshold) const {
        return ::GetImageAlphaBorder(*this, threshold);
    }

    inline Image& ClearBackground(::Color color = WHITE) {
        ::ImageClearBackground(this, color);
        return *this;
    }

    inline Image& DrawPixel(int posX, int posY, ::Color color) {
        ::ImageDrawPixel(this, posX, posY, color);
        return *this;
    }

    inline Image& DrawPixel(::Vector2 position, ::Color color) {
        ::ImageDrawPixelV(this, position, color);
        return *this;
    }

    inline Image& DrawLine(int startPosX, int startPosY, int endPosX, int endPosY, ::Color color) {
        ::ImageDrawLine(this, startPosX, startPosY, endPosX, endPosY, color);
        return *this;
    }

    inline Image& DrawLine(::Vector2 start, ::Vector2 end, ::Color color) {
        ::ImageDrawLineV(this, start, end, color);
        return *this;
    }

    inline Image& DrawCircle(int centerX, int centerY, int radius, ::Color color) {
        ::ImageDrawCircle(this, centerX, centerY, radius, color);
        return *this;
    }

    inline Image& DrawCircle(::Vector2 center, int radius, ::Color color) {
        ::ImageDrawCircleV(this, center, radius, color);
        return *this;
    }

    inline Image& DrawRectangle(int posX, int posY, int width, int height, ::Color color = WHITE) {
        ::ImageDrawRectangle(this, posX, posY, width, height, color);
        return *this;
    }

    inline Image& DrawRectangle(Vector2 position, Vector2 size, ::Color color = WHITE) {
        ::ImageDrawRectangleV(this, position, size, color);
        return *this;
    }

    inline Image& DrawRectangle(::Rectangle rec, ::Color color = WHITE) {
        ::ImageDrawRectangleRec(this, rec, color);
        return *this;
    }

    inline Image& DrawRectangleLines(::Rectangle rec, int thick, ::Color color) {
        ::ImageDrawRectangleLines(this, rec, thick, color);
        return *this;
    }

    inline Image& Draw(const ::Image& src, ::Rectangle srcRec, ::Rectangle dstRec,
            ::Color tint = WHITE) {
        ::ImageDraw(this, src, srcRec, dstRec, tint);
        return *this;
    }

    inline Image& DrawText(const std::string& text, ::Vector2 position, int fontSize,
            ::Color color = WHITE) {
        ::ImageDrawText(this,
            text.c_str(),
            static_cast<int>(position.x),
            static_cast<int>(position.y),
            fontSize,
            color);
        return *this;
    }
    inline Image& DrawText(const std::string& text, int x, int y, int fontSize,
            ::Color color = WHITE) {
        ::ImageDrawText(this, text.c_str(), x, y, fontSize, color);
        return *this;
    }

    inline Image& DrawText(::Font font, const std::string& text, ::Vector2 position,
            float fontSize, float spacing, ::Color tint = WHITE) {
        ::ImageDrawTextEx(this, font, text.c_str(), position, fontSize, spacing, tint);
        return *this;
    }

    inline ::Color* GetImageData() {
        return ::GetImageData(*this);
    }

    inline ::Vector4* GetImageDataNormalized() {
        return ::GetImageDataNormalized(*this);
    }

    ::Texture2D LoadTexture() {
        return ::LoadTextureFromImage(*this);
    }

    inline operator ::Texture2D() {
        return LoadTexture();
    }

 protected:
    inline void set(::Image image) {
        data = image.data;
        width = image.width;
        height = image.height;
        mipmaps = image.mipmaps;
        format = image.format;
    }
};
}  // namespace raylib

#endif  // RAYLIB_CPP_INCLUDE_IMAGE_HPP_
