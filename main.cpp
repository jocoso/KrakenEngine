#include <iostream>
#include <string>
#include "kraken/controller/controller.h"
#include "kraken/user/world/world.h"
#include "kraken/user/object/place/place.h"
#include "kraken/user/object/item/item.h"
#include "kraken/user/object/person/person.h"




int main(void) {
    Place *p = new Place("Place", "A Place");
    Person *pe = new Person("Person", "A Person");
    Item it("Item", "An Item");

    World w(p, pe);

    delete p;

    return 0;
}