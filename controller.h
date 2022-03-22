#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <string>
#include <iostream>

class Controller {
    void(*func)(std::string) = 0;
    bool isRunning;
public:
    void add_input_map(void (*func)(std::string));
    std::string get_user_input(const char* prompt);
    void run();
};

#endif // Controller.h
