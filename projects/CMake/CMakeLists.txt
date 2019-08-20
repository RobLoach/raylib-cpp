cmake_minimum_required(VERSION 3.11) # FetchContent is available in 3.11+
project(example)

find_package(raylib 2.0 QUIET)
if (NOT raylib_FOUND)
  include(FetchContent)
  FetchContent_Declare(
    raylib
    GIT_REPOSITORY https://github.com/raysan5/raylib.git
    GIT_TAG 6f2f09947f5456cefb3d91d3f667f4d72fa55be6
  )
  FetchContent_GetProperties(raylib)
  if (NOT raylib_POPULATED) # Have we downloaded raylib yet?
    set(FETCHCONTENT_QUIET NO)
    FetchContent_Populate(raylib)
    set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE) # don't build the supplied examples
    set(BUILD_GAMES    OFF CACHE BOOL "" FORCE) # or games
    add_subdirectory(${raylib_SOURCE_DIR} ${raylib_BINARY_DIR})
  endif()
endif()

find_package(raylibcpp 2.0 QUIET)
if (NOT raylibcpp_FOUND)
  include(FetchContent)
  FetchContent_Declare(
    raylibcpp
    GIT_REPOSITORY https://github.com/RobLoach/raylib-cpp.git
    GIT_TAG de5e6184d043e9ae3e5a16836bc810b7485e95f2
  )
  FetchContent_GetProperties(raylib)
  if (NOT raylib_POPULATED) # Have we downloaded raylib yet?
    set(FETCHCONTENT_QUIET NO)
    FetchContent_Populate(raylib)
    set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE) # don't build the supplied examples
    set(BUILD_GAMES    OFF CACHE BOOL "" FORCE) # or games
    add_subdirectory(${raylibcpp_SOURCE_DIR} ${raylibcpp_BINARY_DIR})
  endif()
endif()

# This is the main part:
set(PROJECT_NAME core_basic_window)
add_executable(${PROJECT_NAME} core_basic_window.cpp)
#set(raylib_VERBOSE 1)
target_link_libraries(${PROJECT_NAME} raylib)

# That's it! You should have an example executable that you can run. Have fun!
