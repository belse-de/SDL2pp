//
// Created by belse on 02.01.18.
//

#include <iostream>
#include <chrono>
#include <SDL2pp/Img/Image.hpp>
#include <SDL2pp/TTF/Font.hpp>
#include <SDL2pp/Img/SDL2Image.hpp>
#include <SDL2pp/TTF/SDL2TTF.hpp>

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

const auto stepDelay = 250ms;

int main(int argc, char* argv[]){
    SDL2 sdl;
    SDL2pp::Img::SDL2Image img;
    SDL2pp::TTF::SDL2TTF ttf;

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
    SDL2pp::Surface halloWorld( "res/LazyFooTut/hello_world.bmp" );
    //Apply the image
    halloWorld.blitOnto(screen);
    //Update the surface
    window.updateSurface();
    //Wait
    sdl.delay( stepDelay );

    // 03, 04 event driven programming

    //05
    //Load stretching surface
    SDL2pp::Surface stretchedSurface( "res/LazyFooTut/stretch.bmp" );
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
    SDL2pp::Img::Image PNGSurfaceRaw("res/LazyFooTut/loaded.png");
    SDL2pp::Surface PNGSurface = PNGSurfaceRaw.convertTo(screen.getFormat());
    //Apply the PNG image
    PNGSurface.blitOnto(screen);
    //Update the surface
    window.updateSurface();
    //Wait
    sdl.delay( stepDelay );

    //07
    //Create renderer for window
    SDL2pp::Renderer renderer = window.createRenderer(-1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    //Load PNG image as texture
    SDL2pp::Img::Image texture_surface("res/LazyFooTut/texture.png");
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
    SDL2pp::Img::Image viewport_surface("res/LazyFooTut/viewport.png");
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
    SDL2pp::Img::Image background_sur("res/LazyFooTut/background.png");
    background_sur.setColorKey(true, background_sur.mapRGB(0x00, 0xFF, 0xFF));
    SDL_Rect background_quad = {0, 0, background_sur.getWidth(), background_sur.getHeight()};
    SDL2pp::Texture background_texture = renderer.createTexture(background_sur);
    SDL2pp::Img::Image foo_sur("res/LazyFooTut/foo.png");
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
    SDL2pp::Img::Image spriteSheet_sur("res/LazyFooTut/dots.png");
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
    SDL2pp::Img::Image modulated_sur("res/LazyFooTut/colors.png");
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
    SDL2pp::Img::Image fadeout_sur("res/LazyFooTut/fadeout.png");
    fadeout_sur.setColorKey(true, fadeout_sur.mapRGB(0x00, 0xFF, 0xFF));
    SDL2pp::Texture fadeout_tex = renderer.createTexture(fadeout_sur);

    SDL2pp::Img::Image fadein_sur("res/LazyFooTut/fadein.png");
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

    //14
    //Load figure PNG image
    SDL2pp::Img::Image sprite_sur("res/LazyFooTut/foo_walk.png");
    sprite_sur.setColorKey(true, sprite_sur.mapRGB(0x00, 0xFF, 0xFF));
    SDL2pp::Texture sprite_tex = renderer.createTexture(sprite_sur);
    //Walking animation
    const int WALKING_ANIMATION_FRAMES = 4;
    SDL_Rect walkingSpriteClips[ WALKING_ANIMATION_FRAMES ];
    //Set sprite clips
    //Animation step 0
    walkingSpriteClips[ 0 ].x =   0;
    walkingSpriteClips[ 0 ].y =   0;
    walkingSpriteClips[ 0 ].w =  64;
    walkingSpriteClips[ 0 ].h = 205;
    //Animation step 1
    walkingSpriteClips[ 1 ].x =  64;
    walkingSpriteClips[ 1 ].y =   0;
    walkingSpriteClips[ 1 ].w =  64;
    walkingSpriteClips[ 1 ].h = 205;
    //Animation step 2
    walkingSpriteClips[ 2 ].x = 128;
    walkingSpriteClips[ 2 ].y =   0;
    walkingSpriteClips[ 2 ].w =  64;
    walkingSpriteClips[ 2 ].h = 205;
    //Animation step 3
    walkingSpriteClips[ 3 ].x = 196;
    walkingSpriteClips[ 3 ].y =   0;
    walkingSpriteClips[ 3 ].w =  64;
    walkingSpriteClips[ 3 ].h = 205;
    //Play animation
    for(int frame = 0; frame < WALKING_ANIMATION_FRAMES * 12 ; frame++){
        //Clear screen
        renderer.setDrawColor(0xFF, 0xFF, 0xFF, 0xFF);
        renderer.clear();
        //Render current frame
        SDL_Rect* currentClip = &walkingSpriteClips[ frame % WALKING_ANIMATION_FRAMES ];
        SDL_Rect  position = {SCREEN_WIDTH - (currentClip->w / 4) * frame, (SCREEN_HEIGHT - currentClip->h) / 2, 64, 205};
        renderer.copy(sprite_tex, currentClip, &position);
        //Update screen
        renderer.present();
        sdl.delay(60ms);
    }
    //Wait
    sdl.delay( stepDelay );

    //15
    //Load asymmetric arrow PNG image
    SDL2pp::Img::Image arrow_sur("res/LazyFooTut/arrow.png");
    arrow_sur.setColorKey(true, arrow_sur.mapRGB(0x00, 0xFF, 0xFF));
    SDL2pp::Texture arrow_tex = renderer.createTexture(arrow_sur);
    //Flip types
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
    //Run animation
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
    //Wait
    sdl.delay( stepDelay );

    //16
    //Load TTF fong
    SDL2pp::TTF::Font font( "res/LazyFooTut/lazy.ttf", 28 );
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
    //Wait
    sdl.delay( stepDelay );

    //17, 18, 19, 20 events for mouse and game controllers, keyboard states

    sdl.delay(500ms);

    //TODO: 03, 04 event driven programming

    exit(EXIT_SUCCESS);
}