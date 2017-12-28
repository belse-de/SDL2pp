//
// Created by belse on 14.12.17.
//

#include <SDL2pp/Img/Error.hpp>
#include "SDL2pp/Img/SDL2Image.hpp"

using  namespace SDL2pp::Img;

SDL2Image::SDL2Image() {
    int imgFlags = IMG_INIT_PNG;
    if( !( IMG_Init( imgFlags ) & imgFlags ) )
    {
        throw Error("SDL_image could not initialize!");
    }
}

SDL2Image::~SDL2Image() {
    IMG_Quit();
}
