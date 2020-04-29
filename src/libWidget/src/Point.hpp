//
// Created by belse on 18.04.18.
//

#ifndef SDL2PP_POINT_HPP
#define SDL2PP_POINT_HPP

namespace Widget {
    struct Point {
        int x, y;
    };

    inline constexpr Point operator+(const Point& lhs, const Point& rhs){ return Point{lhs.x + rhs.x, lhs.y + rhs.y}; }
    inline constexpr Point operator-(const Point& lhs, const Point& rhs){ return Point{lhs.x - rhs.x, lhs.y - rhs.y}; }
    inline constexpr Point operator*(const Point& lhs, const int& rhs){ return Point{lhs.x * rhs, lhs.y * rhs}; }
    inline constexpr Point operator*(const int& lhs, const Point& rhs){ return rhs * lhs; }
    inline constexpr Point operator/(const Point& lhs, const int& rhs){ return Point{lhs.x / rhs, lhs.y / rhs}; }

    inline constexpr short cmp(const Point &lhs, const Point &rhs) {
        if (lhs.x == rhs.x and lhs.y == rhs.y) { return 0; }
        if (lhs.x < rhs.x and lhs.y < rhs.y) { return -1; }
        if (lhs.x > rhs.x and lhs.y > rhs.y) { return +1; }
        return 127;
    }

    inline bool operator==(const Point &lhs, const Point &rhs) { return cmp(lhs, rhs) == 0; }

    inline bool operator<(const Point &lhs, const Point &rhs) { return cmp(lhs, rhs) == -1; }

    inline bool operator>(const Point &lhs, const Point &rhs) { return cmp(lhs, rhs) == +1; }


    inline std::ostream &operator<<(std::ostream &os, const Point &obj) {
        return os << "(" << obj.x << ", " << obj.y << ")";
    }
};
#endif //SDL2PP_POINT_HPP
