#ifndef __Prototype__Item__H__
#define __Prototype__Item__H__

#include "../object.h"


class Item : public virtual Object {
	Item();
public:
	Item(const char* name, const char *description) :
		Object(name, description) {};
};


#endif // defined(__Prototype__Item__H__)