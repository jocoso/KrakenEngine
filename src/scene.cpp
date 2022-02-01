#include "../include/scene.h"

namespace rawr {
    scene::scene(std::string name) {
        this->scene_name = name;
    }

    scene::scene(std::string name, std::string new_intro) {
        this->scene_name = name;
        this->scene_intro = new_intro;
    }

    std::string scene::getSceneIntro() {
        return this->scene_intro;
    }

    std::string scene::getSceneName() {
        return this->scene_name;
    }

    void scene::setSceneIntro(const std::string new_intro) {
        this->scene_intro = new_intro;
    }

    void scene::setSceneName(const std::string name) {
        this->scene_name = name;
    }

    scene::~scene() {}
}