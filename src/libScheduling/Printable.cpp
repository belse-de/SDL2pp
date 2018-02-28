//
// Created by belse on 09.01.18.
//

#include "Printable.hpp"

std::ostream &operator<<(std::ostream &os, const Printable &obj) {
    // write obj to stream
    return os << obj.toString();
}
