#ifndef RAYLIB_CPP_RenderTexture_HPP_
#define RAYLIB_CPP_RenderTexture_HPP_

#ifdef __cplusplus
extern "C"{
#endif
#include "raylib.h"
#ifdef __cplusplus
}
#endif

#include "./raylib-cpp-utils.hpp"

namespace raylib {
	class RenderTexture : public ::RenderTexture {
	public:
		RenderTexture(::RenderTexture renderTexture) {
			set(renderTexture);
		};
		RenderTexture(unsigned int Id) {
			id = Id;
		};
		RenderTexture(int width, int height) {
			set(LoadRenderTexture(width, height));
		}

		GETTERSETTER(unsigned int,Id,id)
		GETTERSETTER(Texture2D,Texture,texture)
		GETTERSETTER(Texture2D,Depth,depth)

        RenderTexture& operator=(const ::RenderTexture& texture) {
            set(texture);
            return *this;
        }

        RenderTexture& operator=(const RenderTexture& texture) {
            set(texture);
            return *this;
        }

		~RenderTexture() {
			Unload();
		};

		inline void Unload() {
			UnloadRenderTexture(*this);
		}

		inline RenderTexture& BeginTextureMode() {
			::BeginTextureMode(*this);
			return *this;
		}

		inline RenderTexture& EndTextureMode() {
			::EndTextureMode();
			return *this;
		}

	protected:
		inline void set(::RenderTexture renderTexture) {
			id = renderTexture.id;
			texture = renderTexture.texture;
			depth = renderTexture.depth;
		}
	};
	typedef RenderTexture RenderTexture2D;
}

#endif
