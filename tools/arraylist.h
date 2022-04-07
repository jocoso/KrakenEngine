#ifndef __Array__List__
#define __Array__List__

#include <iostream>
#include <cstdlib>
#define CONSTANT_INCREMENT 20


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

