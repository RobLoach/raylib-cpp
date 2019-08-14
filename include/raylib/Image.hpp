#ifndef RAYLIB_CPP_IMAGE_HPP_
#define RAYLIB_CPP_IMAGE_HPP_

#include <string>
#include "raylib.h"
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

		bool Load(const std::string& fileName) {
			set(LoadImage(fileName.c_str()));
		}

		bool LoadEx(::Color *pixels, int width, int height) {
			set(LoadImageEx(pixels, width, height));
		}

		bool LoadPro(void *data, int width, int height, int format) {
			set(LoadImagePro(data, width, height, format));
		}

		bool LoadRaw(const std::string& fileName, int width, int height, int format, int headerSize) {
			set(LoadImageRaw(fileName.c_str(), width, height, format, headerSize));
		}

		void Unload() {
			UnloadImage(*this);
		};

		GETTERSETTER(void*,Data,data)
		GETTERSETTER(int,Width,width)
		GETTERSETTER(int,Height,height)
		GETTERSETTER(int,Mipmaps,mipmaps)
		GETTERSETTER(int,Format,format)

		Image Copy() {
			return ImageCopy(*this);
		}
		Image FromImage(::Rectangle rec) {
			return ImageFromImage(*this, rec);
		}
		void Crop(::Rectangle crop){
			ImageCrop(this, crop);
		}
		void Resize(int newWidth, int newHeight){
			ImageResize(this, newWidth, newHeight);
		}
		void Draw(::Image& src, ::Rectangle srcRec, ::Rectangle dstRec, ::Color tint = WHITE){
			ImageDraw(this, src, srcRec, dstRec, tint);
		}
		void DrawRectangle(::Rectangle rec, ::Color color = WHITE){
			ImageDrawRectangle(this, rec, color);
		}
		void DrawRectangleLines(::Rectangle rec, int thick, ::Color color = WHITE){
			ImageDrawRectangleLines(this, rec, thick, color);
		}
		void DrawText(::Vector2 position, const std::string& text, int fontSize, ::Color color = WHITE){
			ImageDrawText(this, position, text.c_str(), fontSize, color);
		}
		void DrawText(::Vector2 position, ::Font font, const std::string& text, float fontSize, float spacing, ::Color color = WHITE){
			ImageDrawTextEx(this, position, font, text.c_str(), fontSize, spacing, color);
		}
		void FlipVertical() {
			ImageFlipVertical(this);
		}
		void FlipHorizontal() {
			ImageFlipHorizontal(this);
		}

		void RotateCW() {
			ImageRotateCW(this);
		}
		void RotateCCW() {
			ImageRotateCCW(this);
		}
		void ColorTint(::Color color) {
			ImageColorTint(this, color);
		}
		void ColorInvert() {
			ImageColorInvert(this);
		}
		void ColorGrayscale() {
			ImageColorGrayscale(this);
		}
		void ColorContrast(float contrast) {
			ImageColorContrast(this, contrast);
		}
		void ColorBrightness(int brightness) {
			ImageColorBrightness(this, brightness);
		}
		void ColorReplace(::Color color, ::Color replace) {
			ImageColorReplace(this, color, replace);
		}

		::Color* GetData() {
			return ::GetImageData(*this);
		}
	};
}

#endif
