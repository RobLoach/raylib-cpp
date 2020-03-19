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
		Image(::Color* pixels, int width, int height) {
			LoadEx(pixels, width, height);
		};
		Image(void* data, int width, int height, int format) {
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

		void LoadEx(::Color* pixels, int width, int height) {
			set(::LoadImageEx(pixels, width, height));
		}

		void LoadPro(void* data, int width, int height, int format) {
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
		inline Image& Crop(::Rectangle crop){
			::ImageCrop(this, crop);
			return *this;
		}
		inline Image& Resize(int newWidth, int newHeight){
			::ImageResize(this, newWidth, newHeight);
			return *this;
		}
		inline Image& Draw(::Image& src, ::Rectangle srcRec, ::Rectangle dstRec, ::Color tint = WHITE){
			::ImageDraw(this, src, srcRec, dstRec, tint);
			return *this;
		}
		inline Image& DrawRectangle(::Rectangle rec, ::Color color = WHITE){
			::ImageDrawRectangle(this, rec, color);
			return *this;
		}
		inline Image& DrawRectangleLines(::Rectangle rec, int thick, ::Color color = WHITE){
			::ImageDrawRectangleLines(this, rec, thick, color);
			return *this;
		}
		inline Image& DrawText(::Vector2 position, const std::string& text, int fontSize, ::Color color = WHITE){
			::ImageDrawText(this, position, text.c_str(), fontSize, color);
			return *this;
		}
		inline Image& DrawText(::Vector2 position, ::Font font, const std::string& text, float fontSize, float spacing, ::Color color = WHITE){
			::ImageDrawTextEx(this, position, font, text.c_str(), fontSize, spacing, color);
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
		inline Image& ColorTint(::Color color) {
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

		inline ::Color* GetImageData() {
			return ::GetImageData(*this);
		}
	};
}

#endif
