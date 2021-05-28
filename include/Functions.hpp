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
RLCPPAPI inline void InitWindow(int width, int height, const std::string& title = "raylib") {
    ::InitWindow(width, height, title.c_str());
}

/**
 * Set title for window
 */
RLCPPAPI inline void SetWindowTitle(const std::string& title) {
    ::SetWindowTitle(title.c_str());
}

/**
 * Get the human-readable, UTF-8 encoded name of the primary monitor
 */
RLCPPAPI inline std::string GetMonitorName(int monitor = 0) {
    return ::GetMonitorName(monitor);
}

/**
 * Set clipboard text content
 */
RLCPPAPI inline void SetClipboardText(const std::string& text) {
    ::SetClipboardText(text.c_str());
}

/**
 * Get clipboard text content
 */
RLCPPAPI inline std::string GetClipboardText() {
    return ::GetClipboardText();
}

/**
 * Takes a screenshot of current screen (saved a .png)
 */
RLCPPAPI inline void TakeScreenshot(const std::string& fileName) {
    ::TakeScreenshot(fileName.c_str());
}

/**
 * Load text data from file (read)
 */
RLCPPAPI std::string LoadFileText(const std::string& fileName) {
    char* text = ::LoadFileText(fileName.c_str());
    std::string output(text);
    ::UnloadFileText((unsigned char*)text);
    return output;
}

/**
 * Save text data to file (write)
 */
RLCPPAPI inline bool SaveFileText(const std::string& fileName, const std::string& text) {
    return ::SaveFileText(fileName.c_str(), const_cast<char*>(text.c_str()));
}

/**
 * Check if file exists
 */
RLCPPAPI inline bool FileExists(const std::string& fileName) {
    return ::FileExists(fileName.c_str());
}

/**
 * Check if directory path exists
 */
RLCPPAPI inline bool DirectoryExists(const std::string& dirPath) {
    return ::DirectoryExists(dirPath.c_str());
}

/**
 * Check file extension (including point: .png, .wav)
 */
RLCPPAPI inline bool IsFileExtension(const std::string& fileName, const std::string& ext) {
    return ::IsFileExtension(fileName.c_str(), ext.c_str());
}

/**
 * Get pointer to extension for a filename string (including point: ".png")
 */
RLCPPAPI inline std::string GetFileExtension(const std::string& fileName) {
    return ::GetFileExtension(fileName.c_str());
}

/**
 * Get pointer to filename for a path string
 */
RLCPPAPI inline std::string GetFileName(const std::string& filePath) {
    return ::GetFileName(filePath.c_str());
}

/**
 * Get filename string without extension
 */
RLCPPAPI inline std::string GetFileNameWithoutExt(const std::string& filePath) {
    return ::GetFileNameWithoutExt(filePath.c_str());
}

/**
 * Get full path for a given fileName with path
 */
RLCPPAPI inline std::string GetDirectoryPath(const std::string& filePath) {
    return ::GetDirectoryPath(filePath.c_str());
}

/**
 * Get previous directory path for a given path
 */
RLCPPAPI inline std::string GetPrevDirectoryPath(const std::string& dirPath) {
    return ::GetPrevDirectoryPath(dirPath.c_str());
}

/**
 * Get current working directory
 */
RLCPPAPI inline std::string GetWorkingDirectory() {
    return ::GetWorkingDirectory();
}

/**
 * Get filenames in a directory path
 */
RLCPPAPI std::vector<std::string> GetDirectoryFiles(const std::string& dirPath) {
    int count;
    char** files = ::GetDirectoryFiles(dirPath.c_str(), &count);
    std::vector<std::string> output(files, files + count);
    ::ClearDirectoryFiles();
    return output;
}

/**
 * Change working directory, return true on success
 */
RLCPPAPI inline bool ChangeDirectory(const std::string& dir) {
    return ::ChangeDirectory(dir.c_str());
}

/**
 * Get dropped files names
 */
RLCPPAPI std::vector<std::string> GetDroppedFiles() {
    if (!::IsFileDropped()) {
        return std::vector<std::string>();
    }
    int count;
    char** files = ::GetDroppedFiles(&count);
    std::vector<std::string> output(files, files + count);
    ::ClearDroppedFiles();
    return output;
}

/**
 * Get file modification time (last write time)
 */
RLCPPAPI inline long GetFileModTime(const std::string& fileName) { // NOLINT
    return ::GetFileModTime(fileName.c_str());
}

/**
 * Open URL with default system browser (if available)
 */
RLCPPAPI inline void OpenURL(const std::string& url) {
    return ::OpenURL(url.c_str());
}

/**
 * Check gamepad name (if available)
 */
RLCPPAPI inline bool IsGamepadName(int gamepad, const std::string& name) {
    return ::IsGamepadName(gamepad, name.c_str());
}

/**
 * Update camera depending on selected mode
 */
RLCPPAPI inline void UpdateCamera(const ::Camera& camera) {
    ::Camera* cameraPointer = (::Camera*)&camera;
    ::UpdateCamera(cameraPointer);
}

/**
 * Load an image.
 */
RLCPPAPI inline ::Image LoadImage(const std::string& fileName) {
    return ::LoadImage(fileName.c_str());
}

/**
 * Load an image from RAW file data
 */
RLCPPAPI inline ::Image LoadImageRaw(const std::string& fileName,
        int width, int height,
        int format, int headerSize) {
    return ::LoadImageRaw(fileName.c_str(), width, height, format, headerSize);
}

/**
 * Load animated image data
 */
RLCPPAPI inline ::Image LoadImageAnim(const std::string& fileName, int *frames) {
    return ::LoadImageAnim(fileName.c_str(), frames);
}

/**
 * Load image from memory buffer, fileType refers to extension like "png"
 */
RLCPPAPI inline ::Image LoadImageFromMemory(const std::string& fileType,
        const unsigned char *fileData,
        int dataSize) {
    return ::LoadImageFromMemory(fileType.c_str(), fileData, dataSize);
}

/**
 * Export image data to file
 */
RLCPPAPI inline bool ExportImage(const Image& image, const std::string& fileName) {
    return ::ExportImage(image, fileName.c_str());
}

/**
 * Export image as code file (.h) defining an array of bytes
 */
RLCPPAPI inline bool ExportImageAsCode(const Image& image, const std::string& fileName) {
    return ::ExportImageAsCode(image, fileName.c_str());
}

}  // namespace raylib

#endif  // RAYLIB_CPP_INCLUDE_FUNCTIONS_HPP_
