#include "object.h"

Object::Object(const char* name, const char *description) {
	_name = name;
	_description = description;
}

bool operator == (const Object& o1, const Object& o2) {
	return (strcmp(o1._name, o2._name) == 0 &&
		strcmp(o1._description, o2._description) == 0);
}

bool operator != (const Object& o1, const Object& o2) {
	return (strcmp(o1._name, o2._name) != 0 &&
		strcmp(o1._description, o2._description) != 0);
}

const unsigned int Object::get_id(void) {
	return _id;
}

const char* Object::get_name(void) {
	return _name;
}

void Object::set_name(const char* name) {
	_name = name;
}

const char* Object::get_description(void) {
	return _description;
}

void Object::set_description(const char* description) {
	_description = description;
}

Object & Object::operator = (const Object& o) {
	_name = o._name;
	_description = o._description;

	return *this;
}