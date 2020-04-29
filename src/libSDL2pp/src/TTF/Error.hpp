//
// Created by belse on 12.12.17.
//

#ifndef SDL2PP_TTF_ERROR_HPP
#define SDL2PP_TTF_ERROR_HPP


#include <string>
#include <stdexcept>
#include <SDL2/SDL_ttf.h>

namespace SDL2pp::TTF {
    struct Error : public std::runtime_error {
        Error() : Error("") {}

        Error(const std::string &what_arg) :
            std::runtime_error(what_arg + std::string {"\r\n"} + std::string {"SDL_ttf Error: "} + TTF_GetError()) {}

        ~Error() = default;
    };
};

#endif //SDL2PP_TTF_ERROR_HPP
