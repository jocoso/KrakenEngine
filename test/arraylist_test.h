#ifndef _ARRAYLIST_TEST_H_
#define _ARRAYLIST_TEST_H_

#include "../tools/arraylist.h"
#include "../tools/prottest.h"
#include "../krakenLib/components/chapter.h"

#include <string>

class ArrayListTest {
	ArrayList<Chapter> _chapter_test;
	ProtTest pt;

public:
	ArrayListTest() : pt("=== ARRAY LIST TEST ===") {}
	void test_array_take_objects();
	void test_array_get_objects();
	void run();
};

#endif