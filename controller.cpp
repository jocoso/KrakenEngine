#include "controller.h"


void Controller::add_input_map(void(*func)(std::string)) {
    this->func = func;
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
    isRunning = true;

    while (isRunning) {
        std::string user_response = this->get_user_input("-->");

        if (user_response == "QUIT") {
            isRunning = false;
        }
        else {
            try {
                this->func(user_response);
            }
            catch (...) {
                exit(1);
            }
        }
    }
}
