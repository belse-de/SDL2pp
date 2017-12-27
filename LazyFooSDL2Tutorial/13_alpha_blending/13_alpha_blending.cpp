/*This source code copyrighted by Lazy Foo' Productions (2004-2015)
and may not be redistributed without written permission.*/

//Using SDL, SDL_image, standard IO, and strings
#include <SDL.h>
#include <string>
#include <chrono>
#include <SDL2.hpp>
#include <SDL2Image.hpp>
#include <iostream>
#include <Window.hpp>
#include <Image.hpp>

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main(int argc, char *args[]) {
    using namespace std::chrono_literals;
    //Start up SDL and create window
    //Initialize SDL
    SDL2pp::SDL2 sdl;
    SDL2pp::Img::SDL2Image img;

    if (not sdl.setHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
        std::clog << "Warning: Linear texture filtering not enabled!" << std::endl;
    //The window we'll be rendering to
    SDL2pp::Window window("SDL Tutorial 13", SCREEN_WIDTH, SCREEN_HEIGHT);
    //The surface contained by the window
    //Get window surface
    SDL2pp::Surface screen = window.getSurface();
    SDL2pp::Renderer renderer = window.createRenderer(-1, SDL_RENDERER_ACCELERATED);
    //Initialize renderer color
    renderer.setDrawColor(0xFF, 0xFF, 0xFF, 0xFF);


    SDL2pp::Img::Image modulated_sur("13_alpha_blending/fadeout.png");
    modulated_sur.setColorKey(true, modulated_sur.mapRGB(0x00, 0xFF, 0xFF));
    SDL2pp::Texture modulated_tex = renderer.createTexture(modulated_sur);

    SDL2pp::Img::Image background_sur("13_alpha_blending/fadein.png");
    background_sur.setColorKey(true, background_sur.mapRGB(0x00, 0xFF, 0xFF));
    SDL2pp::Texture background_tex = renderer.createTexture(background_sur);

    for (uint8_t a = 0xff; a >= 0x10; a -= 0x10) {
        //Clear screen
        renderer.setDrawColor(0xFF, 0xFF, 0xFF, 0xFF);
        renderer.clear();

        //Render background
        renderer.renderCopy(background_tex);

        //Render front blended
        modulated_tex.setAlphaMod(a);
        renderer.renderCopy(modulated_tex);

        renderer.present();
        sdl.delay(100ms);
    }

    for (uint8_t a = 0x00; a < 0xf0; a += 0x10) {
        //Clear screen
        renderer.setDrawColor(0xFF, 0xFF, 0xFF, 0xFF);
        renderer.clear();

        //Render background
        renderer.renderCopy(background_tex);

        //Render front blended
        modulated_tex.setAlphaMod(a);
        renderer.renderCopy(modulated_tex);

        renderer.present();
        sdl.delay(100ms);
    }
    return 0;
}
