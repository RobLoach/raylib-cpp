#ifndef RAYLIB_CPP_WINDOW_HPP_
#define RAYLIB_CPP_WINDOW_HPP_

#include <string>
#include "raylib.h"

namespace raylib {
	class Window {
	public:
		Window(int width = 800, int height = 450, const std::string& title = "raylib", bool lateInit = false) {
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

		void BeginDrawing() {
			::BeginDrawing();
		}
		void EndDrawing() {
			::EndDrawing();
		}

		bool IsMinimized() {
			return ::IsWindowMinimized();
		}
		bool IsResized() {
			return ::IsWindowResized();
		}
		bool IsHidden() {
			return ::IsWindowHidden();
		}
		void ToggleFullscreen() {
			return ::ToggleFullscreen();
		}
		void Unhide() {
			return ::UnhideWindow();
		}
		void Hide() {
			return ::HideWindow();
		}
		void SetIcon(Image image) {
			SetWindowIcon(image);
		}
		void SetTitle(const std::string& title) {
			::SetWindowTitle(title.c_str());
		}
		void SetPosition(int x, int y) {
			::SetWindowPosition(x, y);
		}
		void SetMonitor(int monitor) {
			::SetWindowMonitor(monitor);
		}
		void SetMinSize(int width, int height) {
			::SetWindowMinSize(width, height);
		}
		void SetSize(int width, int height) {
			::SetWindowSize(width, height);
		}
	};
}

#endif
