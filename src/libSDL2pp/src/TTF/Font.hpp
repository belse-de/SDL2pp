//
// Created by belse on 27.12.17.
//

// further reading:
// http://utfcpp.sourceforge.net/
// http://utf8everywhere.org/
// http://en.cppreference.com/w/cpp/language/string_literal

#ifndef SDL2PP_FONT_HPP
#define SDL2PP_FONT_HPP

#include <string>
#include <SDL_ttf.h>
#include <memory>

namespace SDL2pp {
    class Surface;
}

namespace SDL2pp::TTF {
    class Font {
    public:
        Font(std::string path, int pointSize);
        //Font(Font&& other);
        virtual ~Font();

        SDL2pp::Surface renderSolid_Latin1(const std::string& text, SDL_Color color);
        SDL2pp::Surface renderSolid_UTF8(  const std::string& text, SDL_Color color);

    private:
        std::shared_ptr<TTF_Font> font_;
            //TTF_Font* font_ = nullptr;
    };
}

#endif //SDL2PP_FONT_HPP
