#ifndef RAYLIB_CPP_VECTOR3_HPP_
#define RAYLIB_CPP_VECTOR3_HPP_

#include "raylib.h"
#include "utils.hpp"

namespace raylib {
	class Vector3 : public ::Vector3 {
	public:
		Vector3(::Vector3 vec) {
			set(vec);
		};
		Vector3(float X = 0, float Y = 0, float Z = 0) {
			x = X;
			y = Y;
			z = Z;
		};

		Vector3(::Color color) {
			set(ColorToHSV(color));
		}
		inline void set(::Vector3 vec) {
			x = vec.x;
			y = vec.y;
			z = vec.z;
		}

		GETTERSETTER(float,X,x)
		GETTERSETTER(float,Y,y)
		GETTERSETTER(float,Z,z)

        Vector3& operator=(const ::Vector3& vector3) {
            set(vector3);
            return *this;
        }

        Vector3& operator=(const Vector3& vector3) {
            set(vector3);
            return *this;
        }

		void DrawLine3D(::Vector3 endPos, ::Color color) {
			::DrawLine3D(*this, endPos, color);
		}

		void DrawCube(float width, float height, float length, ::Color color) {
			::DrawCube(*this, width, height, length, color);
		}
		void DrawCube(::Vector3 size, ::Color color) {
			::DrawCubeV(*this, size, color);
		}

		void DrawCubeWires(float width, float height, float length, ::Color color) {
			::DrawCubeWires(*this, width, height, length, color);
		}
		void DrawCubeWires(::Vector3 size, ::Color color) {
			::DrawCubeWiresV(*this, size, color);
		}

		void DrawCubeTexture(::Texture2D texture, float width, float height, float length, ::Color color) {
			::DrawCubeTexture(texture, *this, width, height, length, color);
		}

		void DrawPlane(::Vector2 size, ::Color color) {
			::DrawPlane(*this, size, color);
		}

		void DrawGizmo() {
			::DrawGizmo(*this);
		}

		bool CheckCollision(float radiusA, Vector3 centerB, float radiusB) {
			return CheckCollisionSpheres(*this, radiusA, centerB, radiusB);
		}
	};
}

#endif
