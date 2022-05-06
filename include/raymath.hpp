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
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#include "raymath.h" // NOLINT
#pragma GCC diagnostic pop
#endif
#ifdef __cplusplus
}
#endif

#endif  // RAYLIB_CPP_INCLUDE_RAYMATH_HPP_
