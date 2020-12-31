#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include <string>
#include <vector>
#include "raylib-cpp.hpp"
#include "catch.hpp"

TEST_CASE("raylib_test", "[raylib_test]" ) {
    SECTION("Vector2") {
        raylib::Vector2 position(50, 100);
        REQUIRE(position.GetX() == position.x);
        position.x = 150;
        REQUIRE(position.GetX() == 150);

        // Addition operator.
        raylib::Vector2 speed(10, 10);
        position += speed;
        REQUIRE(position.x == 160);
    }

    SECTION("Window") {
        REQUIRE(raylib::Window::IsReady() == false);
    }

    SECTION("Color") {
        raylib::Color c(RED);
        REQUIRE(c.ToInt() == ::ColorToInt(RED));

        c = RAYWHITE;
        REQUIRE(c.r == RAYWHITE.r);
    }

    SECTION("RayMath") {
        raylib::Vector2 direction(50, 50);
        raylib::Vector2 newDirection = direction.Rotate(30);
        REQUIRE((int)newDirection.x == 18);
    }

    SECTION("Functions") {
        std::vector<std::string> files = raylib::GetDirectoryFiles(::GetWorkingDirectory());
        REQUIRE(files.size() > 2);
    }
}
