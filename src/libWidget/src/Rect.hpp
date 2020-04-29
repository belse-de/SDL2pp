//
// Created by belse on 15.04.18.
//

#ifndef SDL2PP_RECT_HPP
#define SDL2PP_RECT_HPP

#include "Point.hpp"

namespace Widget {
    struct Rect {
        Point position;
        Point size; // dimentions
        Point referenze; // relation: between position and size
    };

    inline bool operator==(const Rect &lhs, const Rect &rhs) {
        return lhs.position == rhs.position and lhs.size == rhs.size and lhs.referenze == rhs.referenze;
    }

    inline bool operator!=(const Rect &lhs, const Rect &rhs) { return not(lhs == rhs); }

    inline std::ostream &operator<<(std::ostream &os, const Rect &obj) {
        return os << "(" << obj.position << ", " << obj.size << ", " << obj.referenze << ")";
    }
}

#endif //SDL2PP_RECT_HPP
