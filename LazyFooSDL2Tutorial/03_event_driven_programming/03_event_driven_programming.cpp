/*This source code copyrighted by Lazy Foo' Productions (2004-2015)
and may not be redistributed without written permission.*/

//Using SDL and standard IO
#include <SDL.h>
#include <SDL2.hpp>
#include <Window.hpp>

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main(int argc, char *args[]) {
    using namespace std::chrono_literals;
    //Start up SDL and create window
    //Initialize SDL
    SDL2pp::SDL2 sdl;
    //The window we'll be rendering to
    SDL2pp::Window window("SDL Tutorial", SCREEN_WIDTH, SCREEN_HEIGHT);
    //The surface contained by the window
    //Get window surface
    SDL2pp::Surface screen = window.getSurface();
    //Loads media
    //Load splash image
    //The image we will load and show on the screen
    SDL2pp::Surface xOut("03_event_driven_programming/x.bmp");


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

        //Apply the image
        xOut.blitOnto(screen);

        //Update the surface
        window.updateSurface();
        // for less cpu hugging
        sdl.delay(50ms);
    }



    //Free resources and close SDL
    // via destructor; RAII for the win

    return 0;
}
