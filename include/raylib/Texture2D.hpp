#ifndef RAYLIB_CPP_TEXTURE2D_HPP_
#define RAYLIB_CPP_TEXTURE2D_HPP_

#include <string>
#include "raylib.h"
#include "utils.hpp"
#include "Vector2.hpp"

namespace raylib {
	class Texture2D : public ::Texture2D {
	public:
		Texture2D() {};

		Texture2D(::Image& image) {
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

		GETTERSETTER(unsigned int,Id,id)
		GETTERSETTER(int,Width,width)
		GETTERSETTER(int,Height,height)
		GETTERSETTER(int,Mipmaps,mipmaps)
		GETTERSETTER(int,Format,format)

        Texture2D& operator=(const ::Texture2D& texture) {
            set(texture);
            return *this;
        }

        Texture2D& operator=(const Texture2D& texture) {
            set(texture);
            return *this;
        }

		bool LoadFromImage(::Image& image) {
			set(LoadTextureFromImage(image));
		}
		bool Load(const std::string& fileName) {
			set(LoadTexture(fileName.c_str()));
		}

		void Draw(int posX, int posY, ::Color tint) {
			DrawTexture(*this, posX, posY, tint);
		}

		void Draw(::Vector2 position, ::Color tint) {
			DrawTextureV(*this, position, tint);
		}
		void Draw(::Vector2 position, float rotation, float scale, ::Color tint) {
			DrawTextureEx(*this, position, rotation, scale, tint);
		}

		void Draw(::Rectangle sourceRec, ::Vector2 position, ::Color tint) {
			DrawTextureRec(*this, sourceRec, position, tint);
		}
		void Draw(::Vector2 tiling, ::Vector2 offset, ::Rectangle quad, ::Color tint) {
			DrawTextureQuad(*this, tiling, offset, quad, tint);
		}
		void Draw(::Rectangle sourceRec, ::Rectangle destRec, ::Vector2 origin, float rotation, ::Color tint) {
			DrawTexturePro(*this, sourceRec, destRec, origin, rotation, tint);
		}
		void Draw(::NPatchInfo nPatchInfo, ::Rectangle destRec, ::Vector2 origin, float rotation, ::Color tint) {
			DrawTextureNPatch(*this, nPatchInfo, destRec, origin, rotation, tint);
		}

		void Unload() {
			UnloadTexture(*this);
		};
	};
	typedef Texture2D Texture;
}

#endif
