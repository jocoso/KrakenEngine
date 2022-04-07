// BWUTest.h
// A simple unit test class
// by Bill Weinman <http://bw.org>
// as of 2018-10-12

#ifndef _Prototype_Test_
#define _Prototype_Test_

#include <cstdio>
#define _PrototypeTest_VERSION "1.0.5"

constexpr const char* __prot_pstr = "pass";
constexpr const char* __prot_fstr = "fail";

class ProtTest {
	const char* _tstr = nullptr;

	unsigned long int _pass_count = 0;
	unsigned long int _fail_count = 0;
	bool _summary_flag = false;

	ProtTest(ProtTest&);               // no copy constructor
	ProtTest operator = (ProtTest&);   // no assignment operator
	ProtTest(){}                       // no default constructor
public:
	ProtTest(const char*);
	void init(const char*);
	bool summary(bool flag) { return _summary_flag = flag; }
	bool summary() { return _summary_flag; }
	unsigned long int pass_count() const { return _pass_count; }
	unsigned long int fail_count() const { return _fail_count; }
	static const char* version() { return _PrototypeTest_VERSION; }
	void test(const char* description, const int flag);
	void report() const;

};

#endif /* defined(_Prototype_Test_) */