#ifndef _AI_SCENE_H_
#define _AI_SCENE_H_

#include <Godot.hpp>
#include <assimp/scene.h>

class AIScene : public godot::Reference {
    GODOT_CLASS(AIScene, godot::Reference)
public:
    static void _register_methods(){
        godot::register_method("_process", &AIScene::_process);
        godot::register_method("has_animations", &AIScene::hasAnimations);
        godot::register_method("has_cameras", &AIScene::hasCameras);
        godot::register_method("has_lights", &AIScene::hasLights);
        godot::register_method("has_materials", &AIScene::hasMaterials);
        godot::register_method("has_meshes", &AIScene::hasMeshes);
        godot::register_method("has_textures", &AIScene::hasTextures);
        godot::register_property<AIScene, godot::Array>("cameras", &AIScene::setCameras, &AIScene::getCameras, godot::Array());
    }

    AIScene() : _ai_scene(nullptr) {
    }

    ~AIScene() {
    }

    void _init() {} // our initializer called by Godot
    void _process(float delta) {}

    void setScene(const aiScene* ai_scene);

    bool hasAnimations() {
        if (!_ai_scene) { return false; }
        return _ai_scene->HasAnimations();
    }
    bool hasCameras() {
        if (!_ai_scene) { return false; }
        return _ai_scene->HasCameras();
    }
    bool hasLights() {
        if (!_ai_scene) { return false; }
        return _ai_scene->HasLights();
    }
    bool hasMaterials() {
        if (!_ai_scene) { return false; }
        return _ai_scene->HasMaterials();
    }
    bool hasMeshes() {
        if (!_ai_scene) { return false; }
        return _ai_scene->HasMeshes();
    }
    bool hasTextures() {
        if (!_ai_scene) { return false; }
        return _ai_scene->HasTextures();
    }

    godot::Array getCameras() {
        return _cameras;
    }
    void setCameras(godot::Array array) {
        _cameras = array;
    }

private:
    const aiScene* _ai_scene;
    godot::Array _cameras;
};

#endif
