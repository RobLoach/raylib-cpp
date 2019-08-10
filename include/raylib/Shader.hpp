#ifndef RAYLIB_CPP_VECTOR4_HPP_
#define RAYLIB_CPP_VECTOR4_HPP_

#include "raylib.h"
#include "utils.hpp"

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

		inline void set(::Shader shader) {
			id = shader.id;
			locs = shader.locs;
		}

		GETTERSETTER(unsigned int,Id,i)

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
			UnloadShader(*this);
		}

		static Shader Load(const std::string& vsFileName, const std::string& fsFileName) {
			return LoadShader(vsFileName.c_str(), fsFileName.c_str());
		}
		static Shader LoadCode(const std::string& vsCode, const std::string& fsCode) {
			return LoadShaderCode(vsCode.c_str(), fsCode.c_str());
		}

		void BeginShaderMode() {
			BeginShaderMode(*this);
		}

		void EndShaderMode() {
			EndShaderMode();
		}

		int GetLocation(const std::string& uniformName) {
			return ::GetShaderLocation(*this, uniformName.c_str());
		}
	};
}

#endif
