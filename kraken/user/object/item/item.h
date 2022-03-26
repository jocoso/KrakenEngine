#ifndef __Prototype__Item__H__
#define __Prototype__Item__H__

#include "../object.h"
#include "../person/person.h"


class Item : public Object {
	Item();
public:
	Item(const char* name, const char* description) : Object(0, name, description) {};
};


#endif // defined(__Prototype__Item__H__)