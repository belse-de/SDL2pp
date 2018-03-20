//
// Created by belse on 17.03.18.
//

#include <iostream>
#include "Button.hpp"

using namespace Widget;

Button::Button(SDL2pp::Texture &imageNormal, SDL2pp::Texture &imageHighlight, SDL2pp::Texture &imageActive,
               SDL_Rect source) : _imageNormal{imageNormal}, _imageHighlight{imageHighlight}, _imageActive{imageActive}, _source{source} {

}


void Button::handleEventMouseOutside(SDL_Event *pEvent) {
    Widget::handleEventMouseOutside(pEvent);
    Signal_t si = SignalOut();
   _state = std::visit(transitionTable(),_state,si);

}

void Button::handleEventMouseOver(SDL_Event *pEvent) {
    Widget::handleEventMouseOver(pEvent);
    Signal_t si = SignalOver();
    _state = std::visit(transitionTable(),_state,si);
}

void Button::handleEventMouseWheel(SDL_Event *pEvent) {
    Widget::handleEventMouseWheel(pEvent);
}

void Button::handleEventMouseDown(SDL_Event *pEvent) {
    Widget::handleEventMouseDown(pEvent);
    Signal_t si = SignalDown();
    _state = std::visit(transitionTable(),_state,si);
}

void Button::handleEventMouseUp(SDL_Event *pEvent) {
    Widget::handleEventMouseUp(pEvent);
    Signal_t si = SignalUp();
    _state = std::visit(transitionTable(),_state,si);
}

void Button::render(SDL2pp::Renderer &renderer) {
    auto rendererVisitor = overloaded{
        [&](const StateNormal &st){
            renderer.copy(_imageNormal, &(_source), &(_hitBox));
        },
        [&](const StateHighlighted &st){
            renderer.copy(_imageHighlight, &(_source), &(_hitBox));
        },
        [&](const StateActive &st){
            renderer.copy(_imageActive, &(_source), &(_hitBox));
        }
    };
    std::visit(rendererVisitor,_state);
}
