/*
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

#ifndef RAYLIB_CPP_INCLUDE_DROPPEDFILES_HPP_
#define RAYLIB_CPP_INCLUDE_DROPPEDFILES_HPP_

#include <string>

#include "./raylib.hpp"

namespace raylib {
class DroppedFiles {
 public:
    DroppedFiles() {
        Get();
    }

    /**
     * Get the dropped files names.
     */
    DroppedFiles& Get() {
        m_files = ::GetDroppedFiles(&m_count);
        return *this;
    }

    /**
     * Check if a file has been dropped into window.
     */
    inline bool IsFileDropped() const {
        return ::IsFileDropped();
    }

    /**
     * Clear dropped files paths buffer.
     */
    inline DroppedFiles& Clear() {
        ::ClearDroppedFiles();
        return *this;
    }

    ~DroppedFiles() {
        Clear();
    }

    inline std::string operator[](int pos) {
        return at(pos);
    }

    inline int Count() const {
        return m_count;
    }

    inline int size() const {
        return m_count;
    }

    inline bool empty() const {
        return m_count == 0;
    }

    inline void clear() {
        Clear();
    }

    inline std::string front() const {
        return at(0);
    }

    inline std::string back() const {
        return at(m_count - 1);
    }

    std::string at(int pos) const {
        if (m_files != NULL && pos < m_count && pos >= 0) {
            return std::string(m_files[pos]);
        }
        return "";
    }

 protected:
    char** m_files;
    int m_count;
};
}  // namespace raylib

#endif  // RAYLIB_CPP_INCLUDE_DROPPEDFILES_HPP_
