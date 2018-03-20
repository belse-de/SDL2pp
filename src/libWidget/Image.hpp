//
// Created by belse on 17.03.18.
//

#ifndef SDL2PP_WIDGET_IMAGE_HPP
#define SDL2PP_WIDGET_IMAGE_HPP

#include <libWidget/Base.hpp>

#include <libSDL2pp/Texture.hpp>

namespace Widget {
    class Image : public Base {
    public:
        Image(SDL2pp::Texture & image, SDL_Rect source);
        void render(SDL2pp::Renderer & renderer);

    protected:
        SDL2pp::Texture &_image;
        SDL_Rect _source;
    };
};

#endif //SDL2PP_WIDGET_IMAGE_HPP
