
#ifndef _CONTROLLER_TEST_H_
#define _CONTROLLER_TEST_H_

#include "../krakenLib/controller.h"
#include "../tools/prottest.h"


class ControllerTest {

	Controller controller;
	ProtTest *pt;

public:

	ControllerTest();
	~ControllerTest();
	void test_set_get_title();
	void test_run();
	void test_input();
	void run();

};

#endif // defined(_CONTROLLER_TEST_H_)