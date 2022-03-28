#ifndef __Prototype__World__H__
#define __Prototype__World__H__

#include "../object/object.h"
#include "../object/item/item.h"
#include "../object/person/person.h"
#include "../object/place/place.h"
#include "../../tools/arraylist.h"
#include <map>
#include <varargs.h>
#include <iostream>

class World {
	std::map<const char*, const unsigned int> registration_table;
	ArrayList<Place> _locations;
	Person _protagonist;
	Place _current_location;

	void add_object_at(Object object, Place location);
public:
	// get and add locations
	Place *get_location(const unsigned int id);
	const unsigned int add_location(Place place);
	// get and add items and people to locations
	Item *get_item_at(const char *item_name, const char *location_name);
	Person *get_person_at(const char* person_name, const char* location_name);

	void add_item_at(const unsigned int item_id, const unsigned int location_id);
	void add_person_at(const unsigned int person_id, const unsigned int location_id);
	void set_item_here(Item& it);
	void set_person_here(Person& pe);

	// get and add items and people from currentLocation
	Item *get_item_here(const char* item_name);
	const unsigned int set_item_here(Item it);
	const unsigned int set_person_here(Person pe);
	Person *get_person_here(const char* person_name);
	void set_current_location(Place place);
	void set_current_location(const char * place_name);
	void set_current_location(const unsigned int place_id);

	// get and set current protagonist
	Person *get_protagonist(void);
	void set_protagonist(Person protagonist);
	void set_protagonist(const char* protagonist_name);
	void set_protagonist(const unsigned int protagonist_id);

	// remove locations
	Place *remove_location(const unsigned int location_id);
	Place *remove_location(const char* location_name);

	// signup
	bool signup(Object &obj);
	bool signup(Object &obj, ...);
};

#endif // defined(__Prototype__World__H__)