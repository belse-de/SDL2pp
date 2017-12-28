//
// Created by belse on 16.12.17.
//

#include <SDL2pp/Error.hpp>
#include "SDL2pp/Texture.hpp"

using namespace SDL2pp;

Texture::Texture() {

}

Texture::Texture(SDL_Texture *texture) : texture_{texture} {

}

Texture::~Texture() {
    if(texture_) {
        SDL_DestroyTexture(texture_);
        texture_ = nullptr;
    }
}

void Texture::setColorMod(uint8_t red, uint8_t green, uint8_t blue) {
    //Modulate texture rgb
    int ret = SDL_SetTextureColorMod( texture_, red, green, blue );
    if(ret < 0) throw Error("Texture could not set color modulation!");
}

void Texture::setBlendMode(SDL_BlendMode blendMode) {
    //Set blending function
    int ret = SDL_SetTextureBlendMode(texture_, blendMode);
    if(ret < 0) throw Error("Texture could not set blend mode!");
}

void Texture::setAlphaMod(uint8_t alpha) {
    //Modulate texture alpha
    int ret = SDL_SetTextureAlphaMod(texture_, alpha);
    if(ret < 0) throw Error("Texture could not set alpha modulation!");
}
