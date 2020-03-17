#ifndef RAYLIB_CPP_TEXTURE2D_HPP_
#define RAYLIB_CPP_TEXTURE2D_HPP_

#include <string>

#ifdef __cplusplus
extern "C"{
#endif
#include "raylib.h"
#ifdef __cplusplus
}
#endif

#include "utils.hpp"
#include "Vector2.hpp"

namespace raylib {
	class Texture2D : public ::Texture2D {
	public:
		Texture2D() {
			set(GetTextureDefault());
		};

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

		void LoadFromImage(::Image& image) {
			set(LoadTextureFromImage(image));
		}

		void Load(const std::string& fileName) {
			set(LoadTexture(fileName.c_str()));
		}

		inline Texture2D& Draw(int posX, int posY, ::Color tint = WHITE) {
			::DrawTexture(*this, posX, posY, tint);
			return *this;
		}

		inline Texture2D& Draw(::Vector2 position, ::Color tint = WHITE) {
			::DrawTextureV(*this, position, tint);
			return *this;
		}
		inline Texture2D& Draw(::Vector2 position, float rotation, float scale = 1.0f, ::Color tint = WHITE) {
			::DrawTextureEx(*this, position, rotation, scale, tint);
			return *this;
		}

		inline Texture2D& Draw(::Rectangle sourceRec, ::Vector2 position, ::Color tint = WHITE) {
			::DrawTextureRec(*this, sourceRec, position, tint);
			return *this;
		}
		inline Texture2D& Draw(::Vector2 tiling, ::Vector2 offset, ::Rectangle quad, ::Color tint = WHITE) {
			::DrawTextureQuad(*this, tiling, offset, quad, tint);
			return *this;
		}
		inline Texture2D& Draw(::Rectangle sourceRec, ::Rectangle destRec, ::Vector2 origin, float rotation = 0, ::Color tint = WHITE) {
			::DrawTexturePro(*this, sourceRec, destRec, origin, rotation, tint);
			return *this;
		}
		inline Texture2D& Draw(::NPatchInfo nPatchInfo, ::Rectangle destRec, ::Vector2 origin, float rotation = 0, ::Color tint = WHITE) {
			::DrawTextureNPatch(*this, nPatchInfo, destRec, origin, rotation, tint);
			return *this;
		}

		inline Texture2D& Draw(::Vector3 position, float width, float height, float length, ::Color color = WHITE) {
			::DrawCubeTexture(*this, position, width, height, length, color);
			return *this;
		}

		inline void Unload() {
			::UnloadTexture(*this);
		}

		inline Texture2D& SetMaterialTexture(Material *material, int mapType) {
			::SetMaterialTexture(material, mapType, *this);
			return *this;
		}
	};

	// Alias the Texture2D as Texture.
	typedef Texture2D Texture;
}

#endif
