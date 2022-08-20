#ifndef RAYLIB_CPP_INCLUDE_RAYLIBEXCEPTION_HPP_
#define RAYLIB_CPP_INCLUDE_RAYLIBEXCEPTION_HPP_

#include <stdexcept>
#include <string>

#include "./raylib.hpp"

namespace raylib {
/**
 * Exception used for most raylib-related exceptions.
 */
class RaylibException : public std::runtime_error {
 public:
    /**
     * Construct a runtime exception with the given message.
     *
     * @param message The message to provide for the exception.
     */
    RaylibException(std::string message) throw() : std::runtime_error(message) {
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

}  // namespace raylib

using RRaylibException = raylib::RaylibException;

#endif  // RAYLIB_CPP_INCLUDE_RAYLIBEXCEPTION_HPP_
