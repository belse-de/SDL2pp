//
// Created by belse on 14.12.17.
//

#ifndef SDL2PP_SDL2IMAGE_HPP
#define SDL2PP_SDL2IMAGE_HPP

namespace SDL2pp::Img {
    class SDL2Image {
    public:
        SDL2Image();
        SDL2Image(int flags);

        virtual ~SDL2Image();

        //IMG_isJPG, IMG_isPNG, and IMG_isTIF
    };
};

#endif //SDL2PP_SDL2IMAGE_HPP
