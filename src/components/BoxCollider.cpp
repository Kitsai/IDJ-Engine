//
// Created by luck3 on 5/19/2024.
//

#include "components/BoxCollider.h"
#include "GameObject.h"
#include "components/CircleCollider.h"

#ifndef DEBUG
#include "components/Camera.h"
#include "Game.h"

#include "SDL2/SDL.h"

#include <iostream>
#endif

BoxCollider::BoxCollider(GameObject &associated,
                         Vec2 scale,
                         Vec2 offset,
                         SDL_Color color
                   ): Collider(associated,scale,offset,color),
                   active(true),
                   box(associated.box) {
    box.w *= scale.x;
    box.h *= scale.y;
    box.set_center((Vec2)associated.box.get_center() + this->offset.rotate(associated.angle_deg));
}

void BoxCollider::update() {
    box.w = _associated.box.w*scale.x;
    box.set_center((Vec2)_associated.box.get_center() + offset.rotate(_associated.angle_deg));
}

void BoxCollider::render() {
#ifndef DEBUG
    Vec2 center( box.get_center() );
    SDL_Point points[5];

    if(Camera::current_camera == nullptr) {
        std::cerr << "State doesn't have a Camera!" << std::endl;
        return;
    }
    auto cam = Camera::current_camera;

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

bool BoxCollider::is(std::string type) {
    return type == "BoxCollider";
}

Vec2 BoxCollider::get_center() const {
    return (Vec2)box.get_center();
}

std::vector<Vec2> BoxCollider::get_points() {
    std::vector<Vec2> points = {
            {box.x,box.y},
            {box.x + box.w,box.y},
            {box.x + box.w, box.y + box.h},
            {box.x,box.y + box.h}
    };

    return points;
}

bool BoxCollider::is_colliding(GameObject &other) {
    std::shared_ptr<Component> col;
    col = other.get_component("CircleCollider").lock();
    if(col != nullptr) {
        return Collision::IsColliding(std::static_pointer_cast<CircleCollider>(col)->circle, box, _associated.angle_deg);
    }

    col = other.get_component("BoxCollider").lock();
    return Collision::IsColliding(std::static_pointer_cast<BoxCollider>(col)->box,box,other.angle_deg,_associated.angle_deg);
}