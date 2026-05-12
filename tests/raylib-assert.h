/**********************************************************************************************
*
*   raylib-assert - Assertion library for raylib.
*   https://github.com/robloach/raylib-assert
*
*   Version: v3.3.1
*
*   Copyright 2026 Rob Loach (@RobLoach)
*
*   DEPENDENCIES:
*       raylib 6.0+ https://www.raylib.com
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

#include <stddef.h> // NULL

#ifndef RAYLIB_H
#error "raylib-assert.h requires raylib.h to be included before raylib-assert.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

// How to report failed assertions
#ifndef RAYLIB_ASSERT_LOG
/**
 * The Trace Log Level used to report to TraceLog() on failed assertions. Defaults to LOG_FATAL.
 *
 * @example
 *     #define RAYLIB_ASSERT_LOG LOG_WARNING
 *
 * @see TraceLogLevel
 */
#define RAYLIB_ASSERT_LOG LOG_FATAL
#endif

// Define NDEBUG or RAYLIB_ASSERT_NDEBUG to skip assertions
#ifdef NDEBUG
#ifndef RAYLIB_ASSERT_NDEBUG
#define RAYLIB_ASSERT_NDEBUG
#endif
#endif

#ifndef RAYLIB_ASSERT_TRACELOG
/**
 * The TraceLog() function to use.
 *
 * @see TraceLog()
 */
#define RAYLIB_ASSERT_TRACELOG TraceLog
#endif

#ifndef RAYLIB_ASSERT_TEXTFORMAT
/**
 * The TextFormat() function to use when formating text.
 *
 * @see TextFormat()
 */
#define RAYLIB_ASSERT_TEXTFORMAT TextFormat
#endif

#ifndef RAYLIB_ASSERT_EPSILON
/**
 * The epsilon used for floating-point comparisons in AssertFloatEqual(),
 * AssertVector2Same(), AssertVector3Same(), AssertVector4Same(), and AssertRectangleSame().
 * Override before including this header to use a different tolerance.
 *
 * @example
 *     #define RAYLIB_ASSERT_EPSILON 0.01f
 */
#define RAYLIB_ASSERT_EPSILON 0.000001f
#endif

// Internal helper: true when two floats are within RAYLIB_ASSERT_EPSILON of each other.
static inline bool RaylibAssertFloatEq(float a, float b)
{
    float delta = a - b;
    if (delta < 0.0f) delta = -delta;
    return delta <= RAYLIB_ASSERT_EPSILON;
}

// Internal helper: true when two color channels differ by no more than the given tolerance.
static inline bool RaylibAssertChannelWithin(int a, int b, int tolerance)
{
    int delta = a - b;
    if (delta < 0) delta = -delta;
    return delta <= tolerance;
}

// Internal helper: true when a mesh contains basic CPU-side geometry data.
static inline bool RaylibAssertMeshValid(Mesh mesh)
{
    return mesh.vertexCount > 0 && mesh.triangleCount > 0 && mesh.vertices != NULL;
}

#define RAYLIB_ASSERT_FLOAT_EQ(a, b) RaylibAssertFloatEq((float)(a), (float)(b))
#define RAYLIB_ASSERT_CHANNEL_WITHIN(a, b, tolerance) RaylibAssertChannelWithin((int)(a), (int)(b), (int)(tolerance))
#define RAYLIB_ASSERT_MESH_VALID(mesh) RaylibAssertMeshValid((mesh))

// Variadic Arguments
#define RAYLIB_ASSERT_CAT(a, b) RAYLIB_ASSERT_CAT_I(a, b)
#define RAYLIB_ASSERT_CAT_I(a, b) a##b
#define RAYLIB_ASSERT_SELECT(name, num) RAYLIB_ASSERT_CAT(name##_, num)
#define RAYLIB_ASSERT_GET_COUNT( _1, _2, _3, _4, _5, _6, _7, RAYLIB_ASSERT_COUNT, ... ) RAYLIB_ASSERT_COUNT
#define RAYLIB_ASSERT_VA_SIZE( ... ) RAYLIB_ASSERT_GET_COUNT( __VA_ARGS__, 7, 6, 5, 4, 3, 2, 1 )
#define RAYLIB_ASSERT_VA_SELECT( NAME, ...) RAYLIB_ASSERT_SELECT( NAME, RAYLIB_ASSERT_VA_SIZE(__VA_ARGS__) )(__VA_ARGS__)

/**
 * Assert whether the given condition is true.
 *
 * @param condition The condition that is expected to be true.
 * @param message (Optional) The message to provide on failed assertions.
 * @param p1 (Optional) The first parameter in the message.
 * @param p2 (Optional) The second parameter in the message.
 * @param p3 (Optional) The third parameter in the message.
 * @param p4 (Optional) The fourth parameter in the message.
 * @param p5 (Optional) The fifth parameter in the message.
 */
#define Assert(...) RAYLIB_ASSERT_VA_SELECT(Assert, __VA_ARGS__)

/**
 * Assert whether the two given parameters are equal.
 *
 * @param actual The actual value.
 * @param expected The expected value.
 * @param message (Optional) The message to provide on failed assertions.
 * @param p1 (Optional) The first parameter in the message.
 * @param p2 (Optional) The second parameter in the message.
 * @param p3 (Optional) The third parameter in the message.
 * @param p4 (Optional) The fourth parameter in the message.
 */
#define AssertEqual(...) RAYLIB_ASSERT_VA_SELECT(AssertEqual, __VA_ARGS__)

/**
 * Assert whether the given condition is false.
 *
 * @param condition The condition that is expected to be false.
 * @param message (Optional) The message to provide on failed assertions.
 * @param p1 (Optional) The first parameter in the message.
 * @param p2 (Optional) The second parameter in the message.
 * @param p3 (Optional) The third parameter in the message.
 * @param p4 (Optional) The fourth parameter in the message.
 * @param p5 (Optional) The fifth parameter in the message.
 */
#define AssertNot(...) RAYLIB_ASSERT_VA_SELECT(AssertNot, __VA_ARGS__)

/**
 * Assert whether the two given parameters are not equal.
 *
 * @param actual The actual value.
 * @param notexpected The expected value that shouldn't equal the actual value.
 * @param message (Optional) The message to provide on failed assertions.
 * @param p1 (Optional) The first parameter in the message.
 * @param p2 (Optional) The second parameter in the message.
 * @param p3 (Optional) The third parameter in the message.
 * @param p4 (Optional) The fourth parameter in the message.
 */
#define AssertNotEqual(...) RAYLIB_ASSERT_VA_SELECT(AssertNotEqual, __VA_ARGS__)

/**
 * Sets a failed assertion, with the given message.
 *
 * @param message (Optional) The message to provide for the failed assertion.
 * @param p1 (Optional) The first parameter in the message.
 * @param p2 (Optional) The second parameter in the message.
 * @param p3 (Optional) The third parameter in the message.
 * @param p4 (Optional) The fourth parameter in the message.
 * @param p5 (Optional) The fifth parameter in the message.
 * @param p6 (Optional) The sixth parameter in the message.
 */
#define AssertFail(...) RAYLIB_ASSERT_VA_SELECT(AssertFail, __VA_ARGS__)

/**
 * Assert whether an image is loaded.
 *
 * @param image The image to check for valid data.
 * @param message (Optional) The message to provide on failed assertions.
 * @param p1 (Optional) The first parameter in the message.
 * @param p2 (Optional) The second parameter in the message.
 * @param p3 (Optional) The third parameter in the message.
 * @param p4 (Optional) The fourth parameter in the message.
 * @param p5 (Optional) The fifth parameter in the message.
 */
#define AssertImage(...) RAYLIB_ASSERT_VA_SELECT(AssertImage, __VA_ARGS__)

/**
 * Assert whether an image has the given dimensions.
 *
 * @param image The image to check.
 * @param width The expected image width.
 * @param height The expected image height.
 * @param message (Optional) The message to provide on failed assertions.
 * @param p1 (Optional) The first parameter in the message.
 * @param p2 (Optional) The second parameter in the message.
 * @param p3 (Optional) The third parameter in the message.
 */
#define AssertImageSize(...) RAYLIB_ASSERT_VA_SELECT(AssertImageSize, __VA_ARGS__)

/**
 * Assert whether two images are the same.
 *
 * @param image1 The first image to check is equal to the second.
 * @param image2 The second image to check is equal to the first.
 * @param message (Optional) The message to provide on failed assertions.
 * @param p1 (Optional) The first parameter in the message.
 * @param p2 (Optional) The second parameter in the message.
 * @param p3 (Optional) The third parameter in the message.
 * @param p4 (Optional) The fourth parameter in the message.
 */
#define AssertImageSame(...) RAYLIB_ASSERT_VA_SELECT(AssertImageSame, __VA_ARGS__)

/**
 * Assert whether two colors are the same.
 *
 * @param color1 The first color to check.
 * @param color2 The second color to check.
 * @param message (Optional) The message to provide on failed assertions.
 * @param p1 (Optional) The first parameter in the message.
 * @param p2 (Optional) The second parameter in the message.
 * @param p3 (Optional) The third parameter in the message.
 * @param p4 (Optional) The fourth parameter in the message.
 */
