/**********************************************************************************************
*
*   raylib-assert - Assertion library for raylib.
*   https://github.com/robloach/raylib-assert
*
*   Copyright 2021 Rob Loach (@RobLoach)
*
*   DEPENDENCIES:
*       raylib https://www.raylib.com/
*
*   LICENSE: zlib/libpng
*
*   raylib-assert is licensed under an unmodified zlib/libpng license, which is an OSI-certified,
*   BSD-like license that allows static linking with closed source software:
*
*   This software is provided "as-is", without any express or implied warranty. In no event
*   will the authors be held liable for any damages arising from the use of this software.
*
*   Permission is granted to anyone to use this software for any purpose, including commercial
*   applications, and to alter it and redistribute it freely, subject to the following restrictions:
*
*     1. The origin of this software must not be misrepresented; you must not claim that you
*     wrote the original software. If you use this software in a product, an acknowledgment
*     in the product documentation would be appreciated but is not required.
*
*     2. Altered source versions must be plainly marked as such, and must not be misrepresented
*     as being the original software.
*
*     3. This notice may not be removed or altered from any source distribution.
*
**********************************************************************************************/

#ifndef RAYLIB_ASSERT_H
#define RAYLIB_ASSERT_H

#ifdef __cplusplus
extern "C" {
#endif

#include "raylib.h" // NOLINT

// How to report failed assertions
#ifndef RAYLIB_ASSERT_LOG
#define RAYLIB_ASSERT_LOG LOG_FATAL
#endif

// Define NDEBUG or RAYLIB_ASSERT_NDEBUG to skip assertions
#ifdef NDEBUG
#ifndef RAYLIB_ASSERT_NDEBUG
#define RAYLIB_ASSERT_NDEBUG
#endif
#endif

// Variadic Arguments
#define RAYLIB_ASSERT_CAT( A, B ) A ## B
#define RAYLIB_ASSERT_SELECT( NAME, NUM ) RAYLIB_ASSERT_CAT( NAME ## _, NUM )
#define RAYLIB_ASSERT_GET_COUNT( _1, _2, _3, _4, _5, _6, _7, RAYLIB_ASSERT_COUNT, ... ) RAYLIB_ASSERT_COUNT
#define RAYLIB_ASSERT_VA_SIZE( ... ) RAYLIB_ASSERT_GET_COUNT( __VA_ARGS__, 7, 6, 5, 4, 3, 2, 1 )
#define RAYLIB_ASSERT_VA_SELECT( NAME, ... ) RAYLIB_ASSERT_SELECT( NAME, RAYLIB_ASSERT_VA_SIZE(__VA_ARGS__) )(__VA_ARGS__)

#define Assert(...) RAYLIB_ASSERT_VA_SELECT( Assert, __VA_ARGS__ )
#define AssertEqual(...) RAYLIB_ASSERT_VA_SELECT( AssertEqual, __VA_ARGS__ )
#define AssertNot(...) RAYLIB_ASSERT_VA_SELECT( AssertNot, __VA_ARGS__ )
#define AssertFail(...) RAYLIB_ASSERT_VA_SELECT( AssertFail, __VA_ARGS__ )

// Assert()
#ifdef RAYLIB_ASSERT_NDEBUG
#define Assert_1(condition)
#define Assert_2(condition, message)
#define Assert_3(condition, message, p1)
#define Assert_4(condition, message, p1, p2)
#define Assert_5(condition, message, p1, p2, p3)
#define Assert_6(condition, message, p1, p2, p3, p4)
#define Assert_7(condition, message, p1, p2, p3, p4, p5)
#else
#define Assert_1(condition) Assert_2(condition, #condition)
#define Assert_2(condition, message) if (!((bool)(condition))) { TraceLog(RAYLIB_ASSERT_LOG, "ASSERT: %s (%s:%i)", message, __FILE__, __LINE__); }
#define Assert_3(condition, message, p1) Assert_2(condition, TextFormat(message, p1))
#define Assert_4(condition, message, p1, p2) Assert_2(condition, TextFormat(message, p1, p2))
#define Assert_5(condition, message, p1, p2, p3) Assert_2(condition, TextFormat(message, p1, p2, p3))
#define Assert_6(condition, message, p1, p2, p3, p4) Assert_2(condition, TextFormat(message, p1, p2, p3, p4))
#define Assert_7(condition, message, p1, p2, p3, p4, p5) Assert_2(condition, TextFormat(message, p1, p2, p3, p4, p5))
#endif

// AssertEqual()
#define AssertEqual_1(condition) Assert_2(condition, #condition)
#define AssertEqual_2(actual, expected) Assert_4((actual) == (expected), "%s == %s", #actual, #expected)
#define AssertEqual_3(actual, expected, message) Assert_2((actual) == (expected), message)
#define AssertEqual_4(actual, expected, message, p1) Assert_3((actual) == (expected), message, p1)
#define AssertEqual_5(actual, expected, message, p1, p2) Assert_4((actual) == (expected), message, p1, p2)
#define AssertEqual_6(actual, expected, message, p1, p2, p3) Assert_5((actual) == (expected), message, p1, p2, p3)
#define AssertEqual_7(actual, expected, message, p1, p2, p3, p4) Assert_6((actual) == (expected), message, p1, p2, p3, p4)

// AssertNot()
#define AssertNot_1(condition) Assert_2(!(bool)(condition), #condition)
#define AssertNot_2(condition, message) Assert_2(!(bool)(condition), message)
#define AssertNot_3(condition, message, p1) Assert_3(!(bool)(condition), message, p1)
#define AssertNot_4(condition, message, p1, p2) Assert_4(!(bool)(condition), message, p1, p2)
#define AssertNot_5(condition, message, p1, p2, p3) Assert_5(!(bool)(condition), message, p1, p2, p3)
#define AssertNot_6(condition, message, p1, p2, p3, p4) Assert_6(!(bool)(condition), message, p1, p2, p3, p4)
#define AssertNot_7(condition, message, p1, p2, p3, p4, p5) Assert_7(!(bool)(condition), message, p1, p2, p3, p4, p5)

// AssertFail()
#ifdef RAYLIB_ASSERT_NDEBUG
#define AssertFail_0()
#define AssertFail_1(message)
#define AssertFail_2(message, p1)
#define AssertFail_3(message, p1, p2)
#define AssertFail_4(message, p1, p2, p3)
#define AssertFail_5(message, p1, p2, p3, p4)
#define AssertFail_6(message, p1, p2, p3, p4, p5)
#define AssertFail_7(message, p1, p2, p3, p4, p5, p6)
#else
#define AssertFail_0() TraceLog(RAYLIB_ASSERT_LOG, "ASSERT: AssertFail() (%s:%i)", __FILE__, __LINE__)
#define AssertFail_1(message) TraceLog(RAYLIB_ASSERT_LOG, "ASSERT: %s (%s:%i)", message, __FILE__, __LINE__)
#define AssertFail_2(message, p1) AssertFail_1(TextFormat(message, p1))
#define AssertFail_3(message, p1, p2) AssertFail_1(TextFormat(message, p1, p2))
#define AssertFail_4(message, p1, p2, p3) AssertFail_1(TextFormat(message, p1, p2, p3))
#define AssertFail_5(message, p1, p2, p3, p4) AssertFail_1(TextFormat(message, p1, p2, p3, p4))
#define AssertFail_6(message, p1, p2, p3, p4, p5) AssertFail_1(TextFormat(message, p1, p2, p3, p4, p5))
#define AssertFail_7(message, p1, p2, p3, p4, p5, p6) AssertFail_1(TextFormat(message, p1, p2, p3, p4, p5, p6))
#endif

// AssertBreakpoint()
#define AssertBreakpoint() AssertFail_1("AssertBreakpoint()")

#ifdef __cplusplus
}
#endif

#endif  // RAYLIB_ASSERT_H
