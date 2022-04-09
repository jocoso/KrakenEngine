#include "controllertest.h"

ControllerTest::ControllerTest() {
	pt = new ProtTest("=== CONTROLLER TEST ===");
}

ControllerTest::~ControllerTest() {
	free(pt);
}

void ControllerTest::test_set_get_title() {
	const char* text1 = "=== THE WITNESS ===";
	controller.set_title(text1);
	const char* text2 = controller.get_title();

	pt->test("Can set and retrieve data\n", strcmp(text1, text2) == 0);
}

void ControllerTest::test_run() {
	controller.run();

	pt->test("Controller prints Title!\n", true);
}

void ControllerTest::test_input() {
	const char *say_hi = controller.ask_for_input("Say hi");
	pt->test("Greet Back", strcmp(say_hi, "hi"));
}

void ControllerTest::run() {
	test_set_get_title();
	test_run();
	test_input();

	pt->summary();
}

