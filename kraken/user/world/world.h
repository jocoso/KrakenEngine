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
	std::map<const char*, const unsigned int> _registration_table;
	//std::map<const char*, const unsigned int>::iterator _registaration_iterator;
	ArrayList<Place> _locations;
	Person *_protagonist = NULL;
	Place *_current_location = NULL;
	unsigned int _locations_size = 0;

	void add_object_at(Object object, Place location);
public:
	World(Place level_0, Person protagonist);
	World(Person protagonist, Place level_0);

	// Current Location
	void set_current_location(Place place);
	Place* get_current_location();


	// Getting and Adding Location
	Place get_location(const unsigned int place_id);
	Place get_location(const char* place_name);
	const unsigned int add_location(Place place);

	// get and add items
		// Current Location
	Item* get_item_here(const char* item_name);
	const unsigned int set_item_here(Item it);
		// At given location
	Item *get_item_at(const char *item_name, const char *location_name);
	void add_item_at(const unsigned int item_id, const unsigned int location_id);
	

	// get and add people
	const unsigned int set_person_here(Person pe);
	Person *get_person_here(const char* person_name);
	void add_person_at(const unsigned int person_id, const unsigned int location_id);
	Person* get_person_at(const char* person_name, const char* location_name);
	

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