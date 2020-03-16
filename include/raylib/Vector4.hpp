#ifndef RAYLIB_CPP_VECTOR4_HPP_
#define RAYLIB_CPP_VECTOR4_HPP_

#ifdef __cplusplus
extern "C"{
#endif
#include "raylib.h"
#ifdef __cplusplus
}
#endif

#include "utils.hpp"

namespace raylib {
	class Vector4 : public ::Vector4 {
	public:
		Vector4(::Vector4 vec) {
			set(vec);
		};

		Vector4(float X = 0, float Y = 0, float Z = 0, float W = 0) {
			x = X;
			y = Y;
			z = Z;
			w = W;
		};

		Vector4(::Color color) {
			set(ColorNormalize(color));
		}

		inline void set(::Vector4 vec4) {
			x = vec4.x;
			y = vec4.y;
			z = vec4.z;
			w = vec4.w;
		}

		GETTERSETTER(float,X,x)
		GETTERSETTER(float,Y,y)
		GETTERSETTER(float,Z,z)
		GETTERSETTER(float,W,w)

        Vector4& operator=(const ::Vector4& vector4) {
            set(vector4);
            return *this;
        }

        Vector4& operator=(const Vector4& vector4) {
            set(vector4);
            return *this;
        }

        inline Color ColorFromNormalized() {
        	return ::ColorFromNormalized(*this);
        }
	};

	// Alias the Vector4 as Quaternion.
	typedef Vector4 Quaternion;
}

#endif
