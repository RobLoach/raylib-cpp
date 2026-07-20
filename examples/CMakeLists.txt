# Get the sources together
set(example_dirs audio core models shaders shapes text textures)
set(example_sources)
set(example_resources)

# C++
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# raylib
find_package(raylib QUIET)
if (NOT raylib_FOUND)
    include(FetchContent)
        FetchContent_Declare(
        raylib
        GIT_REPOSITORY https://github.com/raysan5/raylib.git
        # Track raylib's master branch, so CI verifies compatibility with the latest raylib.
        GIT_TAG master
        GIT_SHALLOW 1
    )
    FetchContent_GetProperties(raylib)
    if (NOT raylib_POPULATED) # Have we downloaded raylib yet?
        set(FETCHCONTENT_QUIET NO)
        set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
        set(BUILD_GAMES    OFF CACHE BOOL "" FORCE)
        FetchContent_MakeAvailable(raylib)
    endif()
endif()

# Find all examples
foreach(example_dir ${example_dirs})
    file(GLOB sources ${example_dir}/*.cpp)
    list(APPEND example_sources ${sources})

    # Any any resources
    file(GLOB resources ${example_dir}/resources/*)
    list(APPEND example_resources ${resources})
endforeach()

# Compile all examples
foreach(example_source ${example_sources})
    # Create the basename for the example
    get_filename_component(example_name ${example_source} NAME)
    string(REPLACE ".cpp" "${OUTPUT_EXT}" example_name ${example_name})

    # Setup the example
    add_executable(${example_name} ${example_source})

    # Link raylib and raylib-cpp
    target_link_libraries(${example_name} PUBLIC raylib_cpp raylib)

    string(REGEX MATCH ".*/.*/" resources_dir ${example_source})
    string(APPEND resources_dir "resources")
endforeach()

# Multiple Files Example
add_executable("multiple" multiple/main.cpp multiple/Player.cpp)
target_link_libraries("multiple" PUBLIC raylib_cpp raylib)

# C++20 modules example: only built when modules are enabled and the
# raylib_cpp_modules target was created (CMake 3.28+).
if(BUILD_RAYLIB_CPP_MODULES AND TARGET raylib_cpp_modules)
    add_executable("module" module/main.cpp)
    target_link_libraries("module" PRIVATE raylib_cpp_modules)
    set_target_properties("module" PROPERTIES
        CXX_STANDARD 20
        CXX_STANDARD_REQUIRED ON
        # Match raylib_cpp_modules' language flags: the compiled module (BMI)
        # can only be imported by a consumer built with the same C++ standard
        # and extension settings, so keep the default extensions here.
        CXX_EXTENSIONS ON
        # The examples directory defaults to C++11, so module scanning is not
        # enabled for this target automatically; turn it on explicitly.
        CXX_SCAN_FOR_MODULES ON
    )
endif()

# Copy all the resources
file(COPY ${example_resources} DESTINATION "resources/")
