/*This source code copyrighted by Lazy Foo' Productions (2004-2015)
and may not be redistributed without written permission.*/

//Using SDL, SDL_image, SDL_ttf, standard IO, strings, and string streams
#include <SDL.h>
#include <string>
#include <sstream>
#include <chrono>
#include <iostream>
#include <SDL2pp/SDL2.hpp>
#include <SDL2pp/Img/SDL2Image.hpp>
#include <SDL2pp/TTF/SDL2TTF.hpp>
#include <SDL2pp/Window.hpp>
#include <SDL2pp/TTF/Font.hpp>

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

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
    SDL2pp::Window window("SDL Tutorial 18", SCREEN_WIDTH, SCREEN_HEIGHT);
    //The surface contained by the window
    //Get window surface
    SDL2pp::Surface screen = window.getSurface();
    SDL2pp::Renderer renderer = window.createRenderer(-1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    //Initialize renderer color
    renderer.setDrawColor(0xFF, 0xFF, 0xFF, 0xFF);

    SDL2pp::TTF::Font font("22_timing/lazy.ttf", 28);
    //Render text
    //Set text color as black
    SDL_Color textColor = {0, 0, 0, 0xFF};
    SDL2pp::Surface text_sur = font.renderSolid_UTF8(u8"\"Press Enter to Reset Start Time.\"", textColor);
    SDL2pp::Texture text_tex = renderer.createTexture(text_sur);
    SDL_Rect text_pos = {
        (SCREEN_WIDTH - text_sur.getWidth()) / 2,
        0,
        text_sur.getWidth(),
        text_sur.getHeight()
    };

    //Main loop flag
    bool quit = false;

    //Event handler
    SDL_Event e;



    //Current time start time
    std::chrono::milliseconds startTime(0);

    //In memory text stream
    std::stringstream timeText;

    //While application is running
    while (!quit) {
        //Handle events on queue
        while (SDL_PollEvent(&e) != 0) {
            //User requests quit
            if (e.type == SDL_QUIT) {
                quit = true;
            }
                //Reset start time on return keypress
            else if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_RETURN) {
                startTime = sdl.getTicks();
            }
        }

        //Set text to be rendered
        timeText.str(u8"");
        std::chrono::milliseconds deltaTime = sdl.getTicks() - startTime;
        timeText << "Milliseconds since start time " << deltaTime.count();

        //Render text
        SDL2pp::Surface time_sur = font.renderSolid_UTF8(timeText.str(), textColor);
        SDL2pp::Texture time_tex = renderer.createTexture(time_sur);
        SDL_Rect time_pos = {
            (SCREEN_WIDTH - time_sur.getWidth()) / 2,
            (SCREEN_HEIGHT - time_sur.getHeight()) / 2,
            time_sur.getWidth(),
            time_sur.getHeight()
        };

        //Clear screen
        renderer.setDrawColor(0xFF, 0xFF, 0xFF, 0xFF);
        renderer.clear();

        //Render textures
        renderer.copy(text_tex, nullptr, &text_pos);
        renderer.copy(time_tex, nullptr, &time_pos);

        //Update screen
        renderer.present();
    }

    return 0;
}
