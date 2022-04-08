#ifndef _IO_USER_H_
#define _IO_USER_H_

class IOUser {
public:
	virtual void println(const char* text) = 0;
	virtual void print(const char* text) = 0;
};

#endif