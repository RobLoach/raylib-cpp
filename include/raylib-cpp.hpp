/**
 * \mainpage raylib-cpp
 *
 * [raylib-cpp](https://github.com/robloach/raylib-cpp) is a C++ wrapper library for raylib, a simple and easy-to-use library to enjoy videogames programming. This C++ header provides object-oriented wrappers around raylib's struct interfaces.
 *
 * See the ::raylib namespace for all available classes.
 *
 * @code
 * #include "raylib-cpp.hpp"
 *
 * int main()
 * {
 * 	int screenWidth = 800;
 * 	int screenHeight = 450;
 *
 * 	raylib::Window w(screenWidth, screenHeight, "raylib-cpp - basic window");
 * 	raylib::Texture logo("raylib_logo.png");
 *
 * 	SetTargetFPS(60);
 *
 * 	while (!w.ShouldClose())
 * 	{
 * 		BeginDrawing();
 *
 * 		raylib::Color::RayWhite.ClearBackground();
 *
 * 		DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);
 *
 * 		// Object methods.
 * 		logo.Draw(
 * 			screenWidth / 2 - texture.getWidth() / 2,
 * 			screenHeight / 2 - texture.getHeight() / 2);
 *
 * 		EndDrawing();
 * 	}
 *
 * 	// UnloadTexture() and CloseWindow() are called automatically.
 *
 * 	return 0;
 * }
 * @endcode
 */

#ifndef RAYLIB_CPP_HPP_
#define RAYLIB_CPP_HPP_

/**
 * Provides all the classes associated with raylib-cpp.
 */
namespace raylib {
	// Nothing yet.
}

#include "./AudioDevice.hpp"
#include "./AudioStream.hpp"
#include "./BoundingBox.hpp"
#include "./Camera2D.hpp"
#include "./Camera3D.hpp"
#include "./Color.hpp"
#include "./DroppedFiles.hpp"
#include "./Font.hpp"
#include "./Gamepad.hpp"
#include "./Image.hpp"
#include "./Material.hpp"
#include "./Matrix.hpp"
#include "./Mesh.hpp"
#include "./Model.hpp"
#include "./ModelAnimation.hpp"
#include "./Mouse.hpp"
#include "./Music.hpp"
#include "./Ray.hpp"
#include "./RayHitInfo.hpp"
#include "./Rectangle.hpp"
#include "./RenderTexture.hpp"
#include "./Shader.hpp"
#include "./Sound.hpp"
#include "./Texture.hpp"
#include "./Vector2.hpp"
#include "./Vector3.hpp"
#include "./Vector4.hpp"
#include "./VrSimulator.hpp"
#include "./Wave.hpp"
#include "./Window.hpp"

#endif
