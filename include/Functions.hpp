/**
 * C++ wrapper functions for raylib.
 */
#ifndef RAYLIB_CPP_INCLUDE_FUNCTIONS_HPP_
#define RAYLIB_CPP_INCLUDE_FUNCTIONS_HPP_

#include <string>
#include <vector>

#include "./raylib.hpp"

/**
 * Allow changing the declare type for all raylib-cpp global functions. Defaults to static.
 */
#ifndef RLCPPAPI
#define RLCPPAPI static
#endif

namespace raylib {

/**
 * Initialize window and OpenGL context
 */
[[maybe_unused]] RLCPPAPI inline void InitWindow(int width, int height, const std::string& title = "raylib") {
    ::InitWindow(width, height, title.c_str());
}

/**
 * Set title for window
 */
[[maybe_unused]] RLCPPAPI inline void SetWindowTitle(const std::string& title) {
    ::SetWindowTitle(title.c_str());
}

/**
 * Get the human-readable, UTF-8 encoded name of the primary monitor
 */
[[maybe_unused]] RLCPPAPI inline std::string GetMonitorName(int monitor = 0) {
    return ::GetMonitorName(monitor);
}

/**
 * Set clipboard text content
 */
[[maybe_unused]] RLCPPAPI inline void SetClipboardText(const std::string& text) {
    ::SetClipboardText(text.c_str());
}

/**
 * Get clipboard text content
 */
[[maybe_unused]] RLCPPAPI inline std::string GetClipboardText() {
    return ::GetClipboardText();
}

/**
 * Takes a screenshot of current screen (saved a .png)
 */
[[maybe_unused]] RLCPPAPI inline void TakeScreenshot(const std::string& fileName) {
    ::TakeScreenshot(fileName.c_str());
}

/**
 * Get gamepad internal name id
 */
[[maybe_unused]] RLCPPAPI inline std::string GetGamepadName(int gamepad) {
    return ::GetGamepadName(gamepad);
}

/**
 * Load text data from file (read)
 */
[[maybe_unused]] RLCPPAPI std::string LoadFileText(const std::string& fileName) {
    char* text = ::LoadFileText(fileName.c_str());
    std::string output(text);
    ::UnloadFileText(text);
    return output;
}

/**
 * Save text data to file (write)
 */
[[maybe_unused]] RLCPPAPI inline bool SaveFileText(const std::string& fileName, const std::string& text) {
    return ::SaveFileText(fileName.c_str(), const_cast<char*>(text.c_str()));
}

/**
 * Check if file exists
 */
[[maybe_unused]] RLCPPAPI inline bool FileExists(const std::string& fileName) {
    return ::FileExists(fileName.c_str());
}

/**
 * Check if directory path exists
 */
[[maybe_unused]] RLCPPAPI inline bool DirectoryExists(const std::string& dirPath) {
    return ::DirectoryExists(dirPath.c_str());
}

/**
 * Check file extension (including point: .png, .wav)
 */
[[maybe_unused]] RLCPPAPI inline bool IsFileExtension(const std::string& fileName, const std::string& ext) {
    return ::IsFileExtension(fileName.c_str(), ext.c_str());
}

/**
 * Get pointer to extension for a filename string (including point: ".png")
 */
[[maybe_unused]] RLCPPAPI inline std::string GetFileExtension(const std::string& fileName) {
    return ::GetFileExtension(fileName.c_str());
}

/**
 * Get pointer to filename for a path string
 */
[[maybe_unused]] RLCPPAPI inline std::string GetFileName(const std::string& filePath) {
    return ::GetFileName(filePath.c_str());
}

/**
 * Get filename string without extension
 */
[[maybe_unused]] RLCPPAPI inline std::string GetFileNameWithoutExt(const std::string& filePath) {
    return ::GetFileNameWithoutExt(filePath.c_str());
}

/**
 * Get full path for a given fileName with path
 */
[[maybe_unused]] RLCPPAPI inline std::string GetDirectoryPath(const std::string& filePath) {
    return ::GetDirectoryPath(filePath.c_str());
}

/**
 * Get previous directory path for a given path
 */
[[maybe_unused]] RLCPPAPI inline std::string GetPrevDirectoryPath(const std::string& dirPath) {
    return ::GetPrevDirectoryPath(dirPath.c_str());
}

/**
 * Get current working directory
 */
[[maybe_unused]] RLCPPAPI inline std::string GetWorkingDirectory() {
    return ::GetWorkingDirectory();
}

/**
 * Get filenames in a directory path
 */
[[maybe_unused]] RLCPPAPI std::vector<std::string> LoadDirectoryFiles(const std::string& dirPath) {
    FilePathList files = ::LoadDirectoryFiles(dirPath.c_str());
    std::vector<std::string> output(files.paths, files.paths + files.count);
    ::UnloadDirectoryFiles(files);
    return output;
}

/**
 * Change working directory, return true on success
 */
[[maybe_unused]] RLCPPAPI inline bool ChangeDirectory(const std::string& dir) {
    return ::ChangeDirectory(dir.c_str());
}

/**
 * Get dropped files names
 */
[[maybe_unused]] RLCPPAPI std::vector<std::string> LoadDroppedFiles() {
    if (!::IsFileDropped()) {
        return std::vector<std::string>();
    }
    FilePathList files = ::LoadDroppedFiles();
    std::vector<std::string> output(files.paths, files.paths + files.count);
    ::UnloadDroppedFiles(files);
    return output;
}

/**
 * Get file modification time (last write time)
 */
[[maybe_unused]] RLCPPAPI inline long GetFileModTime(const std::string& fileName) { // NOLINT
    return ::GetFileModTime(fileName.c_str());
}

/**
 * Open URL with default system browser (if available)
 */
[[maybe_unused]] RLCPPAPI inline void OpenURL(const std::string& url) {
    return ::OpenURL(url.c_str());
}

/**
 * Load an image.
 */
[[maybe_unused]] RLCPPAPI inline ::Image LoadImage(const std::string& fileName) {
    return ::LoadImage(fileName.c_str());
}

/**
 * Load an image from RAW file data
 */
[[maybe_unused]] RLCPPAPI inline ::Image
LoadImageRaw(const std::string& fileName, int width, int height, int format, int headerSize) {
    return ::LoadImageRaw(fileName.c_str(), width, height, format, headerSize);
}

/**
 * Load animated image data
 */
[[maybe_unused]] RLCPPAPI inline ::Image LoadImageAnim(const std::string& fileName, int* frames) {
    return ::LoadImageAnim(fileName.c_str(), frames);
}

/**
 * Load image from memory buffer, fileType refers to extension like "png"
 */
[[maybe_unused]] RLCPPAPI inline ::Image
LoadImageFromMemory(const std::string& fileType, const unsigned char* fileData, int dataSize) {
    return ::LoadImageFromMemory(fileType.c_str(), fileData, dataSize);
}

/**
 * Export image data to file
 */
[[maybe_unused]] RLCPPAPI inline bool ExportImage(const Image& image, const std::string& fileName) {
    return ::ExportImage(image, fileName.c_str());
}

/**
 * Export image as code file (.h) defining an array of bytes
 */
[[maybe_unused]] RLCPPAPI inline bool ExportImageAsCode(const Image& image, const std::string& fileName) {
    return ::ExportImageAsCode(image, fileName.c_str());
}

/**
 * Draw text (using default font)
 */
[[maybe_unused]] RLCPPAPI inline void DrawText(const char* text, int posX, int posY, int fontSize, ::Color color) {
    ::DrawText(text, posX, posY, fontSize, color);
}

/**
 * Draw text (using default font)
 */
[[maybe_unused]] RLCPPAPI inline void
DrawText(const std::string& text, int posX, int posY, int fontSize, ::Color color) {
    ::DrawText(text.c_str(), posX, posY, fontSize, color);
}

/**
 * Draw text using font and additional parameters
 */
[[maybe_unused]] RLCPPAPI inline void
DrawTextEx(const Font& font, char* text, Vector2 position, float fontSize, float spacing, ::Color tint) {
    ::DrawTextEx(font, text, position, fontSize, spacing, tint);
}

/**
 * Draw text using font and additional parameters
 */
[[maybe_unused]] RLCPPAPI inline void
DrawTextEx(const Font& font, const std::string& text, Vector2 position, float fontSize, float spacing, ::Color tint) {
    ::DrawTextEx(font, text.c_str(), position, fontSize, spacing, tint);
}

/**
 * Draw text using Font and pro parameters (rotation)
 */
[[maybe_unused]] RLCPPAPI inline void DrawTextPro(
    const Font& font,
    const char* text,
    Vector2 position,
    Vector2 origin,
    float rotation,
    float fontSize,
    float spacing,
    ::Color tint) {
    ::DrawTextPro(font, text, position, origin, rotation, fontSize, spacing, tint);
}

/**
 * Draw text using Font and pro parameters (rotation)
 */
[[maybe_unused]] RLCPPAPI inline void DrawTextPro(
    const Font& font,
    const std::string& text,
    Vector2 position,
    Vector2 origin,
    float rotation,
    float fontSize,
    float spacing,
    ::Color tint) {
    ::DrawTextPro(font, text.c_str(), position, origin, rotation, fontSize, spacing, tint);
}

/**
 * Load font from file (filename must include file extension)
 */
[[maybe_unused]] RLCPPAPI inline ::Font LoadFont(const std::string& fileName) {
    return ::LoadFont(fileName.c_str());
}

/**
 * Load font from file (filename must include file extension)
 */
[[maybe_unused]] RLCPPAPI inline ::Font
LoadFontEx(const std::string& fileName, int fontSize, int* fontChars, int charsCount) {
    return ::LoadFontEx(fileName.c_str(), fontSize, fontChars, charsCount);
}

/**
 * Measure string width for default font
 */
[[maybe_unused]] RLCPPAPI inline int MeasureText(const char* text, int fontSize) {
    return ::MeasureText(text, fontSize);
}

/**
 * Measure string width for default font
 */
[[maybe_unused]] RLCPPAPI inline int MeasureText(const std::string& text, int fontSize) {
    return ::MeasureText(text.c_str(), fontSize);
}

/**
 * Check if two text string are equal
 */
[[maybe_unused]] RLCPPAPI inline bool TextIsEqual(const char* text1, const char* text2) {
    return ::TextIsEqual(text1, text2);
}

/**
 * Check if two text string are equal
 */
[[maybe_unused]] RLCPPAPI inline bool TextIsEqual(const std::string& text1, const std::string& text2) {
    return ::TextIsEqual(text1.c_str(), text2.c_str());
}

/**
 * Check if two text string are equal
 */
[[maybe_unused]] RLCPPAPI inline unsigned int TextLength(const char* text) {
    return ::TextLength(text);
}

/**
 * Check if two text string are equal
 */
[[maybe_unused]] RLCPPAPI inline unsigned int TextLength(const std::string& text) {
    return ::TextLength(text.c_str());
}

/**
 * Get text length, checks for '\0' ending
 */
[[maybe_unused]] RLCPPAPI inline std::string TextSubtext(const std::string& text, int position, int length) {
    return ::TextSubtext(text.c_str(), position, length);
}

/**
 * Replace text string
 */
[[maybe_unused]] RLCPPAPI std::string
TextReplace(const std::string& text, const std::string& replace, const std::string& by) {
    const char* input = text.c_str();
    char* output = ::TextReplace(const_cast<char*>(input), replace.c_str(), by.c_str());
    if (output != NULL) {
        std::string stringOutput(output);
        free(output);
        return stringOutput;
    }
    return "";
}

/**
 * Insert text in a position
 */
[[maybe_unused]] RLCPPAPI std::string TextInsert(const std::string& text, const std::string& insert, int position) {
    char* output = ::TextInsert(text.c_str(), insert.c_str(), position);
    if (output != NULL) {
        std::string stringOutput(output);
        free(output);
        return stringOutput;
    }
    return "";
}

/**
 * Split text into multiple strings
 */
[[maybe_unused]] RLCPPAPI std::vector<std::string> TextSplit(const std::string& text, char delimiter) {
    int count;
    const char** split = ::TextSplit(text.c_str(), delimiter, &count);
    return std::vector<std::string>(split, split + count);
}

/**
 * Find first text occurrence within a string
 */
[[maybe_unused]] RLCPPAPI inline int TextFindIndex(const std::string& text, const std::string& find) {
    return ::TextFindIndex(text.c_str(), find.c_str());
}

/**
 * Get upper case version of provided string
 */
[[maybe_unused]] RLCPPAPI inline std::string TextToUpper(const std::string& text) {
    return ::TextToUpper(text.c_str());
}

/**
 * Get lower case version of provided string
 */
[[maybe_unused]] RLCPPAPI inline std::string TextToLower(const std::string& text) {
    return ::TextToLower(text.c_str());
}

/**
 * Get Pascal case notation version of provided string
 */
[[maybe_unused]] RLCPPAPI inline std::string TextToPascal(const std::string& text) {
    return ::TextToPascal(text.c_str());
}

/**
 * Get integer value from text (negative values not supported)
 */
[[maybe_unused]] RLCPPAPI inline int TextToInteger(const std::string& text) {
    return ::TextToInteger(text.c_str());
}

} // namespace raylib

#endif // RAYLIB_CPP_INCLUDE_FUNCTIONS_HPP_
