#include <iostream>
#include <string>
#include "kraken/controller/controller.h"
#include "kraken/user/world/world.h"
#include "kraken/user/object/place/place.h"
#include "kraken/user/object/item/item.h"
#include "kraken/user/object/person/person.h"
#include "kraken/tools/prottest.h"

ProtTest pt("=== WORLD ===");
Place p("Place", "A Place");
Person pe("Person", "A Person");
Item it("Item", "An Item");
World w(p, pe);

void testGetCurrentLocationNotNull() {
    Place* p = w.get_current_location();

    pt.test("Current Location not null", p != NULL);
}

void testCurrentLocationIsSameAsPassed() {
    Place* p = w.get_current_location();
    pt.test("Current Location's name same as given at initialization",
        strcmp(p->get_name(), "Place") == 0);
}

void replaceCurrentLocationAndGetCurrentLocation() {
    Place new_place("New Place", "A New Place");
    w.set_current_location(new_place);
    Place* comp_place = w.get_current_location();
    
    pt.test("Current Location is the same as location given",
        strcmp(new_place.get_name(), comp_place->get_name()) == 0); 
}

void testGettingAddingLocation() {
    Place awesome_place("Awesome Place", "It is Awesome");
    unsigned int awesome_p = w.add_location(awesome_place);
    Place test = w.get_location(awesome_p);
    Place test_1 = w.get_location("Awesome Place");

    //pt.test("Location got using get_location(int) is not null", test != NULL);
    //pt.test("Location got using get_location(string) is not null", test_1 != NULL);

    pt.test("Location 0 and 1 are the same:", test == test_1);
        //pt.test("Can read data on tests and the data is the same: ", strcmp(test->get_name(), test_1->get_name()) == 0);
    std::cout << test.get_name() << std::endl;
    std::cout << test_1.get_name() << std::endl;

}

int main(void) {
   
    testGetCurrentLocationNotNull();
    testCurrentLocationIsSameAsPassed();
    replaceCurrentLocationAndGetCurrentLocation();
    testGettingAddingLocation();

    pt.report();

    return 0;
}