#define AssertColorSame(...) RAYLIB_ASSERT_VA_SELECT(AssertColorSame, __VA_ARGS__)

/**
 * Assert whether two colors are approximately the same within a per-channel tolerance.
 *
 * @param color1 The first color to check.
 * @param color2 The second color to check.
 * @param tolerance The maximum allowed difference per RGBA channel.
 * @param message (Optional) The message to provide on failed assertions.
 * @param p1 (Optional) The first parameter in the message.
 * @param p2 (Optional) The second parameter in the message.
 * @param p3 (Optional) The third parameter in the message.
 */
#define AssertColorApprox(...) RAYLIB_ASSERT_VA_SELECT(AssertColorApprox, __VA_ARGS__)

/**
 * Assert whether two Vector2s are the same.
 *
 * @param vector1 The first Vector2 to check.
 * @param vector2 The second Vector2 to check.
 * @param message (Optional) The message to provide on failed assertions.
 * @param p1 (Optional) The first parameter in the message.
 * @param p2 (Optional) The second parameter in the message.
 * @param p3 (Optional) The third parameter in the message.
 * @param p4 (Optional) The fourth parameter in the message.
 */
#define AssertVector2Same(...) RAYLIB_ASSERT_VA_SELECT(AssertVector2Same, __VA_ARGS__)

/**
 * Assert whether two Vector3s are the same.
 *
 * @param vector1 The first Vector3 to check.
 * @param vector2 The second Vector3 to check.
 * @param message (Optional) The message to provide on failed assertions.
 * @param p1 (Optional) The first parameter in the message.
 * @param p2 (Optional) The second parameter in the message.
 * @param p3 (Optional) The third parameter in the message.
 * @param p4 (Optional) The fourth parameter in the message.
 */
#define AssertVector3Same(...) RAYLIB_ASSERT_VA_SELECT(AssertVector3Same, __VA_ARGS__)

/**
 * Assert whether two Vector4s are the same.
 *
 * @param vector1 The first Vector4 to check.
 * @param vector2 The second Vector4 to check.
 * @param message (Optional) The message to provide on failed assertions.
 * @param p1 (Optional) The first parameter in the message.
 * @param p2 (Optional) The second parameter in the message.
 * @param p3 (Optional) The third parameter in the message.
 * @param p4 (Optional) The fourth parameter in the message.
 */
#define AssertVector4Same(...) RAYLIB_ASSERT_VA_SELECT(AssertVector4Same, __VA_ARGS__)

/**
 * Assert whether two Rectangles are the same.
 *
 * @param rect1 The first Rectangle to check.
 * @param rect2 The second Rectangle to check.
 * @param message (Optional) The message to provide on failed assertions.
 * @param p1 (Optional) The first parameter in the message.
 * @param p2 (Optional) The second parameter in the message.
 * @param p3 (Optional) The third parameter in the message.
 * @param p4 (Optional) The fourth parameter in the message.
 */
#define AssertRectangleSame(...) RAYLIB_ASSERT_VA_SELECT(AssertRectangleSame, __VA_ARGS__)

/**
 * Assert whether the given pointer is NULL.
 *
 * @param ptr The pointer expected to be NULL.
 * @param message (Optional) The message to provide on failed assertions.
 * @param p1 (Optional) The first parameter in the message.
 * @param p2 (Optional) The second parameter in the message.
 * @param p3 (Optional) The third parameter in the message.
 * @param p4 (Optional) The fourth parameter in the message.
 * @param p5 (Optional) The fifth parameter in the message.
 */
#define AssertNull(...) RAYLIB_ASSERT_VA_SELECT(AssertNull, __VA_ARGS__)

/**
 * Assert whether the given pointer is not NULL.
 *
 * @param ptr The pointer expected to not be NULL.
 * @param message (Optional) The message to provide on failed assertions.
 * @param p1 (Optional) The first parameter in the message.
 * @param p2 (Optional) The second parameter in the message.
 * @param p3 (Optional) The third parameter in the message.
 * @param p4 (Optional) The fourth parameter in the message.
 * @param p5 (Optional) The fifth parameter in the message.
 */
#define AssertNotNull(...) RAYLIB_ASSERT_VA_SELECT(AssertNotNull, __VA_ARGS__)

/**
 * Assert whether two strings are equal.
 *
 * @param str1 The first string to compare.
 * @param str2 The second string to compare.
 * @param message (Optional) The message to provide on failed assertions.
 * @param p1 (Optional) The first parameter in the message.
 * @param p2 (Optional) The second parameter in the message.
 * @param p3 (Optional) The third parameter in the message.
 * @param p4 (Optional) The fourth parameter in the message.
 */
#define AssertStringEqual(...) RAYLIB_ASSERT_VA_SELECT(AssertStringEqual, __VA_ARGS__)

/**
 * Assert whether the actual value is greater than the expected value.
 *
 * @param actual The actual value.
 * @param expected The value that actual must exceed.
 * @param message (Optional) The message to provide on failed assertions.
 * @param p1 (Optional) The first parameter in the message.
 * @param p2 (Optional) The second parameter in the message.
 * @param p3 (Optional) The third parameter in the message.
 * @param p4 (Optional) The fourth parameter in the message.
 */
#define AssertGreater(...) RAYLIB_ASSERT_VA_SELECT(AssertGreater, __VA_ARGS__)

/**
 * Assert whether the actual value is less than the expected value.
 *
 * @param actual The actual value.
 * @param expected The value that actual must be less than.
 * @param message (Optional) The message to provide on failed assertions.
 * @param p1 (Optional) The first parameter in the message.
 * @param p2 (Optional) The second parameter in the message.
 * @param p3 (Optional) The third parameter in the message.
 * @param p4 (Optional) The fourth parameter in the message.
 */
#define AssertLess(...) RAYLIB_ASSERT_VA_SELECT(AssertLess, __VA_ARGS__)

/**
 * Assert whether the actual value is greater than or equal to the expected value.
 *
 * @param actual The actual value.
 * @param expected The value that actual must be greater than or equal to.
 * @param message (Optional) The message to provide on failed assertions.
 * @param p1 (Optional) The first parameter in the message.
 * @param p2 (Optional) The second parameter in the message.
 * @param p3 (Optional) The third parameter in the message.
 * @param p4 (Optional) The fourth parameter in the message.
 */
#define AssertGreaterEqual(...) RAYLIB_ASSERT_VA_SELECT(AssertGreaterEqual, __VA_ARGS__)

/**
 * Assert whether the actual value is less than or equal to the expected value.
 *
 * @param actual The actual value.
 * @param expected The value that actual must be less than or equal to.
 * @param message (Optional) The message to provide on failed assertions.
 * @param p1 (Optional) The first parameter in the message.
 * @param p2 (Optional) The second parameter in the message.
 * @param p3 (Optional) The third parameter in the message.
 * @param p4 (Optional) The fourth parameter in the message.
 */
#define AssertLessEqual(...) RAYLIB_ASSERT_VA_SELECT(AssertLessEqual, __VA_ARGS__)

/**
 * Assert whether two floats are equal within RAYLIB_ASSERT_EPSILON.
 *
 * @param actual The actual float value.
 * @param expected The expected float value.
 * @param message (Optional) The message to provide on failed assertions.
 * @param p1 (Optional) The first parameter in the message.
 * @param p2 (Optional) The second parameter in the message.
 * @param p3 (Optional) The third parameter in the message.
 * @param p4 (Optional) The fourth parameter in the message.
 */
#define AssertFloatEqual(...) RAYLIB_ASSERT_VA_SELECT(AssertFloatEqual, __VA_ARGS__)

/**
 * Assert whether a value is within an inclusive range [min, max].
 *
 * @param value The value to check.
 * @param min The minimum allowed value (inclusive).
 * @param max The maximum allowed value (inclusive).
 * @param message (Optional) The message to provide on failed assertions.
 * @param p1 (Optional) The first parameter in the message.
 * @param p2 (Optional) The second parameter in the message.
 * @param p3 (Optional) The third parameter in the message.
 */
#define AssertInRange(...) RAYLIB_ASSERT_VA_SELECT(AssertInRange, __VA_ARGS__)

/**
 * Assert whether two strings are not equal.
 *
 * @param str1 The first string to compare.
 * @param str2 The second string to compare.
 * @param message (Optional) The message to provide on failed assertions.
 * @param p1 (Optional) The first parameter in the message.
 * @param p2 (Optional) The second parameter in the message.
 * @param p3 (Optional) The third parameter in the message.
 * @param p4 (Optional) The fourth parameter in the message.
 */
#define AssertStringNotEqual(...) RAYLIB_ASSERT_VA_SELECT(AssertStringNotEqual, __VA_ARGS__)

/**
 * Assert whether a texture is loaded.
 *
 * @param texture The texture to check for valid data.
 * @param message (Optional) The message to provide on failed assertions.
 * @param p1 (Optional) The first parameter in the message.
 * @param p2 (Optional) The second parameter in the message.
 * @param p3 (Optional) The third parameter in the message.
 * @param p4 (Optional) The fourth parameter in the message.
 * @param p5 (Optional) The fifth parameter in the message.
 */
