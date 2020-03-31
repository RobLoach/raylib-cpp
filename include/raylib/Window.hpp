#ifndef RAYLIB_CPP_WINDOW_HPP_
#define RAYLIB_CPP_WINDOW_HPP_

#include <string>

#ifdef __cplusplus
extern "C"{
#endif
#include "raylib.h"
#ifdef __cplusplus
}
#endif

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
			::InitWindow(width, height, title.c_str());
		}

		inline bool ShouldClose() {
			return ::WindowShouldClose();
		};

		inline void Close() {
			::CloseWindow();
		};

		inline static bool IsReady() {
			return ::IsWindowReady();
		};
		inline bool IsMinimized() {
			return ::IsWindowMinimized();
		}
		inline bool IsResized() {
			return ::IsWindowResized();
		}
		inline bool IsHidden() {
			return ::IsWindowHidden();
		}

		inline bool IsFullscreen() {
			return ::IsWindowFullscreen();
		}
		inline Window& ToggleFullscreen() {
			::ToggleFullscreen();
			return *this;
		}
		inline Window& Unhide() {
			::UnhideWindow();
			return *this;
		}
		inline Window& Hide() {
			::HideWindow();
			return *this;
		}
		inline Window& SetIcon(Image image) {
			::SetWindowIcon(image);
			return *this;
		}
		inline Window& SetTitle(const std::string& title) {
			::SetWindowTitle(title.c_str());
			return *this;
		}
		inline Window& SetPosition(int x, int y) {
			::SetWindowPosition(x, y);
			return *this;
		}
		inline Window& SetMonitor(int monitor) {
			::SetWindowMonitor(monitor);
			return *this;
		}
		inline Window& SetMinSize(int width, int height) {
			::SetWindowMinSize(width, height);
			return *this;
		}
		inline Window& SetSize(int width, int height) {
			::SetWindowSize(width, height);
			return *this;
		}
		inline void* GetHandle() {
			return ::GetWindowHandle();
		}

		inline Window& BeginDrawing() {
			::BeginDrawing();
			return *this;
		}
		inline Window& EndDrawing() {
			::EndDrawing();
			return *this;
		}

		inline int GetScreenWidth() {
			return ::GetScreenWidth();
		}

		inline int GetScreenHeight() {
			return ::GetScreenHeight();
		}

		inline Vector2 GetWindowPosition() {
			return ::GetWindowPosition();
		}

		std::string GetMonitorName(int monitor) {
			return std::string(GetMonitorName(monitor));
		}

		std::string GetClipboardText() {
			return std::string(GetClipboardText());
		}

		inline Window& SetClipboardText(const std::string& text) {
			::SetClipboardText(text.c_str());
			return *this;
		}
	};
}

#endif
