#ifndef RAYLIB_CPP_MODEL_HPP_
#define RAYLIB_CPP_MODEL_HPP_

#ifdef __cplusplus
extern "C"{
#endif
#include "raylib.h"
#ifdef __cplusplus
}
#endif

#include "./raylib-cpp-utils.hpp"
#include "./Mesh.hpp"

namespace raylib {
	class ModelAnimation : public ::ModelAnimation {
	public:
		ModelAnimation(::ModelAnimation model) {
			set(model);
		};

		~ModelAnimation() {
			Unload();
		}

		GETTERSETTER(int,BoneCount,boneCount)
		GETTERSETTER(::BoneInfo*,Bones,bones)
		GETTERSETTER(int,FrameCount,frameCount)
		GETTERSETTER(Transform**,FramePoses,framePoses)

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

		inline bool IsValid(::Model model) {
			return ::IsModelAnimationValid(model, *this);
		}

		inline bool IsModelAnimationValid(::Model model) {
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
}

#endif
