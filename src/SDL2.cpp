//
// Created by belse on 12.12.17.
//

#include "SDL2.hpp"
#include "SDL2pp/Error.hpp"

#include <SDL2/SDL.h>

using namespace SDL2pp;

SDL2::SDL2() {
    //Initialize SDL
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        throw Error("SDL could not initialize!");
    }
}

SDL2::~SDL2() {
    //Quit SDL subsystems
    SDL_Quit();
}
