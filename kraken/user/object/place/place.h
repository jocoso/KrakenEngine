#ifndef __Prototype__Place__H__
#define __Prototype__Place__H__

#include "../object.h"

class Place : public virtual Object {
public:
	Place(const char* name, const char* description) :
		Object(name, description) {}
	
};

#endif // defined(__Prototype__Item__H__)