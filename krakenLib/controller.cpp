#include "controller.h"
#include "ioconsole.h"

void Controller::presentation(void) {
	
}


Controller::Controller() {}

// title
const char* Controller::get_title(void) {
	return title;
}

void Controller::set_title(const char* title) {
	this->title = title;
}

// intro
const char* Controller::get_intro(void) {
	return intro;
}

void Controller::set_intro(const char* intro) {
	this->intro = intro;
}

// run
void Controller::run(void) {}