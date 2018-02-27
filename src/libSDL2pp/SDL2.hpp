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
        SDL2(uint32_t flags);
        virtual ~SDL2();

        void delay(std::chrono::milliseconds ms) const;
        std::chrono::milliseconds getTicks();

        bool setHint(const char* name, const char* value) const;

    };
};

#endif //SDL2PP_SDL2PP_HPP
