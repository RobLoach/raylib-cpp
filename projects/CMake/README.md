# raylib-cpp CMake Example Project

Use this template to build a [raylib-cpp](https://github.com/RobLoach/raylib-cpp) project using [CMake](https://cmake.org).

## Build

To build this project, make sure to have CMake installed locally.

### Desktop

```
mkdir build
cd build
cmake ..
make
```

### Web

```
mkdir build
cd build
emcmake cmake .. -DPLATFORM=Web -DCMAKE_BUILD_TYPE=Release
emmake make
```

## Run

```
./raylib-cpp-example
```
