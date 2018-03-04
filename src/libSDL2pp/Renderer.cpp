//
// Created by belse on 16.12.17.
//

#include <SDL_render.h>
#include <stdexcept>
#include <libSDL2pp/Error.hpp>
#include "libSDL2pp/Renderer.hpp"
#include "libSDL2pp/Texture.hpp"
#include "libSDL2pp/Surface.hpp"

using namespace SDL2pp;

Renderer::Renderer() {}

Renderer::Renderer(SDL_Renderer *renderer) {
    if( renderer == nullptr ) throw std::invalid_argument("Surface pointer must not be nullptr!");
    renderer_ = renderer;
}

Renderer::~Renderer() {
    if(renderer_) {
        SDL_DestroyRenderer(renderer_);
        renderer_ = nullptr;
    }
}

void Renderer::setDrawColor(uint8_t r, uint8_t g, uint8_t b, uint8_t a) {
    int ret = SDL_SetRenderDrawColor(renderer_, r, g, b, a);
    if(ret < 0) throw Error("Renderer could not set draw color!");
}

void Renderer::clear() {
    int ret = SDL_RenderClear(renderer_);
    if(ret < 0) throw Error("Renderer could not clear!");
}

void Renderer::present() {
    SDL_RenderPresent(renderer_);
}

void Renderer::copy(const Texture &texture, const SDL_Rect *srcRect, const SDL_Rect *dstRect) {
    int ret = SDL_RenderCopy(renderer_, texture.texture_, srcRect, dstRect);
    if(ret < 0) throw Error("Renderer could not copy texture!");
}

Texture Renderer::createTexture(const Surface& surface) const {
    SDL_Texture* ret = SDL_CreateTextureFromSurface( renderer_, surface.surface_ );
    if(ret == nullptr) throw Error("Renderer could not create texture from surface!");
    return Texture(ret);
}

void Renderer::fillRect(const SDL_Rect *rect) {
    int ret = SDL_RenderFillRect(renderer_, rect);
    if(ret < 0) throw Error("Renderer could not fill rect!");
}

void Renderer::drawRect(const SDL_Rect *rect) {
    int ret = SDL_RenderDrawRect(renderer_, rect);
    if(ret < 0) throw Error("Renderer could not draw rect!");
}

void Renderer::drawLine(int x1, int y1, int x2, int y2) {
    int ret = SDL_RenderDrawLine(renderer_, x1, y1, x2, y2);
    if(ret < 0) throw Error("Renderer could not draw line!");
}

void Renderer::drawPoint(int x, int y) {
    int ret = SDL_RenderDrawPoint(renderer_, x, y);
    if(ret < 0) throw Error("Renderer could not draw point!");
}

void Renderer::setViewport(const SDL_Rect *pRect) {
    int ret = SDL_RenderSetViewport(renderer_, pRect);
    if(ret < 0) throw Error("Renderer could set viewport!");
}

void
Renderer::copyExtended(const Texture &texture, const SDL_Rect *srcRect, const SDL_Rect *dstRect, const double angle,
                       const SDL_Point *center, const SDL_RendererFlip flip) {
    int ret = SDL_RenderCopyEx(renderer_, texture.texture_,
                               srcRect, dstRect,
                               angle, center, flip);
    if(ret < 0) throw Error("Renderer could not copy texture!");
}


