#ifndef RAYLIB_CPP_INCLUDE_MODELANIMATION_HPP_
#define RAYLIB_CPP_INCLUDE_MODELANIMATION_HPP_

#include <string>
#include <vector>

#include "./Mesh.hpp"
#include "./raylib-cpp-utils.hpp"
#include "./raylib.hpp"

namespace raylib {
/**
 * Model animation
 */
class ModelAnimation : public ::ModelAnimation {
public:
    ModelAnimation(const ::ModelAnimation& model) { set(model); }

    ModelAnimation(const ModelAnimation&) = delete;

    ModelAnimation(ModelAnimation&& other) noexcept {
        set(other);

        other.boneCount = 0;
        other.keyframeCount = 0;
        other.keyframePoses = nullptr;
    }

    // Unloads animation data using populated animCount field, which is set by Load() method.
    ~ModelAnimation() { Unload(); }

    /**
     * Load model animations from file
     */
    static std::vector<ModelAnimation> Load(const std::string& fileName) {
        int count = 0;
        ::ModelAnimation* modelAnimations = ::LoadModelAnimations(fileName.c_str(), &count);

        std::vector<ModelAnimation> mats(modelAnimations, modelAnimations + count);

        RL_FREE(modelAnimations);

        return mats;
    }

    GETTERSETTER(int, BoneCount, boneCount)
    GETTERSETTER(int, KeyframeCount, keyframeCount)
    GETTERSETTER(::Transform**, KeyframePoses, keyframePoses)

    ModelAnimation& operator=(const ::ModelAnimation& model) {
        set(model);
        return *this;
    }

    ModelAnimation& operator=(const ModelAnimation&) = delete;

    ModelAnimation& operator=(ModelAnimation&& other) noexcept {
        if (this == &other) {
            return *this;
        }

        Unload();
        set(other);

        other.boneCount = 0;
        other.keyframeCount = 0;
        other.keyframePoses = nullptr;

        return *this;
    }

    /**
     * Unload animation data
     */
    void Unload() {
        ::UnloadModelAnimations(this, 1); 
    }

    static void Unload(ModelAnimation *modelAnimation, int count) {
        ::UnloadModelAnimations(modelAnimation, count); 
    }

    /**
     * Update model animation pose
     */
    ModelAnimation& Update(const ::Model& model, float frame) {
        ::UpdateModelAnimation(model, *this, frame);
        return *this;
    }

    /**
     * Blend two animation poses
     */
    ModelAnimation& Blend(const ::Model& model, float frameA, const ::ModelAnimation& animB, float frameB, float blend) {
        ::UpdateModelAnimationEx(model, *this, frameA, animB, frameB, blend);
        return *this;
    }


    /**
     * Check model animation skeleton match
     */
    [[nodiscard]] bool IsValid(const ::Model& model) const { return ::IsModelAnimationValid(model, *this); }
protected:
    void set(const ::ModelAnimation& model) {
        boneCount = model.boneCount;
        keyframeCount = model.keyframeCount;
        keyframePoses = model.keyframePoses;

        // Duplicate the name. TextCopy() uses the null terminator, which we ignore here.
        for (int i = 0; i < 32; i++) {
            name[i] = model.name[i];
        }
    }
};
} // namespace raylib

using RModelAnimation = raylib::ModelAnimation;

#endif // RAYLIB_CPP_INCLUDE_MODELANIMATION_HPP_
