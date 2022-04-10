#ifndef _DAO_H_
#define _DAO_H_

#include "components/chapter.h"
#include "components/person.h"
#include "components/item.h"
#include "components/place.h"

class Dao {

	// Marshall
	virtual const char* marshall_chapter(Chapter c) = 0;
	virtual const char* marshall_person(Person p) = 0;
	virtual const char* marshall_item(Item i) = 0;
	virtual const char* marshall_place(Place pl) = 0;

	// Unmarshall
	virtual Chapter *unmarshall_chapter(const char* c) = 0;
	virtual Person *unmarshall_person(const char* p) = 0;
	virtual Item *unmarshall_item(const char* i) = 0;
	virtual Place *unmarshall_place(const char* pl) = 0;

	// Management
	virtual void load(void) = 0;
	virtual void write(void) = 0;

public:
	virtual const unsigned int add_chapter(Chapter c) = 0;
	virtual Chapter *get_chapter(const unsigned int id) = 0;
	virtual Chapter *remove_chapter(const unsigned int id) = 0;
	virtual void update_chapter(const unsigned int id) = 0;

};

#endif