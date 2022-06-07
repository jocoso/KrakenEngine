#pragma once

#include <string>
#include <list>
#include <SFML/Graphics.hpp>

#include "kkOutputManager.h"

#ifndef __KK_RUNNER_H__
#define __KK_RUNNER_H__

class kkRunner
{
public:
	kkRunner(int height, int width, std::string title);
	~kkRunner();
private:
	sf::RenderWindow window;
	sf::Event event;
	std::list<std::string> log;
	std::list<std::string>::iterator it;
	std::string txt;
public:
	void run(kkOutputManager *outman);
private:
	void event_handler(kkOutputManager *outman);
	void enter_handler(kkOutputManager *outman);
};

#endif // define(__KK_RUNNER_H__)
