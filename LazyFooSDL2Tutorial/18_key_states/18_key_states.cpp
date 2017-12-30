/*This source code copyrighted by Lazy Foo' Productions (2004-2015)
and may not be redistributed without written permission.*/

//Using SDL, SDL_image, standard IO, and strings
#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include <SDL2pp/Texture.hpp>
#include <chrono>
#include <iostream>
#include <SDL2pp/SDL2.hpp>
#include <SDL2pp/Img/SDL2Image.hpp>
#include <SDL2pp/TTF/SDL2TTF.hpp>
#include <SDL2pp/Window.hpp>
#include <array>
#include <SDL2pp/Img/Image.hpp>

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main(int argc, char *args[]) {
    using namespace std::chrono_literals;
    //Start up SDL and create window
    //Initialize SDL
    SDL2pp::SDL2 sdl;
    SDL2pp::Img::SDL2Image img;
    SDL2pp::TTF::SDL2TTF ttf;

    if (not sdl.setHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
        std::clog << "Warning: Linear texture filtering not enabled!" << std::endl;
    //The window we'll be rendering to
    SDL2pp::Window window("SDL Tutorial 18", SCREEN_WIDTH, SCREEN_HEIGHT);
    //The surface contained by the window
    //Get window surface
    SDL2pp::Surface screen = window.getSurface();
    SDL2pp::Renderer renderer = window.createRenderer(-1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    //Initialize renderer color
    renderer.setDrawColor(0xFF, 0xFF, 0xFF, 0xFF);

    SDL2pp::Img::Image sur_default("18_key_states/press.png");
    SDL2pp::Img::Image sur_up("18_key_states/up.png");
    SDL2pp::Img::Image sur_down("18_key_states/down.png");
    SDL2pp::Img::Image sur_left("18_key_states/left.png");
    SDL2pp::Img::Image sur_right("18_key_states/right.png");
    SDL2pp::Texture tex_default = renderer.createTexture(sur_default);
    SDL2pp::Texture tex_up = renderer.createTexture(sur_up);
    SDL2pp::Texture tex_down = renderer.createTexture(sur_down);
    SDL2pp::Texture tex_left = renderer.createTexture(sur_left);
    SDL2pp::Texture tex_right = renderer.createTexture(sur_right);
    //Set default current surface
    SDL2pp::Texture *tex_current = &tex_default;


    //Main loop flag
    bool quit = false;

    //Event handler
    SDL_Event e;

    //While application is running
    while (!quit) {
        //Handle events on queue
        while (SDL_PollEvent(&e) != 0) {
            //User requests quit
            if (e.type == SDL_QUIT) {
                quit = true;
            }
        }

        //Set texture based on current keystate
        const Uint8 *currentKeyStates = SDL_GetKeyboardState(nullptr);
        if (currentKeyStates[SDL_SCANCODE_UP]) {
            tex_current = &tex_up;
        } else if (currentKeyStates[SDL_SCANCODE_DOWN]) {
            tex_current = &tex_down;
        } else if (currentKeyStates[SDL_SCANCODE_LEFT]) {
            tex_current = &tex_left;
        } else if (currentKeyStates[SDL_SCANCODE_RIGHT]) {
            tex_current = &tex_right;
        } else {
            tex_current = &tex_default;
        }

        //Clear screen
        renderer.setDrawColor(0xFF, 0xFF, 0xFF, 0xFF);
        renderer.clear();

        //Apply the current image
        renderer.copy(*tex_current);

        //Update the surface
        renderer.present();

        sdl.delay(50ms);
    }

    return 0;
}
