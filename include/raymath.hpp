/**
 * C++ header to wrap raymath.h.
 */
#ifndef RAYLIB_CPP_INCLUDE_RAYMATH_HPP_
#define RAYLIB_CPP_INCLUDE_RAYMATH_HPP_

#ifdef __cplusplus
extern "C" {
#endif
#ifndef RAYLIB_CPP_NO_MATH
#ifndef RAYMATH_STATIC_INLINE
#define RAYMATH_STATIC_INLINE
#endif
#ifdef __GNUC__
#pragma GCC diagnostic push  // These throw a warnings on visual studio, need to check if __GNUC__ is defined to use it.
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif
#include "raymath.h" // NOLINT
#ifdef __GNUC__
#pragma GCC diagnostic pop
#endif
#endif
#ifdef __cplusplus
}
#endif

#endif  // RAYLIB_CPP_INCLUDE_RAYMATH_HPP_
