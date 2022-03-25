// BWUTest.cpp
// A simple unit test class
// by Bill Weinman <http://bw.org/>
// as of 2018-10-12

#include "prottest.h"

ProtTest::ProtTest(const char* tstr) {
	init(tstr);
}

void ProtTest::init(const char* tstr) {
	_tstr = tstr;
	_pass_count = _fail_count = 0;
}

void ProtTest::test(const char* description, const int flag) {
	const char* pf = nullptr;
	if (flag) {
		pf = __prot_pstr;
		++_pass_count;
	}
	else {
		pf = __prot_fstr;
		++_fail_count;
	}
	if (!_summary_flag) printf("%s: %s -> %s\n", _tstr, description, pf);
}

void ProtTest::report() const {
	printf("%s: pass: %ld, fail: %ld\n", _tstr, pass_count(), fail_count());
	fflush(stdout);
}