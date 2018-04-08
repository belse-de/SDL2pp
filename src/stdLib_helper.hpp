//
// Created by belse on 09.04.18.
//

#ifndef SDL2PP_STDLIB_HELPER_HPP
#define SDL2PP_STDLIB_HELPER_HPP

#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>

template<class T> std::string to_string(const T& t)
{
    std::ostringstream os;
    os << t;
    return os.str();
}

inline void wait4Input()
{
    std::cin.clear();
    std::cout << "Please enter a character to exit\n";
    char ch;
    std::cin >> ch;
    return;
}

inline void wait4Input(std::string s)
{
    if (s=="") return;
    std::cin.clear();
    std::cin.ignore(120,'\n');
    for (;;) {
        std::cout << "Please enter " << s << " to exit\n";
        std::string ss;
        while (std::cin >> ss && ss!=s)
            std::cout << "Please enter " << s << " to exit\n";
        return;
    }
}

template<typename C>
// requires Container<C>()
void sort(C& c)
{
    std::sort(c.begin(), c.end());
}


// error() simply disguises throws:
inline void error(const std::string& s)
{
    throw std::runtime_error(s);
}

inline void error(const std::string& s, const std::string& s2)
{
    error(s+s2);
}

inline void error(const std::string& s, int i)
{
    std::ostringstream os;
    os << s <<": " << i;
    error(os.str());
}

// trim from start (in place)
static inline std::string & ltrim(std::string &s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](int ch) {
        return !std::isspace(ch);
    }));
    return s;
}

// trim from end (in place)
static inline std::string & rtrim(std::string &s) {
    s.erase(std::find_if(s.rbegin(), s.rend(), [](int ch) {
        return !std::isspace(ch);
    }).base(), s.end());
    return s;
}

// trim from both ends (in place)
static inline std::string & trim(std::string &s) {
    return ltrim(rtrim(s));
}

// trim from start (copying)
static inline std::string ltrim_copy(std::string s) {
    return ltrim(s);
}

// trim from end (copying)
static inline std::string rtrim_copy(std::string s) {
    return rtrim(s);
}

// trim from both ends (copying)
static inline std::string trim_copy(std::string s) {
    return trim(s);
}

#endif //SDL2PP_STDLIB_HELPER_HPP
