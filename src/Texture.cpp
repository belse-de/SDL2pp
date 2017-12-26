//
// Created by belse on 16.12.17.
//

#include <SDL2pp/Error.hpp>
#include "Texture.hpp"

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

void Texture::setColorMode(uint8_t red, uint8_t green, uint8_t blue) {
    //Modulate texture
    int ret = SDL_SetTextureColorMod( texture_, red, green, blue );
    if(ret < 0) throw Error("Texture could not set color mode!");
}
