#include "ioconsole.h"

IOConsole::IOConsole() {

}

void IOConsole::print(const char* text) {
	printf(text);
}

void IOConsole::println(const char* text) {
	printf("%s\n", text);
}

void IOConsole::wait_for(const char *prompt, const char key) {
	println(prompt);
	char a = 0;


	while (std::cin.get() != key) {
		
	}
}

const char *IOConsole::get_input(const char *prompt, const char* caret) {
	
	println(prompt);
	print(caret);
	// XXX: FIX THIS
	char a[500];

	std::cin.get(a, 500);

	return a;
}