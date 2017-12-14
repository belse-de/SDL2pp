/*This source code copyrighted by Lazy Foo' Productions (2004-2015)
and may not be redistributed without written permission.*/

//Using SDL, standard IO, and strings
#include <SDL.h>
#include <stdio.h>
#include <string>
#include <SDL2.hpp>
#include <Window.hpp>

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;


int main( int argc, char* args[] )
{
	using namespace std::chrono_literals;
	//Start up SDL and create window
	//Initialize SDL
	SDL2pp::SDL2 sdl;
	//The window we'll be rendering to
	SDL2pp::Window window("SDL Tutorial", SCREEN_WIDTH, SCREEN_HEIGHT);
	//The surface contained by the window
	//Get window surface
	SDL2pp::Surface screen = window.getSurface();
	// load media
	//Load stretching surface
	SDL2pp::Surface stretchedSurface( "05_optimized_surface_loading_and_soft_stretching/stretch.bmp" );
	SDL2pp::Surface optimizedSurface = stretchedSurface.convertTo(screen.getFormat());


	screen.fillRect( screen.mapRGB( 0x00, 0x00, 0x00) );

	//Apply the image stretched
	SDL_Rect stretchRect;
	stretchRect.x = 0;
	stretchRect.y = 0;
	stretchRect.w = SCREEN_WIDTH;
	stretchRect.h = SCREEN_HEIGHT;
	optimizedSurface.blitAndScaleOnto(screen, nullptr, &stretchRect);

	//Update the surface
	window.updateSurface();

	sdl.delay(550ms);


	//Free resources and close SDL

	return 0;
}
