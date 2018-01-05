//
// Created by belse on 16.12.17.
//

#ifndef SDL2PP_RENDERER_HPP
#define SDL2PP_RENDERER_HPP

#include "Texture.hpp"

namespace SDL2pp {
    class Surface;
    class Renderer {
    public:
        Renderer();
        Renderer(SDL_Renderer* renderer);

        virtual ~Renderer();

        void setDrawColor(uint8_t r, uint8_t g, uint8_t b, uint8_t a);
        void clear();
        void present();
        void copy(const Texture &texture, const SDL_Rect *srcRect = nullptr, const SDL_Rect *dstRect = nullptr);
        void copyExtended(const Texture &texture,
                          const SDL_Rect *srcRect = nullptr, const SDL_Rect *dstRect = nullptr,
                          const double angle = 0.0, const SDL_Point* center = nullptr,
                          const SDL_RendererFlip flip = SDL_FLIP_NONE );

        Texture createTexture(const Surface& surface) const;

        void fillRect(const SDL_Rect *rect);
        void drawRect(const SDL_Rect *rect);
        void drawLine(int x1, int y1, int x2, int y2);
        void drawPoint(int x, int y);

        void setViewport(const SDL_Rect *pRect);

    private:
        SDL_Renderer* renderer_;
    };
};


#endif //SDL2PP_RENDERER_HPP
