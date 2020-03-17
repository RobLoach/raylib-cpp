#ifndef RAYLIB_CPP_IMAGE_HPP_
#define RAYLIB_CPP_IMAGE_HPP_

#include <string>
#ifdef __cplusplus
extern "C"{
#endif
#include "raylib.h"
#ifdef __cplusplus
}
#endif

#include "utils.hpp"

namespace raylib {
	class Image : public ::Image {
	public:
		Image() {};
		Image(::Image image) {
			set(image);
		};
		Image(const std::string& fileName) {
			Load(fileName);
		};
		Image(::Color *pixels, int width, int height) {
			LoadEx(pixels, width, height);
		};
		Image(void *data, int width, int height, int format) {
			LoadPro(data, width, height, format);
		};
		Image(const std::string& fileName, int width, int height, int format, int headerSize) {
			LoadRaw(fileName, width, height, format, headerSize);
		};
		Image(::Texture2D texture) {
			set(GetTextureData(texture));
		}

		static Image GetScreenData() {
			return Image(::GetScreenData());
		}

		~Image() {
			Unload();
		};

        Image& operator=(const ::Image& image) {
            set(image);
            return *this;
        }

        Image& operator=(const Image& image) {
            set(image);
            return *this;
        }

		inline void set(::Image image) {
			data = image.data;
			width = image.width;
			height = image.height;
			mipmaps = image.mipmaps;
			format = image.format;
		}

		void Load(const std::string& fileName) {
			set(::LoadImage(fileName.c_str()));
		}

		void LoadEx(::Color *pixels, int width, int height) {
			set(::LoadImageEx(pixels, width, height));
		}

		void LoadPro(void *data, int width, int height, int format) {
			set(::LoadImagePro(data, width, height, format));
		}

		void LoadRaw(const std::string& fileName, int width, int height, int format, int headerSize) {
			set(::LoadImageRaw(fileName.c_str(), width, height, format, headerSize));
		}

		inline void Unload() {
			::UnloadImage(*this);
		};

		GETTERSETTER(void*,Data,data)
		GETTERSETTER(int,Width,width)
		GETTERSETTER(int,Height,height)
		GETTERSETTER(int,Mipmaps,mipmaps)
		GETTERSETTER(int,Format,format)

		inline Image Copy() {
			return ::ImageCopy(*this);
		}
		inline Image FromImage(::Rectangle rec) {
			return ::ImageFromImage(*this, rec);
		}
		inline void Crop(::Rectangle crop){
			::ImageCrop(this, crop);
		}
		inline void Resize(int newWidth, int newHeight){
			::ImageResize(this, newWidth, newHeight);
		}
		inline void Draw(::Image& src, ::Rectangle srcRec, ::Rectangle dstRec, ::Color tint = WHITE){
			::ImageDraw(this, src, srcRec, dstRec, tint);
		}
		inline void DrawRectangle(::Rectangle rec, ::Color color = WHITE){
			::ImageDrawRectangle(this, rec, color);
		}
		inline void DrawRectangleLines(::Rectangle rec, int thick, ::Color color = WHITE){
			::ImageDrawRectangleLines(this, rec, thick, color);
		}
		inline void DrawText(::Vector2 position, const std::string& text, int fontSize, ::Color color = WHITE){
			::ImageDrawText(this, position, text.c_str(), fontSize, color);
		}
		inline void DrawText(::Vector2 position, ::Font font, const std::string& text, float fontSize, float spacing, ::Color color = WHITE){
			::ImageDrawTextEx(this, position, font, text.c_str(), fontSize, spacing, color);
		}
		inline void FlipVertical() {
			::ImageFlipVertical(this);
		}
		inline void FlipHorizontal() {
			::ImageFlipHorizontal(this);
		}

		inline void RotateCW() {
			::ImageRotateCW(this);
		}
		inline void RotateCCW() {
			::ImageRotateCCW(this);
		}
		inline void ColorTint(::Color color) {
			::ImageColorTint(this, color);
		}
		inline void ColorInvert() {
			::ImageColorInvert(this);
		}
		inline void ColorGrayscale() {
			::ImageColorGrayscale(this);
		}
		inline void ColorContrast(float contrast) {
			::ImageColorContrast(this, contrast);
		}
		inline void ColorBrightness(int brightness) {
			::ImageColorBrightness(this, brightness);
		}
		inline void ColorReplace(::Color color, ::Color replace) {
			::ImageColorReplace(this, color, replace);
		}

		inline ::Color* GetData() {
			return ::GetImageData(*this);
		}
	};
}

#endif
