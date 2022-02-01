#include "../include/scene.h"

namespace rawr {
    scene::scene( std::string scene_name, std::string scene_desc ) : rawr_object( scene_name, scene_desc ) {}
    
    std::string scene::get_scene_intro() {
        return "<" + get_name() + ">" + "\n\t" + get_description();
    }
}