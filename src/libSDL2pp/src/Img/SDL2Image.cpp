//
// Created by belse on 14.12.17.
//

#include "Error.hpp"
#include "SDL2Image.hpp"

using  namespace SDL2pp::Img;

SDL2Image::SDL2Image() : SDL2Image(IMG_INIT_PNG) {
}

SDL2Image::SDL2Image(int flags) {
    if( not ( IMG_Init( flags ) & flags ) )
    {
        throw Error("SDL_image could not initialize!");
    }
}

SDL2Image::~SDL2Image() {
    IMG_Quit();
}
