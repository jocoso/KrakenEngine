#include "controllertest.h"

ControllerTest::ControllerTest() {
	pt = new ProtTest("=== CONTROLLER TEST ===");
}

ControllerTest::~ControllerTest() {
	free(pt);
}

void ControllerTest::test_set_get_title() {
	const char* text1 = "joshua collado";
	controller.set_intro(text1);
	const char* text2 = controller.get_intro();

	pt->test("Can set and retrieve data\n", strcmp(text1, text2) == 0);
}

void ControllerTest::test_run() {
	controller.run();

	pt->test("Controller prints Hello World!\n", true);
}

void ControllerTest::run() {
	test_set_get_title();
	test_run();

	pt->summary();
}

