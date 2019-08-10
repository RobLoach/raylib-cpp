#ifndef RAYLIB_CPP_UTILS_HPP_
#define RAYLIB_CPP_UTILS_HPP_

#ifndef GETTERSETTER
#define GETTERSETTER(type, method, name) \
	inline type get##method() { return name;} \
	inline void set##method(type value) { name = value; }
#endif

#endif
