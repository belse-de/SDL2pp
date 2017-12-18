/*This source code copyrighted by Lazy Foo' Productions (2004-2015)
and may not be redistributed without written permission.*/

//Using SDL, SDL_image, standard IO, math, and strings
#include <SDL.h>
#include <string>
#include <chrono>
#include <SDL2.hpp>
#include <SDL2Image.hpp>
#include <iostream>
#include <Window.hpp>

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
    SDL2pp::Window window("SDL Tutorial 08", SCREEN_WIDTH, SCREEN_HEIGHT);
    //The surface contained by the window
    //Get window surface
    SDL2pp::Surface screen = window.getSurface();
    SDL2pp::Renderer renderer = window.createRenderer(1, SDL_RENDERER_ACCELERATED);
    //Initialize renderer color
    renderer.setDrawColor(0xFF, 0xFF, 0xFF, 0xFF);


    //Clear screen
    renderer.setDrawColor(0xFF, 0xFF, 0xFF, 0xFF);
    renderer.clear();

    //Render red filled quad
    SDL_Rect fillRect = {SCREEN_WIDTH / 4, SCREEN_HEIGHT / 4, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2};
    renderer.setDrawColor(0xFF, 0x00, 0x00, 0xFF);
    renderer.fillRect(&fillRect);

    //Render green outlined quad
    SDL_Rect outlineRect = {SCREEN_WIDTH / 6, SCREEN_HEIGHT / 6, SCREEN_WIDTH * 2 / 3, SCREEN_HEIGHT * 2 / 3};
    renderer.setDrawColor(0x00, 0xFF, 0x00, 0xFF);
    renderer.drawRect(&outlineRect);

    //Draw blue horizontal line
    renderer.setDrawColor(0x00, 0x00, 0xFF, 0xFF);
    renderer.drawLine(0, SCREEN_HEIGHT / 2, SCREEN_WIDTH, SCREEN_HEIGHT / 2);

    //Draw vertical line of yellow dots
    renderer.setDrawColor(0xFF, 0xFF, 0x00, 0xFF);
    for (int i = 0; i < SCREEN_HEIGHT; i += 4) {
        renderer.drawPoint(SCREEN_WIDTH / 2, i);
    }

    //Update screen
    renderer.present();

    sdl.delay(100ms);

    return 0;
}
