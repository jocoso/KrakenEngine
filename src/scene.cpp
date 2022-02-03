#include "../include/prop.h"
#include "../include/scene.h"

namespace rawr {
    scene::scene( std::string scene_name, std::string scene_desc ) : prop( scene_name, scene_desc ) {}
    
    std::string scene::get_scene_intro() {
        return "<" + get_name() + ">" + "\n\t" + get_description();
    }

    void scene::add_item_list( std::vector<prop> item_list ) {
        this->item_list = item_list;
    }

    void scene::add_item( prop object ) {
        this->item_list.push_back( object );
    }
}