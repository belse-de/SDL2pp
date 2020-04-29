//
// Created by belse on 15.03.18.
//

#include <iostream>
#include "catch.hpp"

#include "../src/PointRect.hpp"
#include "../src/Point.hpp"
#include "../src/Rect.hpp"

using namespace Widget;

TEST_CASE("point compaire", "point][widget][lib]"){

    SECTION("null equal"){
        Point zero{0,0};
        CHECK(zero == Point{ 0, 0});
        CHECK_FALSE(zero == Point{ 0, 1});
        CHECK_FALSE(zero == Point{ 0,-1});
        CHECK_FALSE(zero == Point{ 1, 0});
        CHECK_FALSE(zero == Point{ 1, 1});
        CHECK_FALSE(zero == Point{ 1,-1});
        CHECK_FALSE(zero == Point{-1, 0});
        CHECK_FALSE(zero == Point{-1, 1});
        CHECK_FALSE(zero == Point{-1,-1});

        CHECK(Point{ 0, 0} == zero);
        CHECK_FALSE(Point{ 0, 1} == zero);
        CHECK_FALSE(Point{ 0,-1} == zero);
        CHECK_FALSE(Point{ 1, 0} == zero);
        CHECK_FALSE(Point{ 1, 1} == zero);
        CHECK_FALSE(Point{ 1,-1} == zero);
        CHECK_FALSE(Point{-1, 0} == zero);
        CHECK_FALSE(Point{-1, 1} == zero);
        CHECK_FALSE(Point{-1,-1} == zero);
    }

    SECTION("null not equal"){
        Point zero{0,0};
        CHECK_FALSE(zero != Point{ 0, 0});
        CHECK(zero != Point{ 0, 1});
        CHECK(zero != Point{ 0,-1});
        CHECK(zero != Point{ 1, 0});
        CHECK(zero != Point{ 1, 1});
        CHECK(zero != Point{ 1,-1});
        CHECK(zero != Point{-1, 0});
        CHECK(zero != Point{-1, 1});
        CHECK(zero != Point{-1,-1});

        CHECK_FALSE(Point{ 0, 0} != zero);
        CHECK(Point{ 0, 1} != zero);
        CHECK(Point{ 0,-1} != zero);
        CHECK(Point{ 1, 0} != zero);
        CHECK(Point{ 1, 1} != zero);
        CHECK(Point{ 1,-1} != zero);
        CHECK(Point{-1, 0} != zero);
        CHECK(Point{-1, 1} != zero);
        CHECK(Point{-1,-1} != zero);
    }

    SECTION("null less"){
        Point zero{0,0};
        CHECK_FALSE(zero < Point{ 0, 0});
        CHECK_FALSE(zero < Point{ 0, 1});
        CHECK_FALSE(zero < Point{ 0,-1});
        CHECK_FALSE(zero < Point{ 1, 0});
        CHECK(zero < Point{ 1, 1});
        CHECK_FALSE(zero < Point{ 1,-1});
        CHECK_FALSE(zero < Point{-1, 0});
        CHECK_FALSE(zero < Point{-1, 1});
        CHECK_FALSE(zero < Point{-1,-1});

        CHECK_FALSE(Point{ 0, 0} < zero);
        CHECK_FALSE(Point{ 0, 1} < zero);
        CHECK_FALSE(Point{ 0,-1} < zero);
        CHECK_FALSE(Point{ 1, 0} < zero);
        CHECK_FALSE(Point{ 1, 1} < zero);
        CHECK_FALSE(Point{ 1,-1} < zero);
        CHECK_FALSE(Point{-1, 0} < zero);
        CHECK_FALSE(Point{-1, 1} < zero);
        CHECK(Point{-1,-1} < zero);
    }

    SECTION("null greater"){
        Point zero{0,0};
        CHECK_FALSE(zero > Point{ 0, 0});
        CHECK_FALSE(zero > Point{ 0, 1});
        CHECK_FALSE(zero > Point{ 0,-1});
        CHECK_FALSE(zero > Point{ 1, 0});
        CHECK_FALSE(zero > Point{ 1, 1});
        CHECK_FALSE(zero > Point{ 1,-1});
        CHECK_FALSE(zero > Point{-1, 0});
        CHECK_FALSE(zero > Point{-1, 1});
        CHECK(zero > Point{-1,-1});

        CHECK_FALSE(Point{ 0, 0} > zero);
        CHECK_FALSE(Point{ 0, 1} > zero);
        CHECK_FALSE(Point{ 0,-1} > zero);
        CHECK_FALSE(Point{ 1, 0} > zero);
        CHECK(Point{ 1, 1} > zero);
        CHECK_FALSE(Point{ 1,-1} > zero);
        CHECK_FALSE(Point{-1, 0} > zero);
        CHECK_FALSE(Point{-1, 1} > zero);
        CHECK_FALSE(Point{-1,-1} > zero);
    }
}


TEST_CASE("point arithmetic", "[point][widget][lib]"){
    SECTION("addition"){
        CHECK((Point{0,0} + Point{0,0}) == Point{0,0});

        CHECK((Point{0,0} + Point{0,1}) == Point{0,1});
        CHECK((Point{0,0} + Point{0,-1}) == Point{0,-1});
        CHECK((Point{0,0} + Point{1,0}) == Point{1,0});
        CHECK((Point{0,0} + Point{-1,0}) == Point{-1,0});

        CHECK((Point{0,1} + Point{0,0}) == Point{0,1});
        CHECK((Point{0,-1} + Point{0,0}) == Point{0,-1});
        CHECK((Point{1,0} + Point{0,0}) == Point{1,0});
        CHECK((Point{0,-1} + Point{0,0}) == Point{0,-1});

        CHECK((Point{1,2} + Point{3,4}) == Point{4,6});
        CHECK((Point{-1,-2} + Point{-3,-4) == Point{-4,-6});
    }

    SECTION("subtraction"){

    }
}
