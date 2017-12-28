/*This source code copyrighted by Lazy Foo' Productions (2004-2015)
and may not be redistributed without written permission.*/

//Using SDL, standard IO, and strings
#include <SDL.h>
#include <string>
#include <SDL2pp/Surface.hpp>
#include <array>
#include <SDL2pp/Window.hpp>
#include <SDL2pp/SDL2.hpp>

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

//Key press surfaces constants
enum KeyPressSurfaces {
    KEY_PRESS_SURFACE_DEFAULT,
    KEY_PRESS_SURFACE_UP,
    KEY_PRESS_SURFACE_DOWN,
    KEY_PRESS_SURFACE_LEFT,
    KEY_PRESS_SURFACE_RIGHT,
    KEY_PRESS_SURFACE_TOTAL
};

//Starts up SDL and creates window
bool init();

//Loads media
bool loadMedia();

//Frees media and shuts down SDL
void close();

//Loads individual image
SDL_Surface *loadSurface(std::string path);

//The window we'll be rendering to
SDL_Window *gWindow = NULL;

//The surface contained by the window
SDL_Surface *gScreenSurface = NULL;

//The images that correspond to a keypress
SDL_Surface *keyPressSurfaces[KEY_PRESS_SURFACE_TOTAL];

//Current displayed image
SDL_Surface *currentKeyPress = NULL;

int main(int argc, char *args[]) {
    using namespace std::chrono_literals;
    //Start up SDL and create window
    //Initialize SDL
    SDL2pp::SDL2 sdl;
    //The window we'll be rendering to
    SDL2pp::Window window("SDL Tutorial 04", SCREEN_WIDTH, SCREEN_HEIGHT);
    //The surface contained by the window
    //Get window surface
    SDL2pp::Surface screen = window.getSurface();

    std::array<SDL2pp::Surface *, 5> keyPressSurfaces = {
        new SDL2pp::Surface("04_key_presses/press.bmp"),
        new SDL2pp::Surface("04_key_presses/up.bmp"),
        new SDL2pp::Surface("04_key_presses/down.bmp"),
        new SDL2pp::Surface("04_key_presses/left.bmp"),
        new SDL2pp::Surface("04_key_presses/right.bmp"),

    };
    SDL2pp::Surface *currentKeyPress;

    //Main loop flag
    bool quit = false;

    //Event handler
    SDL_Event e;

    //Set default current surface
    currentKeyPress = keyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT];

    //While application is running
    while (!quit) {
        //Handle events on queue
        while (SDL_PollEvent(&e) != 0) {
            //User requests quit
            if (e.type == SDL_QUIT) {
                quit = true;
            }
                //User presses a key
            else if (e.type == SDL_KEYDOWN) {
                //Select surfaces based on key press
                switch (e.key.keysym.sym) {
                    case SDLK_UP:
                        currentKeyPress = keyPressSurfaces[KEY_PRESS_SURFACE_UP];
                        break;

                    case SDLK_DOWN:
                        currentKeyPress = keyPressSurfaces[KEY_PRESS_SURFACE_DOWN];
                        break;

                    case SDLK_LEFT:
                        currentKeyPress = keyPressSurfaces[KEY_PRESS_SURFACE_LEFT];
                        break;

                    case SDLK_RIGHT:
                        currentKeyPress = keyPressSurfaces[KEY_PRESS_SURFACE_RIGHT];
                        break;

                    default:
                        currentKeyPress = keyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT];
                        break;
                }
            }
        }

        //Apply the current image
        currentKeyPress->blitOnto(screen);

        //Update the surface
        window.updateSurface();

        sdl.delay(50ms);
    }

    //Free resources and close SDL
    for (auto s : keyPressSurfaces) {
        delete s;
    }

    return 0;
}
