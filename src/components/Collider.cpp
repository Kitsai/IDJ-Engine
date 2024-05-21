//
// Created by luck3 on 5/20/2024.
//

#include "components/Collider.h"

namespace fyrebird {
    Collider::Collider(GameObject &associated,
                       Vec2 scale,
                       Vec2 offset,
                       SDL_Color color) :
            Component(associated),
            scale(scale),
            offset(offset),
            color(color),
            active(true) {}

    bool Collider::is(std::string type) {
        return type == "Collider";
    }

    void Collider::set_scale(Vec2 s) {
        this->scale = s;
    }

    void Collider::set_offset(Vec2 offs) {
        offset = offs;
    }

    void Collider::set_color(SDL_Color c) {
        color = c;
    }
}