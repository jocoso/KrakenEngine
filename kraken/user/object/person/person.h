#ifndef __Prototype__Person__H__
#define __Prototype__Person__H__

#include "../object.h"

class Person : public virtual Object {
public:
	Person(const char* name, const char* description) :
		Object(name, description) {}
	
};

#endif // defined(__Prototype__Person__H__)