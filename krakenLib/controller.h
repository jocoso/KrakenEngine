#ifndef _CONTROLLER_H_
#define _CONTROLLER_H_

#include "../tools/arraylist.h"
#include "components/chapter.h"
#include "iouser.h"
#include "ioconsole.h"

class Controller {

	const char* title;
	const char* intro;
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

	// run
	void run(void);

};

#endif // defined(_CONTROLLER_H_)
