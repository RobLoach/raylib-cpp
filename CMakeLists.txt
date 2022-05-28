cmake_minimum_required(VERSION 3.14)

include(cmake/prelude.cmake)

project(
    raylib_cpp
    VERSION 4.2.1
    DESCRIPTION "C++ Object Oriented Wrapper for raylib"
    HOMEPAGE_URL "https://github.com/RobLoach/raylib_cpp"
    LANGUAGES NONE
)

include(cmake/project-is-top-level.cmake)
include(cmake/variables.cmake)

# ---- Declare library dependency ----

# raylib
find_package(raylib QUIET)
if (NOT raylib_FOUND)
  include(FetchContent)
  set(FETCHCONTENT_QUIET FALSE)

  FetchContent_Declare(
              raylib
              GIT_REPOSITORY "https://github.com/raysan5/raylib.git"
              GIT_TAG 4.0.0 # 2022-05-11
      )
  set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
  set(BUILD_GAMES    OFF CACHE BOOL "" FORCE)
  set(INCLUDE_EVERYTHING ON CACHE BOOL "" FORCE)
  FetchContent_MakeAvailable(raylib)

  get_target_property(_inc raylib INTERFACE_INCLUDE_DIRECTORIES)
  target_include_directories(raylib SYSTEM INTERFACE ${_inc})
endif()

# ---- Declare library ----

add_library(raylib_cpp_raylib_cpp INTERFACE)
add_library(raylib_cpp::raylib_cpp ALIAS raylib_cpp_raylib_cpp)

set_property(
    TARGET raylib_cpp_raylib_cpp PROPERTY
    EXPORT_NAME raylib_cpp
)

target_include_directories(
    raylib_cpp_raylib_cpp ${warning_guard}
    INTERFACE
    "$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>"
)

# target_compile_features(raylib_cpp_raylib_cpp INTERFACE cxx_std_17)

# ---- Install rules ----

if(NOT CMAKE_SKIP_INSTALL_RULES)
  include(cmake/install-rules.cmake)
endif()

# ---- Examples ----

if(PROJECT_IS_TOP_LEVEL)
  option(BUILD_EXAMPLES "Build examples tree." "${raylib_cpp_DEVELOPER_MODE}")
  if(BUILD_EXAMPLES)
    add_subdirectory(example)
  endif()
endif()

# ---- Developer mode ----

if(NOT raylib_cpp_DEVELOPER_MODE)
  return()
elseif(NOT PROJECT_IS_TOP_LEVEL)
  message(
      AUTHOR_WARNING
      "Developer mode is intended for developers of raylib_cpp"
  )
endif()

include(cmake/dev-mode.cmake)
