#ifndef RAYLIB_CPP_MODEL_HPP_
#define RAYLIB_CPP_MODEL_HPP_

#include "raylib.h"
#include "utils.hpp"
#include "Mesh.hpp"

namespace raylib {
	class ModelAnimation : public ::ModelAnimation {
	public:
		ModelAnimation(::ModelAnimation model) {
			set(model);
		};

		~ModelAnimation() {
			Unload();
		}

		inline void set(::ModelAnimation model) {
			boneCount = model.boneCount;
			bones = model.bones;
			frameCount = model.frameCount;
			framePoses = model.framePoses;
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

		void Unload() {
			UnloadModelAnimation(*this);
		}

		void UpdateAnimation(::Model model, int frame) {
			UpdateModelAnimation(model, *this, frame);
		}

		bool IsValid(::Model model) {
			return ::IsModelAnimationValid(model, *this);
		}

	};
}

#endif
