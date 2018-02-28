//
// Created by belse on 06.01.18.
//

#ifndef SCHEDULING_PRINTABLE_HPP
#define SCHEDULING_PRINTABLE_HPP

#include <string>
#include <chrono>

class Printable {
public:
    virtual std::string toString() const = 0;

public:
    Printable() = default;
    virtual ~Printable() = default;
};

std::ostream& operator<<(std::ostream& os, const Printable& obj);

#endif //SCHEDULING_PRINTABLE_HPP
