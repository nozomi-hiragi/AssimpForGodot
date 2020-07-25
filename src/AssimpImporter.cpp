  
#include "AssimpImporter.h"

using namespace godot;

void AssimpImporter::_register_methods() {
    register_method("_process", &AssimpImporter::_process);
    register_method("update", &AssimpImporter::update);
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

void AssimpImporter::update() {

}
