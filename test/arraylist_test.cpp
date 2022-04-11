#include "arraylist_test.h"

void ArrayListTest::test_array_take_objects(){
	
	Chapter c(0, "Josh", "Collado");
	_chapter_test.insert(c);

	pt.test("Object was inserted properly...", _chapter_test.size() > 0);
}

void ArrayListTest::test_array_get_objects(){

	Chapter d = _chapter_test.get(0);

	pt.test("Object was retrieved successfully...", std::strcmp(d.get_name(), "Josh") == 0);

}
void ArrayListTest::run(){
	this->test_array_take_objects();
	this->test_array_get_objects();
	pt.report();

}