//
// Created by belse on 13.12.17.
//

#ifndef SDL2PP_WINDOW_HPP
#define SDL2PP_WINDOW_HPP

#include <string>
#include <SDL2/SDL_video.h>
#include <SDL2/SDL_render.h>

namespace SDL2pp {
    class Surface;
    class Renderer;
    class Window {
    public:
        Window();
        Window(std::string title, int width, int height);
        Window(std::string title, int positionX, int positionY, int width, int height);

        virtual ~Window();

        SDL_Window* operator&() {return window_;}

        Surface getSurface();
        void updateSurface();

        Renderer createRenderer(int index, uint32_t flags);

        void getSize(int *w, int *h);
        void setSize(int w, int h);

    private:
        SDL_Window *window_ = nullptr;

    };
};


#endif //SDL2PP_WINDOW_HPP
