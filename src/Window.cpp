//
// Created by belse on 13.12.17.
//

#include "Window.hpp"

#include <SDL2/SDL.h>
#include <SDL2pp/Error.hpp>

using namespace SDL2pp;

Window::Window() : Window("", 640, 480) {}

Window::Window(std::string title, int width, int height) {
    SDL_Window *window;                 // Declare a pointer
    // Create an application window with the following settings:
    window = SDL_CreateWindow(
        title.c_str(),                  // window title
        SDL_WINDOWPOS_UNDEFINED,        // initial x position
        SDL_WINDOWPOS_UNDEFINED,        // initial y position
        width,                          // width, in pixels
        height,                         // height, in pixels
        0                               // flags
    );

    if(window == nullptr) throw Error("Window could not be created!");
    window_ = window;
}

Window::~Window() {
    //Destroy window
    SDL_DestroyWindow( window_ );
    window_ = nullptr;
}

Surface Window::getSurface() {
    //The surface contained by the window
    SDL_Surface* screenSurface;
    //Get window surface
    screenSurface = SDL_GetWindowSurface( window_ );

    if(screenSurface == nullptr) throw Error("Surface of window could not be created!");
    return Surface(screenSurface);
}

void Window::updateSurface() {
    int ret = SDL_UpdateWindowSurface(window_);
    if(ret < 0) throw Error("Window could not update its surface!");
}

Renderer Window::createRenderer(int index, uint32_t flags) {
    SDL_Renderer* ret = SDL_CreateRenderer(window_, index, flags);
    if(ret == nullptr) throw Error("Renderer could not be created!");
    return Renderer(ret);
}
