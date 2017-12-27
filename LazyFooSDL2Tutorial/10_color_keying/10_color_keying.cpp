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
    SDL2pp::Window window("SDL Tutorial 10", SCREEN_WIDTH, SCREEN_HEIGHT);
    //The surface contained by the window
    //Get window surface
    SDL2pp::Surface screen = window.getSurface();
    SDL2pp::Renderer renderer = window.createRenderer(-1, SDL_RENDERER_ACCELERATED);
    //Initialize renderer color
    renderer.setDrawColor(0xFF, 0xFF, 0xFF, 0xFF);

    SDL2pp::Img::Image background_sur("10_color_keying/background.png");
    background_sur.setColorKey(true, background_sur.mapRGB(0x00, 0xFF, 0xFF));
    SDL_Rect background_quad = {0, 0, background_sur.getWidth(), background_sur.getHeight()};
    SDL2pp::Texture background_texture = renderer.createTexture(background_sur);

    SDL2pp::Img::Image foo_sur("10_color_keying/foo.png");
    foo_sur.setColorKey(true, foo_sur.mapRGB(0x00, 0xFF, 0xFF));
    SDL_Rect foo_quad = {0, 0, foo_sur.getWidth(), foo_sur.getHeight()};
    SDL2pp::Texture foo_texture = renderer.createTexture(foo_sur);


    //Clear screen
    renderer.setDrawColor(0xFF, 0xFF, 0xFF, 0xFF);
    renderer.clear();

    //Render background texture to screen
    background_quad.x = 0;
    background_quad.y = 0;
    renderer.copy(background_texture, nullptr, &background_quad);

    //Render Foo' to the screen
    foo_quad.x = 240;
    foo_quad.y = 190;
    renderer.copy(foo_texture, nullptr, &foo_quad);

    //Update screen
    renderer.present();

    sdl.delay(100ms);

    return 0;
}
