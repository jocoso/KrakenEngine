#include "../include/general_book.h"

#include <iostream>
#include <string.h>

namespace rawr {
    general_book::general_book() {
        this->init();
    }

    std::string general_book::exec(const char* input, 
                                   rawr::scene current_scene) {

        line a = script.back();
        script.pop_back();

        return a.prompt + " " + print_options(a.options);
    }

    std::string general_book::print_options( std::vector<std::string> list ) {
        std::string out = "\n";
        for(int i = 0; i < list.size(); i++) {
            out.append( std::to_string(i + 1) + ") " + list[i]  + "\n");  
        }

        return out;
    }

    void general_book::init() {
        line line1;
        line1.prompt = "Hi, my name is _________(name)";
        line1.options.push_back("Joshua");
        line1.options.push_back("Collado");
        auto a = [] (std::string a){return a;};
        line1.action = &a;
        script.push_back(line1);
    }

    std::string general_book::describe(scene curr_scene) {
        return curr_scene.get_scene_intro();
    }

    general_book::~general_book() {

    }
}