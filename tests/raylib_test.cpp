#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include <string>
#include <raylib.h>
#include "raylib/raylib.hpp"
#include "catch.hpp"

TEST_CASE("raylib_test", "[raylib_test]" ) {
	SECTION("Vector2") {
		raylib::Vector2 vec(50, 100);
		REQUIRE(vec.getX() == vec.x);
		vec.x = 150;
		REQUIRE(vec.getX() == 150);
	}

	SECTION("Window") {
		REQUIRE(raylib::Window::IsReady() == false);
	}

	SECTION("Color") {
		raylib::Color c(RED);
		REQUIRE(c.ToInt() == ColorToInt(RED));

		c = RAYWHITE;
		REQUIRE(c.r == RAYWHITE.r);

		REQUIRE(raylib::Color::LightGray.r == LIGHTGRAY.r);
	}
}
