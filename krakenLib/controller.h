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

#ifndef _CONTROLLER_H_
#define _CONTROLLER_H_

#include "../tools/arraylist.h"
#include "components/chapter.h"
#include "iouser.h"
#include "ioconsole.h"

// Brains
class Controller {

	// Private
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
