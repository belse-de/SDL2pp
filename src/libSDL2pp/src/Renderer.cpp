//
// Created by belse on 16.12.17.
//

#include <SDL_render.h>
#include <stdexcept>
#include <libSDL2pp/src/Error.hpp>
#include "Renderer.hpp"
#include "Surface.hpp"

using namespace SDL2pp;

Renderer::Renderer(SDL_Renderer *renderer) {
    if (renderer == nullptr) throw std::invalid_argument("Renderer pointer must not be nullptr!");
    renderer_ =
        std::shared_ptr<SDL_Renderer>(
            renderer,
            [](SDL_Renderer *r) { if (r) { SDL_DestroyRenderer(r); }}
        );
}


Renderer::Renderer(Surface &surface) {
    SDL_Renderer *renderer = SDL_CreateSoftwareRenderer(surface.get());
    if (not renderer) throw Error("Software renderer could not be created!");
    renderer_ =
        std::shared_ptr<SDL_Renderer>(
            renderer,
            [](SDL_Renderer *r) { if (r) { SDL_DestroyRenderer(r); }}
        );
}

void Renderer::setDrawColor(uint8_t r, uint8_t g, uint8_t b, uint8_t a) {
    int ret = SDL_SetRenderDrawColor(renderer_.get(), r, g, b, a);
    if (ret < 0) throw Error("Renderer could not set draw color!");
}

void Renderer::clear() {
    int ret = SDL_RenderClear(renderer_.get());
    if (ret < 0) throw Error("Renderer could not clear!");
}

void Renderer::present() {
    SDL_RenderPresent(renderer_.get());
}

void Renderer::copy(const Texture &texture, const SDL_Rect *srcRect, const SDL_Rect *dstRect) {
    int ret = SDL_RenderCopy(renderer_.get(), texture.texture_.get(), srcRect, dstRect);
    if (ret < 0) throw Error("Renderer could not copy texture!");
}

Texture Renderer::createTexture(const Surface &surface) const {
    //TODO: make Texture ctor
    SDL_Texture *ret = SDL_CreateTextureFromSurface(renderer_.get(), surface.surface_);
    if (ret == nullptr) throw Error("Renderer could not create texture from surface!");
    return Texture(ret);
}

void Renderer::fillRect(const SDL_Rect *rect) {
    int ret = SDL_RenderFillRect(renderer_.get(), rect);
    if (ret < 0) throw Error("Renderer could not fill rect!");
}

void Renderer::drawRect(const SDL_Rect *rect) {
    int ret = SDL_RenderDrawRect(renderer_.get(), rect);
    if (ret < 0) throw Error("Renderer could not draw rect!");
}

void Renderer::drawLine(int x1, int y1, int x2, int y2) {
    int ret = SDL_RenderDrawLine(renderer_.get(), x1, y1, x2, y2);
    if (ret < 0) throw Error("Renderer could not draw line!");
}

void Renderer::drawPoint(int x, int y) {
    int ret = SDL_RenderDrawPoint(renderer_.get(), x, y);
    if (ret < 0) throw Error("Renderer could not draw point!");
}

void Renderer::setViewport(const SDL_Rect *pRect) {
    int ret = SDL_RenderSetViewport(renderer_.get(), pRect);
    if (ret < 0) throw Error("Renderer could set viewport!");
}

void
Renderer::copyExtended(const Texture &texture, const SDL_Rect *srcRect, const SDL_Rect *dstRect, const double angle,
                       const SDL_Point *center, const SDL_RendererFlip flip) {
    int ret = SDL_RenderCopyEx(renderer_.get(), texture.texture_.get(),
                               srcRect, dstRect,
                               angle, center, flip);
    if (ret < 0) throw Error("Renderer could not copy texture!");
}



