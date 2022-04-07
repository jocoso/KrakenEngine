// ProtString.h
// A simple string management class
// by Joshua Collado
// as of 3-23-2022

#ifndef __Prototype__String__
#define __Prototype__String__

// Windows
#ifdef _MSC_VER

#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

// Pragma warning
#include <cstdarg>
int vasprintf(char** ret, const char* format, va_list ap);

#endif // _MSC_VER

#include <cstdlib>
#include <cstring>
#include <cstdarg>
#include <cctype>
#include <memory>

constexpr const char* _protstring_version = "2.3.1";
constexpr size_t _protstring_max_len = 65535; // May change
constexpr size_t _protstring_max_split = 1023;

class ProtString {
	char* _str = nullptr;
	size_t _str_len = 0;

	typedef std::shared_ptr<ProtString> _pssp;
	typedef std::unique_ptr<_pssp[]> _split_ptr;
	mutable _split_ptr _split_array;
	mutable size_t _split_count = 0;

	void _reset_split_array()const;
	void _append_split_array(const ProtString& s) const;

public:
	typedef _split_ptr split_ptr;

	ProtString();
	ProtString(const char* s);
	ProtString(const ProtString&);
	ProtString(ProtString&&)noexcept;
	~ProtString();

	const char* alloc_str(size_t sz);
	void reset();
	void swap(ProtString& b);
	const char* c_str() const;
	const char* copy_str(const char*);

	ProtString& operator = (ProtString);
	ProtString& operator += (const char*);
	ProtString& operator += (const ProtString&);
	const char operator[] (const int) const;

	bool operator == (const ProtString&) const;
	bool operator != (const ProtString&) const;
	bool operator > (const ProtString&) const;
	bool operator < (const ProtString&) const;
	bool operator >= (const ProtString&) const;
	bool operator <= (const ProtString&) const;

	operator const char* () const;

	static const char* version() { return _protstring_version; }
	bool have_value() const;
	size_t length() const { return _str_len; }
	size_t size() const { return _str_len; }
	ProtString& format(const char* format, ...);
	ProtString& trim();
	ProtString lower() const;
	ProtString upper() const;
	const char& back() const;
	const char& front() const;

	long int char_find(const char& match) const;
	const ProtString& char_repl(const char & match, const char &repl);
	ProtString substr(size_t start, size_t length);
	long find(const ProtString& match)const;
	const ProtString replace(const ProtString& match, const ProtString& repl);

	const split_ptr& split(const char* match)const;
	const split_ptr& split(const char match)const;
	const split_ptr& split(const char* match, int max_split) const;
	const ProtString& split_item(size_t index)const;
	size_t split_count() const { return _split_count; }

};

ProtString operator + (const ProtString& lhs, const ProtString& rhs);
#endif //  __Prototype__String__