#define AssertTexture(...) RAYLIB_ASSERT_VA_SELECT(AssertTexture, __VA_ARGS__)

/**
 * Assert whether a mesh contains valid CPU-side geometry data.
 *
 * @param mesh The mesh to check for valid data.
 * @param message (Optional) The message to provide on failed assertions.
 * @param p1 (Optional) The first parameter in the message.
 * @param p2 (Optional) The second parameter in the message.
 * @param p3 (Optional) The third parameter in the message.
 * @param p4 (Optional) The fourth parameter in the message.
 * @param p5 (Optional) The fifth parameter in the message.
 */
#define AssertMesh(...) RAYLIB_ASSERT_VA_SELECT(AssertMesh, __VA_ARGS__)

/**
 * Assert whether a material is loaded.
 *
 * @param material The material to check for valid data.
 * @param message (Optional) The message to provide on failed assertions.
 * @param p1 (Optional) The first parameter in the message.
 * @param p2 (Optional) The second parameter in the message.
 * @param p3 (Optional) The third parameter in the message.
 * @param p4 (Optional) The fourth parameter in the message.
 * @param p5 (Optional) The fifth parameter in the message.
 */
#define AssertMaterial(...) RAYLIB_ASSERT_VA_SELECT(AssertMaterial, __VA_ARGS__)

/**
 * Assert whether a render texture is loaded.
 *
 * @param target The render texture to check for valid data.
 * @param message (Optional) The message to provide on failed assertions.
 * @param p1 (Optional) The first parameter in the message.
 * @param p2 (Optional) The second parameter in the message.
 * @param p3 (Optional) The third parameter in the message.
 * @param p4 (Optional) The fourth parameter in the message.
 * @param p5 (Optional) The fifth parameter in the message.
 */
#define AssertRenderTexture(...) RAYLIB_ASSERT_VA_SELECT(AssertRenderTexture, __VA_ARGS__)

/**
 * Assert whether a font is loaded.
 *
 * @param font The font to check for valid data.
 * @param message (Optional) The message to provide on failed assertions.
 * @param p1 (Optional) The first parameter in the message.
 * @param p2 (Optional) The second parameter in the message.
 * @param p3 (Optional) The third parameter in the message.
 * @param p4 (Optional) The fourth parameter in the message.
 * @param p5 (Optional) The fifth parameter in the message.
 */
#define AssertFont(...) RAYLIB_ASSERT_VA_SELECT(AssertFont, __VA_ARGS__)

/**
 * Assert whether a shader is loaded.
 *
 * @param shader The shader to check for valid data.
 * @param message (Optional) The message to provide on failed assertions.
 * @param p1 (Optional) The first parameter in the message.
 * @param p2 (Optional) The second parameter in the message.
 * @param p3 (Optional) The third parameter in the message.
 * @param p4 (Optional) The fourth parameter in the message.
 * @param p5 (Optional) The fifth parameter in the message.
 */
#define AssertShader(...) RAYLIB_ASSERT_VA_SELECT(AssertShader, __VA_ARGS__)

/**
 * Assert whether a model is loaded.
 *
 * @param model The model to check for valid data.
 * @param message (Optional) The message to provide on failed assertions.
 * @param p1 (Optional) The first parameter in the message.
 * @param p2 (Optional) The second parameter in the message.
 * @param p3 (Optional) The third parameter in the message.
 * @param p4 (Optional) The fourth parameter in the message.
 * @param p5 (Optional) The fifth parameter in the message.
 */
#define AssertModel(...) RAYLIB_ASSERT_VA_SELECT(AssertModel, __VA_ARGS__)

/**
 * Assert whether a model animation is valid for a given model.
 *
 * @param model The model to validate against.
 * @param animation The animation to check.
 * @param message (Optional) The message to provide on failed assertions.
 * @param p1 (Optional) The first parameter in the message.
 * @param p2 (Optional) The second parameter in the message.
 * @param p3 (Optional) The third parameter in the message.
 * @param p4 (Optional) The fourth parameter in the message.
 */
#define AssertModelAnimation(...) RAYLIB_ASSERT_VA_SELECT(AssertModelAnimation, __VA_ARGS__)

/**
 * Assert whether a wave is loaded.
 *
 * @param wave The wave to check for valid data.
 * @param message (Optional) The message to provide on failed assertions.
 * @param p1 (Optional) The first parameter in the message.
 * @param p2 (Optional) The second parameter in the message.
 * @param p3 (Optional) The third parameter in the message.
 * @param p4 (Optional) The fourth parameter in the message.
 * @param p5 (Optional) The fifth parameter in the message.
 */
#define AssertWave(...) RAYLIB_ASSERT_VA_SELECT(AssertWave, __VA_ARGS__)

/**
 * Assert whether a sound is loaded.
 *
 * @param sound The sound to check for valid data.
 * @param message (Optional) The message to provide on failed assertions.
 * @param p1 (Optional) The first parameter in the message.
 * @param p2 (Optional) The second parameter in the message.
 * @param p3 (Optional) The third parameter in the message.
 * @param p4 (Optional) The fourth parameter in the message.
 * @param p5 (Optional) The fifth parameter in the message.
 */
#define AssertSound(...) RAYLIB_ASSERT_VA_SELECT(AssertSound, __VA_ARGS__)

/**
 * Assert whether a music stream is loaded.
 *
 * @param music The music to check for valid data.
 * @param message (Optional) The message to provide on failed assertions.
 * @param p1 (Optional) The first parameter in the message.
 * @param p2 (Optional) The second parameter in the message.
 * @param p3 (Optional) The third parameter in the message.
 * @param p4 (Optional) The fourth parameter in the message.
 * @param p5 (Optional) The fifth parameter in the message.
 */
#define AssertMusic(...) RAYLIB_ASSERT_VA_SELECT(AssertMusic, __VA_ARGS__)

/**
 * Assert whether an audio stream is loaded.
 *
 * @param stream The audio stream to check for valid data.
 * @param message (Optional) The message to provide on failed assertions.
 * @param p1 (Optional) The first parameter in the message.
 * @param p2 (Optional) The second parameter in the message.
 * @param p3 (Optional) The third parameter in the message.
 * @param p4 (Optional) The fourth parameter in the message.
 * @param p5 (Optional) The fifth parameter in the message.
 */
#define AssertAudioStream(...) RAYLIB_ASSERT_VA_SELECT(AssertAudioStream, __VA_ARGS__)

// Assert()
#ifdef RAYLIB_ASSERT_NDEBUG
#define Assert_0()
#define Assert_1(condition)
#define Assert_2(condition, message)
#define Assert_3(condition, message, p1)
#define Assert_4(condition, message, p1, p2)
#define Assert_5(condition, message, p1, p2, p3)
#define Assert_6(condition, message, p1, p2, p3, p4)
#define Assert_7(condition, message, p1, p2, p3, p4, p5)
#else
#define Assert_0() AssertFail_1("No condition provided for Assert()")
#define Assert_1(condition) Assert_2(condition, #condition)
#define Assert_2(condition, message) do { if (!((bool)(condition))) { RAYLIB_ASSERT_TRACELOG(RAYLIB_ASSERT_LOG, "ASSERT: %s (%s:%i)", message, __FILE__, __LINE__); } } while(0)
#define Assert_3(condition, message, p1) Assert_2(condition, RAYLIB_ASSERT_TEXTFORMAT(message, p1))
#define Assert_4(condition, message, p1, p2) Assert_2(condition, RAYLIB_ASSERT_TEXTFORMAT(message, p1, p2))
#define Assert_5(condition, message, p1, p2, p3) Assert_2(condition, RAYLIB_ASSERT_TEXTFORMAT(message, p1, p2, p3))
#define Assert_6(condition, message, p1, p2, p3, p4) Assert_2(condition, RAYLIB_ASSERT_TEXTFORMAT(message, p1, p2, p3, p4))
#define Assert_7(condition, message, p1, p2, p3, p4, p5) Assert_2(condition, RAYLIB_ASSERT_TEXTFORMAT(message, p1, p2, p3, p4, p5))
#endif

// AssertEqual()
#define AssertEqual_0() AssertFail_1("No condition provided for AssertEqual()")
#define AssertEqual_1(condition) AssertFail_1("AssertEqual() requires at least two parameters.")
#define AssertEqual_2(actual, expected) Assert_4((actual) == (expected), "AssertEqual(%s, %s) - Provided arguments are not equal", #actual, #expected)
#define AssertEqual_3(actual, expected, message) Assert_2((actual) == (expected), message)
#define AssertEqual_4(actual, expected, message, p1) Assert_3((actual) == (expected), message, p1)
#define AssertEqual_5(actual, expected, message, p1, p2) Assert_4((actual) == (expected), message, p1, p2)
#define AssertEqual_6(actual, expected, message, p1, p2, p3) Assert_5((actual) == (expected), message, p1, p2, p3)
#define AssertEqual_7(actual, expected, message, p1, p2, p3, p4) Assert_6((actual) == (expected), message, p1, p2, p3, p4)

