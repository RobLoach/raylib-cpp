#ifndef RAYLIB_CPP_INCLUDE_MATERIAL_HPP_
#define RAYLIB_CPP_INCLUDE_MATERIAL_HPP_

#include "./MaterialUnmanaged.hpp"

namespace raylib {
/**
 * Material type (generic).
 *
 * The material will be unloaded on object destruction. Use raylib::MaterialUnmanaged if you're looking to not unload.
 *
 * @see raylib::MaterialUnmanaged
 */
class Material : public MaterialUnmanaged {
public:
    using MaterialUnmanaged::MaterialUnmanaged;

    Material(const Material&) = delete;
    Material& operator=(const Material&) = delete;

    Material(Material&& other) noexcept {
        set(other);
        other.maps = nullptr;
        other.shader = {};
        other.params[0] = 0.0f;
        other.params[1] = 0.0f;
        other.params[2] = 0.0f;
        other.params[3] = 0.0f;
    }

    Material& operator=(Material&& other) noexcept {
        if (this == &other) {
            return *this;
        }
        Unload();
        set(other);
        other.maps = nullptr;
        other.shader = {};
        return *this;
    }

    Material& operator=(const ::Material& material) {
        Unload();
        set(material);
        return *this;
    }

    ~Material() { Unload(); }
};
} // namespace raylib

using RMaterial = raylib::Material;

#endif // RAYLIB_CPP_INCLUDE_MATERIAL_HPP_
