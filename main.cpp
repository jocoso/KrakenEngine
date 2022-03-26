#include <iostream>
#include "kraken/controller/controller.h"
#include "kraken/tools/protstring.h"
#include "kraken/tools/prottest.h"
#include "kraken/user/object/item/item.h"
#include "kraken/user/object/place/place.h"
#include "kraken/user/object/person/person.h"
#include "kraken/user/object/object.h"

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

void testPlacePersonAndItem() {
    Item* i;
    Person* p;
    Place* pl;
    try {
        ProtTest pt("== ITEM, PERSON, PLACE ===");

        i = new Item("Test Item", "Just a Test");
        p = new Person("Test Person", "Just a Test");
        pl = new Place("Test Place", "Just a Test");

        pt.test("Information can be safetly stored and retrieved from Item", strcmp(i->get_name(), "Test Item") == 0);
        pt.test("Information can be safetly stored and retrieved from Person", strcmp(p->get_name(), "Test Person") == 0);
        pt.test("Information can be safetly stored and retrieved from Place", strcmp(pl->get_name(), "Test Place") == 0);
        
        pt.report();

        delete i, p, pl;
    }catch(...) {
        std::cout << "NONONO" << std::endl;
        throw;
    }

}

void testPolymorphicObject() {
    ProtTest pt("=== Polymorphic Object ===");
    
    Item i("name", "desc");
    Person p("name", "desc");
    Place pl("name", "desc");

    Object* obj[]{ &i, &p, &pl};

    for (int i = 0; i < 3; i++) {
        pt.test("Can access item, person, place as an object type?", strcmp(obj[i]->get_name(), "name") == 0);
    }

    pt.report();

}

int main(void) {

    testPolymorphicObject();

    return 0;
}