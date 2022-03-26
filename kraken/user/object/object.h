#ifndef __Prototype__Object__H__
#define __Prototype__Object__H__

class Object {
	mutable unsigned int _id;
	const char* _name;
	const char* _description;

protected:
	Object(const unsigned int id,
		const char* name,
		const char* description);

public:
	unsigned int get_id(void) const { return _id; }
	const char* get_name(void) const { return _name; }
	const char* get_description(void) const { return _description; }
	void set_name(const char* new_name);
	void set_description(const char* new_description);
};

#endif /*define(__Prototype__Object__H)*/