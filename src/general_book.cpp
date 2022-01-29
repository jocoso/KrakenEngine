#include "../include/general_book.h"

#include <iostream>
#include <string.h>


namespace rawr {
    general_book::general_book() {

    }

    std::string general_book::exec(std::vector<std::string> input, 
                                   rawr::scene current_scene) {
        if(strcmp(input[0].c_str(), "describe") == 0) {
            return this->describe(current_scene);
        } else {
            return "I can't do that.";
        }
    }

    std::string general_book::describe(rawr::scene curr_scene) {
        return curr_scene.getSceneIntro();
    }

    general_book::~general_book() {

    }
}