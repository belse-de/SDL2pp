//
// Created by belse on 27.12.17.
//

#include <iostream>
#include <SDL_ttf.h>
#include <libSDL2pp/TTF/Error.hpp>
#include "libSDL2pp/TTF/SDL2TTF.hpp"

using  namespace SDL2pp::TTF;

bool SDL2TTF::isInit_ = false;

SDL2TTF::SDL2TTF() {
    if(SDL2TTF::wasInit()){
        throw Error("SDL_ttf is already initialized!");
    }
    //Initialize SDL_ttf
    if( TTF_Init() == -1 )
    {
        throw Error("SDL_ttf could not initialize!");
    }
    isInit_ = true;
}

SDL2TTF::~SDL2TTF() {
    if( SDL2TTF::wasInit() ) { TTF_Quit(); }
    isInit_ = false;
}

bool SDL2TTF::wasInit() {
    return (TTF_WasInit() >= 1);
}


