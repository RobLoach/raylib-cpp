cmake_minimum_required(VERSION 3.11)
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
project (raylib-cpp
	VERSION 0.3.0
	DESCRIPTION "raylib-cpp C++ Object Oriented Wrapper for raylib"
	HOMEPAGE_URL "https://github.com/robloach/raylib-cpp"
	LANGUAGES C CXX)

# CMake configuration
configure_file(${CMAKE_SOURCE_DIR}/cmake/CTestCustom.cmake ${CMAKE_BINARY_DIR})

# raylib
find_package(raylib 3.0.0 QUIET)
if (NOT raylib_FOUND)
	set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE) # don't build the supplied examples
	set(BUILD_GAMES    OFF CACHE BOOL "" FORCE) # or games
	add_subdirectory(vendor/raylib)
endif()

# Options
option(BUILD_RAYLIB_CPP_STATIC "Static Library" ON)
option(BUILD_RAYLIB_CPP_EXAMPLES "Examples" ON)

# Include Directory
add_subdirectory(include)

# Static Library
if(BUILD_RAYLIB_CPP_STATIC)
	add_subdirectory(lib)
endif()

# Examples
if(BUILD_RAYLIB_CPP_EXAMPLES)
	add_subdirectory(examples)
endif()

# Testing
include(CTest)
enable_testing()
if(BUILD_TESTING)
	add_subdirectory(tests)
endif()
