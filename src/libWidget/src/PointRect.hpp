//
// Created by belse on 18.04.18.
//

#ifndef SDL2PP_POINTRECT_HPP
#define SDL2PP_POINTRECT_HPP

#include "Point.hpp"
#include "Rect.hpp"
#include "../../stdLib_helper.hpp"

namespace Widget {
    inline bool operator==(const Point &lhs, const Rect &rhs) {
        return lhs >= rhs.position and lhs < (rhs.position + rhs.size);
    }

    inline bool operator<(const Point &lhs, const Rect &rhs) {
        return lhs < rhs.position and lhs < (rhs.position + rhs.size);
    }

    inline bool operator>(const Point &lhs, const Rect &rhs) {
        return lhs > rhs.position and lhs >= (rhs.position + rhs.size);
    }

    inline bool operator==(const Rect &lhs, const Point &rhs) { return rhs == lhs; }

    inline bool operator<(const Rect &lhs, const Point &rhs) { return rhs > lhs; }

    inline bool operator>(const Rect &lhs, const Point &rhs) { return rhs < lhs; }


    inline bool operator!=(const Point &lhs, const Rect &rhs) { return not(lhs == rhs); }

    inline bool operator<=(const Point &lhs, const Rect &rhs) { return lhs == rhs or lhs < rhs; }

    inline bool operator>=(const Point &lhs, const Rect &rhs) { return lhs == rhs or lhs > rhs; }


    inline bool operator!=(const Rect &lhs, const Point &rhs) { return not(lhs == rhs); }

    inline bool operator<=(const Rect &lhs, const Point &rhs) { return lhs == rhs or lhs < rhs; }

    inline bool operator>=(const Rect &lhs, const Point &rhs) { return lhs == rhs or lhs > rhs; }


    inline Rect operator+(const Rect &r, const Point &p) {
        Rect res = r;
        res.position = r.position + p;
        return res;
    }

    inline Rect operator-(const Rect &r, const Point &p) {
        Rect res = r;
        res.position = r.position - p;
        return res;
    }

    inline Rect operator+(const Point &p, const Rect &r) { return r + p; };


};
#endif //SDL2PP_POINTRECT_HPP