// AssertNotEqual()
#define AssertNotEqual_0() AssertFail_1("No condition provided for AssertNotEqual()")
#define AssertNotEqual_1(condition) AssertFail_1("AssertNotEqual() requires at least two parameters.")
#define AssertNotEqual_2(actual, expected) Assert_4((actual) != (expected), "AssertNotEqual(%s, %s) - Provided arguments are equal", #actual, #expected)
#define AssertNotEqual_3(actual, expected, message) Assert_2((actual) != (expected), message)
#define AssertNotEqual_4(actual, expected, message, p1) Assert_3((actual) != (expected), message, p1)
#define AssertNotEqual_5(actual, expected, message, p1, p2) Assert_4((actual) != (expected), message, p1, p2)
#define AssertNotEqual_6(actual, expected, message, p1, p2, p3) Assert_5((actual) != (expected), message, p1, p2, p3)
#define AssertNotEqual_7(actual, expected, message, p1, p2, p3, p4) Assert_6((actual) != (expected), message, p1, p2, p3, p4)

// AssertNot()
#define AssertNot_0() AssertFail_1("No condition provided for AssertNot()")
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
#define AssertFail_0() RAYLIB_ASSERT_TRACELOG(RAYLIB_ASSERT_LOG, "ASSERT: AssertFail() (%s:%i)", __FILE__, __LINE__)
#define AssertFail_1(message) RAYLIB_ASSERT_TRACELOG(RAYLIB_ASSERT_LOG, "ASSERT: %s (%s:%i)", message, __FILE__, __LINE__)
#define AssertFail_2(message, p1) AssertFail_1(RAYLIB_ASSERT_TEXTFORMAT(message, p1))
#define AssertFail_3(message, p1, p2) AssertFail_1(RAYLIB_ASSERT_TEXTFORMAT(message, p1, p2))
#define AssertFail_4(message, p1, p2, p3) AssertFail_1(RAYLIB_ASSERT_TEXTFORMAT(message, p1, p2, p3))
#define AssertFail_5(message, p1, p2, p3, p4) AssertFail_1(RAYLIB_ASSERT_TEXTFORMAT(message, p1, p2, p3, p4))
#define AssertFail_6(message, p1, p2, p3, p4, p5) AssertFail_1(RAYLIB_ASSERT_TEXTFORMAT(message, p1, p2, p3, p4, p5))
#define AssertFail_7(message, p1, p2, p3, p4, p5, p6) AssertFail_1(RAYLIB_ASSERT_TEXTFORMAT(message, p1, p2, p3, p4, p5, p6))
#endif

// AssertImage()
#define AssertImage_0() AssertFail_1("No image provided for AssertImage()")
#define AssertImage_1(image) Assert_3(IsImageValid(image), "AssertImage(%s) - Image not loaded", #image)
#define AssertImage_2(image, message) Assert_2(IsImageValid(image), message)
#define AssertImage_3(image, message, p1) Assert_3(IsImageValid(image), message, p1)
#define AssertImage_4(image, message, p1, p2) Assert_4(IsImageValid(image), message, p1, p2)
#define AssertImage_5(image, message, p1, p2, p3) Assert_5(IsImageValid(image), message, p1, p2, p3)
#define AssertImage_6(image, message, p1, p2, p3, p4) Assert_6(IsImageValid(image), message, p1, p2, p3, p4)
#define AssertImage_7(image, message, p1, p2, p3, p4, p5) Assert_7(IsImageValid(image), message, p1, p2, p3, p4, p5)

// AssertImageSize()
#define AssertImageSize_0() AssertFail_1("No image provided for AssertImageSize()")
#define AssertImageSize_1(image) AssertFail_1("Expected image, width, and height for AssertImageSize()")
#define AssertImageSize_2(image, expectedWidth) AssertFail_1("Expected image, width, and height for AssertImageSize()")
#define AssertImageSize_3(image, expectedWidth, expectedHeight) AssertImageSize_7(image, expectedWidth, expectedHeight, "AssertImageSize(%s, %s, %s) - Image size does not match", #image, #expectedWidth, #expectedHeight)
#define AssertImageSize_4(image, expectedWidth, expectedHeight, message) Assert_2((image).width == (expectedWidth) && (image).height == (expectedHeight), message)
#define AssertImageSize_5(image, expectedWidth, expectedHeight, message, p1) Assert_3((image).width == (expectedWidth) && (image).height == (expectedHeight), message, p1)
#define AssertImageSize_6(image, expectedWidth, expectedHeight, message, p1, p2) Assert_4((image).width == (expectedWidth) && (image).height == (expectedHeight), message, p1, p2)
#define AssertImageSize_7(image, expectedWidth, expectedHeight, message, p1, p2, p3) Assert_5((image).width == (expectedWidth) && (image).height == (expectedHeight), message, p1, p2, p3)

// AssertTexture()
#define AssertTexture_0() AssertFail_1("No texture provided for AssertTexture()")
#define AssertTexture_1(texture) Assert_3(IsTextureValid(texture), "AssertTexture(%s) - Texture not loaded", #texture)
#define AssertTexture_2(texture, message) Assert_2(IsTextureValid(texture), message)
#define AssertTexture_3(texture, message, p1) Assert_3(IsTextureValid(texture), message, p1)
#define AssertTexture_4(texture, message, p1, p2) Assert_4(IsTextureValid(texture), message, p1, p2)
#define AssertTexture_5(texture, message, p1, p2, p3) Assert_5(IsTextureValid(texture), message, p1, p2, p3)
#define AssertTexture_6(texture, message, p1, p2, p3, p4) Assert_6(IsTextureValid(texture), message, p1, p2, p3, p4)
#define AssertTexture_7(texture, message, p1, p2, p3, p4, p5) Assert_7(IsTextureValid(texture), message, p1, p2, p3, p4, p5)

// AssertMesh()
#define AssertMesh_0() AssertFail_1("No mesh provided for AssertMesh()")
#define AssertMesh_1(mesh) Assert_3(RAYLIB_ASSERT_MESH_VALID(mesh), "AssertMesh(%s) - Mesh not loaded", #mesh)
#define AssertMesh_2(mesh, message) Assert_2(RAYLIB_ASSERT_MESH_VALID(mesh), message)
#define AssertMesh_3(mesh, message, p1) Assert_3(RAYLIB_ASSERT_MESH_VALID(mesh), message, p1)
#define AssertMesh_4(mesh, message, p1, p2) Assert_4(RAYLIB_ASSERT_MESH_VALID(mesh), message, p1, p2)
#define AssertMesh_5(mesh, message, p1, p2, p3) Assert_5(RAYLIB_ASSERT_MESH_VALID(mesh), message, p1, p2, p3)
#define AssertMesh_6(mesh, message, p1, p2, p3, p4) Assert_6(RAYLIB_ASSERT_MESH_VALID(mesh), message, p1, p2, p3, p4)
#define AssertMesh_7(mesh, message, p1, p2, p3, p4, p5) Assert_7(RAYLIB_ASSERT_MESH_VALID(mesh), message, p1, p2, p3, p4, p5)

// AssertMaterial()
#define AssertMaterial_0() AssertFail_1("No material provided for AssertMaterial()")
#define AssertMaterial_1(material) Assert_3(IsMaterialValid(material), "AssertMaterial(%s) - Material not loaded", #material)
#define AssertMaterial_2(material, message) Assert_2(IsMaterialValid(material), message)
#define AssertMaterial_3(material, message, p1) Assert_3(IsMaterialValid(material), message, p1)
#define AssertMaterial_4(material, message, p1, p2) Assert_4(IsMaterialValid(material), message, p1, p2)
#define AssertMaterial_5(material, message, p1, p2, p3) Assert_5(IsMaterialValid(material), message, p1, p2, p3)
#define AssertMaterial_6(material, message, p1, p2, p3, p4) Assert_6(IsMaterialValid(material), message, p1, p2, p3, p4)
#define AssertMaterial_7(material, message, p1, p2, p3, p4, p5) Assert_7(IsMaterialValid(material), message, p1, p2, p3, p4, p5)

