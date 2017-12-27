	/*This source code copyrighted by Lazy Foo' Productions (2004-2015)
and may not be redistributed without written permission.*/

//Using SDL, SDL_image, SDL_ttf, standard IO, math, and strings
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <stdio.h>
#include <string>
#include <cmath>
#include <chrono>
#include <SDL2.hpp>
#include <SDL2Image.hpp>
#include <iostream>
#include <Window.hpp>
#include <SDL2TTF.hpp>
#include <Font.hpp>

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
	SDL2pp::TTF::SDL2TTF ttf;

	if (not sdl.setHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
		std::clog << "Warning: Linear texture filtering not enabled!" << std::endl;
	//The window we'll be rendering to
	SDL2pp::Window window("SDL Tutorial 16", SCREEN_WIDTH, SCREEN_HEIGHT);
	//The surface contained by the window
	//Get window surface
	SDL2pp::Surface screen = window.getSurface();
	SDL2pp::Renderer renderer = window.createRenderer(-1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	//Initialize renderer color
	renderer.setDrawColor(0xFF, 0xFF, 0xFF, 0xFF);


	SDL2pp::TTF::Font font( "16_true_type_fonts/lazy.ttf", 28 );
	//Render text
	SDL_Color textColor = { 0, 0, 0 };
	SDL2pp::Surface text_sur = font.renderSolid_UTF8(u8"The quick brown fox jumps over the lazy dog", textColor);
	SDL2pp::Texture text_tex = renderer.createTexture(text_sur);

	//Clear screen
	renderer.setDrawColor(0xFF, 0xFF, 0xFF, 0xFF);
	renderer.clear();

	SDL_Rect text_pos = {
		( SCREEN_WIDTH - text_sur.getWidth() ) / 2,
		( SCREEN_HEIGHT - text_sur.getHeight() ) / 2,
		text_sur.getWidth(),
        text_sur.getHeight()};

	//Render current frame
	renderer.copy(text_tex, nullptr, &text_pos);

	//Update screen
	renderer.present();
	sdl.delay(100ms);

	return 0;
}
