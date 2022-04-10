#ifndef _DAO_IMPL_H_
#define _DAO_IMPL_H_

#include "dao.h"
#include <memory>
#include <list>

#include "../tools/arraylist.h"

#define KRAKEN_FILE "krakendata.krk"

class DaoImpl : public virtual Dao {

	ArrayList<Chapter> chapters;
	int size = 0;

	// Marshall
	const char* marshall_chapter(Chapter c);
	const char* marshall_person(Person p);
	const char* marshall_item(Item i);
	const char* marshall_place(Place pl);

	// Unmarshall
	Chapter *unmarshall_chapter(const char* c);
	Person *unmarshall_person(const char* p);
	Item *unmarshall_item(const char* i);
	Place *unmarshall_place(const char* pl);

	// Management
	void load(void);
	void write(void);

public:
	const unsigned int add_chapter(Chapter c);
	Chapter *get_chapter(const unsigned int id);
	Chapter *remove_chapter(const unsigned int id);
	void update_chapter(const unsigned int id);
	~DaoImpl();
	
};

#endif