#ifndef RAYLIB_CPP_IMAGE_HPP_
#define RAYLIB_CPP_IMAGE_HPP_

#include <string>
#include "raylib.h"
#include "utils.hpp"
#include <iostream>

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

		~Image() {
			Unload();
		};

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
			std::cout << "UnloadImage()" << std::endl;
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
		void Draw(::Image& src, ::Rectangle srcRec, ::Rectangle dstRec, ::Color tint){
			ImageDraw(this, src, srcRec, dstRec, tint);
		}
		void DrawRectangle(::Rectangle rec, ::Color color){
			ImageDrawRectangle(this, rec, color);
		}
		void DrawRectangleLines(::Rectangle rec, int thick, ::Color color){
			ImageDrawRectangleLines(this, rec, thick, color);
		}
		void DrawText(::Vector2 position, const std::string& text, int fontSize, ::Color color){
			ImageDrawText(this, position, text.c_str(), fontSize, color);
		}
		void DrawTextEx(::Vector2 position, ::Font font, const std::string& text, float fontSize, float spacing, ::Color color){
			ImageDrawTextEx(this, position, font, text.c_str(), fontSize, spacing, color);
		}
		void FlipVertical(){
			ImageFlipVertical(this);
		}
		void FlipHorizontal(){
			ImageFlipHorizontal(this);
		}

	};
}

#endif
