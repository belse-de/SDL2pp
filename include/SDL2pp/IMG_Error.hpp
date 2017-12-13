//
// Created by belse on 12.12.17.
//

#ifndef SDL2PP_IMG_ERROR_HPP
#define SDL2PP_IMG_ERROR_HPP


#include <string>
#include <stdexcept>

#include <SDL2/SDL_image.h>

namespace SDL2pp {
    namespace IMG {
        struct Error : public std::runtime_error {
            Error():Error( "" ) {}
            Error( const char* what_arg ):Error( std::string {what_arg} ) {}
            Error( const std::string& what_arg ):
                std::runtime_error( what_arg + std::string {"\r\n"} + std::string {"SDL_Image Error: "} + IMG_GetError() ) {}

            ~SDL_Error() = default;
        };
    };
};

#endif //SDL2PP_IMG_ERROR_HPP
