#ifndef RAYLIB_CPP_INCLUDE_MODELANIMATION_HPP_
#define RAYLIB_CPP_INCLUDE_MODELANIMATION_HPP_

#include <vector>
#include <string>

#include "./raylib.hpp"
#include "./raylib-cpp-utils.hpp"
#include "./Mesh.hpp"

namespace raylib {
/**
 * Model animation
 */
class ModelAnimation : public ::ModelAnimation {
 public:
    ModelAnimation(const ::ModelAnimation& model) {
        set(model);
    }

    ~ModelAnimation() {
        Unload();
    }

    /**
     * Load model animations from file
     */
    static std::vector<ModelAnimation> Load(const std::string& fileName) {
        int count = 0;
        ::ModelAnimation* modelAnimations = ::LoadModelAnimations(fileName.c_str(), &count);
        return std::vector<ModelAnimation>(modelAnimations, modelAnimations + count);
    }

    GETTERSETTER(int, BoneCount, boneCount)
    GETTERSETTER(::BoneInfo*, Bones, bones)
    GETTERSETTER(int, FrameCount, frameCount)
    GETTERSETTER(::Transform**, FramePoses, framePoses)

    ModelAnimation& operator=(const ::ModelAnimation& model) {
        set(model);
        return *this;
    }

    /**
     * Unload animation data
     */
    inline void Unload() {
        ::UnloadModelAnimation(*this);
    }

    /**
     * Update model animation pose
     */
    inline ModelAnimation& Update(const ::Model& model, int frame) {
        ::UpdateModelAnimation(model, *this, frame);
        return *this;
    }

    /**
     * Check model animation skeleton match
     */
    inline bool IsValid(const ::Model& model) const {
        return ::IsModelAnimationValid(model, *this);
    }

 private:
    inline void set(const ::ModelAnimation& model) {
        boneCount = model.boneCount;
        bones = model.bones;
        frameCount = model.frameCount;
        framePoses = model.framePoses;
    }
};
}  // namespace raylib

#endif  // RAYLIB_CPP_INCLUDE_MODELANIMATION_HPP_
