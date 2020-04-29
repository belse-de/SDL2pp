//
// Created by belse on 17.03.18.
//

#ifndef SDL2PP_WIDGET_BUTTON_HPP
#define SDL2PP_WIDGET_BUTTON_HPP

#include <variant>
#include <libWidget/src/Base.hpp>
#include <libSDL2pp/src/Texture.hpp>
#include "overloaded.hpp"

namespace Widget {
    class Button : public Base {
    public:


        class StateNormal{};
        class StateHighlighted{};
        class StateActive{};
        using State_t = std::variant<StateNormal, StateHighlighted, StateActive>;

        class SignalOver{};
        class SignalOut{};
        class SignalDown{};
        class SignalUp{};
        using Signal_t = std::variant<SignalOver, SignalOut, SignalDown, SignalUp>;

        struct transitionTable {
            State_t operator()(const StateNormal& st, const SignalOver& si){ return StateHighlighted();}
            State_t operator()(const StateNormal& st, const SignalOut&  si){ return st;}
            State_t operator()(const StateNormal& st, const SignalDown& si){ return st;}
            State_t operator()(const StateNormal& st, const SignalUp&   si){ return st;}

            State_t operator()(const StateHighlighted& st, const SignalOver& si){ return st;};
            State_t operator()(const StateHighlighted& st, const SignalOut&  si){ return StateNormal();}
            State_t operator()(const StateHighlighted& st, const SignalDown& si){ return StateActive();}
            State_t operator()(const StateHighlighted& st, const SignalUp&   si){ return st;}

            State_t operator()(const StateActive& st, const SignalOver& si){ return st;}
            State_t operator()(const StateActive& st, const SignalOut&  si){ return StateNormal();}
            State_t operator()(const StateActive& st, const SignalDown& si){ return st;}
            State_t operator()(const StateActive& st, const SignalUp&   si){ return StateHighlighted();}
        };
        State_t _state;

    };
};

#endif //SDL2PP_WIDGET_BUTTON_HPP
