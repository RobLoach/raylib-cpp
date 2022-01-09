cmake_minimum_required(VERSION 3.11) # FetchContent is available in 3.11+
project(raylib_cpp_example)

# raylib
find_package(raylib QUIET)
if (NOT raylib_FOUND)
    include(FetchContent)
        FetchContent_Declare(
        raylib
        GIT_REPOSITORY https://github.com/raysan5/raylib.git
        GIT_TAG 4.0.0
    )
    FetchContent_GetProperties(raylib)
    if (NOT raylib_POPULATED) # Have we downloaded raylib yet?
        set(FETCHCONTENT_QUIET NO)
        FetchContent_Populate(raylib)
        set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
        set(BUILD_GAMES    OFF CACHE BOOL "" FORCE)
        set(BUILD_TESTING  OFF CACHE BOOL "" FORCE)
        add_subdirectory(${raylib_SOURCE_DIR} ${raylib_BINARY_DIR})
    endif()
endif()

# raylib-cpp
find_package(raylib_cpp QUIET)
if (NOT raylib_cpp_FOUND)
    include(FetchContent)
    FetchContent_Declare(
        raylib_cpp
        URL https://github.com/RobLoach/raylib-cpp/archive/master.tar.gz
    )
    FetchContent_GetProperties(raylib_cpp)
    if (NOT raylib_cpp_POPULATED) # Have we downloaded raylib-cpp yet?
        set(FETCHCONTENT_QUIET NO)
        FetchContent_Populate(raylib_cpp)
        set(BUILD_RAYLIB_CPP_EXAMPLES OFF CACHE BOOL "" FORCE)
        set(BUILD_TESTING             OFF CACHE BOOL "" FORCE)
        add_subdirectory(${raylib_cpp_SOURCE_DIR} ${raylib_cpp_BINARY_DIR})
    endif()
endif()

# This is the main part:
set(PROJECT_NAME raylib_cpp_example)
set(PROJECT_SOURCES main.cpp)
add_executable(${PROJECT_NAME} ${PROJECT_SOURCES})
set(raylib_VERBOSE 1)
target_link_libraries(${PROJECT_NAME} PUBLIC raylib raylib_cpp)

# That's it! You should have an example executable that you can run. Have fun!
