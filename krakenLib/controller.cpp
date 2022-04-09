/*
 * This file is part of Kraken.
 *
 * Developed for the LSST Data Management System.
 * This product includes software developed by the LSST Project
 * (https://www.lsst.org).
 * See the COPYRIGHT file at the top-level directory of this distribution
 * for details of code ownership.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include "controller.h"
#include "ioconsole.h"

// Private
// Shows the title of the game
// and prompt [Press Enter to Continue]
void Controller::presentation(void) {
	console->println(this->get_title());
	console->wait_for("\n[Press Enter To Continue]", '\n');
}

// Initializing trinkets.
Controller::Controller() {
	console = new IOConsole();
	caret = "=>";
}

// Destructor
Controller::~Controller() {
}

// Getters and Setters

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
	const char * a = this->console->get_input(prompt, caret); // Display caret and get input from user
	return a;                                                 // XXX: Error Prone.
}