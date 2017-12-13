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
