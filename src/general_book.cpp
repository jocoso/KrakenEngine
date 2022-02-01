#include "../include/general_book.h"

#include <iostream>
#include <string.h>

namespace rawr {
    general_book::general_book() {}

    std::string general_book::exec(const char* input, 
                                   rawr::scene current_scene) {
        if(strcmp(input, "describe") == 0) {
            return this->describe(current_scene);
        } else {
            return "I can't do that.";
        }
    }

    std::string general_book::describe(scene curr_scene) {
        return curr_scene.get_scene_intro();
    }

    general_book::~general_book() {

    }
}