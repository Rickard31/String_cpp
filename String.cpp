#include "String.h"
#include <cstring>
#include <cassert>

String::String(const char *charArr) : _string(new char[strlen(charArr) + 1]), _length(strlen(charArr)) {
    strcpy_s(_string, _length + 1, charArr);
    assert(_length == strlen(_string));
}

String::String(const char ch) : _string(new char[2]), _length(1) {
    _string[0] = ch;
    _string[1] = '\0';
    assert(_length == strlen(_string));
}

String::String(const std::string &str)
        : // String(str.c_str()) {} //Such initialization is not supported by MSVC, even though it works on gcc and minGW
        _string(new char[str.length() + 1]), _length(str.length()) {
    strcpy_s(_string, _length + 1, str.c_str());
}

String::String(const String &other) : _string(new char[other.length() + 1]), _length(other.length()) {
    strcpy_s(_string, other.length() + 1, other.c_string());
}

String::~String() {
    delete[] _string;
}

String &String::operator=(const String &other) {
    if (this == &other)
        return *this;
    return this->operator=(other.c_string());
}

String &String::operator=(const std::string &str) {
    return this->operator=(str.c_str());
}

String &String::operator=(const char *charArr) {
    if (_string == charArr)
        return *this;
    size_t newCharLen = strlen(charArr);
    char *temp = new char[newCharLen + 1];
    strcpy(temp, charArr);
    assert(temp[newCharLen] == '\0');
    assert(strlen(charArr) == strlen(temp));
    delete[] _string;
    _string = temp;
    _length = newCharLen;
    return *this;
}

String& String::operator=(const char ch) {
    delete[] _string;
    _string = new char[2];
    _string[0] = ch;
    _string[1] = '\0';
    _length = 1;
    return *this;
}

String &String::operator+=(const String &other) {
    return *this += other.c_string();
}

String &String::operator+=(const std::string &str) {
    return *this += str.c_str();
}

String &String::operator+=(const char *charArr) {
    size_t newLen = length() + strlen(charArr);
    char *temp = new char[newLen + 1];
    strcpy_s(temp, _length + 1, _string);
    strcat(temp, charArr);
    delete[] _string;
    _string = temp;
    _length = newLen;
    return *this;
}

char String::operator[](const size_t index) const {
    if (length() <= index)
        throw "Invalid index";
    return _string[index];
}

char &String::operator[](const size_t index) {
    if (length() <= index)
        throw "Invalid index";
    return _string[index];
}

size_t String::length() const {
    assert(_length == strlen(_string));
    return _length;
}

const char *String::c_string() const {
    assert(_string[_length] == '\0');
    return _string;
}

std::string String::std_string() const {
    return std::string(_string);
}


std::ostream &operator<<(std::ostream &os, const String &str) {
    return os << str.c_string();
}

const String operator+(const String &a, const String &b) {
    String temp(a);
    temp += b;
    return temp;
}

const String operator+(const String &a, const char *const b) {
    String temp(a);
    temp += b;
    return temp;
}

const String operator+(const String &a, const std::string &b) {
    String temp(a);
    temp += b;
    return temp;
}

bool operator==(const String &a, const String &b) {
    return strcmp(a.c_string(), b.c_string()) == 0;
}

bool operator==(const String &a, const std::string &b) {
    return strcmp(a.c_string(), b.c_str()) == 0;
}

bool operator==(const std::string &a, const String &b) {
    return b == a;
}

bool operator==(const String &a, const char *const b) {
    return strcmp(a.c_string(), b) == 0;
}

bool operator==(const char *const a, const String &b) {
    return b == a;
}

bool operator!=(const String &a, const String &b) {
    return !(a == b);
}

bool operator!=(const String &a, const std::string &b) {
    return !(a == b);
}

bool operator!=(const std::string &a, const String &b) {
    return !(a == b);
}

bool operator!=(const String &a, const char *const b) {
    return !(a == b);
}

bool operator!=(const char *const a, const String &b) {
    return !(a == b);
}

bool operator<(const String &a, const String &b) {
    return strcmp(a.c_string(), b.c_string()) < 0;
}

bool operator<(const String &a, const std::string &b) {
    return strcmp(a.c_string(), b.c_str()) < 0;
}

bool operator<(const std::string &a, const String &b) {
    return !(b >= a);
}

bool operator<(const String &a, const char *const b) {
    return strcmp(a.c_string(), b) < 0;
}

bool operator<(const char *const a, const String &b) {
    return !(b >= a);
}

bool operator>(const String &a, const String &b) {
    return strcmp(a.c_string(), b.c_string()) > 0;
}

bool operator>(const String &a, const std::string &b) {
    return strcmp(a.c_string(), b.c_str()) > 0;
}

bool operator>(const std::string &a, const String &b) {
    return !(b <= a);
}

bool operator>(const String &a, const char *const b) {
    return strcmp(a.c_string(), b) > 0;
}

bool operator>(const char *const a, const String &b) {
    return !(b >= a);
}

bool operator<=(const String &a, const String &b) {
    return !(a > b);
}

bool operator<=(const String &a, const std::string &b) {
    return !(a > b);
}

bool operator<=(const std::string &a, const String &b) {
    return b >= a;
}

bool operator<=(const String &a, const char *const b) {
    return strcmp(a.c_string(), b) <= 0;
}

bool operator<=(const char *const a, const String &b) {
    return b >= a;
}

bool operator>=(const String &a, const String &b) {
    return !(a < b);
}

bool operator>=(const String &a, const std::string &b) {
    return !(a < b);
}

bool operator>=(const std::string &a, const String &b) {
    return b <= a;
}

bool operator>=(const String &a, const char *const b) {
    return !(a < b);
}

bool operator>=(const char *const a, const String &b) {
    return b <= a;
}
