/*This source code copyrighted by Lazy Foo' Productions (2004-2015)
and may not be redistributed without written permission.*/

//Using SDL, SDL_image, standard IO, and strings
#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include <SDL2pp/Img/SDL2Image.hpp>
#include <SDL2pp/SDL2.hpp>
#include <SDL2pp/Window.hpp>
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
    //The window we'll be rendering to
    SDL2pp::Window window("SDL Tutorial 06", SCREEN_WIDTH, SCREEN_HEIGHT);
    //The surface contained by the window
    //Get window surface
    SDL2pp::Surface screen = window.getSurface();

    SDL2pp::Img::Image PNGSurfaceRaw("06_extension_libraries_and_loading_other_image_formats/loaded.png");
    SDL2pp::Surface PNGSurface = PNGSurfaceRaw.convertTo(screen.getFormat());


    //Apply the PNG image
    PNGSurface.blitOnto(screen);

    //Update the surface
    window.updateSurface();

    sdl.delay(100ms);

//Free resources and close SDL

return 0;
}
