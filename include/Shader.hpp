#ifndef RAYLIB_CPP_SHADER_HPP_
#define RAYLIB_CPP_SHADER_HPP_

#ifdef __cplusplus
extern "C"{
#endif
#include "raylib.h"
#ifdef __cplusplus
}
#endif

#include "./raylib-cpp-utils.hpp"
#include "Texture.hpp"

namespace raylib {
	class Shader : public ::Shader {
	public:
		Shader(::Shader shader) {
			set(shader);
		};

		Shader(unsigned int Id, int* Locs) {
			id = Id;
			locs = Locs;
		};

		Shader() {
			set(GetShaderDefault());
		}

		GETTERSETTER(unsigned int,Id,id)
		GETTERSETTER(int*,Locs,locs)

        Shader& operator=(const ::Shader& shader) {
            set(shader);
            return *this;
        }

        Shader& operator=(const Shader& shader) {
            set(shader);
            return *this;
        }

		~Shader() {
			Unload();
		}

		void Unload() {
			::UnloadShader(*this);
		}

		static Shader Load(const std::string& vsFileName, const std::string& fsFileName) {
			return ::LoadShader(vsFileName.c_str(), fsFileName.c_str());
		}
		static Shader LoadCode(const std::string& vsCode, const std::string& fsCode) {
			char* param1 = (char*)vsCode.c_str();
			char* param2 = (char*)fsCode.c_str();
			return ::LoadShaderCode(param1, param2);
		}

		inline Shader& BeginShaderMode() {
			::BeginShaderMode(*this);
			return *this;
		}

		inline Shader& EndShaderMode() {
			::EndShaderMode();
			return *this;
		}

		inline int GetLocation(const std::string& uniformName) const {
			return ::GetShaderLocation(*this, uniformName.c_str());
		}

		inline int GetLocationAttrib(const std::string& attribName) const {
			return ::GetShaderLocationAttrib(*this, attribName.c_str());
		}

		inline Shader& SetValue(int uniformLoc, const std::string& value, int uniformType) {
			::SetShaderValue(*this, uniformLoc, value.c_str(), uniformType);
			return *this;
		}

		/**
		 * @see SetShaderValueV
		 */
		inline Shader& SetValue(int uniformLoc, const std::string& value, int uniformType, int count) {
			::SetShaderValueV(*this, uniformLoc, value.c_str(), uniformType, count);
			return *this;
		}

		/**
		 * @see ::SetShaderValueMatrix
		 */
		inline Shader& SetValue(int uniformLoc, Matrix mat) {
			::SetShaderValueMatrix(*this, uniformLoc, mat);
			return *this;
		}

		/**
		 * @see ::SetShaderValueTexture
		 */
		inline Shader& SetValue(int uniformLoc, Texture2D texture) {
			::SetShaderValueTexture(*this, uniformLoc, texture);
			return *this;
		}

		::TextureCubemap GenTextureCubemap(Texture2D panorama, int size, int format) {
			return ::GenTextureCubemap(*this, panorama, size, format);
		}

		::TextureCubemap GenTextureIrradiance(Texture2D panorama, int size) {
			return ::GenTextureIrradiance(*this, panorama, size);
		}

		::TextureCubemap GenTexturePrefilter(Texture2D panorama, int size) {
			return ::GenTexturePrefilter(*this, panorama, size);
		}

		::Texture2D GenTextureBRDF(int size) {
			return ::GenTextureBRDF(*this, size);
		}

	protected:
		inline void set(::Shader shader) {
			id = shader.id;
			locs = shader.locs;
		}
	};
}

#endif
