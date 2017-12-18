/*This source code copyrighted by Lazy Foo' Productions (2004-2015)
and may not be redistributed without written permission.*/

//Using SDL, SDL_image, standard IO, and strings
#include <SDL.h>
#include <string>
#include <chrono>
#include <SDL2.hpp>
#include <SDL2Image.hpp>
#include <Window.hpp>
#include <iostream>
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
    SDL2pp::Window window("SDL Tutorial 07", SCREEN_WIDTH, SCREEN_HEIGHT);
    //The surface contained by the window
    //Get window surface
    SDL2pp::Surface screen = window.getSurface();
    SDL2pp::Renderer renderer = window.createRenderer(1, SDL_RENDERER_ACCELERATED);
    //Initialize renderer color
    renderer.setDrawColor(0xFF, 0xFF, 0xFF, 0xFF);

    SDL2pp::Img::Image texture_surface("07_texture_loading_and_rendering/texture.png");
    SDL2pp::Texture texture = renderer.createTexture(texture_surface);


    //Clear screen
    renderer.clear();

    //Render texture to screen
    renderer.renderCopy(texture, nullptr, nullptr);

    //Update screen
    renderer.present();

    sdl.delay(100ms);


    return 0;
}
