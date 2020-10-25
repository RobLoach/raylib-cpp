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
		inline bool IsButtonPressed(int button) const {
			return ::IsMouseButtonPressed(button);
		}
		inline bool IsButtonDown(int button) const {
			return ::IsMouseButtonDown(button);
		}
		inline bool IsButtonReleased(int button) const {
			return ::IsMouseButtonReleased(button);
		}
		inline bool IsButtonUp(int button) const {
			return ::IsMouseButtonUp(button);
		}
		inline int GetX() const {
			return ::GetMouseX();
		}
		inline int GetY() const {
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
		inline Vector2 GetPosition() const {
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
		inline float GetWheelMove() const {
			return ::GetMouseWheelMove();
		}

		inline int GetCursor() const {
			return ::GetMouseCursor();
		}
		inline Mouse& SetCursor(int cursor) {
			::SetMouseCursor(cursor);
			return *this;
		}

		inline int GetTouchX() const {
			return ::GetTouchX();
		}
		inline int GetTouchY() const {
			return ::GetTouchY();
		}
		inline Vector2 GetTouchPosition(int index) const {
			return ::GetTouchPosition(index);
		}
	};
}

#endif
