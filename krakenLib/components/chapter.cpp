#include "chapter.h"

const unsigned int Chapter::add_scene(const char* place_name, Place place) const {
	_map[place_name] = place;

	return 0;
}

Place &Chapter::get_scene(const char* name) {
	return _map[name];
}
std::map<const char*, Place> &Chapter::get_map() {
	return _map;
}
void Chapter::operator = (const Chapter& C) {
	C._id = this->_id;
	std::strcpy((char *)C._intro, this->_intro);
	C._map = this->_map;
}
bool Chapter::operator == (const Chapter& C) const {
	return true;
}
bool Chapter::operator != (const Chapter& C) const {
	return false;
}