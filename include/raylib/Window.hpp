#ifndef RAYLIB_CPP_WINDOW_HPP_
#define RAYLIB_CPP_WINDOW_HPP_

#include <string>
#include "raylib.h"

namespace raylib {
	class Window {
	public:
		Window(int width, int height, const std::string& title = "raylib", bool lateInit = false) {
			if (!lateInit) {
				Init(width, height, title);
			}
		};

		~Window() {
			Close();
		};

		void Init(int width, int height, const std::string& title) {
			InitWindow(width, height, title.c_str());
		}

		bool ShouldClose() {
			return WindowShouldClose();
		};

		void Close() {
			CloseWindow();
		};

		static bool IsReady() {
			return IsWindowReady();
		};

	};
}

#endif
