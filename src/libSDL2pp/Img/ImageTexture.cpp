//
// Created by belse on 15.03.18.
//

#include <stdexcept>
#include <SDL_image.h>
#include <libSDL2pp/Renderer.hpp>
#include "ImageTexture.hpp"
#include "Error.hpp"

using namespace SDL2pp::Img;

ImageTexture::ImageTexture(const SDL2pp::Renderer &renderer, std::string pathIMG) {
    if (pathIMG.empty()) throw std::invalid_argument("Path to BMP must not be empty!");
    SDL_Texture *img = IMG_LoadTexture(renderer.getCPtr(), pathIMG.c_str());
    if (img == nullptr) throw Error("Could not load image " + pathIMG + "!");
    texture_ =
        std::shared_ptr<SDL_Texture>(
            img,
            [](SDL_Texture *t) {
                if (not(t == nullptr)) {
                    SDL_DestroyTexture(t);
                }
            }
        );
}
