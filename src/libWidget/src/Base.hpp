//
// Created by belse on 15.03.18.
//

#ifndef SDL2PP_WIDGET_HPP
#define SDL2PP_WIDGET_HPP


#include <SDL_rect.h>
#include <SDL_events.h>
#include <boost/core/demangle.hpp>
#include <rttr/rttr_enable.h>

#include <libSDL2pp/src/Renderer.hpp>
#include <stdLib_helper.hpp>


namespace Widget {
    class Base : public Printable{
        RTTR_ENABLE(Printable);
    public:
        virtual void handleEvent(SDL_Event *event);

        virtual void render(SDL2pp::Renderer & renderer) = 0;
        virtual

        void setHitBox(SDL_Rect hitBox);

        void setVisible(bool visible){
            _visible = visible;
        }

        //std::string to_string() const override;
        // override can not be used with rttr
        // TODO: make request on rttr for override support
        virtual std::string to_string() const;
        virtual std::string type_name() const;


    protected:
        bool _visible = true;
        bool _focus = false;
        bool _redraw = false;
        SDL_Rect _hitBox;

        std::string _name = "unknown";

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
