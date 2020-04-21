# libraylib-cpp static library
add_library(libraylib-cpp STATIC libraylib-cpp)

# raylib
find_package(raylib 3.0.0 QUIET)
if (NOT raylib_FOUND)
	set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE) # don't build the supplied examples
	set(BUILD_GAMES    OFF CACHE BOOL "" FORCE) # or games
	add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/../vendor/raylib ${CMAKE_CURRENT_SOURCE_DIR}/../vendor/raylib)
endif()

# Link raylib and raylib-cpp
target_link_libraries(libraylib-cpp PUBLIC raylib raylib-cpp)

# Remove the "lib" at the beginning since it's already there.
set_target_properties(libraylib-cpp PROPERTIES PREFIX "")

# Set up the install directory.
install(TARGETS libraylib-cpp DESTINATION lib)
