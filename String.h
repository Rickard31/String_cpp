#ifndef HW3_STRING_H
#define HW3_STRING_H

#include <string>
#include <iostream>

class String {
public:
    String(const char *c_str = "\0");

    String(const char ch);

    String(const std::string &std_str);

    String(const String &);

    ~String();

    String &operator=(const String &);

    String &operator=(const std::string &);

    String &operator=(const char *);

    String &operator=(const char);

    String &operator+=(const String &);

    String &operator+=(const std::string &);

    String &operator+=(const char *);

    char operator[](const size_t index) const;

    char &operator[](const size_t index);

    size_t length() const;

    const char *c_string() const;

    std::string std_string() const;

private:
    char *_string;
    size_t _length;
};

std::ostream &operator<<(std::ostream &, const String &);

const String operator+(const String &, const String &);

const String operator+(const String &, const char *const);

const String operator+(const String &, const std::string &);


bool operator==(const String &, const String &);

bool operator==(const String &, const std::string &);

bool operator==(const std::string &, const String &);

bool operator==(const String &, const char *const);

bool operator==(const char *const, const String &);

bool operator!=(const String &, const String &);

bool operator!=(const String &, const std::string &);

bool operator!=(const std::string &, const String &);

bool operator!=(const String &, const char *const);

bool operator!=(const char *const, const String &);

bool operator<(const String &, const String &);

bool operator<(const String &, const std::string &);

bool operator<(const std::string &, const String &);

bool operator<(const String &, const char *const);

bool operator<(const char *const, const String &);

bool operator>(const String &, const String &);

bool operator>(const String &, const std::string &);

bool operator>(const std::string &, const String &);

bool operator>(const String &, const char *const);

bool operator>(const char *const, const String &);

bool operator<=(const String &, const String &);

bool operator<=(const String &, const std::string &);

bool operator<=(const std::string &, const String &);

bool operator<=(const String &, const char *const);

bool operator<=(const char *const, const String &);

bool operator>=(const String &, const String &);

bool operator>=(const String &, const std::string &);

bool operator>=(const std::string &, const String &);

bool operator>=(const String &, const char *const);

bool operator>=(const char *const, const String &);


#endif //HW3_STRING_H
