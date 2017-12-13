//
// Created by belse on 13.12.17.
//

#ifndef SDL2PP_SURFACE_HPP
#define SDL2PP_SURFACE_HPP

#include <SDL2/SDL_surface.h>

namespace SDL2pp {
    class Surface {
    public:
        Surface(SDL_Surface* surface);
        void fillRect( uint32_t color, const SDL_Rect* rect = nullptr);

        SDL_Surface* operator&() {return surface_;}

        uint32_t mapRGB(uint8_t r, uint8_t g, uint8_t b);

    private:
        SDL_Surface* surface_;
    };
};


#endif //SDL2PP_SURFACE_HPP
