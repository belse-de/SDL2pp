//
// Created by belse on 13.12.17.
//

#ifndef SDL2PP_SURFACE_HPP
#define SDL2PP_SURFACE_HPP

#include <string>
#include <SDL2/SDL_surface.h>

namespace SDL2pp {
    class Renderer;
    class Surface {
        friend class Renderer;
    public:
        Surface();

        Surface(SDL_Surface *surface, bool hasToBeFreed = false);
        Surface(std::string pathBMP);

        virtual ~Surface();

        uint32_t mapRGB(uint8_t r, uint8_t g, uint8_t b);
        void fillRect( uint32_t color, const SDL_Rect* rect = nullptr);
        void blitOnto(Surface &destination, const SDL_Rect *srcRect = nullptr, SDL_Rect *dstRect = nullptr);
        void blitAndScaleOnto(Surface &destination, const SDL_Rect *srcRect = nullptr, SDL_Rect *dstRect = nullptr);
        const SDL_PixelFormat* getFormat() const;
        Surface convertTo(const SDL_PixelFormat* fmt, uint32_t flags = 0);
        void setColorKey(bool enable, uint32_t colorkey);

        int getWidth();
        int getHeight();

        SDL_Surface* get(){ return surface_; }
    protected:
        SDL_Surface* surface_ = nullptr;
        bool hasToBeFreed_ = false;
    };
};


#endif //SDL2PP_SURFACE_HPP
