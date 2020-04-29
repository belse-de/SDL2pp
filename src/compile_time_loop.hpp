//
// Created by belse on 19.05.18.
//

#ifndef SDL2PP_COMPILE_TIME_LOOP_HPP
#define SDL2PP_COMPILE_TIME_LOOP_HPP

#include <climits>
/*
 * 26.12. 2015 • Simon Praetorius
 * src: http://spraetor.github.io/2015/12/26/compile-time-loops.html
 */

// class that behaves like an integer and stores an integral constant
// Here, simply using std::integral_constant from <type_traits>
template <int I> using int_ = std::integral_constant<int, I>;

// default behavior (i>=N): do nothing
template <int I, int Step, int N>
struct ForImpl
{
    static_assert( Step != 0, "Stepsize 0 not allowed!" );
    template <class F> static void loop(F) {}
};

// class that performs the loop over all indices [I, N), for i < N
template <int I, int Step, int N>
requires (Step > 0 && I < N) || (Step < 0 && I > N)
struct ForImpl<I, Step, N>
{
    template <class F>
    static void loop(F&& f) // using universal references
    {
        f(int_<I>());
        ForImpl<I+Step, Step, N>::loop(std::forward<F>(f));
    }
};

template <int I, int Step, int N = INT_MAX>
struct For : ForImpl<I, Step, N>
{
    static_assert( (Step > 0 && I <= N) || (Step < 0 && I >= N),
                   "Illegal range definition!" );
};

// if N not given explicitly, use Stepsize=1 or -1
template <int I, int N>
struct For<I, N, INT_MAX> : ForImpl<I, (N >= I ? 1 : -1), N> {};


#endif //SDL2PP_COMPILE_TIME_LOOP_HPP
