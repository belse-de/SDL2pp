//
// Created by belse on 16.12.17.
//

#include <SDL_render.h>
#include <stdexcept>
#include <SDL2pp/Error.hpp>
#include "Renderer.hpp"
#include "Texture.hpp"
#include "Surface.hpp"

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

void Renderer::renderCopy(const Texture& texture, const SDL_Rect *srcRect, const SDL_Rect *dstRect) {
    int ret = SDL_RenderCopy(renderer_, texture.texture_, srcRect, dstRect);
    if(ret < 0) throw Error("Renderer could not copy texture!");
}

Texture Renderer::createTexture(const Surface& surface) const {
    SDL_Texture* ret = SDL_CreateTextureFromSurface( renderer_, surface.surface_ );
    if(ret == nullptr) throw Error("Renderer could not create texture from surface!");
    return Texture(ret);
}
