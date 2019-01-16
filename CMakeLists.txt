cmake_minimum_required(VERSION 3.11)
project (raylib-cpp)

#set(CMAKE_C_FLAGS "-fPIC ${CMAKE_C_FLAGS}")
set (CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
include_directories(include)
add_subdirectory(examples)
