#include "String.h"
#include <cassert>


int main() {
    assert(String("test") == String(std::string("test")));

    String s = "a";
    s = "a";
    s = std::string("b");
    String ss = s;
    s += String("b");
    s += std::string("c");
    s += "d";
    assert(s == "bbcd");
    assert (s.std_string() == std::string("bbcd"));
    assert(s.length() == 4);
    assert(ss != s);


    String a = "ab";
    String b = std::string("b");
    String c = String("abc");
    assert(a < b);
    assert(a != b);
    assert(c >= a);

    String c1("a");
    String c2 = 'a';
    assert(c1 == c2);


    std::cout << "All asserts passed" << std::endl;

    return 0;
}