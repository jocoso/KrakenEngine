#ifndef _CONTROLLER_H_
#define _CONTROLLER_H_

#include "../tools/arraylist.h"
#include "components/chapter.h"
#include "iouser.h"
#include "ioconsole.h"

class Controller {

	const char* title;
	const char* intro;
	const char* caret;
	IOUser *console;

	void presentation(void);

public:

	Controller();
	~Controller();

	// title
	const char* get_title(void);
	void set_title(const char* title);

	// intro
	const char* get_intro(void);
	void set_intro(const char* intro);

	// caret
	void set_caret(const char* caret);
	const char *ask_for_input(const char *prompt);

	// run
	void run(void);

};

#endif // defined(_CONTROLLER_H_)
