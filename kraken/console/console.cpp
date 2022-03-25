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
const char* Console::get_user_response(const char* prompt) const {
	const char* output;
	char* buffer = (char*)malloc(MAX_NAME_LEN * sizeof(char*));

	this->println(prompt);
	std::cin.getline(buffer, MAX_NAME_LEN);

	output = buffer;

	return output;
}


//ProtString Console::get_user_response(const char* prompt) {
//	return NULL;
//}