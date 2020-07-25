#ifndef _IMPORTER_H_
#define _IMPORTER_H_

#include <Godot.hpp>
#include <String.hpp>

class AssimpImporter : public godot::Reference {
    GODOT_CLASS(AssimpImporter, godot::Reference)
public:
    static void _register_methods();

    AssimpImporter();
    ~AssimpImporter();

    void _init(); // our initializer called by Godot
    void _process(float delta);
    void import(godot::String path);

private:

};

#endif
