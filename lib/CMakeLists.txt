# libraylib-cpp static library
add_library(libraylib-cpp STATIC libraylib-cpp)

# Link raylib and raylib-cpp
target_link_libraries(libraylib-cpp PUBLIC raylib raylib-cpp)

# Remove the "lib" at the beginning since it's already there.
set_target_properties(libraylib-cpp PROPERTIES PREFIX "")