// AssertImageSame()
#ifdef RAYLIB_ASSERT_NDEBUG
#define AssertImageSame_0()
#define AssertImageSame_1(image)
#define AssertImageSame_2(image1, image2)
#define AssertImageSame_3(image1, image2, message)
#define AssertImageSame_4(image1, image2, message, p1)
#define AssertImageSame_5(image1, image2, message, p1, p2)
#define AssertImageSame_6(image1, image2, message, p1, p2, p3)
#define AssertImageSame_7(image1, image2, message, p1, p2, p3, p4)
#else
#define AssertImageSame_0() AssertFail_1("AssertImageSame(): No images provided to AssertImageSame(), expected 2")
#define AssertImageSame_1(image) AssertFail_1("Only one image provided for AssertImageSame()")
#define AssertImageSame_2(image1, image2) AssertImageSame_5(image1, image2, "AssertImageSame(%s, %s) - Images do not match", #image1, #image2)
#define AssertImageSame_3(image1, image2, message) do { \
    Image raylibAssertImage1 = (image1); \
    Image raylibAssertImage2 = (image2); \
    if (raylibAssertImage1.width != raylibAssertImage2.width || raylibAssertImage1.height != raylibAssertImage2.height || raylibAssertImage1.format != raylibAssertImage2.format) { \
        AssertFail_1(message); \
        break; \
    } \
    Color* colors1 = LoadImageColors(raylibAssertImage1); \
    Color* colors2 = LoadImageColors(raylibAssertImage2); \
    bool failure = false; \
    for (int i = 0; i < raylibAssertImage1.width * raylibAssertImage1.height; i++) { \
        Color color1 = colors1[i]; \
        Color color2 = colors2[i]; \
        if (color1.r != color2.r || color1.g != color2.g || color1.b != color2.b || color1.a != color2.a) { \
            failure = true; \
            break; \
        } \
    } \
    UnloadImageColors(colors1); \
    UnloadImageColors(colors2); \
    if (failure) { \
        AssertFail_1(message); \
    } \
} while(0)
#define AssertImageSame_4(image1, image2, message, p1) AssertImageSame_3(image1, image2, RAYLIB_ASSERT_TEXTFORMAT(message, p1))
#define AssertImageSame_5(image1, image2, message, p1, p2) AssertImageSame_3(image1, image2, RAYLIB_ASSERT_TEXTFORMAT(message, p1, p2))
#define AssertImageSame_6(image1, image2, message, p1, p2, p3) AssertImageSame_3(image1, image2, RAYLIB_ASSERT_TEXTFORMAT(message, p1, p2, p3))
#define AssertImageSame_7(image1, image2, message, p1, p2, p3, p4) AssertImageSame_3(image1, image2, RAYLIB_ASSERT_TEXTFORMAT(message, p1, p2, p3, p4))
#endif

// AssertColorSame()
#ifdef RAYLIB_ASSERT_NDEBUG
#define AssertColorSame_0()
#define AssertColorSame_1(color)
#define AssertColorSame_2(color1, color2)
#define AssertColorSame_3(color1, color2, message)
#define AssertColorSame_4(color1, color2, message, p1)
#define AssertColorSame_5(color1, color2, message, p1, p2)
#define AssertColorSame_6(color1, color2, message, p1, p2, p3)
#define AssertColorSame_7(color1, color2, message, p1, p2, p3, p4)
#else
#define AssertColorSame_0() AssertFail_1("Colors not provided to AssertColorSame()")
#define AssertColorSame_1(color) AssertFail_1("Expected two colors for AssertColorSame()")
#define AssertColorSame_2(color1, color2) AssertColorSame_5(color1, color2, "AssertColorSame(%s, %s) - Colors do not match", #color1, #color2)
#define AssertColorSame_3(color1, color2, message) do { \
    Color raylibAssertColor1 = (color1); \
    Color raylibAssertColor2 = (color2); \
    if (raylibAssertColor1.r != raylibAssertColor2.r || raylibAssertColor1.g != raylibAssertColor2.g || raylibAssertColor1.b != raylibAssertColor2.b || raylibAssertColor1.a != raylibAssertColor2.a) { \
        AssertFail_1(message); \
    }\
} while (0)
#define AssertColorSame_4(color1, color2, message, p1) AssertColorSame_3(color1, color2, RAYLIB_ASSERT_TEXTFORMAT(message, p1))
#define AssertColorSame_5(color1, color2, message, p1, p2) AssertColorSame_3(color1, color2, RAYLIB_ASSERT_TEXTFORMAT(message, p1, p2))
#define AssertColorSame_6(color1, color2, message, p1, p2, p3) AssertColorSame_3(color1, color2, RAYLIB_ASSERT_TEXTFORMAT(message, p1, p2, p3))
#define AssertColorSame_7(color1, color2, message, p1, p2, p3, p4) AssertColorSame_3(color1, color2, RAYLIB_ASSERT_TEXTFORMAT(message, p1, p2, p3, p4))
#endif

// AssertColorApprox()
#ifdef RAYLIB_ASSERT_NDEBUG
#define AssertColorApprox_0()
#define AssertColorApprox_1(color)
#define AssertColorApprox_2(color1, color2)
#define AssertColorApprox_3(color1, color2, tolerance)
#define AssertColorApprox_4(color1, color2, tolerance, message)
#define AssertColorApprox_5(color1, color2, tolerance, message, p1)
#define AssertColorApprox_6(color1, color2, tolerance, message, p1, p2)
#define AssertColorApprox_7(color1, color2, tolerance, message, p1, p2, p3)
#else
#define AssertColorApprox_0() AssertFail_1("Colors not provided to AssertColorApprox()")
#define AssertColorApprox_1(color) AssertFail_1("Expected two colors and a tolerance for AssertColorApprox()")
#define AssertColorApprox_2(color1, color2) AssertFail_1("Expected two colors and a tolerance for AssertColorApprox()")
#define AssertColorApprox_3(color1, color2, tolerance) AssertColorApprox_7(color1, color2, tolerance, "AssertColorApprox(%s, %s, %s) - Colors differ beyond tolerance", #color1, #color2, #tolerance)
#define AssertColorApprox_4(color1, color2, tolerance, message) do { \
    Color raylibAssertColor1 = (color1); \
    Color raylibAssertColor2 = (color2); \
    int raylibAssertTolerance = (int)(tolerance); \
    if (!RAYLIB_ASSERT_CHANNEL_WITHIN(raylibAssertColor1.r, raylibAssertColor2.r, raylibAssertTolerance) || !RAYLIB_ASSERT_CHANNEL_WITHIN(raylibAssertColor1.g, raylibAssertColor2.g, raylibAssertTolerance) || !RAYLIB_ASSERT_CHANNEL_WITHIN(raylibAssertColor1.b, raylibAssertColor2.b, raylibAssertTolerance) || !RAYLIB_ASSERT_CHANNEL_WITHIN(raylibAssertColor1.a, raylibAssertColor2.a, raylibAssertTolerance)) { \
        AssertFail_1(message); \
    }\
} while (0)
#define AssertColorApprox_5(color1, color2, tolerance, message, p1) AssertColorApprox_4(color1, color2, tolerance, RAYLIB_ASSERT_TEXTFORMAT(message, p1))
#define AssertColorApprox_6(color1, color2, tolerance, message, p1, p2) AssertColorApprox_4(color1, color2, tolerance, RAYLIB_ASSERT_TEXTFORMAT(message, p1, p2))
#define AssertColorApprox_7(color1, color2, tolerance, message, p1, p2, p3) AssertColorApprox_4(color1, color2, tolerance, RAYLIB_ASSERT_TEXTFORMAT(message, p1, p2, p3))
#endif

// AssertVector2Same()
#ifdef RAYLIB_ASSERT_NDEBUG
#define AssertVector2Same_0()
#define AssertVector2Same_1(vector)
#define AssertVector2Same_2(vector1, vector2)
#define AssertVector2Same_3(vector1, vector2, message)
#define AssertVector2Same_4(vector1, vector2, message, p1)
#define AssertVector2Same_5(vector1, vector2, message, p1, p2)
#define AssertVector2Same_6(vector1, vector2, message, p1, p2, p3)
#define AssertVector2Same_7(vector1, vector2, message, p1, p2, p3, p4)
#else
#define AssertVector2Same_0() AssertFail_1("Vectors not provided to AssertVector2Same()")
#define AssertVector2Same_1(vector) AssertFail_1("Expected two vectors for AssertVector2Same()")
#define AssertVector2Same_2(vector1, vector2) AssertVector2Same_5(vector1, vector2, "AssertVector2Same(%s, %s) - vectors do not match", #vector1, #vector2)
#define AssertVector2Same_3(vector1, vector2, message) do { \
    Vector2 raylibAssertVector1 = (vector1); \
    Vector2 raylibAssertVector2 = (vector2); \
    if (!RAYLIB_ASSERT_FLOAT_EQ(raylibAssertVector1.x, raylibAssertVector2.x) || !RAYLIB_ASSERT_FLOAT_EQ(raylibAssertVector1.y, raylibAssertVector2.y)) { \
        AssertFail_1(message); \
    }\
} while (0)
#define AssertVector2Same_4(vector1, vector2, message, p1) AssertVector2Same_3(vector1, vector2, RAYLIB_ASSERT_TEXTFORMAT(message, p1))
#define AssertVector2Same_5(vector1, vector2, message, p1, p2) AssertVector2Same_3(vector1, vector2, RAYLIB_ASSERT_TEXTFORMAT(message, p1, p2))
#define AssertVector2Same_6(vector1, vector2, message, p1, p2, p3) AssertVector2Same_3(vector1, vector2, RAYLIB_ASSERT_TEXTFORMAT(message, p1, p2, p3))
#define AssertVector2Same_7(vector1, vector2, message, p1, p2, p3, p4) AssertVector2Same_3(vector1, vector2, RAYLIB_ASSERT_TEXTFORMAT(message, p1, p2, p3, p4))
#endif

