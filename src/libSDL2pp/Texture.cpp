//
// Created by belse on 16.12.17.
//

#include <libSDL2pp/Error.hpp>
#include "libSDL2pp/Texture.hpp"

using namespace SDL2pp;

Texture::Texture() {

}

Texture::Texture(SDL_Texture *texture){
    texture_ =
        std::shared_ptr<SDL_Texture>(
            texture,
            [](SDL_Texture* t){
                if(not(t == nullptr)){
                    SDL_DestroyTexture(t);
                }
            }
        );
}

Texture::~Texture() {
    /*
     if(texture_) {
        SDL_DestroyTexture(texture_);
        texture_ = nullptr;
    }*/
}

void Texture::setColorMod(uint8_t red, uint8_t green, uint8_t blue) {
    //Modulate texture rgb
    int ret = SDL_SetTextureColorMod( texture_.get(), red, green, blue );
    if(ret < 0) throw Error("Texture could not set color modulation!");
}

void Texture::setBlendMode(SDL_BlendMode blendMode) {
    //Set blending function
    int ret = SDL_SetTextureBlendMode(texture_.get(), blendMode);
    if(ret < 0) throw Error("Texture could not set blend mode!");
}

void Texture::setAlphaMod(uint8_t alpha) {
    //Modulate texture alpha
    int ret = SDL_SetTextureAlphaMod(texture_.get(), alpha);
    if(ret < 0) throw Error("Texture could not set alpha modulation!");
}

void Texture::query(uint32_t *format, int *access, int *w, int *h) {
    int ret = SDL_QueryTexture(texture_.get(), format, access, w, h);
    if(ret < 0) throw Error("Texture could not be queried!");
}
