//
// Created by belse on 27.12.17.
//

#include <libSDL2pp/TTF/Error.hpp>
#include <iostream>
#include "libSDL2pp/src/Surface.hpp"
#include "libSDL2pp/TTF/Font.hpp"


using namespace SDL2pp::TTF;

Font::~Font() {
    /*
     if (font_ != nullptr) {
        //Free font
        TTF_CloseFont(font_);
        font_ = nullptr;
    }*/
}

Font::Font(std::string path, int pointSize) {
    font_ =
        std::shared_ptr<TTF_Font>(
            TTF_OpenFont(path.c_str(), pointSize),
            [](TTF_Font* f){
                if(not(f == nullptr)){
                    TTF_CloseFont(f);
                }
            }
        );
    if (not font_) throw Error("Could not load font " + path + "!");
}

/*
Font::Font(Font &&other) {
    font_ = other.font_;
    if (font_ == nullptr) throw Error("Could not move font!");
    std::cerr << "MOVE: " << font_.get() << std::endl;
}*/

SDL2pp::Surface Font::renderSolid_Latin1(const std::string &text, SDL_Color color) {
    // Render the text in solid to a new surface
    SDL_Surface *text_surface;
    text_surface = TTF_RenderText_Solid(font_.get(), text.c_str(), color);
    if (text_surface == nullptr) throw Error("Font could not render text!");
    return SDL2pp::Surface(text_surface, true);
}

SDL2pp::Surface Font::renderSolid_UTF8(const std::string &text, SDL_Color color) {
    // Render the text in solid to a new surface
    SDL_Surface *text_surface;
    text_surface = TTF_RenderUTF8_Solid(font_.get(), text.c_str(), color);
    if (text_surface == nullptr) throw Error("Font could not render text!");
    return SDL2pp::Surface(text_surface, true);
}
