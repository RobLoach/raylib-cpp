/**
 * Utility for raylib-cpp.
 */
#ifndef RAYLIB_CPP_INCLUDE_RAYLIB_CPP_UTILS_HPP_
#define RAYLIB_CPP_INCLUDE_RAYLIB_CPP_UTILS_HPP_

#ifndef GETTER
/**
 * A utility to build a get method on top of a property.
 *
 * @param type The type of the property.
 * @param method The human-readable name for the method.
 * @param name The machine-readable name of the property.
 */
#define GETTER(type, method, name)                                                        \
    /** Retrieves the name value for the object. @return The name value of the object. */ \
    type Get##method() const {                                                            \
        return name;                                                                      \
    }
#endif

#ifndef GETTERSETTER
/**
 * A utility to build get and set methods on top of a property.
 *
 * @param type The type of the property.
 * @param method The human-readable name for the method.
 * @param name The machine-readable name of the property.
 */
#define GETTERSETTER(type, method, name)                                                       \
    GETTER(type, method, name)                                                                 \
    /** Sets the name value for the object. @param value The value of which to set name to. */ \
    void Set##method(type value) {                                                             \
        name = value;                                                                          \
    }
#endif

#endif // RAYLIB_CPP_INCLUDE_RAYLIB_CPP_UTILS_HPP_