// AssertVector3Same()
#ifdef RAYLIB_ASSERT_NDEBUG
#define AssertVector3Same_0()
#define AssertVector3Same_1(vector)
#define AssertVector3Same_2(vector1, vector2)
#define AssertVector3Same_3(vector1, vector2, message)
#define AssertVector3Same_4(vector1, vector2, message, p1)
#define AssertVector3Same_5(vector1, vector2, message, p1, p2)
#define AssertVector3Same_6(vector1, vector2, message, p1, p2, p3)
#define AssertVector3Same_7(vector1, vector2, message, p1, p2, p3, p4)
#else
#define AssertVector3Same_0() AssertFail_1("Vectors not provided to AssertVector3Same()")
#define AssertVector3Same_1(vector) AssertFail_1("Expected two vectors for AssertVector3Same()")
#define AssertVector3Same_2(vector1, vector2) AssertVector3Same_5(vector1, vector2, "AssertVector3Same(%s, %s) - vectors do not match", #vector1, #vector2)
#define AssertVector3Same_3(vector1, vector2, message) do { \
    Vector3 raylibAssertVector1 = (vector1); \
    Vector3 raylibAssertVector2 = (vector2); \
    if (!RAYLIB_ASSERT_FLOAT_EQ(raylibAssertVector1.x, raylibAssertVector2.x) || !RAYLIB_ASSERT_FLOAT_EQ(raylibAssertVector1.y, raylibAssertVector2.y) || !RAYLIB_ASSERT_FLOAT_EQ(raylibAssertVector1.z, raylibAssertVector2.z)) { \
        AssertFail_1(message); \
    }\
} while (0)
#define AssertVector3Same_4(vector1, vector2, message, p1) AssertVector3Same_3(vector1, vector2, RAYLIB_ASSERT_TEXTFORMAT(message, p1))
#define AssertVector3Same_5(vector1, vector2, message, p1, p2) AssertVector3Same_3(vector1, vector2, RAYLIB_ASSERT_TEXTFORMAT(message, p1, p2))
#define AssertVector3Same_6(vector1, vector2, message, p1, p2, p3) AssertVector3Same_3(vector1, vector2, RAYLIB_ASSERT_TEXTFORMAT(message, p1, p2, p3))
#define AssertVector3Same_7(vector1, vector2, message, p1, p2, p3, p4) AssertVector3Same_3(vector1, vector2, RAYLIB_ASSERT_TEXTFORMAT(message, p1, p2, p3, p4))
#endif

// AssertVector4Same()
#ifdef RAYLIB_ASSERT_NDEBUG
#define AssertVector4Same_0()
#define AssertVector4Same_1(vector)
#define AssertVector4Same_2(vector1, vector2)
#define AssertVector4Same_3(vector1, vector2, message)
#define AssertVector4Same_4(vector1, vector2, message, p1)
#define AssertVector4Same_5(vector1, vector2, message, p1, p2)
#define AssertVector4Same_6(vector1, vector2, message, p1, p2, p3)
#define AssertVector4Same_7(vector1, vector2, message, p1, p2, p3, p4)
#else
#define AssertVector4Same_0() AssertFail_1("Vectors not provided to AssertVector4Same()")
#define AssertVector4Same_1(vector) AssertFail_1("Expected two vectors for AssertVector4Same()")
#define AssertVector4Same_2(vector1, vector2) AssertVector4Same_5(vector1, vector2, "AssertVector4Same(%s, %s) - vectors do not match", #vector1, #vector2)
#define AssertVector4Same_3(vector1, vector2, message) do { \
    Vector4 raylibAssertVector1 = (vector1); \
    Vector4 raylibAssertVector2 = (vector2); \
    if (!RAYLIB_ASSERT_FLOAT_EQ(raylibAssertVector1.x, raylibAssertVector2.x) || !RAYLIB_ASSERT_FLOAT_EQ(raylibAssertVector1.y, raylibAssertVector2.y) || !RAYLIB_ASSERT_FLOAT_EQ(raylibAssertVector1.z, raylibAssertVector2.z) || !RAYLIB_ASSERT_FLOAT_EQ(raylibAssertVector1.w, raylibAssertVector2.w)) { \
        AssertFail_1(message); \
    }\
} while (0)
#define AssertVector4Same_4(vector1, vector2, message, p1) AssertVector4Same_3(vector1, vector2, RAYLIB_ASSERT_TEXTFORMAT(message, p1))
#define AssertVector4Same_5(vector1, vector2, message, p1, p2) AssertVector4Same_3(vector1, vector2, RAYLIB_ASSERT_TEXTFORMAT(message, p1, p2))
#define AssertVector4Same_6(vector1, vector2, message, p1, p2, p3) AssertVector4Same_3(vector1, vector2, RAYLIB_ASSERT_TEXTFORMAT(message, p1, p2, p3))
#define AssertVector4Same_7(vector1, vector2, message, p1, p2, p3, p4) AssertVector4Same_3(vector1, vector2, RAYLIB_ASSERT_TEXTFORMAT(message, p1, p2, p3, p4))
#endif

// AssertRectangleSame()
#ifdef RAYLIB_ASSERT_NDEBUG
#define AssertRectangleSame_0()
#define AssertRectangleSame_1(rect)
#define AssertRectangleSame_2(rect1, rect2)
#define AssertRectangleSame_3(rect1, rect2, message)
#define AssertRectangleSame_4(rect1, rect2, message, p1)
#define AssertRectangleSame_5(rect1, rect2, message, p1, p2)
#define AssertRectangleSame_6(rect1, rect2, message, p1, p2, p3)
#define AssertRectangleSame_7(rect1, rect2, message, p1, p2, p3, p4)
#else
#define AssertRectangleSame_0() AssertFail_1("Rectangles not provided to AssertRectangleSame()")
#define AssertRectangleSame_1(rect) AssertFail_1("Expected two rectangles for AssertRectangleSame()")
#define AssertRectangleSame_2(rect1, rect2) AssertRectangleSame_5(rect1, rect2, "AssertRectangleSame(%s, %s) - rectangles do not match", #rect1, #rect2)
#define AssertRectangleSame_3(rect1, rect2, message) do { \
    Rectangle raylibAssertRect1 = (rect1); \
    Rectangle raylibAssertRect2 = (rect2); \
    if (!RAYLIB_ASSERT_FLOAT_EQ(raylibAssertRect1.x, raylibAssertRect2.x) || !RAYLIB_ASSERT_FLOAT_EQ(raylibAssertRect1.y, raylibAssertRect2.y) || !RAYLIB_ASSERT_FLOAT_EQ(raylibAssertRect1.width, raylibAssertRect2.width) || !RAYLIB_ASSERT_FLOAT_EQ(raylibAssertRect1.height, raylibAssertRect2.height)) { \
        AssertFail_1(message); \
    }\
} while (0)
#define AssertRectangleSame_4(rect1, rect2, message, p1) AssertRectangleSame_3(rect1, rect2, RAYLIB_ASSERT_TEXTFORMAT(message, p1))
#define AssertRectangleSame_5(rect1, rect2, message, p1, p2) AssertRectangleSame_3(rect1, rect2, RAYLIB_ASSERT_TEXTFORMAT(message, p1, p2))
#define AssertRectangleSame_6(rect1, rect2, message, p1, p2, p3) AssertRectangleSame_3(rect1, rect2, RAYLIB_ASSERT_TEXTFORMAT(message, p1, p2, p3))
#define AssertRectangleSame_7(rect1, rect2, message, p1, p2, p3, p4) AssertRectangleSame_3(rect1, rect2, RAYLIB_ASSERT_TEXTFORMAT(message, p1, p2, p3, p4))
#endif

// AssertNull()
#define AssertNull_0() AssertFail_1("No pointer provided for AssertNull()")
#define AssertNull_1(ptr) Assert_3((ptr) == NULL, "AssertNull(%s) - Pointer is not NULL", #ptr)
#define AssertNull_2(ptr, message) Assert_2((ptr) == NULL, message)
#define AssertNull_3(ptr, message, p1) Assert_3((ptr) == NULL, message, p1)
#define AssertNull_4(ptr, message, p1, p2) Assert_4((ptr) == NULL, message, p1, p2)
#define AssertNull_5(ptr, message, p1, p2, p3) Assert_5((ptr) == NULL, message, p1, p2, p3)
#define AssertNull_6(ptr, message, p1, p2, p3, p4) Assert_6((ptr) == NULL, message, p1, p2, p3, p4)
#define AssertNull_7(ptr, message, p1, p2, p3, p4, p5) Assert_7((ptr) == NULL, message, p1, p2, p3, p4, p5)

// AssertNotNull()
#define AssertNotNull_0() AssertFail_1("No pointer provided for AssertNotNull()")
#define AssertNotNull_1(ptr) Assert_3((ptr) != NULL, "AssertNotNull(%s) - Pointer is NULL", #ptr)
#define AssertNotNull_2(ptr, message) Assert_2((ptr) != NULL, message)
#define AssertNotNull_3(ptr, message, p1) Assert_3((ptr) != NULL, message, p1)
#define AssertNotNull_4(ptr, message, p1, p2) Assert_4((ptr) != NULL, message, p1, p2)
#define AssertNotNull_5(ptr, message, p1, p2, p3) Assert_5((ptr) != NULL, message, p1, p2, p3)
#define AssertNotNull_6(ptr, message, p1, p2, p3, p4) Assert_6((ptr) != NULL, message, p1, p2, p3, p4)
#define AssertNotNull_7(ptr, message, p1, p2, p3, p4, p5) Assert_7((ptr) != NULL, message, p1, p2, p3, p4, p5)

