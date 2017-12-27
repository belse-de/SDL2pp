/*This source code copyrighted by Lazy Foo' Productions (2004-2015)
and may not be redistributed without written permission.*/

//Using SDL, SDL_image, standard IO, and strings
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
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


int main( int argc, char* args[] )
{
	using namespace std::chrono_literals;
	//Start up SDL and create window
	//Initialize SDL
	SDL2pp::SDL2 sdl;
	SDL2pp::Img::SDL2Image img;

	if (not sdl.setHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
		std::clog << "Warning: Linear texture filtering not enabled!" << std::endl;
	//The window we'll be rendering to
	SDL2pp::Window window("SDL Tutorial 12", SCREEN_WIDTH, SCREEN_HEIGHT);
	//The surface contained by the window
	//Get window surface
	SDL2pp::Surface screen = window.getSurface();
	SDL2pp::Renderer renderer = window.createRenderer(-1, SDL_RENDERER_ACCELERATED);
	//Initialize renderer color
	renderer.setDrawColor(0xFF, 0xFF, 0xFF, 0xFF);

	SDL2pp::Img::Image modulated_sur("12_color_modulation/colors.png");
    modulated_sur.setColorKey(true, modulated_sur.mapRGB(0x00, 0xFF, 0xFF));
	SDL2pp::Texture modulated_tex = renderer.createTexture(modulated_sur);


    for( uint8_t r=0; r<223; r+=32){
        for( uint8_t g=0; g<223; g+=32){
            for( uint8_t b=0; b<223; b+=32){
                //Clear screen
                renderer.setDrawColor( 0xFF, 0xFF, 0xFF, 0xFF );
                renderer.clear();

                modulated_tex.setColorMod(r, g, b);
                renderer.renderCopy(modulated_tex);

                renderer.present();
                sdl.delay(10ms);
            }
        }
    }

	return 0;
}
