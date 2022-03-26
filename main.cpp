#include <iostream>
#include "kraken/controller/controller.h"
#include "kraken/tools/protstring.h"
#include "kraken/tools/prottest.h"

#include <string>

bool summary_flag = false;

void input_function(const char *input) {
    ProtString s = input;
    if (input == "ROSA")
        std::cout << "ROJA" << std::endl;
}

void consoleTest() {

    Console* c = new Console();
    ProtTest pt("===Console===");
    const char* foo = c->println_and_get_response("Write DONE");
    pt.test("String given by the user is the same as the as it asks for:", strcmp(foo, "DONE") == 0);
    pt.report();
    delete c;

}

void function_test(const char* input, Console* console) {
    if (strcmp(input, "ROSE") == 0)
        console->println("ROJA");
    else 
        console->println("I Can't Understand");
    
}

void controllerTest() {
    Controller *c = new Controller();
    ProtTest pt("===CONTROLLER===");
    c->add_input_map(&function_test);
    std::cout << c->version() << std::endl;
    c->run();
    delete c;
}

int main(void) {

    controllerTest();

    return 0;
}