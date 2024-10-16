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

#if !defined(RAYLIB_VERSION_MAJOR) || !defined(RAYLIB_VERSION_MINOR)
#error "raylib-cpp requires raylib >= 5"
#endif

#if RAYLIB_VERSION_MAJOR < 5
#error "raylib-cpp requires raylib >= 5"
#endif

#if RAYLIB_VERSION_MAJOR > 5
#error "raylib-cpp requires raylib ~5.0. Use the `next` branch for the next version of raylib."
#endif

#if RAYLIB_VERSION_MINOR < 1
    #error "raylib-cpp targets raylib 5.1 or higher."
#endif

#ifdef __cplusplus
}
#endif

#endif // RAYLIB_CPP_INCLUDE_RAYLIB_HPP_