// AssertStringEqual()
#define AssertStringEqual_0() AssertFail_1("No strings provided for AssertStringEqual()")
#define AssertStringEqual_1(str) AssertFail_1("Expected two strings for AssertStringEqual()")
#define AssertStringEqual_2(str1, str2) Assert_4(TextIsEqual(str1, str2), "AssertStringEqual(%s, %s) - Strings are not equal", #str1, #str2)
#define AssertStringEqual_3(str1, str2, message) Assert_2(TextIsEqual(str1, str2), message)
#define AssertStringEqual_4(str1, str2, message, p1) Assert_3(TextIsEqual(str1, str2), message, p1)
#define AssertStringEqual_5(str1, str2, message, p1, p2) Assert_4(TextIsEqual(str1, str2), message, p1, p2)
#define AssertStringEqual_6(str1, str2, message, p1, p2, p3) Assert_5(TextIsEqual(str1, str2), message, p1, p2, p3)
#define AssertStringEqual_7(str1, str2, message, p1, p2, p3, p4) Assert_6(TextIsEqual(str1, str2), message, p1, p2, p3, p4)

// AssertGreater()
#define AssertGreater_0() AssertFail_1("No values provided for AssertGreater()")
#define AssertGreater_1(value) AssertFail_1("Expected two values for AssertGreater()")
#define AssertGreater_2(actual, expected) Assert_4((actual) > (expected), "AssertGreater(%s, %s) - Value is not greater than expected", #actual, #expected)
#define AssertGreater_3(actual, expected, message) Assert_2((actual) > (expected), message)
#define AssertGreater_4(actual, expected, message, p1) Assert_3((actual) > (expected), message, p1)
#define AssertGreater_5(actual, expected, message, p1, p2) Assert_4((actual) > (expected), message, p1, p2)
#define AssertGreater_6(actual, expected, message, p1, p2, p3) Assert_5((actual) > (expected), message, p1, p2, p3)
#define AssertGreater_7(actual, expected, message, p1, p2, p3, p4) Assert_6((actual) > (expected), message, p1, p2, p3, p4)

// AssertLess()
#define AssertLess_0() AssertFail_1("No values provided for AssertLess()")
#define AssertLess_1(value) AssertFail_1("Expected two values for AssertLess()")
#define AssertLess_2(actual, expected) Assert_4((actual) < (expected), "AssertLess(%s, %s) - Value is not less than expected", #actual, #expected)
#define AssertLess_3(actual, expected, message) Assert_2((actual) < (expected), message)
#define AssertLess_4(actual, expected, message, p1) Assert_3((actual) < (expected), message, p1)
#define AssertLess_5(actual, expected, message, p1, p2) Assert_4((actual) < (expected), message, p1, p2)
#define AssertLess_6(actual, expected, message, p1, p2, p3) Assert_5((actual) < (expected), message, p1, p2, p3)
#define AssertLess_7(actual, expected, message, p1, p2, p3, p4) Assert_6((actual) < (expected), message, p1, p2, p3, p4)

// AssertGreaterEqual()
#define AssertGreaterEqual_0() AssertFail_1("No values provided for AssertGreaterEqual()")
#define AssertGreaterEqual_1(value) AssertFail_1("Expected two values for AssertGreaterEqual()")
#define AssertGreaterEqual_2(actual, expected) Assert_4((actual) >= (expected), "AssertGreaterEqual(%s, %s) - Value is not greater than or equal to expected", #actual, #expected)
#define AssertGreaterEqual_3(actual, expected, message) Assert_2((actual) >= (expected), message)
#define AssertGreaterEqual_4(actual, expected, message, p1) Assert_3((actual) >= (expected), message, p1)
#define AssertGreaterEqual_5(actual, expected, message, p1, p2) Assert_4((actual) >= (expected), message, p1, p2)
#define AssertGreaterEqual_6(actual, expected, message, p1, p2, p3) Assert_5((actual) >= (expected), message, p1, p2, p3)
#define AssertGreaterEqual_7(actual, expected, message, p1, p2, p3, p4) Assert_6((actual) >= (expected), message, p1, p2, p3, p4)

// AssertLessEqual()
#define AssertLessEqual_0() AssertFail_1("No values provided for AssertLessEqual()")
#define AssertLessEqual_1(value) AssertFail_1("Expected two values for AssertLessEqual()")
#define AssertLessEqual_2(actual, expected) Assert_4((actual) <= (expected), "AssertLessEqual(%s, %s) - Value is not less than or equal to expected", #actual, #expected)
#define AssertLessEqual_3(actual, expected, message) Assert_2((actual) <= (expected), message)
#define AssertLessEqual_4(actual, expected, message, p1) Assert_3((actual) <= (expected), message, p1)
#define AssertLessEqual_5(actual, expected, message, p1, p2) Assert_4((actual) <= (expected), message, p1, p2)
#define AssertLessEqual_6(actual, expected, message, p1, p2, p3) Assert_5((actual) <= (expected), message, p1, p2, p3)
#define AssertLessEqual_7(actual, expected, message, p1, p2, p3, p4) Assert_6((actual) <= (expected), message, p1, p2, p3, p4)

// AssertFloatEqual()
#define AssertFloatEqual_0() AssertFail_1("No values provided for AssertFloatEqual()")
#define AssertFloatEqual_1(value) AssertFail_1("Expected two values for AssertFloatEqual()")
#define AssertFloatEqual_2(actual, expected) Assert_4(RAYLIB_ASSERT_FLOAT_EQ(actual, expected), "AssertFloatEqual(%s, %s) - Floats are not equal within epsilon", #actual, #expected)
#define AssertFloatEqual_3(actual, expected, message) Assert_2(RAYLIB_ASSERT_FLOAT_EQ(actual, expected), message)
#define AssertFloatEqual_4(actual, expected, message, p1) Assert_3(RAYLIB_ASSERT_FLOAT_EQ(actual, expected), message, p1)
#define AssertFloatEqual_5(actual, expected, message, p1, p2) Assert_4(RAYLIB_ASSERT_FLOAT_EQ(actual, expected), message, p1, p2)
#define AssertFloatEqual_6(actual, expected, message, p1, p2, p3) Assert_5(RAYLIB_ASSERT_FLOAT_EQ(actual, expected), message, p1, p2, p3)
#define AssertFloatEqual_7(actual, expected, message, p1, p2, p3, p4) Assert_6(RAYLIB_ASSERT_FLOAT_EQ(actual, expected), message, p1, p2, p3, p4)

// AssertInRange()
#define AssertInRange_0() AssertFail_1("No values provided for AssertInRange()")
#define AssertInRange_1(value) AssertFail_1("Expected three values for AssertInRange()")
#define AssertInRange_2(value, min) AssertFail_1("Expected three values for AssertInRange()")
#define AssertInRange_3(value, min, max) Assert_5((value) >= (min) && (value) <= (max), "AssertInRange(%s, %s, %s) - Value is not within range", #value, #min, #max)
#define AssertInRange_4(value, min, max, message) Assert_2((value) >= (min) && (value) <= (max), message)
#define AssertInRange_5(value, min, max, message, p1) Assert_3((value) >= (min) && (value) <= (max), message, p1)
#define AssertInRange_6(value, min, max, message, p1, p2) Assert_4((value) >= (min) && (value) <= (max), message, p1, p2)
#define AssertInRange_7(value, min, max, message, p1, p2, p3) Assert_5((value) >= (min) && (value) <= (max), message, p1, p2, p3)

// AssertStringNotEqual()
#define AssertStringNotEqual_0() AssertFail_1("No strings provided for AssertStringNotEqual()")
#define AssertStringNotEqual_1(str) AssertFail_1("Expected two strings for AssertStringNotEqual()")
#define AssertStringNotEqual_2(str1, str2) Assert_4(!TextIsEqual(str1, str2), "AssertStringNotEqual(%s, %s) - Strings are equal", #str1, #str2)
#define AssertStringNotEqual_3(str1, str2, message) Assert_2(!TextIsEqual(str1, str2), message)
#define AssertStringNotEqual_4(str1, str2, message, p1) Assert_3(!TextIsEqual(str1, str2), message, p1)
#define AssertStringNotEqual_5(str1, str2, message, p1, p2) Assert_4(!TextIsEqual(str1, str2), message, p1, p2)
#define AssertStringNotEqual_6(str1, str2, message, p1, p2, p3) Assert_5(!TextIsEqual(str1, str2), message, p1, p2, p3)
#define AssertStringNotEqual_7(str1, str2, message, p1, p2, p3, p4) Assert_6(!TextIsEqual(str1, str2), message, p1, p2, p3, p4)

