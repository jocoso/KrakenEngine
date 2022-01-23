#include "../include/narrator.h"
#include <iostream>

namespace rawr{
    narrator::narrator() {}

    void narrator::exec(std::vector<std::string> &input) {
        if(input.size() < 2) {
            // This message will be modifiable by the users in the future.
            std::cout << "Not an input I can recognize." << std::endl;
            return;
        }

        std::cout << "Directive: " << input[0] << std::endl;
        std::cout << "Object: " << input[1] << std::endl;

        input.clear();
    }

    narrator::~narrator() {}
}