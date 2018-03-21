//
// Created by belse on 21.03.18.
//

#ifndef SDL2PP_SOFTWARERENDERER_HPP
#define SDL2PP_SOFTWARERENDERER_HPP

#include "Renderer.hpp"

namespace SDL2pp {
    class Surface;

    class SoftwareRenderer : public Renderer{
        SoftwareRenderer(Surface &surface);
    };
};

#endif //SDL2PP_SOFTWARERENDERER_HPP
