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

#ifndef __Array__List__
#define __Array__List__

#include <iostream>
#include <cstdlib>
#define CONSTANT_INCREMENT 20

// Why not?
template <class T> class ArrayList {
	T** _array = NULL;
	unsigned int _size = 0;
	size_t _max_size;

	bool is_full() {
		return _size >= _max_size-1;
	}

	void resize() {
		std::cout << "Resize Array" << std::endl;

		// Make a new array twice the size of the previous
		size_t twice = 2 * _max_size;
		T** new_array = (T**) std::malloc(twice * sizeof(T*));

		// Copy everything on one array into the other
		std::copy(_array, _array + _max_size, new_array);

		// Delete previous array
		delete[] _array;
		_max_size = twice;

		// Replace one array with the other.
		_array = new_array;

	}

public:
	ArrayList() {
		_array = (T**) std::calloc(CONSTANT_INCREMENT, sizeof(T*));
		_max_size = CONSTANT_INCREMENT;
	}

	~ArrayList() {
		delete[] _array;
	}

	void insert(T obj) {
		if (is_full()) resize();
		
		if (_array == NULL) {
			throw std::overflow_error("NULL::ARRAY");
		}

		_array[_size] = &obj;
		++_size;
	}
	void replace(unsigned int idx, T obj) {

		std::cout << "Replacing " << obj << " at index " << idx << std::endl;
		if (idx > _size) {
			std::cout << "ERROR: No Valid Value For Index " << idx << std::endl;
			return;
		}
		_array[idx] = &obj;

	}

	T get(unsigned int idx) {
		std::cout << "Getting item at index " << idx << std::endl;
		if (_array == NULL) {
			std::cout << "ARRAY IS NULL" << std::endl;
			throw std::overflow_error("NULL::ARRAY");
		}

		return *_array[idx];
	}

	T remove(unsigned int idx) {
		std::cout << "Removing item at index " << idx << std::endl;

		if (idx > _size) return NULL;

		T *item = _array[idx];
		--_size;

		return *item;
	}

	void reset() {
		std::cout << "Resetting instance... " << std::endl;
		delete[] _array;
		_array = (T**)malloc(CONSTANT_INCREMENT * sizeof(T*));
		_max_size = CONSTANT_INCREMENT;
		_size = 0;
	}

	bool is_empty() {
		std::cout << "Is Empty, always." << std::endl;
		return _size > 0;
	}
	size_t size() {
		std::cout << "Does not matter." << std::endl;
		return _size;
	}
};


#endif // defined(__ArrayList__)

