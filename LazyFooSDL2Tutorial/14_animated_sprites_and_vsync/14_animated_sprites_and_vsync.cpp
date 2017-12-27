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
	SDL2pp::Window window("SDL Tutorial 14", SCREEN_WIDTH, SCREEN_HEIGHT);
	//The surface contained by the window
	//Get window surface
	SDL2pp::Surface screen = window.getSurface();
	SDL2pp::Renderer renderer = window.createRenderer(-1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	//Initialize renderer color
	renderer.setDrawColor(0xFF, 0xFF, 0xFF, 0xFF);


	SDL2pp::Img::Image sprite_sur("14_animated_sprites_and_vsync/foo.png");
	sprite_sur.setColorKey(true, sprite_sur.mapRGB(0x00, 0xFF, 0xFF));
	SDL2pp::Texture sprite_tex = renderer.createTexture(sprite_sur);

	//Walking animation
	const int WALKING_ANIMATION_FRAMES = 4;
	SDL_Rect spriteClips[ WALKING_ANIMATION_FRAMES ];
	//Set sprite clips
	spriteClips[ 0 ].x =   0;
	spriteClips[ 0 ].y =   0;
	spriteClips[ 0 ].w =  64;
	spriteClips[ 0 ].h = 205;

	spriteClips[ 1 ].x =  64;
	spriteClips[ 1 ].y =   0;
	spriteClips[ 1 ].w =  64;
	spriteClips[ 1 ].h = 205;

	spriteClips[ 2 ].x = 128;
	spriteClips[ 2 ].y =   0;
	spriteClips[ 2 ].w =  64;
	spriteClips[ 2 ].h = 205;

	spriteClips[ 3 ].x = 196;
	spriteClips[ 3 ].y =   0;
	spriteClips[ 3 ].w =  64;
	spriteClips[ 3 ].h = 205;


	for(int frame = 0; frame < WALKING_ANIMATION_FRAMES * 12; frame++){
		//Clear screen
		renderer.setDrawColor(0xFF, 0xFF, 0xFF, 0xFF);
		renderer.clear();

		//Render current frame
		SDL_Rect* currentClip = &spriteClips[ frame % WALKING_ANIMATION_FRAMES ];
		SDL_Rect  position = {SCREEN_WIDTH - (currentClip->w / 4) * frame, (SCREEN_HEIGHT - currentClip->h) / 2, 64, 205};
        renderer.copy(sprite_tex, currentClip, &position);

		//Update screen
		renderer.present();
		sdl.delay(100ms);
	}

	return 0;
}
