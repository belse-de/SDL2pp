//
// Created by belse on 13.12.17.
//

#include <stdexcept>
#include <SDL2pp/Error.hpp>
#include "Surface.hpp"

using namespace SDL2pp;

Surface::Surface() {}

Surface::Surface(SDL_Surface* surface) : surface_{surface}, hasToBeFreed_{false} {
    if( surface == nullptr ) throw std::invalid_argument("Surface pointer must not be nullptr!");
}

Surface::Surface(std::string pathBMP) : hasToBeFreed_{true} {
    if( pathBMP.empty() ) throw std::invalid_argument("Path to BMP must not be empty!");
    SDL_Surface* bmp = SDL_LoadBMP( pathBMP.c_str() );
    if(bmp == nullptr) throw Error("Surface could not load BMP " + pathBMP + "!");
    surface_ = bmp;
}

Surface::~Surface() {
    if(hasToBeFreed_){
        //Deallocate surface
        if(surface_) {
            SDL_FreeSurface(surface_);
            surface_ = nullptr;
        }
    }
}

void Surface::fillRect(uint32_t color, const SDL_Rect *rect) {
    int ret = SDL_FillRect(surface_, rect, color);
    if(ret < 0) throw Error("Surface could not be filled!");
}

uint32_t Surface::mapRGB(uint8_t r, uint8_t g, uint8_t b) {
    return SDL_MapRGB( surface_->format, r, g, b );
}

void Surface::blitOnto(Surface &destination, const SDL_Rect *srcRect, SDL_Rect *dstRect) {
    int ret = SDL_BlitSurface(surface_, srcRect, destination.surface_, dstRect);
    if(ret < 0) throw Error("Surface could not blit onto  its surface!");
}

void Surface::blitAndScaleOnto(Surface &destination, const SDL_Rect *srcRect, SDL_Rect *dstRect) {
    int ret = SDL_BlitScaled(surface_, srcRect, destination.surface_, dstRect);
    if(ret < 0) throw Error("Surface could not blit onto  its surface!");
}

const SDL_PixelFormat *Surface::getFormat() const {
    return surface_->format;
}

Surface Surface::convertTo(const SDL_PixelFormat *fmt, uint32_t flags) {
    SDL_Surface* converted = SDL_ConvertSurface( surface_, fmt, flags);
    Surface conv_surf(converted);
    conv_surf.hasToBeFreed_ = true;
    return conv_surf;
}
