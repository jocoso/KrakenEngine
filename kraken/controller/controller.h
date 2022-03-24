// KrakenController.h
// A user-friendly control library
// by Joshua Collado
// as of 3-23-2022

#ifndef __Prototype__Controller__
#define __Prototype__Controller__

#include <string>
#include <iostream>

#define __ControllerPrototype_VERSION "0.0.1 Sea Monster"

class Controller {
    void(*_func)(std::string) = nullptr;
    bool _isRunning;
public:
    void add_input_map(void (*func)(std::string));
    std::string get_user_input(const char* prompt);
    static const char* version() { return __ControllerPrototype_VERSION; }
    void run();
};

#endif /* defined(__Prototype__Controller__) */
