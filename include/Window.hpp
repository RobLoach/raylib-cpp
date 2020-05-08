#ifndef RAYLIB_CPP_WINDOW_HPP_
#define RAYLIB_CPP_WINDOW_HPP_

#include <string>

namespace raylib{
#ifdef __cplusplus
extern "C"{
#endif
#include "raylib.h"
#ifdef __cplusplus
}
#endif
}
namespace raylibcpp {
	/**
	 * Window and Graphics Device Functions.
	 */
	class Window {
	public:
		/**
		 * Initialize window and OpenGL context.
		 */
		Window(int width = 800, int height = 450, const std::string& title = "raylib", bool lateInit = false) {
			if (!lateInit) {
				Init(width, height, title);
			}
		};

		~Window() {
			Close();
		};

		void Init(int width, int height, const std::string& title) {
			raylib::InitWindow(width, height, title.c_str());
		}

		/**
		 * Check if KEY_ESCAPE pressed or Close icon pressed
		 */
		inline bool ShouldClose() {
			return raylib::WindowShouldClose();
		};

		/**
		 * Close window and unload OpenGL context
		 */
		inline void Close() {
			raylib::CloseWindow();
		};

		/**
		 * Check if window has been initialized successfully
		 */
		inline static bool IsReady() {
			return raylib::IsWindowReady();
		};
		inline bool IsMinimized() {
			return raylib::IsWindowMinimized();
		}
		inline bool IsResized() {
			return raylib::IsWindowResized();
		}
		inline bool IsHidden() {
			return raylib::IsWindowHidden();
		}

		inline bool IsFullscreen() {
			return raylib::IsWindowFullscreen();
		}
		inline Window& ToggleFullscreen() {
			raylib::ToggleFullscreen();
			return *this;
		}
		inline Window& Unhide() {
			raylib::UnhideWindow();
			return *this;
		}
		inline Window& Hide() {
			raylib::HideWindow();
			return *this;
		}
		inline Window& SetIcon(Image image) {
			raylib::SetWindowIcon(image);
			return *this;
		}
		inline Window& SetTitle(const std::string& title) {
			raylib::SetWindowTitle(title.c_str());
			return *this;
		}
		inline Window& SetPosition(int x, int y) {
			raylib::SetWindowPosition(x, y);
			return *this;
		}
		inline Window& SetMonitor(int monitor) {
			raylib::SetWindowMonitor(monitor);
			return *this;
		}
		inline Window& SetMinSize(int width, int height) {
			raylib::SetWindowMinSize(width, height);
			return *this;
		}
		inline Window& SetSize(int width, int height) {
			raylib::SetWindowSize(width, height);
			return *this;
		}
		inline void* GetHandle() {
			return raylib::GetWindowHandle();
		}

		inline Window& BeginDrawing() {
			raylib::BeginDrawing();
			return *this;
		}
		inline Window& EndDrawing() {
			raylib::EndDrawing();
			return *this;
		}

		inline int GetScreenWidth() {
			return raylib::GetScreenWidth();
		}

		inline int GetScreenHeight() {
			return raylib::GetScreenHeight();
		}

		inline Vector2 GetWindowPosition() {
			return raylib::GetWindowPosition();
		}

		std::string GetMonitorName(int monitor) {
			return std::string(::GetMonitorName(monitor));
		}

		std::string GetClipboardText() {
			return std::string(::GetClipboardText());
		}

		inline Window& SetClipboardText(const std::string& text) {
			raylib::SetClipboardText(text.c_str());
			return *this;
		}

		inline Window& SetTargetFPS(int fps) {
			raylib::SetTargetFPS(fps);
			return *this;
		}
		inline int GetFPS() {
			return raylib::GetFPS();
		}
		inline float GetFrameTime() {
			return raylib::GetFrameTime();
		}
		inline double GetTime() {
			return raylib::GetTime();
		}
	};
}

#endif
