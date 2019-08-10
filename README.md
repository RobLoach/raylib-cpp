# raylib-cpp

C++ wrapper library around [raylib](https://www.raylib.com/), a simple and easy-to-use library to enjoy videogames programming.

Provides object-oriented wrappers around some of the struct interfaces.

## Example

``` cpp
#include "raylib/raylib.hpp"

int main(int argc, char* argv[])
{
	int screenWidth = 800;
	int screenHeight = 450;

	raylib::Window w(screenWidth, screenHeight, "raylib-cpp - basic window");
	raylib::Texture logo("raylib_logo.png");

	SetTargetFPS(60);

	while (!w.ShouldClose())
	{
		BeginDrawing();

		ClearBackground(RAYWHITE);

		DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);

		logo.Draw(screenWidth / 2 - texture.getWidth() / 2, screenHeight / 2 - texture.getHeight() / 2);

		EndDrawing();
	}

	// UnloadTexture() and CloseWindow() are called automatically.

	return 0;
}
```

## Development

``` bash
mkdir build
cd build
cmake ..
make
make test
./examples/core_basic_window
```
