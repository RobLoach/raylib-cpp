#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include <string>
#include <raylib.h>
#include "raylib/raylib.hpp"
#include "catch.hpp"

TEST_CASE("raylib_test functions work", "[raylib_test]" ) {
	raylib::Vector2 vec(50, 100);
	CHECK(vec.getX() == 50.0f);

	CHECK(raylib::Window::IsReady() == false);
}