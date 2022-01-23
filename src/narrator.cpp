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

        input.clear();
    }

    narrator::~narrator() {}
}