//
// Created by belse on 01.01.18.
//

#include <SDL_net.h>
#include "SDL2Net.hpp"
#include "Error.hpp"

using namespace SDL2pp::Net;

bool SDL2Net::isInit_ = false;

SDL2Net::SDL2Net() {
    if(SDL2Net::wasInit()){
        throw Error("SDL_net is already initialized!");
    }
    if(SDLNet_Init()==-1) {
        throw Error("SDL_net could not initialize!");
    }
    isInit_ = true;
}

SDL2Net::~SDL2Net() {
    SDLNet_Quit();
    isInit_ = false;
}

bool SDL2Net::wasInit() {
    return isInit_;
}
