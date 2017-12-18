//
// Created by belse on 16.12.17.
//

#ifndef SDL2PP_TEXTURE_HPP
#define SDL2PP_TEXTURE_HPP

#include <SDL_render.h>


namespace SDL2pp {
    class Renderer;
    class Texture {
        friend class Renderer;

    public:
        Texture();
        Texture(SDL_Texture* texture);
        ~Texture();

    private:
        SDL_Texture *texture_ = nullptr;

    };
};

#endif //SDL2PP_TEXTURE_HPP
