//
// Created by belse on 27.01.18.
//

#ifndef SCHEDULING_OVERLOADED_HPP
#define SCHEDULING_OVERLOADED_HPP

template<class... Ts> struct overloaded : Ts... { using Ts::operator()...; };
template<class... Ts> overloaded(Ts...) -> overloaded<Ts...>;

/*
 * inspired from std proposal: C++ generic overload function (Revision 2)
 *  http://open-std.org/JTC1/SC22/WG21/docs/papers/2016/p0051r2.pdf
 * requires c++17
 * sources:
 *  https://dev.to/tmr232/that-overloaded-trick-overloading-lambdas-in-c17
 */
#endif //SCHEDULING_OVERLOADED_HPP
