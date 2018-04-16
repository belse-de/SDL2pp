//
// Created by belse on 15.03.18.
//

#ifndef SDL2PP_IMAGETEXTURE_HPP
#define SDL2PP_IMAGETEXTURE_HPP

#include <string>
#include <libSDL2pp/src/Texture.hpp>

namespace SDL2pp::Img {
    class ImageTexture : public SDL2pp::Texture {
    public:
        ImageTexture(const SDL2pp::Renderer &rendere, std::string pathIMG);
    };
};


#endif //SDL2PP_IMAGETEXTURE_HPP
