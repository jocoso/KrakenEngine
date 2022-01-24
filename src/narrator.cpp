#include "../include/narrator.h"
#include <iostream>

namespace rawr{
    narrator::narrator() {
        current_room = 0;
    }

    std::string narrator::exec(std::vector<std::string> &input) {
        if(input.size() < 2) {
            // This message will be modifiable by the users in the future.
            return "Not an input I can recognize.";
        }

        input.clear();

        return "I don't know what to tell you.";
    }

    void narrator::learnScene(rawr::scene &new_scene){
        scenes.push_back(new_scene);
    }

    bool narrator::knowScenes(){
        return (scenes.size() > 0) ? true : false;
    }

    std::string narrator::describeScene() {
        if(this->knowScenes() == true) {
            return scenes[current_room].getSceneIntro();
        }

        std::string a = "I'm sorry. I don't know.";

        return a;
    }

    narrator::~narrator() {}
}