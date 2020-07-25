#include <Godot.hpp>

extern "C" void GDN_EXPORT assimp_gdnative_init(godot_gdnative_init_options *o) {
    godot::Godot::gdnative_init(o);
}

extern "C" void GDN_EXPORT assimp_gdnative_terminate(godot_gdnative_terminate_options *o) {
    godot::Godot::gdnative_terminate(o);
}

extern "C" void GDN_EXPORT assmp_nativescript_init(void *handle) {
    godot::Godot::nativescript_init(handle);

    // Todo add some classes
    //godot::register_class<>();
}
