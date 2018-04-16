//
// Created by belse on 15.04.18.
//

#include "stdLib_helper.hpp"

#include <rttr/registration>

RTTR_REGISTRATION
{
    rttr::registration::class_<Printable>("Printable").method("to_string", &Printable::to_string);
}

std::ostream &operator<<(std::ostream &os, const Printable &obj) {
    // write obj to stream
    return os << obj.to_string();
}
