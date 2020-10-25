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

		inline void set(int gamepadNumber) {
			number = gamepadNumber;
		}

		GETTERSETTER(int,Number,number)

        Gamepad& operator=(const Gamepad& gamepad) {
            set(gamepad);
            return *this;
        }

		operator int() const { return number; }

		inline bool IsAvailable() const {
			return ::IsGamepadAvailable(number);
		}
		inline bool IsName(const std::string& name) const {
			return ::IsGamepadName(number, name.c_str());
		}
		std::string GetName() const {
			return std::string(::GetGamepadName(number));
		}
		inline bool IsButtonPressed(int button) const {
			return ::IsGamepadButtonPressed(number, button);
		}

		inline bool IsButtonDown(int button) const {
			return ::IsGamepadButtonDown(number, button);
		}

		inline bool IsButtonReleased(int button) const {
			return ::IsGamepadButtonReleased(number, button);
		}
		inline bool IsButtonUp(int button) const {
			return ::IsGamepadButtonUp(number, button);
		}

		inline int GetButtonPressed() const {
			return ::GetGamepadButtonPressed();
		}

		inline int GetAxisCount() const {
			return ::GetGamepadAxisCount(number);
		}

		inline float GetAxisMovement(int axis) const {
			return ::GetGamepadAxisMovement(number, axis);
		}
	};
}

#endif
