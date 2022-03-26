#ifndef __Prototype__Person__H__
#define __Prototype__Person__H__

#include "../object.h"
#include "../item/item.h"

class Person : public Object {
protected:
	// Member functions to safely
	// modify an instance of a person (Optional Tool)
	Person *engage(Person p, Person(*f)(Object&));
public:
	Person(const char* name, const char* description) : Object(0, name, description) {};
	
};

#endif // defined(__Prototype__Person__H__)