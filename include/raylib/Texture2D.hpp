#ifndef RAYLIB_CPP_TEXTURE2D_HPP_
#define RAYLIB_CPP_TEXTURE2D_HPP_

#include <string>
#include "raylib.h"
#include "utils.hpp"

namespace raylib {
	class Texture2D : public ::Texture2D {
	public:
		Texture2D() {};

		Texture2D(Image image) {
			LoadFromImage(image);
		}

		Texture2D(const std::string& fileName) {
			Load(fileName);
		}

		~Texture2D() {
			Unload();
		};

		inline void set(::Texture2D texture) {
			id = texture.id;
			width = texture.width;
			height = texture.height;
			mipmaps = texture.mipmaps;
			format = texture.format;
		}

		bool LoadFromImage(Image image) {
			set(LoadTextureFromImage(image));
		}
		bool Load(const std::string fileName) {
			set(LoadTexture(fileName.c_str()));
		}

		void Draw(int posX, int posY, Color tint) {
			DrawTexture(*this, posX, posY, tint);
		}

		void Draw(::Vector2D position, Color tint) {
			DrawTexture(*this, position, tint);
		}

		void Unload() {
			UnloadTexture(*this);
		};

		GETTERSETTER(unsigned int,Id,id)
		GETTERSETTER(int,Width,width)
		GETTERSETTER(int,Height,height)
		GETTERSETTER(int,Mipmaps,mipmaps)
		GETTERSETTER(int,Format,format)
	};
	typedef Texture2D Texture;
}

#endif
