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

#if RAYLIB_VERSION_MAJOR < 6
#error "raylib-cpp requires raylib >= 6"
#endif

#if RAYLIB_VERSION_MAJOR > 6
#error "raylib-cpp requires raylib ~6.0. Use the `next` branch for the next version of raylib."
#endif

#ifndef RLCPP_MAYBEUNUSED
#  if defined(__has_cpp_attribute)
#    if __has_cpp_attribute(maybe_unused) && __cplusplus >= 201703L
#      define RLCPP_MAYBEUNUSED [[maybe_unused]]
#    else
#      define RLCPP_MAYBEUNUSED
#    endif
#  elif (defined(_MSVC_LANG) && _MSVC_LANG >= 201703L) || (__cplusplus >= 201703L)
#    define RLCPP_MAYBEUNUSED [[maybe_unused]]
#  else
#    define RLCPP_MAYBEUNUSED
#  endif
#endif

#ifndef RLCPP_NODISCARD
#  if defined(__has_cpp_attribute)
#    if __has_cpp_attribute(nodiscard) && __cplusplus >= 201703L
#      define RLCPP_NODISCARD [[nodiscard]]
#    else
#      define RLCPP_NODISCARD
#    endif
#  elif (defined(_MSVC_LANG) && _MSVC_LANG >= 201703L) || (__cplusplus >= 201703L)
#    define RLCPP_NODISCARD [[nodiscard]]
#  else
#    define RLCPP_NODISCARD
#  endif
#endif

#ifdef __cplusplus
}
#endif

#endif // RAYLIB_CPP_INCLUDE_RAYLIB_HPP_
