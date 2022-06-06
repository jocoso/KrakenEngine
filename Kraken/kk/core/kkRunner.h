#pragma once

#include <string>
#include <SFML/Window.hpp>

#ifndef __KK_RUNNER_H__
#define __KK_RUNNER_H__

class kkRunner
{
public:
	kkRunner(int height, int width, std::string title);
	~kkRunner();
private:
	sf::Window window;
	sf::Event event;
public:
	void run();
};

#endif
