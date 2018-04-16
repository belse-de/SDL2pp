//
// Created by belse on 15.03.18.
//

#ifndef SDL2PP_WIDGET_WINDOW_HPP
#define SDL2PP_WIDGET_WINDOW_HPP


#include <libSDL2pp/src/Window.hpp>
#include <libWidget/src/Base.hpp>
namespace Widget{
    class Window : public Base{
        RTTR_ENABLE(Base);
    public:
        Window(SDL2pp::Window &w);
        void render(SDL2pp::Renderer & renderer) override;

    private:
        SDL2pp::Window &_window;
    };
};


#endif //SDL2PP_WIDGET_WINDOW_HPP
