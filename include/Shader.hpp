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

		inline int GetLocation(const std::string& uniformName) {
			return ::GetShaderLocation(*this, uniformName.c_str());
		}
	};
}

#endif
