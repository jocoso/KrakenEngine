#include "../include/general_book.h"

#include <iostream>
#include <string.h>

namespace rawr {
    general_book::general_book() {}

    string general_book::exec(const char* input, 
                                   scene current_scene) {
        if(this->compare(input, "describe")) {
            return describe(current_scene);
        }

        return "I am not sure what you are trying to say.";
    }

    string general_book::describe(scene curr_scene) {
        return curr_scene.get_scene_intro();
    }

    general_book::~general_book() {}
}