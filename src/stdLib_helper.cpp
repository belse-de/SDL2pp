//
// Created by belse on 15.04.18.
//

#include "stdLib_helper.hpp"

std::ostream &operator<<(std::ostream &os, const Printable &obj) {
    // write obj to stream
    return os << obj.to_string();
}

std::ostream &operator<<(std::ostream &os, const bool &obj) {
    // write obj to stream
    return os << (obj?"true":"false");
}
