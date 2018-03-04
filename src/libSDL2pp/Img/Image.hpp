//
// Created by belse on 14.12.17.
//

#ifndef SDL2PP_IMAGE_HPP
#define SDL2PP_IMAGE_HPP

#include "libSDL2pp/Surface.hpp"

namespace SDL2pp::Img {
    class Image : public SDL2pp::Surface {
    public:
        Image(std::string pathIMG);
    };
};


#endif //SDL2PP_IMAGE_HPP
