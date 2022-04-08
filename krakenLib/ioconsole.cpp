#include "ioconsole.h"

IOConsole::IOConsole() {

}

void IOConsole::print(const char* text) {
	printf(text);
}

void IOConsole::println(const char* text) {
	printf("%s\n", text);
}