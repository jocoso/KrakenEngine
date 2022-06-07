/**
	CS-11 Main window of the engine
	@file kkRunner.cpp
	@author Joshua C
	@version 1.1 6/6/22
*/
#include "kkRunner.h"

// Constructor and Destructor
kkRunner::kkRunner(int height, int width, std::string title) {
	window.create(sf::VideoMode(width, height), title);
	txt = "";
}
kkRunner::~kkRunner() {}

void kkRunner::enter_handler(kkOutputManager *outman) {
	std::cout << "ENTER" << std::endl;
	log.push_back(txt);
	txt = "";
}

void kkRunner::event_handler(kkOutputManager *outman) {
	if (event.type == sf::Event::Closed) {
		window.close();
	}

	if (event.type == sf::Event::TextEntered) {

		sf::Uint32 unicode = event.text.unicode;

		if (unicode < 128) {
			if (unicode == 8 && txt.length() > 0) {
				txt.pop_back();
			}
			else if(unicode == 13 && txt.length() > 0) {
				enter_handler(outman);
			}
			else if (txt.length() < 40 && unicode != 8) { // Magic number here
				txt += static_cast<char>(event.text.unicode);
				std::cout << unicode << std::endl;
			}
		} else
			std::cout << unicode << std::endl;

	}
}

/**
	Controls program main loop
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
		outman->print(&window, txt, 5.0f, window.getSize().y - 50);
		for (std::string log_entry : log) {
			outman->print(&window, log_entry, 5.0f, 50.0f * (i++));
		}

		i = 0;

		window.display();
	}

}
