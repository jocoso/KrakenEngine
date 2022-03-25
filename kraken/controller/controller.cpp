// KrakenController.cpp
// A user-friendly control library
// by Joshua Collado
// as of 3-23-2022

#include "controller.h"

Controller::Controller() {
    _brush = new Console();
    _isRunning = false;
}

void Controller::add_input_map(void(*func)(const char *)) {
    this->_func = func;
}


// Render loop
void Controller::run() {
    _isRunning = true;

    while (_isRunning) {
        const char* user_response = this->_brush->get_user_response("-->");
  

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