// AssertRenderTexture()
#define AssertRenderTexture_0() AssertFail_1("No render texture provided for AssertRenderTexture()")
#define AssertRenderTexture_1(target) Assert_3(IsRenderTextureValid(target), "AssertRenderTexture(%s) - Render texture not loaded", #target)
#define AssertRenderTexture_2(target, message) Assert_2(IsRenderTextureValid(target), message)
#define AssertRenderTexture_3(target, message, p1) Assert_3(IsRenderTextureValid(target), message, p1)
#define AssertRenderTexture_4(target, message, p1, p2) Assert_4(IsRenderTextureValid(target), message, p1, p2)
#define AssertRenderTexture_5(target, message, p1, p2, p3) Assert_5(IsRenderTextureValid(target), message, p1, p2, p3)
#define AssertRenderTexture_6(target, message, p1, p2, p3, p4) Assert_6(IsRenderTextureValid(target), message, p1, p2, p3, p4)
#define AssertRenderTexture_7(target, message, p1, p2, p3, p4, p5) Assert_7(IsRenderTextureValid(target), message, p1, p2, p3, p4, p5)

// AssertFont()
#define AssertFont_0() AssertFail_1("No font provided for AssertFont()")
#define AssertFont_1(font) Assert_3(IsFontValid(font), "AssertFont(%s) - Font not loaded", #font)
#define AssertFont_2(font, message) Assert_2(IsFontValid(font), message)
#define AssertFont_3(font, message, p1) Assert_3(IsFontValid(font), message, p1)
#define AssertFont_4(font, message, p1, p2) Assert_4(IsFontValid(font), message, p1, p2)
#define AssertFont_5(font, message, p1, p2, p3) Assert_5(IsFontValid(font), message, p1, p2, p3)
#define AssertFont_6(font, message, p1, p2, p3, p4) Assert_6(IsFontValid(font), message, p1, p2, p3, p4)
#define AssertFont_7(font, message, p1, p2, p3, p4, p5) Assert_7(IsFontValid(font), message, p1, p2, p3, p4, p5)

// AssertShader()
#define AssertShader_0() AssertFail_1("No shader provided for AssertShader()")
#define AssertShader_1(shader) Assert_3(IsShaderValid(shader), "AssertShader(%s) - Shader not loaded", #shader)
#define AssertShader_2(shader, message) Assert_2(IsShaderValid(shader), message)
#define AssertShader_3(shader, message, p1) Assert_3(IsShaderValid(shader), message, p1)
#define AssertShader_4(shader, message, p1, p2) Assert_4(IsShaderValid(shader), message, p1, p2)
#define AssertShader_5(shader, message, p1, p2, p3) Assert_5(IsShaderValid(shader), message, p1, p2, p3)
#define AssertShader_6(shader, message, p1, p2, p3, p4) Assert_6(IsShaderValid(shader), message, p1, p2, p3, p4)
#define AssertShader_7(shader, message, p1, p2, p3, p4, p5) Assert_7(IsShaderValid(shader), message, p1, p2, p3, p4, p5)

// AssertModel()
#define AssertModel_0() AssertFail_1("No model provided for AssertModel()")
#define AssertModel_1(model) Assert_3(IsModelValid(model), "AssertModel(%s) - Model not loaded", #model)
#define AssertModel_2(model, message) Assert_2(IsModelValid(model), message)
#define AssertModel_3(model, message, p1) Assert_3(IsModelValid(model), message, p1)
#define AssertModel_4(model, message, p1, p2) Assert_4(IsModelValid(model), message, p1, p2)
#define AssertModel_5(model, message, p1, p2, p3) Assert_5(IsModelValid(model), message, p1, p2, p3)
#define AssertModel_6(model, message, p1, p2, p3, p4) Assert_6(IsModelValid(model), message, p1, p2, p3, p4)
#define AssertModel_7(model, message, p1, p2, p3, p4, p5) Assert_7(IsModelValid(model), message, p1, p2, p3, p4, p5)

// AssertModelAnimation()
#define AssertModelAnimation_0() AssertFail_1("No model or animation provided for AssertModelAnimation()")
#define AssertModelAnimation_1(model) AssertFail_1("Expected model and animation for AssertModelAnimation()")
#define AssertModelAnimation_2(model, animation) Assert_4(IsModelAnimationValid(model, animation), "AssertModelAnimation(%s, %s) - Animation is not valid for model", #model, #animation)
#define AssertModelAnimation_3(model, animation, message) Assert_2(IsModelAnimationValid(model, animation), message)
#define AssertModelAnimation_4(model, animation, message, p1) Assert_3(IsModelAnimationValid(model, animation), message, p1)
#define AssertModelAnimation_5(model, animation, message, p1, p2) Assert_4(IsModelAnimationValid(model, animation), message, p1, p2)
#define AssertModelAnimation_6(model, animation, message, p1, p2, p3) Assert_5(IsModelAnimationValid(model, animation), message, p1, p2, p3)
#define AssertModelAnimation_7(model, animation, message, p1, p2, p3, p4) Assert_6(IsModelAnimationValid(model, animation), message, p1, p2, p3, p4)

// AssertWave()
#define AssertWave_0() AssertFail_1("No wave provided for AssertWave()")
#define AssertWave_1(wave) Assert_3(IsWaveValid(wave), "AssertWave(%s) - Wave not loaded", #wave)
#define AssertWave_2(wave, message) Assert_2(IsWaveValid(wave), message)
#define AssertWave_3(wave, message, p1) Assert_3(IsWaveValid(wave), message, p1)
#define AssertWave_4(wave, message, p1, p2) Assert_4(IsWaveValid(wave), message, p1, p2)
#define AssertWave_5(wave, message, p1, p2, p3) Assert_5(IsWaveValid(wave), message, p1, p2, p3)
#define AssertWave_6(wave, message, p1, p2, p3, p4) Assert_6(IsWaveValid(wave), message, p1, p2, p3, p4)
#define AssertWave_7(wave, message, p1, p2, p3, p4, p5) Assert_7(IsWaveValid(wave), message, p1, p2, p3, p4, p5)

// AssertSound()
#define AssertSound_0() AssertFail_1("No sound provided for AssertSound()")
#define AssertSound_1(sound) Assert_3(IsSoundValid(sound), "AssertSound(%s) - Sound not loaded", #sound)
#define AssertSound_2(sound, message) Assert_2(IsSoundValid(sound), message)
#define AssertSound_3(sound, message, p1) Assert_3(IsSoundValid(sound), message, p1)
#define AssertSound_4(sound, message, p1, p2) Assert_4(IsSoundValid(sound), message, p1, p2)
#define AssertSound_5(sound, message, p1, p2, p3) Assert_5(IsSoundValid(sound), message, p1, p2, p3)
#define AssertSound_6(sound, message, p1, p2, p3, p4) Assert_6(IsSoundValid(sound), message, p1, p2, p3, p4)
#define AssertSound_7(sound, message, p1, p2, p3, p4, p5) Assert_7(IsSoundValid(sound), message, p1, p2, p3, p4, p5)

// AssertMusic()
#define AssertMusic_0() AssertFail_1("No music provided for AssertMusic()")
#define AssertMusic_1(music) Assert_3(IsMusicValid(music), "AssertMusic(%s) - Music not loaded", #music)
#define AssertMusic_2(music, message) Assert_2(IsMusicValid(music), message)
#define AssertMusic_3(music, message, p1) Assert_3(IsMusicValid(music), message, p1)
#define AssertMusic_4(music, message, p1, p2) Assert_4(IsMusicValid(music), message, p1, p2)
#define AssertMusic_5(music, message, p1, p2, p3) Assert_5(IsMusicValid(music), message, p1, p2, p3)
#define AssertMusic_6(music, message, p1, p2, p3, p4) Assert_6(IsMusicValid(music), message, p1, p2, p3, p4)
#define AssertMusic_7(music, message, p1, p2, p3, p4, p5) Assert_7(IsMusicValid(music), message, p1, p2, p3, p4, p5)

// AssertAudioStream()
#define AssertAudioStream_0() AssertFail_1("No audio stream provided for AssertAudioStream()")
#define AssertAudioStream_1(stream) Assert_3(IsAudioStreamValid(stream), "AssertAudioStream(%s) - Audio stream not loaded", #stream)
#define AssertAudioStream_2(stream, message) Assert_2(IsAudioStreamValid(stream), message)
#define AssertAudioStream_3(stream, message, p1) Assert_3(IsAudioStreamValid(stream), message, p1)
#define AssertAudioStream_4(stream, message, p1, p2) Assert_4(IsAudioStreamValid(stream), message, p1, p2)
#define AssertAudioStream_5(stream, message, p1, p2, p3) Assert_5(IsAudioStreamValid(stream), message, p1, p2, p3)
#define AssertAudioStream_6(stream, message, p1, p2, p3, p4) Assert_6(IsAudioStreamValid(stream), message, p1, p2, p3, p4)
#define AssertAudioStream_7(stream, message, p1, p2, p3, p4, p5) Assert_7(IsAudioStreamValid(stream), message, p1, p2, p3, p4, p5)

#ifdef __cplusplus
}
#endif

#endif  // RAYLIB_ASSERT_H
