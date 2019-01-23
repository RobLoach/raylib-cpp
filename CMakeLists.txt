cmake_minimum_required(VERSION 3.11)
project (raylib-cpp)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
configure_file(${CMAKE_SOURCE_DIR}/cmake/CTestCustom.cmake ${CMAKE_BINARY_DIR})
include_directories(include)

add_subdirectory(examples)

include(CTest)
enable_testing()
if(BUILD_TESTING)
	add_subdirectory(tests)
endif()