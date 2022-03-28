#ifndef __Prototype__Object__H__
#define __Prototype__Object__H__

class Object {
	mutable unsigned int _id = 0;
	const char* _name;
	const char* _description;
protected:
	Object() {}
	Object(const char*, const char*);
public:
	const unsigned int get_id(void);
	const char* get_name(void);
	void set_name(const char* );
	const char* get_description(void);
	void set_description(const char*);
};

#endif /*define(__Prototype__Object__H)*/