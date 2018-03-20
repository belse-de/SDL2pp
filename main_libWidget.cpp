//
// Created by belse on 15.03.18.
//

#include <iostream>
#include <variant>
#include <vector>

#include <libSDL2pp/SDL2.hpp>
#include <libSDL2pp/Window.hpp>
#include <libSDL2pp/Renderer.hpp>
#include <libSDL2pp/Surface.hpp>
#include <libSDL2pp/Texture.hpp>

#include <libSDL2pp/Img/SDL2Image.hpp>
#include <libSDL2pp/Img/ImageSurface.hpp>
#include <libSDL2pp/Img/ImageTexture.hpp>

#include <libSDL2pp/TTF/SDL2TTF.hpp>
#include <libSDL2pp/TTF/Font.hpp>

#include <libWidget/Widget.hpp>
#include <libWidget/Window.hpp>
#include <libWidget/Image.hpp>
#include <libWidget/Button.hpp>

#include "extern/overloaded.hpp"


using namespace std::chrono_literals;
using namespace SDL2pp;

using Widget_t = std::variant<Widget::Window>;

int main(int argc, char* argv[]) {
    std::cout << "Hallo World!" << std::endl;

    //Screen dimension constants
    const int SCREEN_WIDTH = 640;
    const int SCREEN_HEIGHT = 480;
    const auto reactionDelay = 50ms;
    const int textfont_size = 15;
    const int buttonfont_size = 12;

    SDL2 sdl;
    Img::SDL2Image img;
    TTF::SDL2TTF ttf;

    std::vector<Widget_t> widgets;
    std::vector<TTF::Font> fonts;
    std::vector<Img::ImageTexture> images;

    SDL_Rect displayBounds = sdl.getDisplayBounds(0);
    if(SCREEN_WIDTH > displayBounds.w or SCREEN_HEIGHT > displayBounds.h){
        std::cerr << "Programm needs bigger screen to run. At least: " << SCREEN_WIDTH << "x" << SCREEN_HEIGHT << std::endl;
        return EXIT_FAILURE;
    }

    //The window we'll be rendering to
    int winPosX = displayBounds.w / 2 - SCREEN_WIDTH / 2;
    int winPosY = displayBounds.h / 2 - SCREEN_HEIGHT / 2;
    Window window( "SDL Widgets", winPosX, winPosY, SCREEN_WIDTH, SCREEN_HEIGHT);
    //Create renderer for window
    SDL2pp::Renderer renderer = window.createRenderer(-1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    //Initialize renderer color
    renderer.setDrawColor(0xFF, 0xFF, 0xFF, 0xFF);
    //Clear screen
    renderer.clear();
    //Update screen
    renderer.present();
    //Wait
    sdl.delay( reactionDelay );


    //widgets.push_back(std::move(Widget::Window(window)));

    fonts.push_back(std::move(TTF::Font("kiss_font.ttf", textfont_size)));
    fonts.push_back(std::move(TTF::Font("kiss_font.ttf", buttonfont_size)));

    images.push_back(std::move(Img::ImageTexture(renderer, "kiss_normal.png")));
    images.push_back(std::move(Img::ImageTexture(renderer, "kiss_prelight.png")));
    images.push_back(std::move(Img::ImageTexture(renderer, "kiss_active.png")));
    images.push_back(std::move(Img::ImageTexture(renderer, "kiss_bar.png")));
    images.push_back(std::move(Img::ImageTexture(renderer, "kiss_vslider.png")));
    images.push_back(std::move(Img::ImageTexture(renderer, "kiss_hslider.png")));
    images.push_back(std::move(Img::ImageTexture(renderer, "kiss_up.png")));
    images.push_back(std::move(Img::ImageTexture(renderer, "kiss_down.png")));
    images.push_back(std::move(Img::ImageTexture(renderer, "kiss_left.png")));
    images.push_back(std::move(Img::ImageTexture(renderer, "kiss_right.png")));
    images.push_back(std::move(Img::ImageTexture(renderer, "kiss_combo.png")));
    images.push_back(std::move(Img::ImageTexture(renderer, "kiss_selected.png")));
    images.push_back(std::move(Img::ImageTexture(renderer, "kiss_unselected.png")));


    Widget::Window win_w(window);
    Widget::Image img_w(images[0], SDL_Rect{0,0,62,22});
    img_w.setHitBox(SDL_Rect{10,10,62,22});
    Widget::Button but_w(images[0], images[1], images[2], SDL_Rect{0,0,62,22});
    but_w.setHitBox(SDL_Rect{10,10+22+3,62,22});

    win_w.render(renderer);
    img_w.render(renderer);
    renderer.present();

    SDL_Event event;
    bool running = true;
    while(running){
        while(SDL_PollEvent(&event)){
            if (event.type == SDL_QUIT) {
                running = false;
            }

            img_w.handleEvent(&event);
            but_w.handleEvent(&event);
        }

        img_w.render(renderer);
        but_w.render(renderer);
        renderer.present();

        //Wait
        sdl.delay( reactionDelay );
    }

    sdl.delay(500ms);
}
