//
// Created by belse on 13.12.17.
//

#ifndef SDL2PP_SURFACE_HPP
#define SDL2PP_SURFACE_HPP

#include <string>
#include <SDL2/SDL_surface.h>

namespace SDL2pp {
    class Surface {
    public:
        Surface(SDL_Surface* surface);
        Surface(std::string pathBMP);

        virtual ~Surface();


        SDL_Surface* operator&() {return surface_;}
        uint32_t mapRGB(uint8_t r, uint8_t g, uint8_t b);
        void fillRect( uint32_t color, const SDL_Rect* rect = nullptr);
        void blitOnto(Surface &destination, const SDL_Rect *srcRect = nullptr, SDL_Rect *dstRect = nullptr);

    private:
        SDL_Surface* surface_ = nullptr;
        bool hasToBeFreed_ = false;
    };
};


#endif //SDL2PP_SURFACE_HPP
