#include "daotest.h"

DaoTest::DaoTest() {

	pt = new ProtTest("=== DAO TEST ===");
	dao = new DaoImpl();

}

void DaoTest::test_adding_getting_chapter() {

	Chapter chapter;
	chapter.name = "josh";

	// SET
	const unsigned int chapter_id = dao->add_chapter(chapter);
	pt->test("Chapter is added properly", chapter_id == 0);

	// GET
	Chapter *chapter_1 = dao->get_chapter(chapter_id);
	pt->test("Retrieved chapter properly", chapter_1 != nullptr);

	// SAME
	const char* dane = chapter.name;
	const char* done = chapter_1->name;

	// pt->test("Chapters are the same.", strcmp(dane, done) == 0);

}

void DaoTest::run() {

	test_adding_getting_chapter();
	pt->report();

}
