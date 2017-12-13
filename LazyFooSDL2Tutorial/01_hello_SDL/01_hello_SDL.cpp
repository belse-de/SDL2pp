/*This source code copyrighted by Lazy Foo' Productions (2004-2015)
and may not be redistributed without written permission.*/

//Using SDL and standard IO
#include <SDL2/SDL.h>
#include <exception>
#include <iostream>
#include "SDL2.hpp"
#include "Window.hpp"

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main( int argc, char* args[] )
{

	
	//The surface contained by the window
	SDL_Surface* screenSurface = NULL;

    try {
        SDL2pp::SDL2 sdl();

        //The window we'll be rendering to
        SDL2pp::Window window( "SDL Tutorial", SCREEN_WIDTH, SCREEN_HEIGHT);

        //The surface contained by the window
        SDL_Surface* screenSurface;
        //Get window surface
        screenSurface = window.getSurface();

        //Fill the surface white
        SDL_FillRect( screenSurface, NULL, SDL_MapRGB( screenSurface->format, 0xFF, 0xFF, 0xFF ) );

        //Update the surface
        window.updateSurface();

        //Wait two seconds
        SDL_Delay( 100 );

    }catch( std::exception &e )
    {
        std::cerr << e.what() << std::endl;
    }

	return 0;
}
