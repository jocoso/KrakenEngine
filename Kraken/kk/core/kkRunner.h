#pragma once

#include <string>
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
public:
	void run(kkOutputManager *outman);
};

#endif // define(__KK_RUNNER_H__)
