// KrakenController.h
// A user-friendly control library
// by Joshua Collado
// as of 3-23-2022

#ifndef __Prototype__Controller__
#define __Prototype__Controller__

#include "../tools/protstring.h"
#include "../console/console.h"

#define __ControllerPrototype_VERSION__ "0.0.1 Sea Monster"

class Controller {
    Console *_brush;
    void(*_func)(const char *, Console*) = nullptr;
    bool _isRunning;
public:
    Controller();
    ~Controller() { delete _brush; }
    void add_input_map(void (*func)(const char *, Console*));
    static const char* version() { return __ControllerPrototype_VERSION__; }
    void run();
};

#endif /* defined(__Prototype__Controller__) */
