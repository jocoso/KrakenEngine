#include "object.h"

Object::Object(const char* name, const char *description) {
	_name = name;
	_description = description;
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