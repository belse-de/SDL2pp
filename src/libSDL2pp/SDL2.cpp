//
// Created by belse on 12.12.17.
//

#include "libSDL2pp/SDL2.hpp"
#include "libSDL2pp/Error.hpp"

#include <SDL2/SDL.h>

using namespace SDL2pp;

SDL2::SDL2() : SDL2(SDL_INIT_EVERYTHING) {
}

SDL2::SDL2(uint32_t flags) {
    //Initialize SDL
    if( SDL_Init( flags ) < 0 )
    {
        throw Error("SDL could not initialize!");
    }
}

SDL2::~SDL2() {
    //Quit SDL subsystems
    SDL_Quit();
}

void SDL2::delay(std::chrono::milliseconds ms) const{
    SDL_Delay(ms.count());
}

bool SDL2::setHint(const char *name, const char *value) const{
    SDL_bool ret = SDL_SetHint(name, value);
    return ret ==  SDL_TRUE ? true : false;
}

std::chrono::milliseconds SDL2::getTicks() {
    uint32_t ticks = SDL_GetTicks();
    return std::chrono::milliseconds(ticks);
}

