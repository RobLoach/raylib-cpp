cmake_minimum_required(VERSION 3.11)
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
project (raylib_cpp
    VERSION 5.5.0
    DESCRIPTION "raylib-cpp C++ Object Oriented Wrapper for raylib"
    HOMEPAGE_URL "https://github.com/robloach/raylib-cpp"
    LANGUAGES C CXX
)

# Options
if ("${CMAKE_SOURCE_DIR}" STREQUAL "${CMAKE_CURRENT_SOURCE_DIR}")
    set(RAYLIB_CPP_IS_MAIN TRUE)
else()
    set(RAYLIB_CPP_IS_MAIN FALSE)
endif()
option(BUILD_RAYLIB_CPP_EXAMPLES "Examples" ${RAYLIB_CPP_IS_MAIN})

# Include Directory
add_subdirectory(include)

# Modules
option(BUILD_RAYLIB_CPP_MODULES "Build C++ modules support" OFF)

if(BUILD_RAYLIB_CPP_MODULES)
    if(CMAKE_VERSION VERSION_GREATER_EQUAL 3.28)
        message(STATUS "Building raylib-cpp C++ modules (CMake ${CMAKE_VERSION} supports modules)")
        add_subdirectory(modules)
    else()
        message(WARNING "Skipping raylib-cpp C++ modules (requires CMake 3.28+, found ${CMAKE_VERSION})")
    endif()
else()
    message(STATUS "raylib-cpp C++ modules support is disabled. Enable with -BUILD_RAYLIB_CPP_MODULES=ON")
endif()

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

    if (RAYLIB_CPP_IS_MAIN)
        # @TODO: add examples files
        add_custom_target(format-tests
                COMMAND clang-format
                -i
                ${CMAKE_CURRENT_SOURCE_DIR}/tests/raylib_cpp_test.cpp
        )
    endif()
endif()
