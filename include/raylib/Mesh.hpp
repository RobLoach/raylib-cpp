#ifndef RAYLIB_CPP_MESH_HPP_
#define RAYLIB_CPP_MESH_HPP_

#include "raylib.h"
#include "utils.hpp"

#include "BoundingBox.hpp"

namespace raylib {
	class Mesh : public ::Mesh {
	public:
		Mesh(::Mesh mesh) {
			set(mesh);
		};

		Mesh(float VertexCount = 0, float TriangleCount = 0) {
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

		GETTERSETTER(float,VertexCount,vertexCount)
		GETTERSETTER(float,TriangleCount,triangleCount)

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

		void Export(const std::string& fileName) {
			ExportMesh(*this, fileName.c_str());
		}

		void Unload() {
			UnloadMesh(*this);
		}

		BoundingBox GetBoundingBox() {
			return BoundingBox(MeshBoundingBox(*this));
		}

		void Tangents() {
			MeshTangents(this);
		}

		void Binormals() {
			MeshBinormals(this);
		}
	};
}

#endif
