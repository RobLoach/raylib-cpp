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
        GIT_REPOSITORY https://github.com/RobLoach/raylib-cpp.git
        GIT_TAG v4.0.4
    )
    FetchContent_GetProperties(raylib_cpp)
    if (NOT raylib_cpp_POPULATED) # Have we downloaded raylib-cpp yet?
        set(FETCHCONTENT_QUIET NO)
        FetchContent_Populate(raylib_cpp)
        add_subdirectory(${raylib_cpp_SOURCE_DIR} ${raylib_cpp_BINARY_DIR})
    endif()
endif()

# This is the main part:
set(PROJECT_NAME raylib_cpp_example)
set(PROJECT_SOURCES main.cpp)
add_executable(${PROJECT_NAME} ${PROJECT_SOURCES})
set_target_properties(${PROJECT_NAME} PROPERTIES CXX_STANDARD 11)
target_link_libraries(${PROJECT_NAME} PUBLIC raylib raylib_cpp)

# Web Configurations
if (${PLATFORM} STREQUAL "Web")
    # Tell Emscripten to build an example.html file.
    set_target_properties(${PROJECT_NAME} PROPERTIES SUFFIX ".html")
endif()

# Checks if OSX and links appropriate frameworks (Only required on MacOS)
if (APPLE)
    target_link_libraries(${PROJECT_NAME} "-framework IOKit")
    target_link_libraries(${PROJECT_NAME} "-framework Cocoa")
    target_link_libraries(${PROJECT_NAME} "-framework OpenGL")
endif()

# That's it! You should have an example executable that you can run. Have fun!
