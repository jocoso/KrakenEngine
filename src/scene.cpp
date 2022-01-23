#include "../include/scene.h"

namespace rawr {
    scene::scene() {}

    scene::scene(std::string new_intro) {
        scene_intro = new_intro;
    }

    std::string scene::getSceneIntro() {
        return scene_intro;
    }

    void scene::setSceneIntro(std::string new_intro) {
        scene_intro = new_intro;
    }

    scene::~scene() {}
}