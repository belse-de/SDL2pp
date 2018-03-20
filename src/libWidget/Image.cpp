//
// Created by belse on 17.03.18.
//

#include "Image.hpp"

#include <libSDL2pp/Renderer.hpp>

using namespace Widget;

Image::Image(SDL2pp::Texture &image, SDL_Rect source) : _image{image}, _source{source} {
    _hitBox = source;
}

void Image::render(SDL2pp::Renderer &renderer) {
    renderer.copy(_image, &_source, &_hitBox);
    //renderer.copy(_image, nullptr, nullptr);
}

