// Console.h
// A displayer for the kraken library
// by Joshua Collado
// as of 3-24-2022

#ifndef __Prototype__Console__H
#define __Prototype__Console__H

#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <string>
#include "../tools/protstring.h"

#define MAX_NAME_LEN 50

class Console {
public:
	void println(const char *promp) const;
	void print(const char *prompt) const;
	const char* println_and_get_response(const char* prompt) const;
	const char* print_and_get_response(const char* prompt) const;
	bool are_equal(const char* a, const char* b) const;
};

#endif /*defined(__Prototype__Console__H)*/