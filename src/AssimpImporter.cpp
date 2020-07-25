#include "AssimpImporter.h"

#include <GodotGlobal.hpp>

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h> 

using namespace godot;

void AssimpImporter::_register_methods() {
    register_method("_process", &AssimpImporter::_process);
    register_method("import", &AssimpImporter::import);
}

AssimpImporter::AssimpImporter() {
}

AssimpImporter::~AssimpImporter() {
}

void AssimpImporter::_init() {
    Godot::print("assimp test");
}

void AssimpImporter::_process(float delta) {
}

void AssimpImporter::import(String path) {
    Assimp::Importer importer;
    auto path_c = path.alloc_c_string();
    const aiScene* scene =    importer.ReadFile(path_c,
        aiProcess_Triangulate
        | aiProcess_FlipUVs
        | aiProcess_JoinIdenticalVertices
        | aiProcess_OptimizeMeshes
        | aiProcess_LimitBoneWeights
        | aiProcess_RemoveRedundantMaterials);

    godot::api->godot_free(path_c);

    Godot::print(scene ? "true" : "false");
    Godot::print("camera:" + String::num(scene->mNumCameras));

    if (scene->mNumMeshes >= 1) {
        const auto mesh = scene->mMeshes[0];
        Godot::print(mesh->mName.C_Str());
    }
}
