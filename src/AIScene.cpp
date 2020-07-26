#include "AIScene.h"
#include "AICamera.h"

using namespace godot;

void AIScene::setScene(const aiScene* ai_scene) {
    if(!ai_scene) return;
    _ai_scene = ai_scene;

    if (_ai_scene->HasCameras()) {
        _cameras.clear();
        for (int i = 0; i < _ai_scene->mNumCameras; i++) {
            Ref<AICamera> camera;
            camera.instance();
            camera->setCamera(_ai_scene->mCameras[i]);
            _cameras.push_back(camera);
        }
    }
}
