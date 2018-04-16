//
// Created by belse on 15.03.18.
//

#include <SDL_events.h>
#include <iostream>

#include <rttr/registration>
#include "Base.hpp"

using namespace Widget;


RTTR_REGISTRATION
{
    rttr::registration::class_<Base>("Widget::Base").method("setVisible", &Base::setVisible);
}


std::string Base::to_string() const{
    return type_name() + "(" + _name + ")";
}

std::string Base::type_name() const{
    return getTypeName(*this);
}


void Base::setHitBox(SDL_Rect hitBox) {
    _hitBox = hitBox;
}

void Base::handleEvent(SDL_Event *event) {
    if (not event) { return; }
    if (not _visible) { return; }

    if (event->type == SDL_WINDOWEVENT and event->window.event == SDL_WINDOWEVENT_EXPOSED) {
        _redraw = true;
        return;
    }

    if (event->type == SDL_MOUSEMOTION or event->type == SDL_MOUSEBUTTONDOWN or event->type == SDL_MOUSEBUTTONUP or
        event->type == SDL_MOUSEWHEEL) {
        handleEventMouse(event);

    }
}

void Base::handleEventMouse(SDL_Event *event) {
    //Get mouse position
    int x, y;
    SDL_GetMouseState(&x, &y);
    bool mouseInsideHitBox = x >= _hitBox.x
                             and x < (_hitBox.x + _hitBox.w)
                             and y >= _hitBox.y
                             and y < (_hitBox.y + _hitBox.h);

    if (mouseInsideHitBox) {
        switch (event->type) {
            case SDL_MOUSEMOTION:
                handleEventMouseOver(event);
                break;
            case SDL_MOUSEWHEEL:
                handleEventMouseWheel(event);
                break;
            case SDL_MOUSEBUTTONDOWN:
                handleEventMouseDown(event);
                break;
            case SDL_MOUSEBUTTONUP:
                handleEventMouseUp(event);
                break;
            default:
                std::clog << __PRETTY_FUNCTION__ << std::endl;
                break;
        }
    } else if(event->type == SDL_MOUSEMOTION) {
        handleEventMouseOutside(event);
    }
}


void Base::handleEventMouseOutside(SDL_Event *pEvent) {
}

void Base::handleEventMouseOver(SDL_Event *pEvent) {
}

void Base::handleEventMouseWheel(SDL_Event *pEvent) {
}

void Base::handleEventMouseDown(SDL_Event *pEvent) {
}

void Base::handleEventMouseUp(SDL_Event *pEvent) {
}

