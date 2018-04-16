//
// Created by belse on 13.12.17.
//

#include "Window.hpp"
#include "Surface.hpp"
#include "Renderer.hpp"

#include <SDL2/SDL.h>
#include <libSDL2pp/src/Error.hpp>

using namespace SDL2pp;

Window::Window() : Window("", 640, 480) {}

Window::Window(std::string title, int width, int height) : Window(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height) {}


Window::Window(std::string title, int positionX, int positionY, int width, int height) {
    SDL_Window *window;                 // Declare a pointer
    // Create an application window with the following settings:
    window = SDL_CreateWindow(
        title.c_str(),                  // window title
        positionX,                      // initial x position
        positionY,                      // initial y position
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
    return Surface(screenSurface, false);
}

void Window::updateSurface() {
    int ret = SDL_UpdateWindowSurface(window_);
    if(ret < 0) throw Error("Window could not update its surface!");
}

Renderer Window::createRenderer(int index, uint32_t flags) {
    //TODO: make Renderer Ctor
    SDL_Renderer* ret = SDL_CreateRenderer(window_, index, flags);
    if(ret == nullptr) throw Error("Renderer could not be created!");
    return Renderer(ret);
}

void Window::getSize(int *w, int *h) {
    SDL_GetWindowSize(window_, w, h);
}

void Window::setSize(int w, int h) {
    SDL_SetWindowSize(window_, w, h);
}

