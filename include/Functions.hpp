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
[[maybe_unused]] RLCPPAPI inline void InitWindow(int width, int height, const char* title = "raylib") {
    ::InitWindow(width, height, title);
}

/**
 * Set title for window
 */
[[maybe_unused]] RLCPPAPI inline void SetWindowTitle(const char* title) {
    ::SetWindowTitle(title);
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
[[maybe_unused]] RLCPPAPI inline void SetClipboardText(const char* text) {
    ::SetClipboardText(text);
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
[[maybe_unused]] RLCPPAPI inline void TakeScreenshot(const char* fileName) {
    ::TakeScreenshot(fileName);
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
[[maybe_unused]] RLCPPAPI std::string LoadFileText(const char* fileName) {
    char* text = ::LoadFileText(fileName);
    std::string output(text);
    ::UnloadFileText(text);
    return output;
}

/**
 * Save text data to file (write)
 */
[[maybe_unused]] RLCPPAPI inline bool SaveFileText(const char* fileName, char* text) {
    return ::SaveFileText(fileName, text);
}

/**
 * Check if file exists
 */
[[maybe_unused]] RLCPPAPI inline bool FileExists(const char* fileName) {
    return ::FileExists(fileName);
}

/**
 * Check if directory path exists
 */
[[maybe_unused]] RLCPPAPI inline bool DirectoryExists(const char* dirPath) {
    return ::DirectoryExists(dirPath);
}

/**
 * Check file extension (including point: .png, .wav)
 */
[[maybe_unused]] RLCPPAPI inline bool IsFileExtension(const char* fileName, const char* ext) {
    return ::IsFileExtension(fileName, ext);
}

/**
 * Get pointer to extension for a filename string (including point: ".png")
 */
[[maybe_unused]] RLCPPAPI inline std::string GetFileExtension(const char* fileName) {
    return ::GetFileExtension(fileName);
}

/**
 * Get pointer to filename for a path string
 */
[[maybe_unused]] RLCPPAPI inline std::string GetFileName(const char* filePath) {
    return ::GetFileName(filePath);
}

/**
 * Get filename string without extension
 */
[[maybe_unused]] RLCPPAPI inline std::string GetFileNameWithoutExt(const char* filePath) {
    return ::GetFileNameWithoutExt(filePath);
}

/**
 * Get full path for a given fileName with path
 */
[[maybe_unused]] RLCPPAPI inline std::string GetDirectoryPath(const char* filePath) {
    return ::GetDirectoryPath(filePath);
}

/**
 * Get previous directory path for a given path
 */
[[maybe_unused]] RLCPPAPI inline std::string GetPrevDirectoryPath(const char* dirPath) {
    return ::GetPrevDirectoryPath(dirPath);
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
[[maybe_unused]] RLCPPAPI std::vector<std::string> LoadDirectoryFiles(const char* dirPath) {
    FilePathList files = ::LoadDirectoryFiles(dirPath);
    std::vector<std::string> output(files.paths, files.paths + files.count);
    ::UnloadDirectoryFiles(files);
    return output;
}

/**
 * Change working directory, return true on success
 */
[[maybe_unused]] RLCPPAPI inline bool ChangeDirectory(const char* dir) {
    return ::ChangeDirectory(dir);
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
[[maybe_unused]] RLCPPAPI inline long GetFileModTime(const char* fileName) { // NOLINT
    return ::GetFileModTime(fileName);
}

/**
 * Open URL with default system browser (if available)
 */
[[maybe_unused]] RLCPPAPI inline void OpenURL(const char* url) {
    return ::OpenURL(url);
}

/**
 * Load an image.
 */
[[maybe_unused]] RLCPPAPI inline ::Image LoadImage(const char* fileName) {
    return ::LoadImage(fileName);
}

/**
 * Load an image from RAW file data
 */
[[maybe_unused]] RLCPPAPI inline ::Image LoadImageRaw(const char* fileName,
        int width, int height,
        int format, int headerSize) {
    return ::LoadImageRaw(fileName, width, height, format, headerSize);
}

/**
 * Load animated image data
 */
[[maybe_unused]] RLCPPAPI inline ::Image LoadImageAnim(const char* fileName, int *frames) {
    return ::LoadImageAnim(fileName, frames);
}

/**
 * Load image from memory buffer, fileType refers to extension like "png"
 */
[[maybe_unused]] RLCPPAPI inline ::Image LoadImageFromMemory(const char* fileType,
        const unsigned char *fileData,
        int dataSize) {
    return ::LoadImageFromMemory(fileType, fileData, dataSize);
}

/**
 * Export image data to file
 */
[[maybe_unused]] RLCPPAPI inline bool ExportImage(const Image& image, const char* fileName) {
    return ::ExportImage(image, fileName);
}

/**
 * Export image as code file (.h) defining an array of bytes
 */
[[maybe_unused]] RLCPPAPI inline bool ExportImageAsCode(const Image& image, const char* fileName) {
    return ::ExportImageAsCode(image, fileName);
}

/**
 * Draw text (using default font)
 */
[[maybe_unused]] RLCPPAPI inline void DrawText(const char* text, int posX, int posY, int fontSize, ::Color color) {
    ::DrawText(text, posX, posY, fontSize, color);
}

/**
 * Draw text using font and additional parameters
 */
[[maybe_unused]] RLCPPAPI inline void DrawTextEx(const Font& font, const char* text, Vector2 position,
        float fontSize, float spacing, ::Color tint) {
    ::DrawTextEx(font, text, position, fontSize, spacing, tint);
}

/**
 * Draw text using Font and pro parameters (rotation)
 */
[[maybe_unused]] RLCPPAPI inline void DrawTextPro(const Font& font, const char* text, Vector2 position,
        Vector2 origin, float rotation, float fontSize, float spacing, ::Color tint) {
    ::DrawTextPro(font, text, position, origin, rotation, fontSize, spacing, tint);
}

/**
 * Load font from file (filename must include file extension)
 */
[[maybe_unused]] RLCPPAPI inline ::Font LoadFont(const char* fileName) {
    return ::LoadFont(fileName);
}

/**
 * Load font from file (filename must include file extension)
 */
[[maybe_unused]] RLCPPAPI inline ::Font LoadFontEx(const char* fileName, int fontSize, int *fontChars, int charsCount) {
    return ::LoadFontEx(fileName, fontSize, fontChars, charsCount);
}

/**
 * Measure string width for default font
 */
[[maybe_unused]] RLCPPAPI inline int MeasureText(const char* text, int fontSize) {
    return ::MeasureText(text, fontSize);
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
[[maybe_unused]] RLCPPAPI inline unsigned int TextLength(const char* text) {
    return ::TextLength(text);
}

/**
 * Get text length, checks for '\0' ending
 */
[[maybe_unused]] RLCPPAPI inline std::string TextSubtext(const char* text, int position, int length) {
    return ::TextSubtext(text, position, length);
}

/**
 * Replace text string
 */
[[maybe_unused]] RLCPPAPI std::string TextReplace(char* text, const char* replace, const char* by) {
    char* output = ::TextReplace(text, replace, by);
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
[[maybe_unused]] RLCPPAPI std::string TextInsert(const char* text, const char* insert, int position) {
    char* output = ::TextInsert(text, insert, position);
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
[[maybe_unused]] RLCPPAPI std::vector<std::string> TextSplit(const char* text, char delimiter) {
    int count;
    const char** split = ::TextSplit(text, delimiter, &count);
    return std::vector<std::string>(split, split + count);
}

/**
 * Find first text occurrence within a string
 */
[[maybe_unused]] RLCPPAPI inline int TextFindIndex(const char* text, const char* find) {
    return ::TextFindIndex(text, find);
}

/**
 * Get upper case version of provided string
 */
[[maybe_unused]] RLCPPAPI inline std::string TextToUpper(const char* text) {
    return ::TextToUpper(text);
}

/**
 * Get lower case version of provided string
 */
[[maybe_unused]] RLCPPAPI inline std::string TextToLower(const char* text) {
    return ::TextToLower(text);
}

/**
 * Get Pascal case notation version of provided string
 */
[[maybe_unused]] RLCPPAPI inline std::string TextToPascal(const char* text) {
    return ::TextToPascal(text);
}

/**
 * Get integer value from text (negative values not supported)
 */
[[maybe_unused]] RLCPPAPI inline int TextToInteger(const char* text) {
    return ::TextToInteger(text);
}

}  // namespace raylib

#endif  // RAYLIB_CPP_INCLUDE_FUNCTIONS_HPP_
