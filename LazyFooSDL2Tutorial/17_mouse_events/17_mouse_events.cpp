/*This source code copyrighted by Lazy Foo' Productions (2004-2015)
and may not be redistributed without written permission.*/

//Using SDL, SDL_image, standard IO, and strings
#include <SDL.h>
#include <string>
#include <chrono>
#include <SDL2pp/SDL2.hpp>
#include <SDL2pp/Img/SDL2Image.hpp>
#include <SDL2pp/TTF/SDL2TTF.hpp>
#include <iostream>
#include <SDL2pp/Window.hpp>
#include <SDL2pp/Img/Image.hpp>

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

//Button constants
const int BUTTON_WIDTH = 300;
const int BUTTON_HEIGHT = 200;
const int TOTAL_BUTTONS = 4;

enum class ButtonSprite {
    BUTTON_SPRITE_MOUSE_OUT = 0,
    BUTTON_SPRITE_MOUSE_OVER_MOTION = 1,
    BUTTON_SPRITE_MOUSE_DOWN = 2,
    BUTTON_SPRITE_MOUSE_UP = 3,
    BUTTON_SPRITE_TOTAL = 4
};


int main(int argc, char *args[]) {
    using namespace std::chrono_literals;
    //Start up SDL and create window
    //Initialize SDL
    SDL2pp::SDL2 sdl;
    SDL2pp::Img::SDL2Image img;
    SDL2pp::TTF::SDL2TTF ttf;

    if (not sdl.setHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
        std::clog << "Warning: Linear texture filtering not enabled!" << std::endl;
    //The window we'll be rendering to
    SDL2pp::Window window("SDL Tutorial 17", SCREEN_WIDTH, SCREEN_HEIGHT);
    //The surface contained by the window
    //Get window surface
    SDL2pp::Surface screen = window.getSurface();
    SDL2pp::Renderer renderer = window.createRenderer(-1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    //Initialize renderer color
    renderer.setDrawColor(0xFF, 0xFF, 0xFF, 0xFF);


    SDL2pp::Img::Image button_sur("17_mouse_events/button.png");
    button_sur.setColorKey(true, button_sur.mapRGB(0x00, 0xFF, 0xFF));
    SDL2pp::Texture button_tex = renderer.createTexture(button_sur);

    //Set sprites
    SDL_Rect spriteClips[static_cast<int>(ButtonSprite::BUTTON_SPRITE_TOTAL)];
    for (int i = 0; i < static_cast<int>(ButtonSprite::BUTTON_SPRITE_TOTAL); ++i) {
        spriteClips[i].x = 0;
        spriteClips[i].y = i * 200;
        spriteClips[i].w = BUTTON_WIDTH;
        spriteClips[i].h = BUTTON_HEIGHT;
    }

    //Set buttons in corners
    SDL_Rect button_pos[TOTAL_BUTTONS];
    for (int i = 0; i < TOTAL_BUTTONS; ++i) {
        int X = i % 2;
        int Y = i / 2;

        button_pos[i].x = X * (SCREEN_WIDTH - BUTTON_WIDTH);
        button_pos[i].y = Y * (SCREEN_HEIGHT - BUTTON_HEIGHT);
        button_pos[i].w = BUTTON_WIDTH;
        button_pos[i].h = BUTTON_HEIGHT;

    }
    ButtonSprite button_state[TOTAL_BUTTONS];
    for (int i = 0; i < TOTAL_BUTTONS; ++i) {
        button_state[i] = ButtonSprite::BUTTON_SPRITE_MOUSE_OUT;
    }


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
                //If mouse event happened
            else if (e.type == SDL_MOUSEMOTION || e.type == SDL_MOUSEBUTTONDOWN || e.type == SDL_MOUSEBUTTONUP) {
                //Get mouse position
                int x, y;
                SDL_GetMouseState(&x, &y);

                //Handle button events
                //Check if mouse is in button
                for (int i = 0; i < TOTAL_BUTTONS; ++i) {
                    if (x >= button_pos[i].x
                        and y >= button_pos[i].y
                        and x <= (button_pos[i].x + button_pos[i].w)
                        and y <= (button_pos[i].y + button_pos[i].h)) {
                        //Mouse is inside button
                        if (e.type == SDL_MOUSEMOTION) {
                            button_state[i] = ButtonSprite::BUTTON_SPRITE_MOUSE_OVER_MOTION;
                        } else if (e.type == SDL_MOUSEBUTTONDOWN) {
                            button_state[i] = ButtonSprite::BUTTON_SPRITE_MOUSE_DOWN;
                        } else if (e.type == SDL_MOUSEBUTTONUP) {
                            button_state[i] = ButtonSprite::BUTTON_SPRITE_MOUSE_UP;
                        } else {
                            button_state[i] = ButtonSprite::BUTTON_SPRITE_MOUSE_OUT;
                        }
                    } else {
                        //Mouse is outside button
                        button_state[i] = ButtonSprite::BUTTON_SPRITE_MOUSE_OUT;
                    }
                }
                std::clog << std::flush;
            }
        }

        //Clear screen
        renderer.setDrawColor(0xFF, 0xFF, 0xFF, 0xFF);
        renderer.clear();

        //Render buttons
        for (int i = 0; i < TOTAL_BUTTONS; ++i) {
            renderer.copy(button_tex,
                          &spriteClips[static_cast<int>(button_state[i])],
                          &button_pos[i]);
        }

        //Update screen
        renderer.present();
        sdl.delay(1ms);
    }
    
    return 0;
}
