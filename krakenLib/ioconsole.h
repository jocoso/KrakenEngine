#ifndef _IO_CONSOLE_H_
#define _IO_CONSOLE_H_

#include <cstdio>
#include <iostream>
#include "iouser.h"

class IOConsole : virtual public IOUser {
public:
	IOConsole();
	void print(const char* text);
	void println(const char* text);
	const char* get_input(const char* prompt, const char* caret);
	void wait_for(const char* prompt, const char key);
};

#endif // defined(_IO_CONSOLE_H_)