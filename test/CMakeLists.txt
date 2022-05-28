cmake_minimum_required(VERSION 3.14)

project(raylib_cppTests LANGUAGES CXX)

include(../cmake/project-is-top-level.cmake)
include(../cmake/folders.cmake)
include(../cmake/windows-set-path.cmake)

# ---- Dependencies ----

if(PROJECT_IS_TOP_LEVEL)
  find_package(raylib_cpp REQUIRED)
  enable_testing()
endif()

# ---- Tests ----

add_executable(raylib_cpp_test raylib_cpp_test.cpp)
target_link_libraries(raylib_cpp_test PRIVATE raylib_cpp::raylib_cpp raylib)
#target_compile_features(raylib_cpp_test PRIVATE cxx_std_14)

add_test(NAME raylib_cpp_test COMMAND raylib_cpp_test)

# ---- End-of-file commands ----

# Copy all the resources
file(COPY resources/ DESTINATION "resources/")

add_folders(Test)
