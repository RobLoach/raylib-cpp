#ifndef RAYLIB_CPP_INCLUDE_FONT_HPP_
#define RAYLIB_CPP_INCLUDE_FONT_HPP_

#include "./FontUnmanaged.hpp"

namespace raylib {
/**
 * Font type, includes texture and charSet array data.
 *
 * The font will be unloaded on object destruction. Use raylib::FontUnmanaged if you're looking to not unload.
 *
 * @see raylib::FontUnmanaged
 */
class Font : public FontUnmanaged {
public:
    using FontUnmanaged::FontUnmanaged;

    Font(const Font&) = delete;
    Font& operator=(const Font&) = delete;

    Font(Font&& other) noexcept {
        set(other);
        other.baseSize = 0;
        other.glyphCount = 0;
        other.glyphPadding = 0;
        other.texture = {};
        other.recs = nullptr;
        other.glyphs = nullptr;
    }

    Font& operator=(Font&& other) noexcept {
        if (this == &other) {
            return *this;
        }
        Unload();
        set(other);
        other.baseSize = 0;
        other.glyphCount = 0;
        other.glyphPadding = 0;
        other.texture = {};
        other.recs = nullptr;
        other.glyphs = nullptr;
        return *this;
    }

    Font& operator=(const ::Font& font) {
        Unload();
        set(font);
        return *this;
    }

    ~Font() { Unload(); }

    void Load(const std::string& fileName) {
        Unload();
        FontUnmanaged::Load(fileName);
    }

    void Load(const std::string& fileName, int fontSize, const int* codepoints = nullptr, int codepointCount = 0) {
        Unload();
        FontUnmanaged::Load(fileName, fontSize, codepoints, codepointCount);
    }

    void Load(const ::Image& image, ::Color key, int firstChar) {
        Unload();
        FontUnmanaged::Load(image, key, firstChar);
    }

    void Load(
        const std::string& fileType,
        const unsigned char* fileData,
        int dataSize,
        int fontSize,
        const int* codepoints,
        int codepointCount) {
        Unload();
        FontUnmanaged::Load(fileType, fileData, dataSize, fontSize, codepoints, codepointCount);
    }
};
} // namespace raylib

using RFont = raylib::Font;

#endif // RAYLIB_CPP_INCLUDE_FONT_HPP_
