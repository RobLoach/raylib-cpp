#ifndef RAYLIB_CPP_MATERIAL_HPP_
#define RAYLIB_CPP_MATERIAL_HPP_

#include "raylib.h"
#include "utils.hpp"

namespace raylib {
	class Material : public ::Material {
	public:
		Material(::Material material) {
			set(material);
		};

		Material() {
			set(LoadMaterialDefault());
		};

		~Material() {
			Unload();
		}

		inline void set(::Material material) {
			shader = material.shader;
			maps = material.maps;
			params = material.params;
		}

		GETTERSETTER(::Shader,Shader,shader)

        Material& operator=(const ::Material& material) {
            set(material);
            return *this;
        }

        Material& operator=(const Material& material) {
            set(material);
            return *this;
        }


		void Unload() {
			UnloadMaterial(*this);
		}

		void SetTexture(int mapType, ::Texture2D texture) {
			SetMaterialTexture(this, mapType, texture);
		}

	};
}

#endif
