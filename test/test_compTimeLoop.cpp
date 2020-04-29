//
// Created by belse on 19.05.18.
//

#include <catch.hpp>
#include <iostream>

#include "../src/compile_time_loop.hpp"

template <long I> struct Fibo    { static constexpr long value = 0; };
template <>       struct Fibo<1> { static constexpr long value = 1; };

template <long I>
requires (I > 1)
struct Fibo<I> // recursion formula
{
    static constexpr long value = Fibo<I-1>::value + Fibo<I-2>::value;
};

TEST_CASE( "compile time loop", "[header fun]" ) {
    // loop backward from 10 down to one and print all Fibonacci-numbers
    For<10,-1,0>::loop([](auto I)
                       {
                           std::cout << "Fibo<" << I << ">::value = " << Fibo<I>::value << "\n";
                       });

}
