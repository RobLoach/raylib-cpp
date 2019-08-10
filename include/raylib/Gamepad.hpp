#ifndef RAYLIB_CPP_GAMEPAD_HPP_
#define RAYLIB_CPP_GAMEPAD_HPP_

#include <string>

#include "raylib.h"
#include "utils.hpp"

namespace raylib {
	class Gamepad {
	public:
		Gamepad(int gamepadNumber = 0) {
			set(gamepadNumber);
		};
		int number;

		inline void set(int gamepadNumber) {
			number = gamepadNumber;
		}

		GETTERSETTER(int,Number,number)

        Gamepad& operator=(const Gamepad& gamepad) {
            set(gamepad);
            return *this;
        }

		operator int() const { return number; }

		bool IsAvailable() {
			return IsGamepadAvailable(number);
		}
		bool IsName(const std::string& name) {
			return IsGamepadName(number, name.c_str());
		}
		std::string GetName() {
			return std::string(GetGamepadName(number));
		}
		bool IsButtonPressed(int button) {
			return IsGamepadButtonPressed(number, button);
		}

		bool IsButtonDown(int button) {
			return IsGamepadButtonDown(number, button);
		}

		bool IsButtonReleased(int button) {
			return IsGamepadButtonReleased(number, button);
		}
		bool IsButtonUp(int button) {
			return IsGamepadButtonUp(number, button);
		}

		int GetButtonPressed() {
			return GetGamepadButtonPressed();
		}

		int GetAxisCount() {
			return GetGamepadAxisCount(number);
		}

		float GetAxisMovement(int axis) {
			return GetGamepadAxisMovement(number, axis);
		}
	};
}

#endif
