cmake_minimum_required(VERSION 3.11)
project (raylib-cpp)

option(BUILD_EXAMPLES "Examples" TRUE)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
configure_file(${CMAKE_SOURCE_DIR}/cmake/CTestCustom.cmake ${CMAKE_BINARY_DIR})

add_subdirectory(include)

if(BUILD_EXAMPLES)
	add_subdirectory(examples)
endif()

include(CTest)
enable_testing()
if(BUILD_TESTING)
	add_subdirectory(tests)
endif()
