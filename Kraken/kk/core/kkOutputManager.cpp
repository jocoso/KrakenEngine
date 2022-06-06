#include "kkOutputManager.h"

/**
	CS-11 Controls the input and output of 
	terminal windows.
	@file kkOutputRunner.cpp
	@author Joshua C
	@version 1.1 6/6/22
*/

// Constructor and Destructor
kkOutputManager::kkOutputManager() {
	// Loading font
	if (!font.loadFromFile("C:\\Users\\Josh\\Desktop\\Programming\\Kraken\\Kraken\\kk\\tools\\fonts\\ao.ttf")) {
		throw "Couldn't Load Font.";
	}
}
kkOutputManager::~kkOutputManager() {}

/**
	Prints a question for the player
	Waits for the player to press enter
	returns the answer to whoever asked.
	@param win: The window we are writing in
	@param what: Question prompted to the player
	@return Player's answer
*/
std::string kkOutputManager::askUserInput(sf::RenderWindow *win, std::string what) {
	return "";
}

/**
	Returns an input iff the input is an integer
	@param win: The window we are writing in
	@param what: Question prompted to the player
	@return the user's answer as an integer
*/
int kkOutputManager::askUserNumericInput(sf::RenderWindow *win, std::string what) {
	return 0;
}

/**
	Prints text on the window screen
	@param win: The window we are writing in
	@param what: What to write on the screen
*/
void kkOutputManager::print(sf::RenderWindow *win, std::string what) {
	sf::Text text;
	// Select the font
	text.setFont(font);

	// Set the string to display
	text.setString(what);

	// Set size
	text.setCharacterSize(200);

	// Set Color
	text.setFillColor(sf::Color::Red);

	text.setStyle(sf::Text::Bold);



	win->draw(text);

}