//
// Created by belse on 15.03.18.
//

#include <iostream>
#include <memory>

#include "Base.hpp"
#include "PointRect.hpp"

using namespace Widget;

std::string Base::to_string() const {
    return type_name() + "(" + _name + ")";
}

std::string Base::type_name() const {
    return getTypeName(*this);
}

bool Base::hasParent() {
    return not _parent.expired();
}

void Base::registerParent(std::weak_ptr<Base> parent) {
    _parent = parent;
}

bool Base::hasChildren() {
    return _children.size() > 0;
}

void Base::registerChild(std::shared_ptr<Base> child) {
    _children.push_back(child);
}

void Base::updateAbsolute() {
    if (auto parent = _parent.lock()) {
        _areaAbsolute = parent->_areaAbsolute.position + _area;
        // TODO: signal: position changed
    } else {
        _areaAbsolute = _area;
    }
    _hitboxAbsolute = _areaAbsolute.position + _hitbox;
}
