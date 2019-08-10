#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include <string>
#include <raylib.h>
#include "raylib/raylib.hpp"
#include "catch.hpp"

TEST_CASE("raylib_test", "[raylib_test]" ) {
	SECTION("Vector2") {
		raylib::Vector2 vec(50, 100);
		CHECK(vec.getX() == vec.x);
	}

	SECTION("Window") {
		CHECK(raylib::Window::IsReady() == false);
	}

	SECTION("Color") {
		raylib::Color c(RED);
		CHECK(c.ToInt() == ColorToInt(RED));
	}
}
