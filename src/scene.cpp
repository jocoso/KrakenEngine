#include "../include/props.h"

namespace rawr {
    scene::scene( std::string scene_name, std::string scene_desc ) : rawr_object( scene_name, scene_desc ) {}
    
    std::string scene::get_scene_intro() {
        return "<" + get_name() + ">" + "\n\t" + get_description();
    }

    void scene::add_item_list( std::vector<rawr_object> item_list ) {
        this->item_list = item_list;
    }

    void scene::add_item( rawr_object object ) {
        this->item_list.push_back(object);
    }
}