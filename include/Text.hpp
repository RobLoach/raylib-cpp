/*
*   Font Loading and Text Drawing Functions (Module: text)
*
*   LICENSE: zlib/libpng
*
*   raylib-cpp is licensed under an unmodified zlib/libpng license, which is an OSI-certified,
*   BSD-like license that allows static linking with closed source software:
*
*   Copyright (c) 2020 Rob Loach (@RobLoach)
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
*/


#ifndef RAYLIB_CPP_INCLUDE_TEXT_HPP_
#define RAYLIB_CPP_INCLUDE_TEXT_HPP_

#include <string>

#include "./raylib.hpp"

/**
 * Allow changing the declare type for all raylib-cpp global functions. Defaults to static.
 */
#ifndef RLCPPAPI
#define RLCPPAPI static
#endif

namespace raylib {

/**
 * Draw text (using default font)
 */
RLCPPAPI inline void DrawText(
        const std::string& title,
        int posX,
        int posY,
        int fontSize,
        ::Color color) {
    ::DrawText(title.c_str(), posX, posY, fontSize, color);
}

/**
 * Measure string width for default font
 */
RLCPPAPI inline int MeasureText(const std::string& text, int fontSize) {
    return ::MeasureText(text.c_str(), fontSize);
}

/**
 * Check if two text string are equal
 */
RLCPPAPI inline bool TextIsEqual(const std::string& text1, const std::string& text2) {
    return ::TextIsEqual(text1.c_str(), text2.c_str());
}

// TODO(RobLoach): Add remaining raylib C functions with string c_str() wrappers.

}  // namespace raylib

#endif  // RAYLIB_CPP_INCLUDE_TEXT_HPP_
