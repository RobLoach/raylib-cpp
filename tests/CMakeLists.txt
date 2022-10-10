# Test Options
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CTEST_CUSTOM_TESTS_IGNORE pkg-config--static)

# Executable
add_executable(raylib_cpp_test raylib_cpp_test.cpp)
if (MSVC)
    target_compile_options(raylib_cpp_test PRIVATE /Wall /W4)
else()
    target_compile_options(raylib_cpp_test PRIVATE -Wall -Wextra -Wconversion -Wsign-conversion)
endif()
target_link_libraries(raylib_cpp_test raylib_cpp raylib)

# Test
list(APPEND CMAKE_CTEST_ARGUMENTS "--output-on-failure")
add_test(NAME raylib_cpp_test COMMAND raylib_cpp_test)

# Copy all the resources
file(COPY resources/ DESTINATION "resources/")
