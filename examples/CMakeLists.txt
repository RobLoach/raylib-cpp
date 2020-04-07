find_package(Raylib)

# Get the sources together
set(example_dirs audio core models shapes text textures)
set(example_sources)
set(example_resources)

foreach(example_dir ${example_dirs})
  file(GLOB sources ${example_dir}/*.cpp)
  list(APPEND example_sources ${sources})

  # Any any resources
  file(GLOB resources ${example_dir}/resources/*)
  list(APPEND example_resources ${resources})
endforeach()

set(OUTPUT_EXT)

if(${PLATFORM} MATCHES "Web")
  set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Os -s USE_GLFW=3 -s ASSERTIONS=1 -s WASM=1 -s EMTERPRETIFY=1 -s EMTERPRETIFY_ASYNC=1")
  # Since WASM is used, ALLOW_MEMORY_GROWTH has no extra overheads
  set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -s ALLOW_MEMORY_GROWTH=1 --no-heap-copy")
  set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} --shell-file ${CMAKE_SOURCE_DIR}/include/raylib/shell.html")
  set(OUTPUT_EXT ".html")

  # Remove the -rdynamic flag because otherwise emscripten
  # does not generate HTML+JS+WASM files, only a non-working
  # and fat HTML
  #string(REPLACE "-rdynamic" "" CMAKE_SHARED_LIBRARY_LINK_C_FLAGS ${CMAKE_SHARED_LIBRARY_LINK_C_FLAGS})
endif()

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

  if(${PLATFORM} MATCHES "Web" AND EXISTS ${resources_dir})
    # The local resources path needs to be mapped to /resources virtual path
    string(APPEND resources_dir "@resources")
    set_target_properties(${example_name} PROPERTIES LINK_FLAGS "--preload-file ${resources_dir}")
  endif()
endforeach()

file(COPY ${example_resources} DESTINATION "resources/")
