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
