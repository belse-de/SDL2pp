//
// Created by belse on 27.12.17.
//

#include <SDL2pp/TTF/Error.hpp>
#include "SDL2pp/Surface.hpp"
#include "SDL2pp/TTF/Font.hpp"


using namespace SDL2pp::TTF;

Font::~Font() {
    if (font_ != nullptr) {
        //Free font
        TTF_CloseFont(font_);
        font_ = nullptr;
    }
}

Font::Font(std::string path, int pointSize) {
    // load font
    TTF_Font *font;
    font = TTF_OpenFont(path.c_str(), pointSize);
    // handle error
    if (font == nullptr) throw Error("Could not load font " + path + "!");
    font_ = font;
}

SDL2pp::Surface Font::renderSolid_Latin1(const std::string &text, SDL_Color color) {
    // Render the text in solid to a new surface
    SDL_Surface *text_surface;
    text_surface = TTF_RenderText_Solid(font_, text.c_str(), color);
    if (text_surface == nullptr) throw Error("Font could not render text!");
    return SDL2pp::Surface(text_surface, true);
}

SDL2pp::Surface Font::renderSolid_UTF8(const std::string &text, SDL_Color color) {
    // Render the text in solid to a new surface
    SDL_Surface *text_surface;
    text_surface = TTF_RenderUTF8_Solid(font_, text.c_str(), color);
    if (text_surface == nullptr) throw Error("Font could not render text!");
    return SDL2pp::Surface(text_surface, true);
}
