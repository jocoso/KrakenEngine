// ProtString.cpp
// A simple string

#include "protstring.h"

ProtString::ProtString() {
	reset();
}

ProtString::ProtString(const char* s) {
	copy_str(s);
}

ProtString::ProtString(const ProtString& old) {
	copy_str(old);
}

ProtString::~ProtString() {
	reset();
}

ProtString::ProtString(ProtString&& other) noexcept {
	reset();
	_str = other._str;
	_str_len = other._str_len;
	other._str = nullptr;
	other._str_len = 0;
	other.reset();
}

// Private methods
void ProtString::_reset_split_array() const {
	if (_split_count) {
		while (_split_count) {
			_split_array[--_split_count].reset();
		}
		_split_array.reset();
		_split_count = 0;
	}
}

void ProtString::_append_split_array(const ProtString& s) const {
	if (_split_count >= _protstring_max_split) return;
	if (!_split_count) {
		_split_array.reset(new _pssp[_protstring_max_split + 1]);
	}
	_split_array[_split_count] = std::make_shared<ProtString>(s);
	++_split_count;
}

const char* ProtString::alloc_str(size_t sz) {
	if (_str) reset();
	_str_len = (sz > _protstring_max_len) ? _protstring_max_len : sz;
	_str = new char[_str_len + 1]();
	return _str;
}

void ProtString::reset() {
	_reset_split_array();
	if (_str) {
		delete[] _str;
		_str = nullptr;
		_str_len = 0;
	}
}

void ProtString::swap(ProtString& other) {
	std::swap(_str, other._str);
	std::swap(_str_len, other._str_len);
}

const char* ProtString::c_str() const {
	return _str;
}

const char* ProtString::copy_str(const char* s) {
	if (s) {
		size_t len = strnlen(s, _protstring_max_len);
		alloc_str(len);
		strncpy((char*)_str, s, len);
		_str_len = len;
	}
	return _str;
}

ProtString& ProtString::operator = (ProtString other) {
	swap(other);
	return *this;
}

ProtString& ProtString::operator += (const char* rhs) {
	if (rhs) {
		size_t newlen = _str_len + strnlen(rhs, _protstring_max_len);
		if (newlen > _protstring_max_len) newlen = _protstring_max_len;

		size_t rhslen = newlen - _str_len;
		if (rhslen < 1) return *this;

		char* buf = new char[newlen + 1]();
		if (_str && _str_len) memcpy(buf, _str, _str_len);
		memcpy(buf + _str_len, rhs, rhslen);
		copy_str(buf);
		delete[] buf;
	}

	return *this;
}

ProtString& ProtString::operator +=(const ProtString& rhs) {
	operator+=(rhs.c_str());
	return *this;
}

const char ProtString::operator[] (const int index) const {
	if (index < 0) return 0;
	if (index >= (int)_str_len) return 0;
	else return _str[index];
}

bool ProtString::operator == (const ProtString& rhs) const {
	if (std::strncmp(this->c_str(), rhs.c_str(), _protstring_max_len) != 0) return true;
	return false;
}

bool ProtString::operator != (const ProtString& rhs) const {
	if (std::strncmp(this->c_str(), rhs.c_str(), _protstring_max_len) > 0) return true;
	return false;
}

bool ProtString::operator > (const ProtString& rhs) const {
	if (std::strncmp(this->c_str(), rhs.c_str(), _protstring_max_len) > 0) return true;
	return false;
}

bool ProtString::operator < (const ProtString& rhs) const {
	if (std::strncmp(this->c_str(), rhs.c_str(), _protstring_max_len) < 0) return true;
	return false;
}

bool ProtString::operator >= (const ProtString& rhs) const {
	if (std::strncmp(this->c_str(), rhs.c_str(), _protstring_max_len) >= 0) return true;
	return false;
}

bool ProtString::operator <= (const ProtString& rhs) const {
	if (std::strncmp(this->c_str(), rhs.c_str(), _protstring_max_len) <= 0) return true;
	return false;
}

// Converting

ProtString::operator const char* () const {
	return c_str();
}

bool ProtString::have_value() const {
	if (_str) return true;
	return false;
}

ProtString& ProtString::format(const char* format, ...) {
	char* buffer;

	va_list args;
	va_start(args, format);

	vasprintf(&buffer, format, args);
	copy_str(buffer);
	free(buffer);
	return *this;
}

