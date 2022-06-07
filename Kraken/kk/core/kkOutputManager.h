#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

#include <experimental/filesystem>

#ifndef __KK_OUTMAN_H__
#define __KK_OUTMAN_H__
class kkOutputManager
{

public:
	kkOutputManager();
	~kkOutputManager();

private:
	sf::Font font;

public:
	std::string askUserInput(sf::RenderWindow *win, std::string what);
	int askUserNumericInput(sf::RenderWindow *win, std::string what);
	void print(sf::RenderWindow *win, std::string what, float x = 0.0f, float y = 0.0f);

};

#endif // define(__KK_OUTMAN_H__)

