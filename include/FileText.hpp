#ifndef RAYLIB_CPP_INCLUDE_FILETEXT_HPP_
#define RAYLIB_CPP_INCLUDE_FILETEXT_HPP_

#include <string>
#include <utility>

#include "./raylib.hpp"
#include "./raylib-cpp-utils.hpp"

namespace raylib {

class FileText {
 public:
    FileText() = default;
    FileText(const FileText&) = delete;
    FileText(FileText&& other) noexcept : data(other.data), length(other.length) {
        other.data = nullptr;
        other.length = 0;
    }
    FileText& operator=(const FileText&) = delete;
    FileText& operator=(FileText&& other) noexcept {
        std::swap(data, other.data);
        std::swap(length, other.length);
        return *this;
    }
    ~FileText() { Unload(); }

    explicit FileText(const std::string& fileName) {
        Load(fileName);
    }

    GETTER(const char*, Data, data)
    GETTER(unsigned int, Length, length)

    [[nodiscard]] const char* c_str() const { return data; }

    [[nodiscard]] std::string ToString() const { return data; }
    explicit operator std::string() const {
        return data;
    }

    void Load(const std::string& fileName) { Load(fileName.c_str()); }
    void Load(const char* fileName) {
        data = ::LoadFileText(fileName);
        length = ::TextLength(data);
    }

    void Unload() {
        if (data != nullptr) {
            ::UnloadFileText(data);
            data = nullptr;
            length = 0;
        }
    }

 private:
    char* data{nullptr};
    unsigned int length{0};
};

}  // namespace raylib

using RFileText = raylib::FileText;

#endif  // RAYLIB_CPP_INCLUDE_FILETEXT_HPP_
