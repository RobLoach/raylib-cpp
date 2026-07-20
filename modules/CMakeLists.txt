# raylib-cpp C++ module target (`import raylib;`).
#
# Consuming this target requires a tool-chain that can scan for C++ module
# dependencies:
#   * CMake 3.28 or newer.
#   * A generator that supports module dependency scanning: Ninja,
#     Ninja Multi-Config, or Visual Studio 17.4+. The Makefile generators
#     (including the default on macOS/Linux) CANNOT scan for modules.
#   * A compiler with scanning support: Clang 16+ (LLVM, not Apple Clang),
#     MSVC 19.34+, or GCC 14+.
#
# When these requirements are not met CMake reports the cryptic error
# "the compiler does not provide a way to discover the import graph
# dependencies"; the checks below turn that into an actionable message.

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
