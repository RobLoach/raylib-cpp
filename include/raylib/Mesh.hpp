#ifndef RAYLIB_CPP_MESH_HPP_
#define RAYLIB_CPP_MESH_HPP_

#ifdef __cplusplus
extern "C"{
#endif
#include "raylib.h"
#ifdef __cplusplus
}
#endif

#include "utils.hpp"

#include "BoundingBox.hpp"

namespace raylib {
	class Mesh : public ::Mesh {
	public:
		Mesh(::Mesh mesh) {
			set(mesh);
		};

		Mesh(int VertexCount = 0, int TriangleCount = 0) {
			vertexCount = VertexCount;
			triangleCount = TriangleCount;
		};

		inline void set(::Mesh mesh) {
			vertexCount = mesh.vertexCount;
			triangleCount = mesh.triangleCount;
			vertices = mesh.vertices;
			texcoords = mesh.texcoords;
			texcoords2 = mesh.texcoords2;
			normals = mesh.normals;
			tangents = mesh.tangents;
			colors = mesh.colors;
			indices = mesh.indices;
			animVertices = mesh.animVertices;
			animNormals = mesh.animNormals;
			boneIds = mesh.boneIds;
			boneWeights = mesh.boneWeights;
			vaoId = mesh.vaoId;
			vboId = mesh.vboId;
		}

		GETTERSETTER(int,VertexCount,vertexCount)
		GETTERSETTER(int,TriangleCount,triangleCount)

        Mesh& operator=(const ::Mesh& mesh) {
            set(mesh);
            return *this;
        }

        Mesh& operator=(const Mesh& mesh) {
            set(mesh);
            return *this;
        }

		~Mesh() {
			Unload();
		}

		inline void Export(const std::string& fileName) {
			ExportMesh(*this, fileName.c_str());
		}

		inline void Unload() {
			UnloadMesh(*this);
		}

		inline BoundingBox GetBoundingBox() {
			return BoundingBox(MeshBoundingBox(*this));
		}

		inline void Tangents() {
			MeshTangents(this);
		}

		inline void Binormals() {
			MeshBinormals(this);
		}
	};
}

#endif
