#include <iostream>
#include "kraken/controller/controller.h"
#include "kraken/tools/protstring.h"
#include "kraken/tools/prottest.h"
#include "kraken/tools/arraylist.h"

#include "kraken/user/object/object.h"
#include "kraken/user/object/item/item.h"

#include <string>

ProtTest pt("=== OBJECTS ===");



void testGetters() {

    Item it("Item", "It is an item");
    Object* getter_list[] = { &it };
    const char* names[] = { "Item" };
    int size = 1;

    for (int i = 0; i < size; i++) {
        pt.test(
            "Testing Getter: ",
            strcmp(getter_list[i]->get_name(),
                names[i]) == 0
        );
    }

}

void testSetters() {
    
    Item it("Item", "It is an item");
    Object* getter_list[] = { &it };
    const char* names[] = { "Bell" };
    int size = 1;

    for (int i = 0; i < size; i++) {
        getter_list[i]->set_name(names[i]);
    }

    for (int i = 0; i < size; i++) {
        pt.test(
            "Testing Getter: ",
            strcmp(getter_list[i]->get_name(),
                names[i]) == 0
        );
    }
}


int main(void) {
    
    testGetters();
    testSetters();
    
    return 0;
}