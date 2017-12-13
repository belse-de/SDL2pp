//
// Created by belse on 12.12.17.
//

#ifndef SDL2PP_SDL2PP_HPP
#define SDL2PP_SDL2PP_HPP

#include <chrono>

namespace SDL2pp {
    class SDL2 {
    public:
        SDL2();
        virtual ~SDL2();

        void delay(std::chrono::milliseconds ms);
    };
};

#endif //SDL2PP_SDL2PP_HPP
