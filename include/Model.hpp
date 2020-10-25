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
	class Model : public ::Model {
	public:
		Model(::Model model) {
			set(model);
		};

		Model(const std::string& fileName) {
			set(LoadModel(fileName.c_str()));
		};

		Model(::Mesh mesh) {
			set(LoadModelFromMesh(mesh));
		};

		~Model() {
			Unload();
		}

		GETTERSETTER(::Matrix,Transform,transform)
		GETTERSETTER(int,MeshCount,meshCount)
		GETTERSETTER(int,MaterialCount,materialCount)

        Model& operator=(const ::Model& model) {
            set(model);
            return *this;
        }

        Model& operator=(const Model& model) {
            set(model);
            return *this;
        }

		inline void Unload() {
			::UnloadModel(*this);
		}

		inline Model& SetMeshMaterial(int meshId, int materialId) {
			::SetModelMeshMaterial(this, meshId, materialId);
			return *this;
		}

		inline RayHitInfo GetCollision(::Ray ray) {
			return ::GetCollisionRayModel(ray, *this);
		}

		inline Model& UpdateModelAnimation(::ModelAnimation anim, int frame) {
			::UpdateModelAnimation(*this, anim, frame);
			return *this;
		}

		inline bool IsModelAnimationValid(::ModelAnimation anim) {
			return ::IsModelAnimationValid(*this, anim);
		}

	protected:
		inline void set(::Model model) {
			transform = model.transform;

			meshCount = model.meshCount;
			meshes = model.meshes;

			materialCount = model.materialCount;
			materials = model.materials;
			meshMaterial = model.meshMaterial;
			boneCount = model.boneCount;
			bones = model.bones;
			bindPose = model.bindPose;
		}
	};
}

#endif
