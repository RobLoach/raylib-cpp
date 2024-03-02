#ifndef RAYLIB_CPP_INCLUDE_FILEDATA_HPP_
#define RAYLIB_CPP_INCLUDE_FILEDATA_HPP_

#include <string>
#include <utility>

#include "./raylib.hpp"
#include "./raylib-cpp-utils.hpp"

namespace raylib {

class FileData {
public:
    FileData() = default;
    FileData(const FileData&) = delete;
    FileData(FileData&& other) noexcept : data(other.data), bytesRead(other.bytesRead) {
        other.data = nullptr;
        other.bytesRead = 0;
    }
    FileData& operator=(const FileData&) = delete;
    FileData& operator=(FileData&& other) noexcept {
        std::swap(data, other.data);
        std::swap(bytesRead, other.bytesRead);
        return *this;
    }
    ~FileData() { Unload(); }

    explicit FileData(const std::string& fileName) {
        Load(fileName);
    }

    GETTER(const unsigned char*, Data, data)
    GETTER(int, BytesRead, bytesRead)

    void Load(const std::string& fileName) { Load(fileName.c_str()); }
    void Load(const char* fileName) {
        data = ::LoadFileData(fileName, &bytesRead);
    }

    void Unload() {
        if (data != nullptr) {
            ::UnloadFileData(data);
            data = nullptr;
        }
    }

private:
    unsigned char* data{nullptr};
    int bytesRead{0};
};

}  // namespace raylib

using RFileData = raylib::FileData;

#endif  // RAYLIB_CPP_INCLUDE_FILEDATA_HPP_
