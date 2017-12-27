//
// Created by belse on 27.12.17.
//

#include <SDL_ttf.h>
#include <SDL2pp/TTF/Error.hpp>
#include "SDL2TTF.hpp"

using  namespace SDL2pp::TTF;

SDL2TTF::SDL2TTF() {
    //Initialize SDL_ttf
    if( TTF_Init() == -1 )
    {
        throw Error("SDL_ttf could not initialize!");
    }
}

SDL2TTF::~SDL2TTF() {
    TTF_Quit();
}


