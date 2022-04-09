#include "controller.h"
#include "ioconsole.h"

void Controller::presentation(void) {
	bool is_waiting = true;

	console->println(this->get_title());
	console->wait_for("\n[Press Enter To Continue]", '\n');
}

Controller::Controller() {
	console = new IOConsole();
	caret = "=>";
}

Controller::~Controller() {
	
}

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
void Controller::run(void) {
	presentation();
}

// caret
void Controller::set_caret(const char* caret) {
	this->caret = caret;
}

const char* Controller::ask_for_input(const char *prompt) {
	const char * a = this->console->get_input(prompt, caret);
	return a;
}