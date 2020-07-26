#ifndef _IMPORTER_H_
#define _IMPORTER_H_

#include <Godot.hpp>
#include <String.hpp>

#include <assimp/Importer.hpp>

class AIScene;

class AssimpImporter : public godot::Reference {
    GODOT_CLASS(AssimpImporter, godot::Reference)
public:
    static void _register_methods();

    AssimpImporter();
    ~AssimpImporter();

    void _init(); // our initializer called by Godot
    void _process(float delta);
    godot::Ref<AIScene> import(godot::String path);

    godot::Ref<AIScene> getScene() { return _ai_scene; }

private:
    Assimp::Importer _importer;
    godot::Ref<AIScene> _ai_scene;
};

#endif
