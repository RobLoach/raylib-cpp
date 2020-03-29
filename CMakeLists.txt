cmake_minimum_required(VERSION 3.11)
project (raylib-cpp)

option(BUILD_STATIC "Static Library" ON)
option(BUILD_EXAMPLES "Examples" ON)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

add_subdirectory(include)

if(BUILD_STATIC)
	add_subdirectory(lib)
endif()

if(BUILD_EXAMPLES)
	add_subdirectory(examples)
endif()

include(CTest)
enable_testing()
if(BUILD_TESTING)
	add_subdirectory(tests)
endif()
