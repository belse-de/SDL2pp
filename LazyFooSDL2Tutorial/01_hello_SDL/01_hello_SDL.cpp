/*This source code copyrighted by Lazy Foo' Productions (2004-2015)
and may not be redistributed without written permission.*/

//Using SDL and standard IO
#include <SDL2/SDL.h>
#include <exception>
#include <iostream>
#include "SDL2pp/SDL2.hpp"
#include "SDL2pp/Window.hpp"

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main( int argc, char* args[] )
{
    using namespace std::chrono_literals;

    try {
        SDL2pp::SDL2 sdl;

        //The window we'll be rendering to
        SDL2pp::Window window( "SDL Tutorial 01", SCREEN_WIDTH, SCREEN_HEIGHT);

        //The surface contained by the window
        //Get window surface
        SDL2pp::Surface screen = window.getSurface();

        //Fill the surface white
        screen.fillRect( screen.mapRGB( 0xFF, 0xFF, 0xFF) );

        //Update the surface
        window.updateSurface();

        //Wait
        sdl.delay( 100ms );

    }catch( std::exception &e )
    {
        std::cerr << e.what() << std::endl;
    }

	return 0;
}
