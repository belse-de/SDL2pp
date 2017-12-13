/*This source code copyrighted by Lazy Foo' Productions (2004-2015)
and may not be redistributed without written permission.*/

//Using SDL and standard IO
#include <SDL.h>
#include <stdio.h>
#include <Surface.hpp>
#include <Window.hpp>
#include <SDL2.hpp>

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

//Loads media
bool loadMedia();

//Frees media and shuts down SDL
void close();

//The image we will load and show on the screen
SDL_Surface* gHelloWorld = NULL;

bool loadMedia()
{
	//Loading success flag
	bool success = true;

	//Load splash image
	gHelloWorld = SDL_LoadBMP( "02_getting_an_image_on_the_screen/hello_world.bmp" );
	if( gHelloWorld == NULL )
	{
		printf( "Unable to load image %s! SDL Error: %s\n", "02_getting_an_image_on_the_screen/hello_world.bmp", SDL_GetError() );
		success = false;
	}

	return success;
}

void close()
{
	//Deallocate surface
	SDL_FreeSurface( gHelloWorld );
	gHelloWorld = NULL;
}

int main( int argc, char* args[] )
{
	using namespace std::chrono_literals;
	//Start up SDL and create window
	//Initialize SDL
	SDL2pp::SDL2 sdl;
	//The window we'll be rendering to
	SDL2pp::Window window( "SDL Tutorial", SCREEN_WIDTH, SCREEN_HEIGHT);
	//The surface contained by the window
	//Get window surface
	SDL2pp::Surface screen = window.getSurface();

		//Load media
		if( !loadMedia() )
		{
			printf( "Failed to load media!\n" );
		}
		else
		{
			//Apply the image
			SDL_BlitSurface( gHelloWorld, NULL, &screen, NULL );
			
			//Update the surface
			window.updateSurface();

			//Wait
			sdl.delay( 1000ms );
		}

	//Free resources and close SDL
	close();

	return 0;
}
