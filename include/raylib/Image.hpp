#ifndef RAYLIB_CPP_IMAGE_HPP_
#define RAYLIB_CPP_IMAGE_HPP_

#include <string>
#include "raylib.h"
#include "utils.hpp"

namespace raylib {
	class Image : public ::Image {
	public:
		Image() {};
		Image(const std::string& fileName) {
			Load(fileName);
		};

		~Image() {
			Unload();
		};

		void set(::Image image) {
			data = image.data;
			width = image.width;
			height = image.height;
			mipmaps = image.mipmaps;
			format = image.format;
		}

		bool Load(const std::string& fileName) {
			set(LoadImage(fileName.c_str()));
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
