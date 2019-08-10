find_package(Raylib)

# Get the sources together
set(example_dirs audio core text textures)
set(example_sources)
set(example_resources)

foreach(example_dir ${example_dirs})
  file(GLOB sources ${example_dir}/*.cpp)
  list(APPEND example_sources ${sources})

  # Any any resources
  file(GLOB resources ${example_dir}/resources/*)
  list(APPEND example_resources ${resources})
endforeach()


# Do each example
foreach(example_source ${example_sources})
  # Create the basename for the example
  get_filename_component(example_name ${example_source} NAME)
  string(REPLACE ".cpp" "${OUTPUT_EXT}" example_name ${example_name})

  # Setup the example
  add_executable(${example_name} ${example_source})

  target_link_libraries(${example_name} PUBLIC raylib-cpp raylib)

  string(REGEX MATCH ".*/.*/" resources_dir ${example_source})
  string(APPEND resources_dir "resources")

endforeach()

file(COPY ${example_resources} DESTINATION "resources/")
