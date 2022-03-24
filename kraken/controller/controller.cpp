// KrakenController.cpp
// A user-friendly control library
// by Joshua Collado
// as of 3-23-2022

#include "controller.h"

void Controller::add_input_map(void(*func)(std::string)) {
    this->_func = func;
}

// Helper method
std::string Controller::get_user_input(const char* prompt) {
    std::string line;

    std::cout << prompt;
    std::getline(std::cin, line);

    return line;
}

// Render loop
void Controller::run() {
    _isRunning = true;

    while (_isRunning) {
        std::string user_response = this->get_user_input("-->");

        if (user_response == "QUIT") {
            _isRunning = false;
        }
        else {
            try {
                this->_func(user_response);
            }
            catch (...) {
                exit(1);
            }
        }
    }
}
