/**
	CS-11 Main window of the engine
	@file kkRunner.cpp
	@author Joshua C
	@version 1.1 6/6/22
*/


#include "kkRunner.h"

kkRunner::kkRunner(int height, int width, std::string title) {
	window.create(sf::VideoMode(width, height), title);
}

kkRunner::~kkRunner() {}

/**
	Controls program main loop
	@param None
	@return None
*/
void kkRunner::run() {

	while (window.isOpen()) {
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}
	}

}
