/**
 * C++ header to wrap raylib.h.
 */
#ifndef RAYLIB_CPP_INCLUDE_RAYLIB_HPP_
#define RAYLIB_CPP_INCLUDE_RAYLIB_HPP_

#ifdef __cplusplus
extern "C" {
#endif

#ifndef RAYLIB_H_FILE
#define RAYLIB_H_FILE "raylib.h"
#endif

#include RAYLIB_H_FILE // NOLINT

#if !defined(RAYLIB_VERSION_MAJOR) || !defined(RAYLIB_VERSION_MINOR) || RAYLIB_VERSION_MAJOR < 4 || RAYLIB_VERSION_MINOR < 5
#error "raylib-cpp requires at least raylib 4.5.0"
#endif

#ifdef __cplusplus
}
#endif

#endif  // RAYLIB_CPP_INCLUDE_RAYLIB_HPP_
