//
// Created by belse on 19.05.18.
//

#include <catch.hpp>
#include <funtions1D.hpp>

TEST_CASE("smooth functions") {
    const int max_i = 16;

    SECTION("scale") {
        auto f = [](double v) { return v; };
        for (int i = 0; i <= max_i; ++i) {
            double x = 1. * i / max_i;
            double y = scale(f)(x);
            REQUIRE(y >= 0);
            REQUIRE(y <= 1);
        }
    }

    SECTION("scale revers") {
        auto f = [](double v) { return v; };
        for (int i = 0; i <= max_i; ++i) {
            double x = 1. * i / max_i;
            double y = scale_reverse(f)(x);
            REQUIRE(y >= 0);
            REQUIRE(y <= 1);
        }
    }

    SECTION("flip") {
        for (int i = 0; i <= max_i; ++i) {
            double x = 1. * i / max_i;
            double y = flip(x);
            REQUIRE(y >= 0);
            REQUIRE(y <= 1);
        }
    }

    SECTION("arch") {
        for (int i = 0; i <= max_i; ++i) {
            double x = 1. * i / max_i;
            double y = arch_2(x);
            REQUIRE(y >= 0);
            REQUIRE(y <= 1);
        }
    }

    SECTION("smooth start arch") {
        for (int i = 0; i <= max_i; ++i) {
            double x = 1. * i / max_i;
            double y = smooth_start_arch_3(x);
            REQUIRE(y >= 0);
            REQUIRE(y <= 1);
        }
    }

    SECTION("smooth stop arch") {
        for (int i = 0; i <= max_i; ++i) {
            double x = 1. * i / max_i;
            double y = smooth_stop_arch_3(x);
            REQUIRE(y >= 0);
            REQUIRE(y <= 1);
        }
    }

    SECTION("smooth step arch") {
        for (int i = 0; i <= max_i; ++i) {
            double x = 1. * i / max_i;
            double y = smooth_step_arch_4(x);
            REQUIRE(y >= 0);
            REQUIRE(y <= 1);
        }
    }

    SECTION("smooth start") {
        for (int i = 0; i <= max_i; ++i) {
            double x = 1. * i / max_i;
            double y = smooth_start<1,double>(x);
            REQUIRE(y >= 0);
            REQUIRE(y <= 1);

            y = smooth_start<1,double>(x);
            REQUIRE(y >= 0);
            REQUIRE(y <= 1);

            y = smooth_start<2,double>(x);
            REQUIRE(y >= 0);
            REQUIRE(y <= 1);

            y = smooth_start<3,double>(x);
            REQUIRE(y >= 0);
            REQUIRE(y <= 1);

            y = smooth_start<4,double>(x);
            REQUIRE(y >= 0);
            REQUIRE(y <= 1);

            y = smooth_start<5,double>(x);
            REQUIRE(y >= 0);
            REQUIRE(y <= 1);

            y = smooth_start<6,double>(x);
            REQUIRE(y >= 0);
            REQUIRE(y <= 1);
        }
    }

    SECTION("smooth stop") {
        for (int i = 0; i <= max_i; ++i) {
            double x = 1. * i / max_i;
            double y = smooth_stop<1,double>(x);
            REQUIRE(y >= 0);
            REQUIRE(y <= 1);

            y = smooth_stop<1,double>(x);
            REQUIRE(y >= 0);
            REQUIRE(y <= 1);

            y = smooth_stop<2,double>(x);
            REQUIRE(y >= 0);
            REQUIRE(y <= 1);

            y = smooth_stop<3,double>(x);
            REQUIRE(y >= 0);
            REQUIRE(y <= 1);

            y = smooth_stop<4,double>(x);
            REQUIRE(y >= 0);
            REQUIRE(y <= 1);

            y = smooth_stop<5,double>(x);
            REQUIRE(y >= 0);
            REQUIRE(y <= 1);

            y = smooth_stop<6,double>(x);
            REQUIRE(y >= 0);
            REQUIRE(y <= 1);
        }
    }
}
