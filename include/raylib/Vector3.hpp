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
		void DrawPoint3D(::Color color) {
			::DrawPoint3D(*this, color);
		}
		void DrawCircle3D(float radius, Vector3 rotationAxis, float rotationAngle, Color color) {
			::DrawCircle3D(*this, radius, rotationAxis, rotationAngle, color);
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

		void DrawSphere(float radius, Color color) {
			::DrawSphere(*this, radius, color);
		}

		void DrawSphere(float radius, int rings, int slices, Color color) {
			::DrawSphereEx(*this, radius, rings, slices, color);
		}

		void DrawSphereWires(float radius, int rings, int slices, Color color) {
			::DrawSphereWires(*this, radius, rings, slices, color);
		}

		void DrawCylinder(float radius, int rings, int slices, Color color) {
			::DrawCylinder(*this, radius, rings, slices, color);
		}

		void DrawCylinder(float radiusTop, float radiusBottom, float height, int slices, Color color) {
			::DrawCylinder(*this, radiusTop, radiusBottom, height, slices, color);
		}

		void DrawCylinderWires(float radiusTop, float radiusBottom, float height, int slices, Color color) {
			::DrawCylinderWires(*this, position, radiusTop, radiusBottom, height, slices, color);
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
