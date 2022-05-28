# Building with CMake

## Build

This project doesn't require any special command-line flags to build to keep
things simple.

Here are the steps for building in release mode with a single-configuration
generator, like the Unix Makefiles one:

```sh
cmake -S . -B build -D CMAKE_BUILD_TYPE=Release
cmake --build build
```

Here are the steps for building in release mode with a multi-configuration
generator, like the Visual Studio ones:

```sh
cmake -S . -B build
cmake --build build --config Release
```

### Building with MSVC

Note that MSVC by default is not standards compliant and you need to pass some
flags to make it behave properly. See the `flags-windows` preset in the
[CMakePresets.json](CMakePresets.json) file for the flags and with what
variable to provide them to CMake during configuration.

### Building on Apple Silicon

CMake supports building on Apple Silicon properly since 3.20.1. Make sure you
have the [latest version][1] installed.






### Compiling

Since *raylib-cpp* is a header only library, the build process is the same as raylib's, except you will use C++ to compile instead of C. The following are some specific instructions on local development.

#### Desktop

*raylib-cpp* uses [CMake](https://cmake.org) as a primary target for development. To build it, and run the tests or examples, use...

``` bash
git clone https://github.com/RobLoach/raylib-cpp.git
cd raylib-cpp
mkdir build
cd build
cmake ..
make
make test
./examples/core_basic_window
```

#### Web

Use [emscripten](https://emscripten.org/) to build and test [core_basic_window_web.cpp](examples/core/core_basic_window_web.cpp).

```
mkdir build
cd build
emcmake cmake .. -DPLATFORM=Web -DCMAKE_BUILD_TYPE=Release -DCMAKE_EXE_LINKER_FLAGS="-s USE_GLFW=3"
emmake make
```

See [`core_basic_window_web.html`](examples/core/resources/core_basic_window_web.html) for an example HTML canvas you can you.

## Install

This project doesn't require any special command-line flags to install to keep
things simple. As a prerequisite, the project has to be built with the above
commands already.

The below commands require at least CMake 3.15 to run, because that is the
version in which [Install a Project][2] was added.

Here is the command for installing the release mode artifacts with a
single-configuration generator, like the Unix Makefiles one:

```sh
cmake --install build
```

Here is the command for installing the release mode artifacts with a
multi-configuration generator, like the Visual Studio ones:

```sh
cmake --install build --config Release
```

### CMake package

This project exports a CMake package to be used with the [`find_package`][3]
command of CMake:

* Package name: `raylib_cpp`
* Target name: `raylib_cpp::raylib_cpp`

Example usage:

```cmake
find_package(raylib_cpp REQUIRED)
# Declare the imported target as a build requirement using PRIVATE, where
# project_target is a target created in the consuming project
target_link_libraries(
    project_target PRIVATE
    raylib_cpp::raylib_cpp
)
```

[1]: https://cmake.org/download/
[2]: https://cmake.org/cmake/help/latest/manual/cmake.1.html#install-a-project
[3]: https://cmake.org/cmake/help/latest/command/find_package.html
