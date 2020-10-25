#ifndef RAYLIB_CPP_DROPPEDFILES_HPP_
#define RAYLIB_CPP_DROPPEDFILES_HPP_

#include <string>

#ifdef __cplusplus
extern "C"{
#endif
#include "raylib.h"
#ifdef __cplusplus
}
#endif

namespace raylib {
	class DroppedFiles {
	protected:
		char** m_files;
		int m_count;
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
	};
}

#endif
