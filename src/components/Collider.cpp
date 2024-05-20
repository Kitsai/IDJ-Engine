//
// Created by luck3 on 5/19/2024.
//

#include "Collider.h"
#include "GameObject.h"

#ifndef DEBUG
#include "Camera.h"
#include "Game.h"

#include "SDL2/SDL.h"

#include <iostream>
#endif

Collider::Collider(GameObject &associated,
                   Vec2 scale,
                   Vec2 offset,
                   SDL_Color color
                   ): Component(associated),
                   scale(scale),
                   offset(offset),
                   color(color),
                   active(true),
                   box(associated.box){
    box.w *= scale.x;
    box.h *= scale.y;
    box.set_center((Vec2)associated.box.get_center() + this->offset.rotate(associated.angle_deg));
}

void Collider::update() {
    box.set_center((Vec2)_associated.box.get_center() + offset.rotate(_associated.angle_deg));
}

void Collider::render() {
#ifndef DEBUG
    Vec2 center( box.get_center() );
    SDL_Point points[5];

    if(Camera::current_camera.expired()) {
        std::cerr << "State doesn't have a Camera!" << std::endl;
        return;
    }
    auto cam = Camera::current_camera.lock();

    Vec2 point = (Vec2(box.x, box.y) - center).rotate( _associated.angle_deg )
                 + center - cam->pos();
    points[0] = {(int)point.x, (int)point.y};
    points[4] = {(int)point.x, (int)point.y};

    point = (Vec2(box.x + box.w, box.y) - center).rotate( _associated.angle_deg )
            + center - cam->pos();
    points[1] = {(int)point.x, (int)point.y};

    point = (Vec2(box.x + box.w, box.y + box.h) - center).rotate( _associated.angle_deg )
            + center - cam->pos();
    points[2] = {(int)point.x, (int)point.y};

    point = (Vec2(box.x, box.y + box.h) - center).rotate( _associated.angle_deg )
            + center - cam->pos();
    points[3] = {(int)point.x, (int)point.y};

    SDL_SetRenderDrawColor(&Game::Instance().Renderer(), color.r , color.g, color.b, color.a);
    SDL_RenderDrawLines(&Game::Instance().Renderer(), points, 5);
#endif
}

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

Vec2 Collider::get_center() const {
    return (Vec2)box.get_center();
}

std::vector<Vec2> Collider::get_points() {
    std::vector<Vec2> points = {
            {box.x,box.y},
            {box.x + box.w,box.y},
            {box.x + box.w, box.y + box.h},
            {box.x,box.y + box.h}
    };

    return points;
}

bool Collider::is_colliding(Rect &other_box, float other_angle) {
    return Collision::IsColliding(_associated.box,other_box,_associated.angle_deg,other_angle);
}