//
// Created by belse on 14.12.17.
//

#ifndef SDL2PP_IMAGESURFACE_HPP
#define SDL2PP_IMAGESURFACE_HPP

#include <string>
#include <libSDL2pp/src/Surface.hpp>

namespace SDL2pp::Img {
    class ImageSurface : public SDL2pp::Surface {
    public:
        ImageSurface(std::string pathIMG);
    };
};


#endif //SDL2PP_IMAGESURFACE_HPP
