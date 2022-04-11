#ifndef _CHAPTER_H_
#define _CHAPTER_H_

#include "../../tools/protstring.h"
#include "../../tools/arraylist.h"
#include "place.h"
#include <map>

class Chapter {

	mutable unsigned int _id = 0;
	const char* _name;
	const char* _intro;
	std::map<const char*, Place>_map;

public:

	 Chapter(const unsigned int id, const char* name, const char* intro) : _id(id), _name(name), _intro(intro), _map() {}
	 const char* get_name(void) const { return _name; }
	 const char* get_intro(void) const { return _intro; }
	 void set_name(const char* name) { _name = name; }
	 void set_intro(const char* intro) { _intro = intro; }
	 const unsigned int get_id(void) const { return _id; }
	 const unsigned int add_scene(const char* place_name, Place place) const;
	 Place &get_scene(const char* name);
	 std::map<const char*, Place> &get_map();
	 void operator = (const Chapter& C);
	 bool operator == (const Chapter& C) const;
	 bool operator != (const Chapter& C) const;

};

#endif