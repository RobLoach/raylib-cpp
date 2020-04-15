#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include <string>
#include <raylib.h>
#define RAYLIB_CPP_IMPLEMENTATION
#include "raylib/raylib.hpp"
#include "catch.hpp"

TEST_CASE("raylib_test", "[raylib_test]" ) {
	SECTION("Vector2") {
		raylib::Vector2 vec(50, 100);
		REQUIRE(vec.GetX() == vec.x);
		vec.x = 150;
		REQUIRE(vec.GetX() == 150);
	}

	SECTION("Window") {
		REQUIRE(raylib::Window::IsReady() == false);
	}

	SECTION("Color") {
		raylib::Color c(RED);
		REQUIRE(c.ToInt() == ::ColorToInt(RED));

		c = RAYWHITE;
		REQUIRE(c.r == RAYWHITE.r);

		REQUIRE(raylib::Color::LightGray.r == LIGHTGRAY.r);
	}

	SECTION("Vector2") {
		raylib::Vector2 position(50, 50);
		raylib::Vector2 speed(10, 10);
		position += speed;
		REQUIRE(position.x == 60);
	}
}
