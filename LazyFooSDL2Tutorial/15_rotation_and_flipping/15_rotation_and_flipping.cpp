/*This source code copyrighted by Lazy Foo' Productions (2004-2015)
and may not be redistributed without written permission.*/

//Using SDL, SDL_image, standard IO, math, and strings
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include <cmath>
#include <chrono>
#include <SDL2.hpp>
#include <SDL2Image.hpp>
#include <Window.hpp>
#include <Image.hpp>
#include <iostream>

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
	SDL2pp::Window window("SDL Tutorial 15", SCREEN_WIDTH, SCREEN_HEIGHT);
	//The surface contained by the window
	//Get window surface
	SDL2pp::Surface screen = window.getSurface();
	SDL2pp::Renderer renderer = window.createRenderer(-1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	//Initialize renderer color
	renderer.setDrawColor(0xFF, 0xFF, 0xFF, 0xFF);


	SDL2pp::Img::Image arrow_sur("15_rotation_and_flipping/arrow.png");
	arrow_sur.setColorKey(true, arrow_sur.mapRGB(0x00, 0xFF, 0xFF));
	SDL2pp::Texture arrow_tex = renderer.createTexture(arrow_sur);


    //Flip type
    SDL_RendererFlip flipTypes[3] = {
        SDL_FLIP_NONE,
        SDL_FLIP_HORIZONTAL,
        SDL_FLIP_VERTICAL,
    };
    SDL_Rect arrow_pos = {
        ( SCREEN_WIDTH  - arrow_sur.getWidth()  ) / 2,
        ( SCREEN_HEIGHT - arrow_sur.getHeight() ) / 2,
        arrow_sur.getWidth(),
        arrow_sur.getHeight(),
    };

    int stepSize = 5;
    for(int step=0; step<=3*360/stepSize; step++){
        renderer.setDrawColor(0xFF, 0xFF, 0xFF, 0xFF);
        renderer.clear();

        renderer.copyExtended(arrow_tex, nullptr, &arrow_pos,
                              1.*stepSize*step, nullptr,
                              flipTypes[(step/60)%3]);

        renderer.present();
        sdl.delay(10ms);
    }

	return 0;
}
