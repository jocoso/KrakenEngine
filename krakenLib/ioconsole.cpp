/*
 * This file is part of Kraken.
 *
 * Developed for the LSST Data Management System.
 * This product includes software developed by the LSST Project
 * (https://www.lsst.org).
 * See the COPYRIGHT file at the top-level directory of this distribution
 * for details of code ownership.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include "ioconsole.h"

IOConsole::IOConsole() {
	// Initialize in the future
}

void IOConsole::print(const char* text) {
	printf(text); // XXX: Change printf to something safer.
}

void IOConsole::println(const char* text) {
	printf("%s\n", text);  // XXX: Change printf to something safer.
}

void IOConsole::wait_for(const char *prompt, const char key) {
	println(prompt);
	while (std::cin.get() != key); // Kinda ridiculous you can actually do something like this out of a whim.
}

const char *IOConsole::get_input(const char *prompt, const char* caret) {
	
	println(prompt);
	print(caret);
	// XXX: FIX THIS
	char a[500];			// XXX: Replace for custom made string
	std::cin.get(a, 500);	// XXX: Pre-scream -> Code -> Cry -> Wash -> Rinse -> Repeat.
							// XXX: Infinite loop of life.

	return a;
}