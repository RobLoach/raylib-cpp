# raylib-cpp

C++ wrapper library around [raylib](https://www.raylib.com/), a simple and easy-to-use library to enjoy videogames programming.

Provides object oriented wrappers around some of the struct interfaces, which saves you from having to worry about unloading the objects yourself.

## Example

``` cpp
#include "raylib/raylib.hpp"

int main(int argc, char* argv[])
{
	int screenWidth = 800;
	int screenHeight = 450;
	raylib::Window w(screenWidth, screenHeight, "raylib [core] example - basic window");

	SetTargetFPS(60);

	while (!w.ShouldClose())
	{
		BeginDrawing();

		ClearBackground(RAYWHITE);

		DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);

		EndDrawing();
	}

	// No need to call CloseWindow().

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
