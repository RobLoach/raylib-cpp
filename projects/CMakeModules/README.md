# raylib-cpp CMake Example Project

Use this template to build a [raylib-cpp](https://github.com/RobLoach/raylib-cpp) project using [CMake](https://cmake.org).

## Build

To build this project, make sure to have CMake installed locally.

### Desktop

```
mkdir build
cmake . --preset Release
cmake --build build/Release --preset Release
```

### Web

```
mkdir build
emcmake cmake . --preset ReleaseWeb
emcmake cmake --build build/ReleaseWeb --preset ReleaseWeb
```

## Run

```
./build/Release/raylib-cpp-example
```
