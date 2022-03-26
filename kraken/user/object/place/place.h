#ifndef __Prototype__Place__H__
#define __Prototype__Place__H__

#include "../object.h"

class Place : public Object {
	const char* _introduction;
	Place();
public:
	Place(const char* name, const char* description, const char* introduction);
	Place(const char* name, const char* description);
	const char* get_introduction(void) const { return _introduction; }
	void set_introduction(const char* new_introduction) { _introduction = new_introduction; };
};

#endif // defined(__Prototype__Item__H__)