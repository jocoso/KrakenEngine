#include "../include/general_book.h"

#include <iostream>
#include <string.h>

namespace rawr {
    general_book::general_book() {

    }

    std::string general_book::exec(std::vector<std::string> input) {
        if(strcmp(input[0].c_str(), "describe") == 0) {
            return this->describe(input[1]);
        } else {
            return "I can't do that.";
        }
    }

    std::string general_book::describe(std::string obj) {
        return "Describe " + obj;
    }

    general_book::~general_book() {

    }
}