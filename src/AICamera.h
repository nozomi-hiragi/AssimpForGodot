#ifndef _AI_CAMERA_H_
#define _AI_CAMERA_H_

#include <Godot.hpp>
#include <assimp/camera.h>

#include <string>

class AICamera : public godot::Reference {
    GODOT_CLASS(AICamera, godot::Reference)
public:
    static void _register_methods(){
        godot::register_method("_process", &AICamera::_process);
        godot::register_method("get_aspect", &AICamera::getAspect);
        godot::register_method("get_far", &AICamera::getFar);
        godot::register_method("get_near", &AICamera::getNear);
        godot::register_method("get_fov", &AICamera::getFOV);
        godot::register_method("get_look_at", &AICamera::getLookAt);
        godot::register_method("get_name", &AICamera::getName);
        godot::register_method("get_position", &AICamera::getPosition);
        godot::register_method("get_up", &AICamera::getUp);
    }

    AICamera() {
        AICamera(nullptr);
    }

    AICamera(const aiCamera* ai_camera) : _ai_camera(ai_camera) {
    }

    ~AICamera() {
    }

    void _init() {} // our initializer called by Godot
    void _process(float delta) {}

    void setCamera(const aiCamera* ai_camera) {
        _ai_camera = ai_camera;
    }

    float getAspect() {
        if (!_ai_camera) { return 0; }
        return _ai_camera->mAspect;
    }
    float getFar() {
        if (!_ai_camera) { return 0; }
        return _ai_camera->mClipPlaneFar;
    }
    float getNear() {
        if (!_ai_camera) { return 0; }
        return _ai_camera->mClipPlaneNear;
    }
    float getFOV() {
        if (!_ai_camera) { return 0; }
        return _ai_camera->mHorizontalFOV;
    }
    godot::Vector3 getLookAt() {
        if (!_ai_camera) { return godot::Vector3(); }
        auto look_at = _ai_camera->mLookAt;
        return godot::Vector3(look_at.x, look_at.y, look_at.z);
    }
    godot::String getName() {
        if (!_ai_camera) { return godot::String(); }
        return _ai_camera->mName.C_Str();
    }
    godot::Vector3 getPosition() {
        if (!_ai_camera) { return godot::Vector3(); }
        auto pos = _ai_camera->mPosition;
        return godot::Vector3(pos.x, pos.y, pos.z);
    }
    godot::Vector3 getUp() {
        if (!_ai_camera) { return godot::Vector3(); }
        auto up = _ai_camera->mUp;
        return godot::Vector3(up.x, up.y, up.z);
    }

private:
    const aiCamera* _ai_camera;
};

#endif
