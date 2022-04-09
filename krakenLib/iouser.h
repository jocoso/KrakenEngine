#ifndef _IO_USER_H_
#define _IO_USER_H_

class IOUser {
public:
	virtual void println(const char* text) = 0;
	virtual void print(const char* text) = 0;
	virtual void wait_for(const char* prompt, const char key) = 0;
	virtual const char *get_input(const char *prompt, const char* caret) = 0;
};

#endif