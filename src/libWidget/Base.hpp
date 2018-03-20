//
// Created by belse on 15.03.18.
//

#ifndef SDL2PP_WIDGET_HPP
#define SDL2PP_WIDGET_HPP


#include <SDL_rect.h>
#include <SDL_events.h>

#include <libSDL2pp/Renderer.hpp>

namespace Widget {
    class Base {
    public:
        virtual void handleEvent(SDL_Event *event);

        virtual void render(SDL2pp::Renderer & renderer) = 0;

        void setHitBox(SDL_Rect hitBox);

    protected:
        bool _visible = true;
        bool _focus = false;
        bool _redraw = false;
        SDL_Rect _hitBox;

        std::shared_ptr<Base> parent;

        virtual void handleEventMouse(SDL_Event *event);
        virtual void handleEventMouseOutside(SDL_Event *pEvent);
        virtual void handleEventMouseOver(SDL_Event *pEvent);
        virtual void handleEventMouseWheel(SDL_Event *pEvent);
        virtual void handleEventMouseDown(SDL_Event *pEvent);
        virtual void handleEventMouseUp(SDL_Event *pEvent);

    };
};

#endif //SDL2PP_WIDGET_HPP
