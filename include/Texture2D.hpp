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

#include "./raylib-cpp-utils.hpp"
#include "./Vector2.hpp"
#include "./Material.hpp"

namespace raylib {
	class Texture2D : public ::Texture2D {
	public:
		Texture2D() {
			set(::GetTextureDefault());
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
			set(::LoadTextureFromImage(image));
		}

		void LoadTextureCubemap(::Image& image, int layoutType) {
			set(::LoadTextureCubemap(image, layoutType));
		}

		void Load(const std::string& fileName) {
			set(::LoadTexture(fileName.c_str()));
		}

		inline void Unload() {
			::UnloadTexture(*this);
		}

		inline Texture2D& Update(const void *pixels) {
			::UpdateTexture(*this, pixels);
			return *this;
		}

		inline Texture2D& UpdateRec(Rectangle rec, const void *pixels) {
			UpdateTextureRec(*this, rec, pixels);
			return *this;
		}

		inline Image GetTextureData() {
			return ::GetTextureData(*this);
		}
		inline operator raylib::Image() {
			return GetTextureData();
		}

		inline Texture2D& GenMipmaps() {
			::GenTextureMipmaps(this);
			return *this;
		}

		inline Texture2D& SetFilter(int filterMode) {
			::SetTextureFilter(*this, filterMode);
			return *this;
		}

		inline Texture2D& SetWrap(int wrapMode) {
			::SetTextureWrap(*this, wrapMode);
			return *this;
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

		inline Texture2D& DrawTiled(Rectangle sourceRec, Rectangle destRec, Vector2 origin, float rotation, float scale, Color tint = WHITE) {
			::DrawTextureTiled(*this, sourceRec, destRec, origin, rotation, scale, tint);
			return *this;
		}

		inline Texture2D& SetMaterialTexture(Material *material, int mapType) {
			::SetMaterialTexture(material, mapType, *this);
			return *this;
		}

		static int GetPixelDataSize(int width, int height, int format) {
			return ::GetPixelDataSize(width, height, format);
		}

	protected:
		inline void set(::Texture2D texture) {
			id = texture.id;
			width = texture.width;
			height = texture.height;
			mipmaps = texture.mipmaps;
			format = texture.format;
		}
	};

	// Create the Texture2D aliases.
	typedef Texture2D Texture;
	typedef Texture2D TextureCubemap;
}

#endif
