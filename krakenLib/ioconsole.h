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

#ifndef _IO_CONSOLE_H_
#define _IO_CONSOLE_H_

#include <cstdio>
#include <iostream>
#include "iouser.h"


class IOConsole : virtual public IOUser {
public:
	IOConsole();

	// Display text on screen (Do not include new line).
	void print(const char* text);
	// Display text on screen (Includes new line).
	void println(const char* text);
	/**
	* Gets an input from the user.
	* 
	* @param[in] prompt Text displayed before asking for input.
	* @param[in] caret A symbol identifying where to input.
	* @return the user input as a char array.
	*/
	const char* get_input(const char* prompt, const char* caret);
	/**
	* Pester user for a particular response.
	* 
	* @param[in] prompt Text displayed before asking for input.
	* @param[in] key Input desired from the player.
	*/
	void wait_for(const char* prompt, const char key);
};

#endif // defined(_IO_CONSOLE_H_)