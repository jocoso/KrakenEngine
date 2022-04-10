#ifndef _CHAPTER_H_
#define _CHAPTER_H_

#include "../../tools/protstring.h"
#include "../../tools/arraylist.h"
#include "place.h"
#include <list>

typedef struct Chapter {

	 mutable unsigned int id;
	 ProtString name;
	 ProtString intro;
	 ArrayList<Place> places();

	 Chapter() {
		 init();
	 }

private:
	void init() {
		id = 0;
		name = "";
		intro = "";
	}
	 
} Chapter;

#endif