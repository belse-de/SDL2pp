//
// Created by belse on 15.03.18.
//

#ifndef SDL2PP_WIDGET_HPP
#define SDL2PP_WIDGET_HPP

#include <memory>
#include <vector>

#include <SDL_rect.h>
#include <SDL_events.h>
#include <boost/core/demangle.hpp>

#include <stdLib_helper.hpp>

#include "Rect.hpp"

namespace Widget {
    class Base : public Printable{ ;
    public:
        std::string to_string() const override;
        virtual std::string type_name() const;

        bool hasParent();
        void registerParent(std::weak_ptr<Base> parent);
        // only for optimisation
        // void registerParent(std::weak_ptr<Base>&& parent);

        bool hasChildren();
        void registerChild(std::shared_ptr<Base> child);
        // only for optimisation
        // void registerChild(std::shared_ptr<Base>&& child);

        void updateAbsolute();
    //protected:
        unsigned int id = 0;
        std::string _name = "unnamed";

        // make weak_ptr;
        std::weak_ptr<Base> _parent;
        std::vector<std::shared_ptr<Base>> _children;

        Rect _area{0,0,0,0};
        Rect _hitbox{0,0,0,0};

        Rect _areaAbsolute{0,0,0,0};
        Rect _hitboxAbsolute{0,0,0,0};

        bool _visible = true;
        bool _focusMouse = false;
        bool _focusKeyboard = false;
        bool _redraw = false;
    };
};


#endif //SDL2PP_WIDGET_HPP
