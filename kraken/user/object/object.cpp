#include "object.h"

Object::Object(const unsigned int id,
	const char* name,
	const char* description) {

	this->_id = id;
	this->_name = name;
	this->_description = description;
}

void Object::set_name(const char* new_name) {
	this->_name = new_name;
}

void Object::set_description(const char* new_description) {
	this->_description = new_description;
}