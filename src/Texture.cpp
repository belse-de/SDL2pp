//
// Created by belse on 16.12.17.
//

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
