//
// Created by belse on 19.05.18.
//

#ifndef SDL2PP_FUNTIONS1D_HPP
#define SDL2PP_FUNTIONS1D_HPP


class funtions1D {

};

#include <cmath>
/*
 * src: https://www.youtube.com/watch?v=mr5xkf6zSzk
 * Math for Game Programmers: Fast and Funky 1D (normalized) Nonlinear Transformations
 *
 * transfer function with:
 *      input = [0,1]
 *      output = [0,1]
 *      y = f(x)
 *
 *
 * for animation over time:
 *      position
 *      scale
 *      alpha
 *      (color)
 *      ...
 */

template<typename F>
inline constexpr auto scale(F fun) {
    return [=](auto val) { return val * fun(val); };
};

template<typename F>
inline constexpr auto scale_reverse(F fun) {
    //return (1 - val) * fun(val);
    return [=](auto val) { return (1 - val) * fun(val); };
};

template<typename N>
inline constexpr auto flip(N val) {
    return 1 - val;
}

template<typename N>
inline constexpr auto arch_2(N val) {
    return scale(flip<N>)(val);
}

template<typename N>
inline constexpr auto smooth_start_arch_3(N val) {
    return scale(arch_2<N>)(val);
}

template<typename N>
inline constexpr auto smooth_stop_arch_3(N val) {
    return scale_reverse(arch_2<N>)(val);
}

template<typename N>
inline constexpr auto smooth_step_arch_4(N val) {
    return scale_reverse(scale(arch_2<N>))(val);
}

template<int ord, typename T>
struct SmoothStart {
    auto operator()(T val) { return val * SmoothStart<ord - 1, T>()(val); };
};

template<typename T>
struct SmoothStart<1,T> {
    auto operator()(T val) { return val; }
};

template<int ord, typename T>
inline constexpr auto smooth_start(T in) {
    return SmoothStart<ord, T>()(in);
}

template<int ord, typename T>
inline constexpr auto smooth_stop(T val) {
    return flip(SmoothStart<ord, T>()(flip(val)));
}

template<typename T>
inline constexpr auto bell_curve_6(T val){
    return smooth_start<3,T>(val) * smooth_stop<3,T>(val);
}

// bounces of the bottom of [0,1] since neg. become pos.
template<typename T>
inline constexpr auto clamp_bounce_bottom(T val){
    return std::abs(val);
}

// bounces of the top of [0,1] since val. big then 1 become inverted below 1
template<typename T>
inline constexpr auto clamp_bounce_top(T val){
    return flip(clamp_bounce_bottom(flip(val)));
}

template<typename T>
inline constexpr auto clamp_bounce_bottom_top(T val){
    return clamp_bounce_top(clamp_bounce_bottom(val));
}

template<typename F, typename T>
inline constexpr auto mix(F funA, F funB, T w) {
    return [=](auto val) { return (1 - w) * funA(val) + w * funB(val); };
};

// cubic (3rd) Bezier through A,B,C,D, where A(start) and D(end) are assumed 0 and 1
template<typename T>
inline constexpr auto bezier_3(T b, T c, T t) {
    T s = flip(t);
    T s2 = s*s;
    T t2 = t * t;
    T t3 = t2 * t;
    return (3*b*s2*t) + (3*c*s*t2) + t3;
}

template<int ord, typename T>
inline constexpr auto smooth_step(T val) {
    return mix(smooth_start<ord,T>, smooth_stop<ord,T>, val)(val);
}


template<typename T>
inline constexpr auto normalize(T in_start, T in_end){
    return [=](T val){
        T out = val - in_start; // puts in [0, in_end - in_start]
        out /= in_end - in_start; // puts in [0, 1]
        return out; };
}

template<typename T>
inline constexpr auto denormalize(T out_start, T out_end){
    return [=](T val){
        T out = val * (out_end - out_start); // puts in [0, out_end - out_start]
        out += out_start; // puts in [out_start, out_end]
        return out; };
}

template<typename T>
inline constexpr auto range_map(T in, T in_start, T in_end, T out_start, T out_end){
    return [=](T val){ return denormalize(out_start, out_end)(normalize(in_start, in_end)(val)); };
}

// out = easing(out); // in [0, 1]


#endif //SDL2PP_FUNTIONS1D_HPP
