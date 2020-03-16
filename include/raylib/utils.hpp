#ifndef RAYLIB_CPP_UTILS_HPP_
#define RAYLIB_CPP_UTILS_HPP_

#ifndef GETTERSETTER
/**
 * A utility to build get and set methods on top of a property.
 *
 * @param type The type of the property.
 * @param method The human-readable name for the method.
 * @param name The machine-readable name of the property.
 */
#define GETTERSETTER(type, method, name) \
	inline type get##method() { return name; } \
	inline void set##method(type value) { name = value; }
#endif

#endif
