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

#ifndef RAYLIB_CPP_INCLUDE_MODELANIMATION_HPP_
#define RAYLIB_CPP_INCLUDE_MODELANIMATION_HPP_

#include "./raylib.hpp"
#include "./raylib-cpp-utils.hpp"
#include "./Mesh.hpp"

namespace raylib {
class ModelAnimation : public ::ModelAnimation {
 public:
    ModelAnimation(::ModelAnimation model) {
        set(model);
    }

    ~ModelAnimation() {
        Unload();
    }

    GETTERSETTER(int, BoneCount, boneCount)
    GETTERSETTER(::BoneInfo*, Bones, bones)
    GETTERSETTER(int, FrameCount, frameCount)
    GETTERSETTER(::Transform**, FramePoses, framePoses)

    ModelAnimation& operator=(const ::ModelAnimation& model) {
        set(model);
        return *this;
    }

    ModelAnimation& operator=(const ModelAnimation& model) {
        set(model);
        return *this;
    }

    inline void Unload() {
        ::UnloadModelAnimation(*this);
    }

    inline ModelAnimation& UpdateAnimation(::Model model, int frame) {
        ::UpdateModelAnimation(model, *this, frame);
        return *this;
    }

    inline bool IsValid(::Model model) const {
        return ::IsModelAnimationValid(model, *this);
    }

    inline bool IsModelAnimationValid(::Model model) const {
        return ::IsModelAnimationValid(model, *this);
    }

 protected:
    inline void set(::ModelAnimation model) {
        boneCount = model.boneCount;
        bones = model.bones;
        frameCount = model.frameCount;
        framePoses = model.framePoses;
    }
};
}  // namespace raylib

#endif  // RAYLIB_CPP_INCLUDE_MODELANIMATION_HPP_
