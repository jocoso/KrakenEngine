#ifndef __Prototype__Object__H__
#define __Prototype__Object__H__

#include <string>

class Object {
	friend class World;
	mutable unsigned int _id = 0;
	const char* _name;
	const char* _description;
protected:
	Object(const char*, const char*);
public:
	friend bool operator == (const Object& o1, const Object& o2);
	friend bool operator != (const Object& o1, const Object& o2);
	const unsigned int get_id(void);
	const char* get_name(void);
	void set_name(const char* );
	const char* get_description(void);
	void set_description(const char*);
	Object& operator = (const Object& o);
};

#endif /*define(__Prototype__Object__H)*/