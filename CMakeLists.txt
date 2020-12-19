cmake_minimum_required(VERSION 3.11)
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
project (raylib-cpp
    VERSION 3.5.0
    DESCRIPTION "raylib-cpp C++ Object Oriented Wrapper for raylib"
    HOMEPAGE_URL "https://github.com/robloach/raylib-cpp"
    LANGUAGES C CXX)

# Options
option(BUILD_RAYLIB_CPP_EXAMPLES "Examples" ON)

# C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Include Directory
add_subdirectory(include)

# Examples
if(BUILD_RAYLIB_CPP_EXAMPLES)
    add_subdirectory(examples)
    set(BUILD_RAYLIB_CPP_STATIC ON)
endif()

# Testing
include(CTest)
enable_testing()
if(BUILD_TESTING)
    set(CTEST_CUSTOM_TESTS_IGNORE
        pkg-config--static
    )

    add_subdirectory(tests)
endif()
