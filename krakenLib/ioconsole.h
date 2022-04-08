#ifndef _IO_CONSOLE_H_
#define _IO_CONSOLE_H_

#include <cstdio>
#include "iouser.h"

class IOConsole : virtual public IOUser {
public:
	IOConsole();
	void print(const char* text);
	void println(const char* text);
};

#endif // defined(_IO_CONSOLE_H_)