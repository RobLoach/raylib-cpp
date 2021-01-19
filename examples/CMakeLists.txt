# Get the sources together
set(example_dirs audio core models physics shapes text textures)
set(example_sources)
set(example_resources)

# raylib
find_package(raylib QUIET)
if (NOT raylib_FOUND)
    set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE) # don't build the supplied examples
    set(BUILD_GAMES    OFF CACHE BOOL "" FORCE) # or games
    add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/../vendor/raylib ${CMAKE_CURRENT_SOURCE_DIR}/../vendor/raylib)
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
    target_link_libraries(${example_name} PUBLIC raylib-cpp raylib)

    string(REGEX MATCH ".*/.*/" resources_dir ${example_source})
    string(APPEND resources_dir "resources")

endforeach()

# Copy all the resources
file(COPY ${example_resources} DESTINATION "resources/")
