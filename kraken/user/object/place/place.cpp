#include "place.h"

Place::Place(const char* name, 
			const char* description, 
			const char* introduction) 
			: Object(0, name, description) {
	
	this->_introduction = introduction;
}

Place::Place(const char* name,
	const char* description) : Object(0, name, description) {
	this->_introduction = "Place has not been written an introduction";
}