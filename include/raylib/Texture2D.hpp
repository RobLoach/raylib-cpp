#ifndef RAYLIB_TEXTURE2D_HPP_
#define RAYLIB_TEXTURE2D_HPP_

#include <string>
#include "raylib.h"

namespace raylib {
	class Texture2D {
	public:
		Texture2D() {};

		Texture2D(Image image) {
			Load(image);
		}

		Texture2D(const std::string& fileName) {
			Load(fileName);
		}

		~Texture2D() {
			Unload();
		};

		bool Load(Image image) {
			texture = LoadTextureFromImage(image.image);
		}
		bool Load(const std::string fileName) {
			texture = LoadTexture(fileName.c_str());
		}

		void Draw(int posX, int posY, Color tint) {
			DrawTexture(texture, posX, posY, tint);
		}

		void Unload() {
			UnloadTexture(texture);
		};

		int width() {
			return texture.width;
		}
		int height() {
			return texture.height;
		}
	private:
		::Texture2D texture;
	};
}

#endif
