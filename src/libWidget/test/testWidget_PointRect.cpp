//
// Created by belse on 15.03.18.
//

#include "catch.hpp"

#include "../src/PointRect.hpp"
#include "../src/Point.hpp"
#include "../src/Rect.hpp"

using namespace Widget;

TEST_CASE( "dummy", "[widget][lib]" ) {
    REQUIRE(true);
}


TEST_CASE("point inside rect", "[rect][point][widget][lib]"){

    SECTION("null size rect"){
        Rect zero{0,0,0,0};
        CHECK(zero != Point{ 0, 0});
        CHECK(zero != Point{ 0, 1});
        CHECK(zero != Point{ 0,-1});
        CHECK(zero != Point{ 1, 0});
        CHECK(zero != Point{ 1, 1});
        CHECK(zero != Point{ 1,-1});
        CHECK(zero != Point{-1, 0});
        CHECK(zero != Point{-1, 1});
        CHECK(zero != Point{-1,-1});

        CHECK(Point{ 0, 0} != zero);
        CHECK(Point{ 0, 1} != zero);
        CHECK(Point{ 0,-1} != zero);
        CHECK(Point{ 1, 0} != zero);
        CHECK(Point{ 1, 1} != zero);
        CHECK(Point{ 1,-1} != zero);
        CHECK(Point{-1, 0} != zero);
        CHECK(Point{-1, 1} != zero);
        CHECK(Point{-1,-1} != zero);
    }

    SECTION("1. dim null size rect"){
        Rect zero1{0,0,0,1};
        CHECK(zero1 != Point{ 0, 0});
        CHECK(zero1 != Point{ 0, 1});
        CHECK(zero1 != Point{ 0,-1});
        CHECK(zero1 != Point{ 1, 0});
        CHECK(zero1 != Point{ 1, 1});
        CHECK(zero1 != Point{ 1,-1});
        CHECK(zero1 != Point{-1, 0});
        CHECK(zero1 != Point{-1, 1});
        CHECK(zero1 != Point{-1,-1});
    }

    SECTION("2. dim null size rect"){
        Rect zero1{0,0,1,0};
        CHECK(zero1 != Point{ 0, 0});
        CHECK(zero1 != Point{ 0, 1});
        CHECK(zero1 != Point{ 0,-1});
        CHECK(zero1 != Point{ 1, 0});
        CHECK(zero1 != Point{ 1, 1});
        CHECK(zero1 != Point{ 1,-1});
        CHECK(zero1 != Point{-1, 0});
        CHECK(zero1 != Point{-1, 1});
        CHECK(zero1 != Point{-1,-1});
    }

    SECTION("one size rect"){
        Rect one{0,0,1,1};
        CHECK(one == Point{ 0, 0});
        CHECK(one != Point{ 0, 1});
        CHECK(one != Point{ 0,-1});
        CHECK(one != Point{ 1, 0});
        CHECK(one != Point{ 1, 1});
        CHECK(one != Point{ 1,-1});
        CHECK(one != Point{-1, 0});
        CHECK(one != Point{-1, 1});
        CHECK(one != Point{-1,-1});

        CHECK(one < Point{ 1, 1});
        CHECK(one > Point{-1,-1});

        CHECK(Point{ 1, 1} > one);
        CHECK(Point{-1,-1} < one);
    }
}


TEST_CASE("offset rect by point", "[rect][point][widget][lib]"){
    SECTION("addition"){
        CHECK((Rect{0,0,0,0} + Point{1,1}) == Rect{1,1,0,0});
        CHECK((Rect{0,0,0,0} + Point{1,0}) == Rect{1,0,0,0});
        CHECK((Rect{0,0,0,0} + Point{0,1}) == Rect{0,1,0,0});
        CHECK((Rect{0,0,0,0} + Point{0,0}) == Rect{0,0,0,0});
        CHECK((Rect{0,0,0,0} + Point{-1,-1}) == Rect{-1,-1,0,0});

        CHECK((Point{1,1} + Rect{0,0,0,0}) == Rect{1,1,0,0});
        CHECK((Point{1,0} + Rect{0,0,0,0}) == Rect{1,0,0,0});
        CHECK((Point{0,1} + Rect{0,0,0,0}) == Rect{0,1,0,0});
        CHECK((Point{0,0} + Rect{0,0,0,0}) == Rect{0,0,0,0});
        CHECK((Point{-1,-1} + Rect{0,0,0,0}) == Rect{-1,-1,0,0});
    }

    SECTION("subtraction"){
        CHECK((Rect{0,0,0,0} - Point{1,1}) == Rect{-1,-1,0,0});
        CHECK((Rect{0,0,0,0} - Point{1,0}) == Rect{-1,0,0,0});
        CHECK((Rect{0,0,0,0} - Point{0,1}) == Rect{0,-1,0,0});
        CHECK((Rect{0,0,0,0} - Point{0,0}) == Rect{0,0,0,0});
        CHECK((Rect{0,0,0,0} - Point{-1,-1}) == Rect{1,1,0,0});
    }
}
