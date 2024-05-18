//
// Created by kitsai on 17/05/24.
//

#include "Rect.h"

Rect::Rect(float x, float y, float z, float w, float h) {
    this->x = x;
    this->y = y;
    this->z = z;
    this->w = w;
    this->h = h;
}

Rect::Rect(float x, float y, float w, float h) {
    this->x = x;
    this->y = y;
    this->z = 0;
    this->w = w;
    this->h = h;
}

Rect &Rect::operator=(const Rect &r) = default;

Rect Rect::operator+(const Rect &r) const {
    return {this->x + r.x, this->y + r.y, this->z + r.z, this->w + r.w, this->h + r.h};
}

Rect Rect::operator-(const Rect &r) const {
    return {this->x - r.x, this->y - r.y, this->z - r.z, this->w - r.w, this->h - r.h};
}

Rect &Rect::operator=(const Vec3 &r) {
    this->x = r.x;
    this->y = r.y;
    this->z = r.z;
    return *this;
}

Rect Rect::operator+(const Vec3 &v) const {
    return {this->x + v.x, this->y + v.y, this->z + v.z, this->w, this->h};
}

Rect Rect::operator-(const Vec3 &v) const {
    return {this->x - v.x, this->y - v.y, this->z - v.z, this->w, this->h};
}

void Rect::operator+=(const Vec3 &v) {
    this->x += v.x;
    this->y += v.y;
    this->z += v.z;
}

void Rect::operator-=(const Vec3 &v) {
    this->x -= v.x;
    this->y -= v.y;
    this->z -= v.z;
}

Rect::operator Vec3() const {
    return {this->x, this->y, this->z};
}

Rect::operator Vec2() const {
    return {this->x, this->y};
}

Vec3 Rect::get_pos() const {
    return {this->x, this->y, this->z};
}

Vec3 Rect::get_center() const {
    return {this->x + this->w * 0.5f, this->y + this->h * 0.5f, this->z};
}

void Rect::set_center(const Vec2 &center) {
    this->x = center.x - this->w * 0.5f;
    this->y = center.y - this->h * 0.5f;
}

float Rect::dist_rect(const Rect &other) const {
    const Vec3 center = this->get_center();
    const Vec3 other_center = other.get_center();
    return center.distVec3(other_center);
}
