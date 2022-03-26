// Console.h
// A displayer for the kraken library
// by Joshua Collado
// as of 3-24-2022

#include "console.h"

void Console::println(const char* prompt) const {
	std::cout << prompt << std::endl;
}

void Console::print(const char* prompt) const {
	std::cout << prompt;
}

// Get user input will take small commands like
// GET SOMETHING
// or
// DO SOMETHING WITH SOMETHING
// Thus there is not need for a big length
const char* Console::println_and_get_response(const char* prompt) const {

	const char* output;
	char* buffer = (char*)malloc(MAX_NAME_LEN * sizeof(char*));

	this->println(prompt);
	std::cin.getline(buffer, MAX_NAME_LEN);

	output = buffer;
	return output;
}

const char* Console::print_and_get_response(const char* prompt) const {

	const char* output;
	char* buffer = (char*)malloc(MAX_NAME_LEN * sizeof(char*));

	this->print(prompt);
	std::cin.getline(buffer, MAX_NAME_LEN);

	output = buffer;
	return output;
	
}

bool Console::are_equal(const char* a, const char* b) const {
	return (strcmp(a, b) == 0);
}