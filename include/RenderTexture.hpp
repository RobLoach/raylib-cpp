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

#ifndef RAYLIB_CPP_INCLUDE_RENDERTEXTURE_HPP_
#define RAYLIB_CPP_INCLUDE_RENDERTEXTURE_HPP_

#include "./raylib.hpp"
#include "./raylib-cpp-utils.hpp"

namespace raylib {
class RenderTexture : public ::RenderTexture {
 public:
    RenderTexture(::RenderTexture renderTexture) {
        set(renderTexture);
    }

    RenderTexture(unsigned int Id) {
        id = Id;
    }

    RenderTexture(int width, int height) {
        set(LoadRenderTexture(width, height));
    }

    GETTERSETTER(unsigned int, Id, id)
    GETTERSETTER(::Texture2D, Texture, texture)
    GETTERSETTER(::Texture2D, Depth, depth)

    RenderTexture& operator=(const ::RenderTexture& texture) {
        set(texture);
        return *this;
    }

    RenderTexture& operator=(const RenderTexture& texture) {
        set(texture);
        return *this;
    }

    ~RenderTexture() {
        Unload();
    }

    inline void Unload() {
        UnloadRenderTexture(*this);
    }

    inline RenderTexture& BeginTextureMode() {
        ::BeginTextureMode(*this);
        return *this;
    }

    inline RenderTexture& EndTextureMode() {
        ::EndTextureMode();
        return *this;
    }

 protected:
    inline void set(::RenderTexture renderTexture) {
        id = renderTexture.id;
        texture = renderTexture.texture;
        depth = renderTexture.depth;
    }
};
typedef RenderTexture RenderTexture2D;
}  // namespace raylib

#endif  // RAYLIB_CPP_INCLUDE_RENDERTEXTURE_HPP_
