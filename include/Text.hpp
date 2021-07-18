/**
 * Text drawing functions
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

/**
 * Check if two text string are equal
 */
RLCPPAPI inline unsigned int TextLength(const std::string& text) {
    return ::TextLength(text.c_str());
}

// TODO(RobLoach): Add remaining raylib C functions with string c_str() wrappers.

}  // namespace raylib

#endif  // RAYLIB_CPP_INCLUDE_TEXT_HPP_
