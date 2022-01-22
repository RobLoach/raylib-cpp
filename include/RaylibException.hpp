#ifndef RAYLIB_CPP_INCLUDE_RAYLIBEXCEPTION_HPP_
#define RAYLIB_CPP_INCLUDE_RAYLIBEXCEPTION_HPP_

#include <stdexcept>

#include <string>

#include "raylib.h"

namespace raylib {
class RaylibException : public std::runtime_error {
    protected:
 public:
    RaylibException(std::string msg) throw() : std::runtime_error(msg)
        {

        }


    /** Destructor.
     *  Virtual to allow for subclassing.
     */
    //virtual ~Except() throw () {}

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
