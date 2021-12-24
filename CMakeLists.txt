cmake_minimum_required(VERSION 3.11)
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
project (raylib-cpp
    VERSION 4.0.1
    DESCRIPTION "raylib-cpp C++ Object Oriented Wrapper for raylib"
    HOMEPAGE_URL "https://github.com/robloach/raylib-cpp"
    LANGUAGES C CXX)

# Options
if(CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR)
    set(BUILD_RAYLIB_CPP_EXAMPLES_DEFAULT TRUE)
else()
    set(BUILD_RAYLIB_CPP_EXAMPLES_DEFAULT FALSE)
endif()
option(BUILD_RAYLIB_CPP_EXAMPLES "Examples" ${BUILD_RAYLIB_CPP_EXAMPLES_DEFAULT})

# Include Directory
add_subdirectory(include)

# Examples
if(BUILD_RAYLIB_CPP_EXAMPLES)
    add_subdirectory(examples)
    set(BUILD_RAYLIB_CPP_STATIC ON)

    # Testing
    include(CTest)
    enable_testing()
    if(BUILD_TESTING)
        set(CTEST_CUSTOM_TESTS_IGNORE
            pkg-config--static
        )
        add_subdirectory(tests)
    endif()
endif()
