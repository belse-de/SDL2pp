/*This source code copyrighted by Lazy Foo' Productions (2004-2015)
and may not be redistributed without written permission.*/

//Using SDL, SDL_image, standard math, and strings
#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include <chrono>
#include <SDL2pp/SDL2.hpp>
#include <SDL2pp/Img/SDL2Image.hpp>
#include <iostream>
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

    if (not sdl.setHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
        std::clog << "Warning: Linear texture filtering not enabled!" << std::endl;
    //The window we'll be rendering to
    SDL2pp::Window window("SDL Tutorial 11", SCREEN_WIDTH, SCREEN_HEIGHT);
    //The surface contained by the window
    //Get window surface
    SDL2pp::Surface screen = window.getSurface();
    SDL2pp::Renderer renderer = window.createRenderer(-1, SDL_RENDERER_ACCELERATED);
    //Initialize renderer color
    renderer.setDrawColor(0xFF, 0xFF, 0xFF, 0xFF);

    SDL2pp::Img::Image spriteSheet_sur("11_clip_rendering_and_sprite_sheets/dots.png");
    spriteSheet_sur.setColorKey(true, spriteSheet_sur.mapRGB(0x00, 0xFF, 0xFF));
    SDL2pp::Texture spriteSheet_tex = renderer.createTexture(spriteSheet_sur);

    //Scene sprites
    SDL_Rect spriteClips[4];
    //Set top left sprite
    spriteClips[0].x = 0;
    spriteClips[0].y = 0;
    spriteClips[0].w = 100;
    spriteClips[0].h = 100;

    //Set top right sprite
    spriteClips[1].x = 100;
    spriteClips[1].y = 0;
    spriteClips[1].w = 100;
    spriteClips[1].h = 100;

    //Set bottom left sprite
    spriteClips[2].x = 0;
    spriteClips[2].y = 100;
    spriteClips[2].w = 100;
    spriteClips[2].h = 100;

    //Set bottom right sprite
    spriteClips[3].x = 100;
    spriteClips[3].y = 100;
    spriteClips[3].w = 100;
    spriteClips[3].h = 100;

    //Clear screen
    renderer.setDrawColor(0xFF, 0xFF, 0xFF, 0xFF);
    renderer.clear();

    //Render top left sprite
    SDL_Rect target_tl = {0, 0, 100, 100};
    renderer.copy(spriteSheet_tex, &spriteClips[0], &target_tl);

    //Render top right sprite
    SDL_Rect target_tr = {SCREEN_WIDTH - spriteClips[1].w, 0, 100, 100};
    renderer.copy(spriteSheet_tex, &spriteClips[1], &target_tr);

    //Render bottom left sprite
    SDL_Rect target_bl = {0, SCREEN_HEIGHT - spriteClips[2].h, 100, 100};
    renderer.copy(spriteSheet_tex, &spriteClips[2], &target_bl);

    //Render bottom right sprite
    SDL_Rect target_br = {SCREEN_WIDTH - spriteClips[3].w, SCREEN_HEIGHT - spriteClips[3].h, 100, 100};
    renderer.copy(spriteSheet_tex, &spriteClips[3], &target_br);


    //Update screen
    renderer.present();

    sdl.delay(100ms);

    return 0;
}
