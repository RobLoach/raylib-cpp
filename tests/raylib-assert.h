/**********************************************************************************************
*
*   raylib-assert - Assertion library for raylib.
*   https://github.com/robloach/raylib-assert
*
*   Version: v2.0.0
*
*   Copyright 2023 Rob Loach (@RobLoach)
*
*   DEPENDENCIES:
*       raylib 4.5+ https://www.raylib.com
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

// Variadic Arguments
#define RAYLIB_ASSERT_CAT( A, B ) A ## B
#define RAYLIB_ASSERT_SELECT( NAME, NUM ) RAYLIB_ASSERT_CAT( NAME ## _, NUM )
#define RAYLIB_ASSERT_GET_COUNT( _1, _2, _3, _4, _5, _6, _7, RAYLIB_ASSERT_COUNT, ... ) RAYLIB_ASSERT_COUNT
#define RAYLIB_ASSERT_VA_SIZE( ... ) RAYLIB_ASSERT_GET_COUNT( __VA_ARGS__, 7, 6, 5, 4, 3, 2, 1 )
#define RAYLIB_ASSERT_VA_SELECT( NAME, ... ) RAYLIB_ASSERT_SELECT( NAME, RAYLIB_ASSERT_VA_SIZE(__VA_ARGS__) )(__VA_ARGS__)

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
#define AssertEqual_1(condition) Assert_2(condition, #condition)
#define AssertEqual_2(actual, expected) Assert_4((actual) == (expected), "AssertEqual(%s, %s) - Provided arguments are not equal", #actual, #expected)
#define AssertEqual_3(actual, expected, message) Assert_2((actual) == (expected), message)
#define AssertEqual_4(actual, expected, message, p1) Assert_3((actual) == (expected), message, p1)
#define AssertEqual_5(actual, expected, message, p1, p2) Assert_4((actual) == (expected), message, p1, p2)
#define AssertEqual_6(actual, expected, message, p1, p2, p3) Assert_5((actual) == (expected), message, p1, p2, p3)
#define AssertEqual_7(actual, expected, message, p1, p2, p3, p4) Assert_6((actual) == (expected), message, p1, p2, p3, p4)

// AssertNotEqual()
#define AssertNotEqual_0() AssertFail_1("No condition provided for AssertNotEqual()")
#define AssertNotEqual_1(condition) AssertNot_2(condition, #condition)
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
#define AssertImage_1(image) Assert_3(IsImageReady(image), "AssertImage(%s) - Image not loaded", #image)
#define AssertImage_2(image, message) Assert_2(IsImageReady(image), message)
#define AssertImage_3(image, message, p1) Assert_3(IsImageReady(image), message, p1)
#define AssertImage_4(image, message, p1, p2) Assert_4(IsImageReady(image), message, p1, p2)
#define AssertImage_5(image, message, p1, p2, p3) Assert_5(IsImageReady(image), message, p1, p2, p3)
#define AssertImage_6(image, message, p1, p2, p3, p4) Assert_6(IsImageReady(image), message, p1, p2, p3, p4)

// AssertTexture()
#define AssertTexture_0() AssertFail_1("No texture provided for AssertTexture()")
#define AssertTexture_1(texture) Assert_3(IsTextureReady(texture), "AssertTexture(%s) - Texture not loaded", #texture)
#define AssertTexture_2(texture, message) Assert_2(IsTextureReady(texture), message)
#define AssertTexture_3(texture, message, p1) Assert_3(IsTextureReady(texture), message, p1)
#define AssertTexture_4(texture, message, p1, p2) Assert_4(IsTextureReady(texture), message, p1, p2)
#define AssertTexture_5(texture, message, p1, p2, p3) Assert_5(IsTextureReady(texture), message, p1, p2, p3)
#define AssertTexture_6(texture, message, p1, p2, p3, p4) Assert_6(IsTextureReady(texture), message, p1, p2, p3, p4)

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
    if (image1.width != image2.width || image1.height != image2.height || image1.format != image2.format) { \
        AssertFail_1(message); \
        break; \
    } \
    Color* colors1 = LoadImageColors(image1); \
    Color* colors2 = LoadImageColors(image2); \
    bool failure = false; \
    for (int i = 0; i < image1.width * image1.height; i++) { \
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
    if (color1.r != color2.r || color1.g != color2.g || color1.b != color2.b || color1.a != color2.a) { \
        AssertFail_1(message); \
    }\
} while (0)
#define AssertColorSame_4(color1, color2, message, p1) AssertColorSame_3(color1, color2, RAYLIB_ASSERT_TEXTFORMAT(message, p1))
#define AssertColorSame_5(color1, color2, message, p1, p2) AssertColorSame_3(color1, color2, RAYLIB_ASSERT_TEXTFORMAT(message, p1, p2))
#define AssertColorSame_6(color1, color2, message, p1, p2, p3) AssertColorSame_3(color1, color2, RAYLIB_ASSERT_TEXTFORMAT(message, p1, p2, p3))
#define AssertColorSame_7(color1, color2, message, p1, p2, p3, p4) AssertColorSame_3(color1, color2, RAYLIB_ASSERT_TEXTFORMAT(message, p1, p2, p3, p4))
#endif

#ifdef __cplusplus
}
#endif

#endif  // RAYLIB_ASSERT_H
