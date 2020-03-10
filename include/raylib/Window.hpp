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

		inline bool ShouldClose() {
			return ::WindowShouldClose();
		};

		inline void Close() {
			::CloseWindow();
		};

		static bool IsReady() {
			return ::IsWindowReady();
		};

		inline void BeginDrawing() {
			::BeginDrawing();
		}
		inline void EndDrawing() {
			::EndDrawing();
		}

		inline bool IsMinimized() {
			return ::IsWindowMinimized();
		}
		inline bool IsResized() {
			return ::IsWindowResized();
		}
		inline bool IsHidden() {
			return ::IsWindowHidden();
		}
		inline void ToggleFullscreen() {
			return ::ToggleFullscreen();
		}
		inline void Unhide() {
			return ::UnhideWindow();
		}
		inline void Hide() {
			return ::HideWindow();
		}
		inline void SetIcon(Image image) {
			SetWindowIcon(image);
		}
		inline void SetTitle(const std::string& title) {
			::SetWindowTitle(title.c_str());
		}
		inline void SetPosition(int x, int y) {
			::SetWindowPosition(x, y);
		}
		inline void SetMonitor(int monitor) {
			::SetWindowMonitor(monitor);
		}
		inline void SetMinSize(int width, int height) {
			::SetWindowMinSize(width, height);
		}
		inline void SetSize(int width, int height) {
			::SetWindowSize(width, height);
		}
		inline void* GetHandle() {
			return ::GetWindowHandle();
		}
	};
}

#endif
