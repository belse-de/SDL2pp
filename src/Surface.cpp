//
// Created by belse on 13.12.17.
//

#include <stdexcept>
#include <SDL2pp/Error.hpp>
#include "Surface.hpp"

using namespace SDL2pp;

Surface::Surface(SDL_Surface* surface) : surface_{surface} {
    if( surface == nullptr ) throw std::invalid_argument("Surface pointer must not be nullptr!");
}

void Surface::fillRect(uint32_t color, const SDL_Rect *rect) {
    int ret = SDL_FillRect(surface_, rect, color);
    if(ret < 0) throw Error("Surface could not be filled!");
}
