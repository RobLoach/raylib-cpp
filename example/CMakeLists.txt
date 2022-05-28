cmake_minimum_required(VERSION 3.14)

project(raylib_cppExamples C CXX)

include(../cmake/project-is-top-level.cmake)
include(../cmake/folders.cmake)

if(PROJECT_IS_TOP_LEVEL)
  find_package(raylib_cpp REQUIRED)
endif()

#[[
add_custom_target(run-examples)

function(add_example NAME)
  add_executable("${NAME}" "${NAME}.cpp")
  target_link_libraries("${NAME}" PRIVATE raylib_cpp::raylib_cpp)
  target_compile_features("${NAME}" PRIVATE cxx_std_14)
  add_custom_target("run_${NAME}" COMMAND "${NAME}" VERBATIM)
  add_dependencies("run_${NAME}" "${NAME}")
  add_dependencies(run-examples "run_${NAME}")
endfunction()

add_example(empty_example)

]]

# Get the sources together
set(example_dirs audio core models physics shaders shapes text textures)
set(example_sources)
set(example_resources)

add_custom_target(run-examples)

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

    # Link raylib and raylib_cpp
    target_link_libraries(${example_name} PUBLIC raylib_cpp::raylib_cpp raylib)

    # Custom target to run the example
    add_custom_target("run_${example_name}" COMMAND "${example_name}" VERBATIM)
    add_dependencies("run_${example_name}" "${example_name}")
    add_dependencies(run-examples "run_${example_name}")

    string(REGEX MATCH ".*/.*/" resources_dir ${example_source})
    string(APPEND resources_dir "resources")
endforeach()

# Multiple Files Example
add_executable("multiple" multiple/main.cpp multiple/Player.cpp)
target_link_libraries("multiple" PUBLIC raylib_cpp::raylib_cpp raylib)

# Copy all the resources
file(COPY ${example_resources} DESTINATION "resources/")


add_folders(Example)
