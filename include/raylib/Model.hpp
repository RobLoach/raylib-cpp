#ifndef RAYLIB_CPP_MODEL_HPP_
#define RAYLIB_CPP_MODEL_HPP_

#include "raylib.h"
#include "utils.hpp"
#include "Mesh.hpp"

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

		void Unload() {
			UnloadModel(*this);
		}

		void SetMeshMaterial(int meshId, int materialId) {
			SetModelMeshMaterial(this, meshId, materialId);
		}

		RayHitInfo GetCollision(::Ray ray) {
			return GetCollisionRayModel(ray, *this);
		}

		void UpdateModelAnimation(::ModelAnimation anim, int frame) {
			::UpdateModelAnimation(*this, anim, frame);
		}

		bool IsModelAnimationValid(::ModelAnimation anim) {
			return ::IsModelAnimationValid(*this, anim);
		}
	};
}

#endif
