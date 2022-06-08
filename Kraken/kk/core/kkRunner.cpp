/**
	CS-11 Main window of the engine
	@file kkRunner.cpp
	@author Joshua C
	@version 1.1 6/6/22
*/
#include "kkRunner.h"

#define _ENTER 13
#define _BACKSPACE 8

#define MAX_INPUT 40

// Constructor and Destructor
kkRunner::kkRunner(int height, int width, std::string title) {
	window.create(sf::VideoMode(width, height), title);
	input = "";
}
kkRunner::~kkRunner() {}

/**
	Executes when the player press enter
	@param The output manager to display in the window
*/
void kkRunner::enter_handler(kkOutputManager *outman) {
	if (input.length() > 0) {
		log.push_back(input);
		input = "";
	}
}

/**
	Execute when the player press delete
*/
void kkRunner::delete_handler() {
	if(input.length() > 0)
		input.pop_back();
}

/**
	Controls how inputs will be displayed on the input bar
	@param A integer representing an unicode character
*/
void kkRunner::input_handler(sf::Uint32 unicode) {
	if (input.length() <= MAX_INPUT && unicode != _BACKSPACE) {
		input += static_cast<char>(unicode);
	}
}

/**
	Manages events
	@param The output manager to display in the window
*/
void kkRunner::event_handler(kkOutputManager *outman) {
	if (event.type == sf::Event::Closed) {
		window.close();
	}

	if (event.type == sf::Event::TextEntered) {

		sf::Uint32 unicode = event.text.unicode;

		if (unicode < 128) {
			switch (unicode) {

				case _BACKSPACE: 								// User press delete
						delete_handler();
				case _ENTER:									// User pressed enter
						enter_handler(outman);
				default:										// Adds letter to input
						input_handler(unicode);
		
			}
		}

	}
}

/**
	Controls the program main loop
	@param The output manager
	@return None
*/
void kkRunner::run(kkOutputManager *outman) {
	int i = 0;
	while (window.isOpen()) {
		while (window.pollEvent(event)) {
			
			// Handle Events duh
			event_handler(outman);

		}

		window.clear(sf::Color::White);
		outman->print(&window, input, 5.0f, window.getSize().y - 50);
		for (std::string log_entry : log) {								// Prints the log
			outman->print(&window, log_entry, 5.0f, 50.0f * (i++));  
		}

		i = 0;

		window.display();
	}

}
