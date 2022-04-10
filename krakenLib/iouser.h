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

#ifndef _IO_USER_H_
#define _IO_USER_H_

// Abstract
class IOUser {
public:

	virtual void println(const char* text) = 0;
	virtual void print(const char* text) = 0;
	virtual void wait_for(const char* prompt, const char key) = 0;
	virtual const char *get_input(const char *prompt, const char* caret) = 0;
	virtual ~IOUser() {}

};

#endif