//
// Created by belse on 01.01.18.
//

#ifndef SDL2PP_NET_ERROR_HPP
#define SDL2PP_NET_ERROR_HPP

#include <string>
#include <stdexcept>

#include <SDL2/SDL_net.h>

namespace SDL2pp::Net {
    struct Error : public std::runtime_error {
        Error() : Error("") {}

        Error(const std::string &what_arg) :
            std::runtime_error(what_arg + std::string {"\r\n"} + std::string {"SDL_Net Error: "} + SDLNet_GetError()) {}

        ~Error() = default;
    };
};

#endif //SDL2PP_NET_ERROR_HPP
