#ifndef RAYLIB_CPP_INCLUDE_RAYLIBEXCEPTION_HPP_
#define RAYLIB_CPP_INCLUDE_RAYLIBEXCEPTION_HPP_

#include <stdexcept>

#include <string>

#include "./raylib.hpp"

namespace raylib {
class RaylibException : public std::runtime_error {
    protected:
 public:
    RaylibException(std::string msg) throw() : std::runtime_error(msg) {
        // Nothing
    }

    /**
     * Outputs the exception message to TraceLog().
     *
     * @param logLevel The output status to use when outputing.
     */
    void TraceLog(int logLevel = LOG_ERROR) {
        ::TraceLog(logLevel, std::runtime_error::what());
    }
};
}

#endif  // RAYLIB_CPP_INCLUDE_RAYLIBEXCEPTION_HPP_
