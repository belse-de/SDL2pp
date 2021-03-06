//
// Created by belse on 14.12.17.
//

#include <stdexcept>
#include "Error.hpp"
#include "ImageSurface.hpp"

using namespace SDL2pp::Img;

ImageSurface::ImageSurface(std::string pathIMG) {
    if( pathIMG.empty() ) throw std::invalid_argument("Path to BMP must not be empty!");
    SDL_Surface* img = IMG_Load( pathIMG.c_str() );
    if(img == nullptr) throw Error("Could not load image " + pathIMG + "!");
    surface_ = img;
    hasToBeFreed_ = true;
}