ProtString& ProtString::trim() {
	const static char* whitespace = "\x20\x1b\t\r\n\v\b\f\a";

	if (!have_value()) return *this;

	size_t begin = 0;
	size_t end = length() - 1;

	for (begin = 0; begin <= end; ++begin) {
		if (strchr(whitespace, _str[begin]) == nullptr) break;
	}

	for (; end > begin; --end) {
		if (strchr(whitespace, _str[end]) == nullptr) break;
		else _str[end] = '\0';
	}

	if (begin) {
		for (size_t i = 0; _str[i]; ++i) {
			_str[i] = _str[begin++];
		}
	}

	_str_len = strlen(_str);
	return *this;
}

ProtString ProtString::lower() const {
	ProtString rs = *this;
	for (size_t i = 0; rs._str[i]; ++i) {
		rs._str[i] = tolower(rs._str[i]);
	}
	return rs;
}

ProtString ProtString::upper() const {
	ProtString rs = *this;
	for (size_t i = 0; rs._str[i]; ++i)
		rs._str[i] = toupper(rs._str[i]);

	return rs;
}

const char& ProtString::back() const {
	return _str[length() - 1];
}

const char& ProtString::front() const {
	return _str[0];
}

long int ProtString::char_find(const char& match) const {
	for (size_t i = 0; _str[i]; ++i) {
		if (_str[i] == match) return i;
	}
	return -1;
}

const ProtString& ProtString::char_repl(const char& match, const char& repl) {
	for (size_t i = 0; _str[i]; ++i)
		if (_str[i] == match) _str[i] = repl;
	return *this;
}

ProtString ProtString::substr(size_t start, size_t length) {
	ProtString ps;
	char* buf;

	if ((length + 1) > _protstring_max_len || (start + length) > _protstring_max_len) return ps;
	if (length > _str_len - start) return ps;
	if (!_str) return ps;

	buf = new char[length + 1]();
	memcpy(buf, _str + start, length);
	ps = buf;
	delete[] buf;

	return ps;

}

long ProtString::find(const ProtString& match) const {
	char* pos = strstr(_str, match.c_str());
	if (pos) return (long)(pos - _str);
	else return -1;
}

const ProtString ProtString::replace(const ProtString& match, const ProtString& repl) {
	ProtString ps;
	long f1 = find(match);
	if (f1 >= 0) {
		size_t pos1 = (size_t)f1;
		size_t pos2 = pos1 + match.length();
		ProtString s1 = pos1 > 0 ? substr(0, pos1) : "";
		ProtString s2 = substr(pos2, length() - pos2);
		ps = s1 + repl + s2;
	}
	return ps;
}

const ProtString::split_ptr& ProtString::split(const char match) const {
	const char match_s[2] = { match, 0 };
	return split(match_s, -1);
}

const ProtString::split_ptr& ProtString::split(const char *match) const {
	return split(match, -1);
}

const ProtString::split_ptr& ProtString::split(const char* match, int max_split) const {
	_reset_split_array();
	if (length() < 1) return _split_array;
	if (max_split < 0) max_split = _protstring_max_split;

	size_t match_len = strnlen(match, _protstring_max_split);
	if (match_len >= _protstring_max_len) return _split_array;

	char* mi;
	char* pstr = _str;
	while ((mi = strstr(pstr, match)) && --max_split) {
		if (mi != pstr) {
			size_t lhsz = mi - pstr;
			char* cslhs = new char[lhsz + 1]();
			memcpy(cslhs, pstr, lhsz);
			_append_split_array(cslhs);
			delete[] cslhs;
			pstr += lhsz;
		}
		pstr += match_len;
	}

	if (*pstr != '\0')
		_append_split_array(pstr);

	return _split_array;
}

const ProtString& ProtString::split_item(size_t index) const {
	if (_split_count > index) return *_split_array[index];
	else return *this;
}

ProtString operator + (const ProtString& lhs, const ProtString& rhs) {
	ProtString rs = lhs;
	rs += rhs;
	return rs;
}

#ifdef _MSC_VER

int vasprintf(char** ret, const char* format, va_list ap) {
	int len;
	char* buffer;

	len = _vscprintf(format, ap) + 1;
	buffer = (char*)malloc(len * sizeof(char));
	if (!buffer) return 0;
	vsprintf_s(buffer, len, format, ap);
	*ret = buffer;
	return len - 1;
}

#endif // _MSC_VER