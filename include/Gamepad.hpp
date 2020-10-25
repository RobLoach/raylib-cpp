#ifndef RAYLIB_CPP_GAMEPAD_HPP_
#define RAYLIB_CPP_GAMEPAD_HPP_

#include <string>

#ifdef __cplusplus
extern "C"{
#endif
#include "raylib.h"
#ifdef __cplusplus
}
#endif

#include "./raylib-cpp-utils.hpp"

namespace raylib {
	class Gamepad {
	public:
		Gamepad(int gamepadNumber = 0) {
			set(gamepadNumber);
		}
		int number;

		GETTERSETTER(int,Number,number)

        Gamepad& operator=(const Gamepad& gamepad) {
            set(gamepad);
            return *this;
        }

        Gamepad& operator=(int gamepadNumber) {
            set(gamepadNumber);
            return *this;
        }

		operator int() const { return number; }

		inline bool IsAvailable() {
			return ::IsGamepadAvailable(number);
		}
		inline bool IsName(const std::string& name) {
			return ::IsGamepadName(number, name.c_str());
		}
		std::string GetName() {
			return std::string(::GetGamepadName(number));
		}
		inline bool IsButtonPressed(int button) {
			return ::IsGamepadButtonPressed(number, button);
		}

		inline bool IsButtonDown(int button) {
			return ::IsGamepadButtonDown(number, button);
		}

		inline bool IsButtonReleased(int button) {
			return ::IsGamepadButtonReleased(number, button);
		}
		inline bool IsButtonUp(int button) {
			return ::IsGamepadButtonUp(number, button);
		}

		inline int GetButtonPressed() {
			return ::GetGamepadButtonPressed();
		}

		inline int GetAxisCount() {
			return ::GetGamepadAxisCount(number);
		}

		inline float GetAxisMovement(int axis) {
			return ::GetGamepadAxisMovement(number, axis);
		}

	protected:
		inline void set(int gamepadNumber) {
			number = gamepadNumber;
		}
	};
}

#endif
