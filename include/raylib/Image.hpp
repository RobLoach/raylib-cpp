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
		Image(const char *fileName, int width, int height, int format, int headerSize) {
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

		bool LoadRaw(const char *fileName, int width, int height, int format, int headerSize) {
			set(LoadImageRaw(fileName, width, height, format, headerSize));
		}

		void Unload() {
			UnloadImage(*this);
		};
		
		GETTERSETTER(void*,Data,data)
		GETTERSETTER(int,Width,width)
		GETTERSETTER(int,Height,height)
		GETTERSETTER(int,Mipmaps,mipmaps)
		GETTERSETTER(int,Format,format)
	};
}

#endif
