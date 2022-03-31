#include "world.h"


World::World(Place level_0, Person protagonist) {
	_protagonist = &protagonist;
	_current_location = &level_0;
}

World::World(Person protagonist, Place level_0) {
	_protagonist = &protagonist;
	_current_location = &level_0;
}

void World::add_object_at(Object object, Place location) {
	std::cout << "Adding Object " << object.get_name() << " at " << location.get_name() << std::endl;
}

// Current Location
void World::set_current_location(Place place) {
	_current_location = &place;
}
Place* World::get_current_location() {
	return _current_location;
}

// get and add locations
const unsigned int World::add_location(Place place) {
	// give an id to the place.
	// XXX: Breaks the rules of encapsulation
	place._id = this->_locations_size;
	++_locations_size;

	// maps location name with index
	_registration_table.insert(
		std::pair<const char*, const unsigned int>
		(place.get_name(), place.get_id()));

	_locations.insert(place);

	// add place to the list of places
	return place.get_id();
}
Place World::get_location(const unsigned int location_id) {
	return _locations.get(location_id);
}
Place World::get_location(const char* location_name) {
	int id = -1;

	// Find if object name is registered
	if (_registration_table.count(location_name))
		id = _registration_table[location_name];

	// No? return null, otherwise make a pointer and return it
	if (id < 0) throw std::out_of_range("OUT::OF::BOUNDS");
	else {
		return this->get_location(id);
	}
}


// get and add items and people to locations
Item* World::get_item_at(const char* item_name, const char* location_name) {
	std::cout << "Getting item " << item_name << " at " << location_name << std::endl;

	return NULL;
}

Person* World::get_person_at(const char* person_name, const char* location_name) {
	std::cout << "Getting person " << person_name << " at " << location_name << std::endl;

	return NULL;
}

void World::add_item_at(const unsigned int item_id, const unsigned int location_id) {
	std::cout << "Adding item referenced on " << item_id << " to location referenced on " << location_id << std::endl;
}

void World::add_person_at(const unsigned int person_id, const unsigned int location_id) {
	std::cout << "Adding person referenced on " << person_id << " to location referenced on " << location_id << std::endl;
}

// get and add items and people from currentLocation
Item* World::get_item_here(const char* item_name) {
	std::cout << "Getting item " << item_name << " at current location" << std::endl;
	return NULL;
}
const unsigned int World::set_item_here(Item it) {
	std::cout << "Setting " << it.get_name() << " in current location" << std::endl;
	return 0;
}
const unsigned int World::set_person_here(Person pe) {
	std::cout << "Setting " << pe.get_name() << " in current location" << std::endl;
	return 0;
}
Person* World::get_person_here(const char* person_name) {
	std::cout << "Getting person " << person_name << " at current location" << std::endl;
	return NULL;
}

// get and set current protagonist
Person* World::get_protagonist(void) {
	std::cout << "Getting protagonist" << std::endl;
	return NULL;
}
void World::set_protagonist(Person protagonist) {
	std::cout << "Setting protagonist " << protagonist.get_name() << std::endl;
}
void World::set_protagonist(const char *protagonist_name) {
	std::cout << "Setting protagonist " << protagonist_name << std::endl;
}
void World::set_protagonist(const unsigned int protagonist_id) {
	std::cout << "Setting protagonist found at id " << protagonist_id << std::endl;
}

// remove locations
Place* World::remove_location(const unsigned int location_id) {
	std::cout << "Removing location at id " << location_id << std::endl;
	return NULL;
}

Place* World::remove_location(const char* location_name) {
	std::cout << "Removing location " << location_name << std::endl;
	return NULL;
}

// signup
bool World::signup(Object &obj) {
	std::cout << "Signing " << *obj.get_name() << std::endl;
	return false;
}
bool World::signup(Object &obj, ...) {
	std::cout << "Signing Multiple " << std::endl;
	return false;
}