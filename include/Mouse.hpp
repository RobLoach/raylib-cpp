#ifndef RAYLIB_CPP_MOUSE_HPP_
#define RAYLIB_CPP_MOUSE_HPP_

#ifdef __cplusplus
extern "C"{
#endif
#include "raylib.h"
#ifdef __cplusplus
}
#endif

#include "./Vector2.hpp"

namespace raylib {
	class Mouse {
	public:
		inline bool IsButtonPressed(int button) {
			return ::IsMouseButtonPressed(button);
		}
		inline bool IsButtonDown(int button) {
			return ::IsMouseButtonDown(button);
		}
		inline bool IsButtonReleased(int button) {
			return ::IsMouseButtonReleased(button);
		}
		inline bool IsButtonUp(int button) {
			return ::IsMouseButtonUp(button);
		}
		inline int GetX() {
			return ::GetMouseX();
		}
		inline int GetY() {
			return ::GetMouseY();
		}
		inline Mouse& SetX(int x) {
			::SetMouseOffset(x, GetY());
			return *this;
		}
		inline Mouse& SetY(int y) {
			::SetMouseOffset(GetX(), y);
			return *this;
		}
		inline Vector2 GetPosition() {
			return ::GetMousePosition();
		}
		inline Mouse& SetPosition(int x, int y) {
			::SetMousePosition(x, y);
			return *this;
		}
		inline Mouse& SetOffset(int offsetX, int offsetY) {
			::SetMouseOffset(offsetX, offsetY);
			return *this;
		}
		inline Mouse& SetScale(float scaleX, float scaleY) {
			::SetMouseScale(scaleX, scaleY);
			return *this;
		}
		inline int GetWheelMove() {
			return ::GetMouseWheelMove();
		}
		inline int GetTouchX() {
			return ::GetTouchX();
		}
		inline int GetTouchY() {
			return ::GetTouchY();
		}
		inline Vector2 GetTouchPosition(int index) {
			return ::GetTouchPosition(index);
		}
	};
}

#endif
