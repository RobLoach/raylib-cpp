# raylib-cpp CMake Example Project

Use this template to build a [raylib-cpp](https://github.com/RobLoach/raylib-cpp) project using CMake.

## Build

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
emcmake cmake .. -DPLATFORM=Web -DCMAKE_BUILD_TYPE=Release -DCMAKE_EXE_LINKER_FLAGS="-s USE_GLFW=3"
emmake make
```

## Run

```
./raylib-cpp-example
```
