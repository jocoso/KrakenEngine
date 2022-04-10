#ifndef _DAO_TEST_H_
#define _DAO_TEST_H_

#include <iostream>

#include "../tools/prottest.h"
#include "../krakenLib/daoimpl.h"
#include "../krakenLib/daoimpl.h"
#include "../krakenLib/components/chapter.h"

class DaoTest {
	ProtTest *pt;
	Dao* dao;

public:
	DaoTest();
	void test_adding_getting_chapter();
	void run();
};

#endif