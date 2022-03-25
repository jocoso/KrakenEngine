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
    const char* foo = c->get_user_response("Write DONE");
    pt.test("String given by the user is the same as the as it asks for:", strcmp(foo, "DONE") == 0);
    pt.report();
    delete c;

}

void function_test(const char* input) {
    
}

void controllerTest() {
    Controller c;
    ProtTest pt("===CONTROLLER===");

}

int main(void) {

    
    

    return 0;
}