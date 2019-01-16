#ifndef RAYLIB_IMAGE_HPP_
#define RAYLIB_IMAGE_HPP_

#include <string>
#include "raylib.h"

namespace raylib {
	class Image {
	public:
		Image() {};
		Image(const std::string& fileName) {
			Load(fileName);
		};

		~Image() {
			Unload();
		};

		bool Load(const std::string& fileName) {
			image = LoadImage(fileName.c_str());
		}

		void Unload() {
			UnloadImage(image);
		};
		::Image image;
	};
}

#endif
