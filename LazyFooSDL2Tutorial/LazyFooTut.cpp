//
// Created by belse on 02.01.18.
//

#include <iostream>
#include <chrono>
#include <SDL2pp/Img/Image.hpp>

#include "SDL2pp/SDL2.hpp"
#include "SDL2pp/Window.hpp"
#include "SDL2pp/Surface.hpp"
#include "SDL2pp/Renderer.hpp"
#include "SDL2pp/Texture.hpp"

using namespace std::chrono_literals;
using namespace std;
using namespace SDL2pp;

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

const auto stepDelay = 350ms;

int main(int argc, char* argv[]){
    SDL2 sdl;

    //The window we'll be rendering to
    Window window( "SDL Tutorials 01-", SCREEN_WIDTH, SCREEN_HEIGHT);

    //01
    //The surface contained by the window
    //Get window surface
    Surface screen = window.getSurface();
    //Fill the surface white
    screen.fillRect( screen.mapRGB( 0xFF, 0xFF, 0xFF) );
    //Update the surface
    window.updateSurface();
    //Wait
    sdl.delay( stepDelay );

    //02
    //Loads media
    //Load splash image
    SDL2pp::Surface halloWorld( "02_getting_an_image_on_the_screen/hello_world.bmp" );
    //Apply the image
    halloWorld.blitOnto(screen);
    //Update the surface
    window.updateSurface();
    //Wait
    sdl.delay( stepDelay );

    // 03, 04 event driven programming

    //05
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
    //Wait
    sdl.delay( stepDelay );

    //06
    //Load PNG image
    SDL2pp::Img::Image PNGSurfaceRaw("06_extension_libraries_and_loading_other_image_formats/loaded.png");
    SDL2pp::Surface PNGSurface = PNGSurfaceRaw.convertTo(screen.getFormat());
    //Apply the PNG image
    PNGSurface.blitOnto(screen);
    //Update the surface
    window.updateSurface();
    //Wait
    sdl.delay( stepDelay );

    //07
    //Create renderer for window
    SDL2pp::Renderer renderer = window.createRenderer(-1, SDL_RENDERER_ACCELERATED);
    //Load PNG image as texture
    SDL2pp::Img::Image texture_surface("07_texture_loading_and_rendering/texture.png");
    SDL2pp::Texture texture = renderer.createTexture(texture_surface);
    //Initialize renderer color
    renderer.setDrawColor(0xFF, 0xFF, 0xFF, 0xFF);
    //Clear screen
    renderer.clear();
    //Render texture to screen
    renderer.copy(texture, nullptr, nullptr);
    //Update screen
    renderer.present();
    //Wait
    sdl.delay( stepDelay );

    //08
    //Clear screen
    renderer.setDrawColor(0xFF, 0xFF, 0xFF, 0xFF);
    renderer.clear();
    //Render red filled quad
    SDL_Rect fillRect = {SCREEN_WIDTH / 4, SCREEN_HEIGHT / 4, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2};
    renderer.setDrawColor(0xFF, 0x00, 0x00, 0xFF);
    renderer.fillRect(&fillRect);
    //Render green outlined quad
    SDL_Rect outlineRect = {SCREEN_WIDTH / 6, SCREEN_HEIGHT / 6, SCREEN_WIDTH * 2 / 3, SCREEN_HEIGHT * 2 / 3};
    renderer.setDrawColor(0x00, 0xFF, 0x00, 0xFF);
    renderer.drawRect(&outlineRect);
    //Draw blue horizontal line
    renderer.setDrawColor(0x00, 0x00, 0xFF, 0xFF);
    renderer.drawLine(0, SCREEN_HEIGHT / 2, SCREEN_WIDTH, SCREEN_HEIGHT / 2);
    //Draw vertical line of yellow dots
    renderer.setDrawColor(0xFF, 0xFF, 0x00, 0xFF);
    for (int i = 0; i < SCREEN_HEIGHT; i += 4) {
        renderer.drawPoint(SCREEN_WIDTH / 2, i);
    }
    //Update screen
    renderer.present();
    //Wait
    sdl.delay( stepDelay );

    //09
    //Load viewport PNG image
    SDL2pp::Img::Image viewport_surface("09_the_viewport/viewport.png");
    SDL2pp::Texture viewport = renderer.createTexture(viewport_surface);
    //Clear screen
    renderer.setDrawColor(0xFF, 0xFF, 0xFF, 0xFF);
    renderer.clear();
    //Top left corner viewport
    SDL_Rect topLeftViewport;
    topLeftViewport.x = 0;
    topLeftViewport.y = 0;
    topLeftViewport.w = SCREEN_WIDTH / 2;
    topLeftViewport.h = SCREEN_HEIGHT / 2;
    renderer.setViewport(&topLeftViewport);
    //Render texture to screen
    renderer.copy(viewport);
    //Top right viewport
    SDL_Rect topRightViewport;
    topRightViewport.x = SCREEN_WIDTH / 2;
    topRightViewport.y = 0;
    topRightViewport.w = SCREEN_WIDTH / 2;
    topRightViewport.h = SCREEN_HEIGHT / 2;
    renderer.setViewport(&topRightViewport);
    //Render texture to screen
    renderer.copy(viewport);
    //Bottom viewport
    SDL_Rect bottomViewport;
    bottomViewport.x = 0;
    bottomViewport.y = SCREEN_HEIGHT / 2;
    bottomViewport.w = SCREEN_WIDTH;
    bottomViewport.h = SCREEN_HEIGHT / 2;
    renderer.setViewport(&bottomViewport);
    //Render texture to screen
    renderer.copy(viewport);
    //Update screen
    renderer.present();
    //Reset viewport
    SDL_Rect normalViewport;
    normalViewport.x = 0;
    normalViewport.y = 0;
    normalViewport.w = SCREEN_WIDTH;
    normalViewport.h = SCREEN_HEIGHT;
    renderer.setViewport(&normalViewport);
    //Wait
    sdl.delay( stepDelay );

    //10
    SDL2pp::Img::Image background_sur("10_color_keying/background.png");
    background_sur.setColorKey(true, background_sur.mapRGB(0x00, 0xFF, 0xFF));
    SDL_Rect background_quad = {0, 0, background_sur.getWidth(), background_sur.getHeight()};
    SDL2pp::Texture background_texture = renderer.createTexture(background_sur);
    SDL2pp::Img::Image foo_sur("10_color_keying/foo.png");
    foo_sur.setColorKey(true, foo_sur.mapRGB(0x00, 0xFF, 0xFF));
    SDL_Rect foo_quad = {0, 0, foo_sur.getWidth(), foo_sur.getHeight()};
    SDL2pp::Texture foo_texture = renderer.createTexture(foo_sur);
    //Clear screen
    renderer.setDrawColor(0xFF, 0xFF, 0xFF, 0xFF);
    renderer.clear();
    //Render background texture to screen
    background_quad.x = 0;
    background_quad.y = 0;
    renderer.copy(background_texture, nullptr, &background_quad);
    //Render Foo' to the screen
    foo_quad.x = 240;
    foo_quad.y = 190;
    renderer.copy(foo_texture, nullptr, &foo_quad);
    //Update screen
    renderer.present();
    //Wait
    sdl.delay( stepDelay );

    //11
    //Load sprite sheet PNG image
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
    //Wait
    sdl.delay( stepDelay );

    //12
    //Load colorful PNG image
    SDL2pp::Img::Image modulated_sur("12_color_modulation/colors.png");
    modulated_sur.setColorKey(true, modulated_sur.mapRGB(0x00, 0xFF, 0xFF));
    SDL2pp::Texture modulated_tex = renderer.createTexture(modulated_sur);

    //Iterate over all colors in a step size of 32
    for( uint8_t r=0; r<223; r+=32){
        for( uint8_t g=0; g<223; g+=32){
            for( uint8_t b=0; b<223; b+=32){
                //Clear screen
                renderer.setDrawColor( 0xFF, 0xFF, 0xFF, 0xFF );
                renderer.clear();

                modulated_tex.setColorMod(r, g, b);
                renderer.copy(modulated_tex);

                renderer.present();
                sdl.delay(5ms);
            }
        }
    }
    //Wait
    sdl.delay( stepDelay );

    //13
    SDL2pp::Img::Image fadeout_sur("13_alpha_blending/fadeout.png");
    fadeout_sur.setColorKey(true, fadeout_sur.mapRGB(0x00, 0xFF, 0xFF));
    SDL2pp::Texture fadeout_tex = renderer.createTexture(fadeout_sur);

    SDL2pp::Img::Image fadein_sur("13_alpha_blending/fadein.png");
    fadein_sur.setColorKey(true, fadein_sur.mapRGB(0x00, 0xFF, 0xFF));
    SDL2pp::Texture fadein_tex = renderer.createTexture(fadein_sur);
    //Fade out
    for (uint8_t a = 0xff; a >= 0x10; a -= 0x10) {
        //Clear screen
        renderer.setDrawColor(0xFF, 0xFF, 0xFF, 0xFF);
        renderer.clear();

        //Render background
        renderer.copy(fadein_tex);

        //Render front blended
        fadeout_tex.setAlphaMod(a);
        renderer.copy(fadeout_tex);

        renderer.present();
        sdl.delay(50ms);
    }
    //Fade in
    for (uint8_t a = 0x00; a < 0xf0; a += 0x10) {
        //Clear screen
        renderer.setDrawColor(0xFF, 0xFF, 0xFF, 0xFF);
        renderer.clear();

        //Render background
        renderer.copy(fadein_tex);

        //Render front blended
        fadeout_tex.setAlphaMod(a);
        renderer.copy(fadeout_tex);

        renderer.present();
        sdl.delay(50ms);
    }
    //Wait
    sdl.delay( stepDelay );

    sdl.delay(500ms);

    //TODO: 03, 04 event driven programming

    exit(EXIT_SUCCESS);
}
