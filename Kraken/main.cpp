#include <iostream>

#include "kk/core/kkRunner.h"
#include "kk/core/kkOutputManager.h"

int main(void) {
	kkOutputManager outman;
	kkRunner runner(500, 700, "Trial 1");
	runner.run(&outman);

	return 0;
}
