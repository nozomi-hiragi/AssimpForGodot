#include "AssimpImporter.h"

#include "AIScene.h"

#include <GodotGlobal.hpp>

#include <assimp/scene.h>
#include <assimp/postprocess.h> 

using namespace godot;

void AssimpImporter::_register_methods() {
    register_method("_process", &AssimpImporter::_process);
    register_method("import", &AssimpImporter::import);
    register_method("getScene", &AssimpImporter::getScene);
}

AssimpImporter::AssimpImporter() {
}

AssimpImporter::~AssimpImporter() {
}

void AssimpImporter::_init() {
    Godot::print("importer init");
}

void AssimpImporter::_process(float delta) {
}

godot::Ref<AIScene> AssimpImporter::import(String path) {
    auto path_c = path.alloc_c_string();
    const aiScene* scene = _importer.ReadFile(path_c,
        aiProcess_Triangulate
        | aiProcess_FlipUVs
        | aiProcess_JoinIdenticalVertices
        | aiProcess_OptimizeMeshes
        | aiProcess_LimitBoneWeights
        | aiProcess_RemoveRedundantMaterials);

    godot::api->godot_free(path_c);

    _ai_scene.instance();
    _ai_scene->setScene(scene);
    return _ai_scene;
}
