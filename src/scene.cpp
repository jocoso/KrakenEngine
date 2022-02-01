#include "../include/scene.h"

namespace rawr {
    scene::scene() : rawr_object() {}
    scene::scene(std::string name, std::string new_intro) : rawr_object(name, new_intro) {}

    std::string scene::get_scene_intro() {
        return this->description;
    }

    void scene::set_scene_intro(const std::string new_intro) {
        this->description = new_intro;
    }

    scene::~scene() {}
}