#include <iostream>
#include <string>
#include "controller.h"

// Function Tests: All the posible user verbs.
void function1(std::string input) {
    if (input == "HELLO")
        std::cout << "HI" << std::endl;
    else
        std::cout << "I CAN'T UNDERSTAND" << std::endl;
}

int main(void) {

    // Create controller and run it.
    Controller *c = new Controller();
    c->add_input_map(&function1);
    c->run();
    delete c;

    return 0;
}