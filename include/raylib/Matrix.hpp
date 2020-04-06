#ifndef RAYLIB_CPP_MATRIX_HPP_
#define RAYLIB_CPP_MATRIX_HPP_

#ifdef __cplusplus
extern "C"{
#endif
#include "raylib.h"
#ifndef RAYLIB_CPP_NO_MATH
#include "raymath.h"
#endif
#ifdef __cplusplus
}
#endif

#include "utils.hpp"
#ifndef RAYLIB_CPP_NO_MATH
#include <cmath>
#endif

namespace raylib {
	class Matrix : public ::Matrix {
	public:
		Matrix(::Matrix mat) {
			set(mat);
		};

		Matrix(float M0 = 0, float M1 = 0, float M2 = 0, float M3 = 0, float M4 = 0, float M5 = 0, float M6 = 0, float M7 = 0, float M8 = 0, float M9 = 0, float M10 = 0, float M11 = 0, float M12 = 0, float M13 = 0, float M14 = 0, float M15 = 0) {
			m0 = M0;
			m1 = M1;
			m2 = M2;
			m3 = M3;
			m4 = M4;
			m5 = M5;
			m6 = M6;
			m7 = M7;
			m8 = M8;
			m9 = M9;
			m10 = M10;
			m11 = M11;
			m12 = M12;
			m13 = M13;
			m14 = M14;
			m15 = M15;
		};

		inline void set(::Matrix mat) {
			m0 = mat.m0;
			m1 = mat.m1;
			m2 = mat.m2;
			m3 = mat.m3;
			m4 = mat.m4;
			m5 = mat.m5;
			m6 = mat.m6;
			m7 = mat.m7;
			m8 = mat.m8;
			m9 = mat.m9;
			m10 = mat.m10;
			m11 = mat.m11;
			m12 = mat.m12;
			m13 = mat.m13;
			m14 = mat.m14;
			m15 = mat.m15;
		}

		GETTERSETTER(float,M0,m0)
		GETTERSETTER(float,M1,m1)
		GETTERSETTER(float,M2,m2)
		GETTERSETTER(float,M3,m3)
		GETTERSETTER(float,M4,m4)
		GETTERSETTER(float,M5,m5)
		GETTERSETTER(float,M6,m6)
		GETTERSETTER(float,M7,m7)
		GETTERSETTER(float,M8,m8)
		GETTERSETTER(float,M9,m9)
		GETTERSETTER(float,M10,m10)
		GETTERSETTER(float,M11,m11)
		GETTERSETTER(float,M12,m12)
		GETTERSETTER(float,M13,m13)
		GETTERSETTER(float,M14,m14)
		GETTERSETTER(float,M15,m15)

		Matrix& operator=(const ::Matrix& matrix) {
			set(matrix);
			return *this;
		}

		Matrix& operator=(const Matrix& matrix) {
			set(matrix);
			return *this;
		}

		inline Matrix& SetProjection() {
			::SetMatrixProjection(*this);
			return *this;
		}

		inline Matrix& SetModelview() {
			::SetMatrixModelview(*this);
			return *this;
		}

		static Matrix GetModelview() {
			return ::GetMatrixModelview();
		}

		static Matrix GetProjection() {
			return ::GetMatrixProjection();
		}

#ifndef RAYLIB_CPP_NO_MATH
		float Trace() {
			return ::MatrixTrace(*this);
		}
		Matrix Transpose() {
			return ::MatrixTranspose(*this);
		}
		Matrix Invert() {
			return ::MatrixInvert(*this);
		}
		Matrix Normalize() {
			return ::MatrixNormalize(*this);
		}
		static Matrix Identity() {
			return ::MatrixIdentity();
		}
		Matrix Add(::Matrix right) {
			return ::MatrixAdd(*this, right);
		}
		Matrix operator+(const Matrix& matrix) {
				return ::MatrixAdd(*this, matrix);
		}
		Matrix Subtract(::Matrix right) {
			return ::MatrixSubtract(*this, right);
		}
		Matrix operator-(const Matrix& matrix) {
			return ::MatrixSubtract(*this, matrix);
		}
		static Matrix Translate(float x, float y, float z) {
			return MatrixTranslate(x, y, z);
		}
		static Matrix Rotate(Vector3 axis, float angle) {
			return MatrixRotate(axis, angle);
		}
		static Matrix RotateXYZ(Vector3 angle) {
			return MatrixRotateXYZ(angle);
		}
		static Matrix RotateX(float angle) {
			return MatrixRotateX(angle);
		}
		static Matrix RotateY(float angle) {
			return MatrixRotateY(angle);
		}
		static Matrix RotateZ(float angle) {
			return MatrixRotateZ(angle);
		}
		static Matrix Scale(float x, float y, float z) {
			return MatrixScale(x, y, z);
		}
		Matrix Multiply(Matrix right) {
			return MatrixMultiply(*this, right);
		}
		Matrix operator*(const Matrix& matrix) {
			return MatrixMultiply(*this, matrix);
		}

		/**
		 * TODO: Add more raymath.h functions. Starting with MatrixFrustum().
		 */
#endif
	};
}


#endif
