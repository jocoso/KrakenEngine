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

    ProtTest pt("===INPUT===");
    if (console->are_equal(input, "JUMP")) {
        pt.test("Input is the same as JUMP?", strcmp(input, "JUMP") == 0);
        console->println("How High?");
    } else if (console->are_equal(input, "GO")) {
        pt.test("Input is the same as GO?", strcmp(input, "GO") == 0);
        console->println("Where?");
    } else if (console->are_equal(input, "TAKE")) {
        pt.test("Input is the same as TAKE?", strcmp(input, "TAKE") == 0);
        console->println("What?");
    } else if(console->are_equal(input, "KILL")) {
        pt.test("Input is the same as KILL?", strcmp(input, "KILL") == 0);
        console->println("Whom?");
    } else {
        console->println("I Can't Understand");
    }

}

void controllerTest() {
    Controller *c = new Controller();
    
    c->add_input_map(&function_test);
    std::cout << c->version() << std::endl;
    c->run();
    delete c;
}

int main(void) {

    controllerTest();

    return 0;
}