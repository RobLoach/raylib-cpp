# raylib-cpp C++ module target (`import raylib;`).
#
# Requirements
# - CMake 3.28+
# - Module dependency scanning generator, like Ninja, VS17.4+
# - Compiler with scanning support, like CLang (16+, MSVC 19.34+ or GCC 14+

if(CMAKE_VERSION VERSION_LESS 3.28)
  message(WARNING
    "raylib-cpp: C++ modules require CMake 3.28 or newer (found "
    "${CMAKE_VERSION}). Skipping the raylib_cpp_modules target.")
  return()
endif()

# Module dependency scanning is only implemented for the Ninja and
# Visual Studio generators.
if(NOT CMAKE_GENERATOR MATCHES "Ninja|Visual Studio")
  message(WARNING
    "raylib-cpp: building C++ modules requires the Ninja or Visual Studio "
    "generator; the '${CMAKE_GENERATOR}' generator cannot discover module "
    "import dependencies. Reconfigure with '-G Ninja' to use 'import raylib;'.")
endif()

add_library(raylib_cpp_modules STATIC)

# Allow a parent project to customise how the module sources are attached.
if(NOT COMMAND configure_cpp_module_target)
  function(configure_cpp_module_target target)
    target_sources(${target}
      PUBLIC
        FILE_SET CXX_MODULES FILES ${CMAKE_CURRENT_SOURCE_DIR}/raylib.cppm
    )
  endfunction()
endif()

configure_cpp_module_target(raylib_cpp_modules)

target_link_libraries(raylib_cpp_modules
  PUBLIC
    raylib_cpp
    raylib
)

target_include_directories(raylib_cpp_modules
  PRIVATE
    ${PROJECT_SOURCE_DIR}/include
)

# C++ modules require at least C++20; propagate the requirement to consumers
# so that module scanning is enabled for targets that `import raylib;`.
target_compile_features(raylib_cpp_modules PUBLIC cxx_std_20)
