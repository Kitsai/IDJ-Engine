//
// Created by luck3 on 5/20/2024.
//

#include "arith/Circle.h"
#include "arith/Vec2.h"

Circle::Circle(float x, float y, float z, float radius): x(x), y(y), z(z), radius(radius) {}
Circle::Circle(Vec3 center, float radius):x(center.x), y(center.y), z(center.z),radius(radius) {}

Circle Circle::operator+(const Vec3 &v) const {
    return {x + v.x,y + v.y,z + v.z, radius};
}
Circle Circle::operator-(const Vec3 &v) const {
    return {x - v.x,y - v.y,z - v.z, radius};
}
Circle &Circle::operator+=(const Vec3 &v) {
    x += v.x;
    y += v.y;
    z += v.z;
    return *this;
}
Circle &Circle::operator-=(const Vec3 &v) {
    x -= v.x;
    y -= v.y;
    z -= v.z;
    return *this;
}

Circle Circle::operator+(const Vec2 &v) const {
    return {x + v.x,y + v.y,z, radius};
}
Circle Circle::operator-(const Vec2 &v) const {
    return {x - v.x,y - v.y,z,radius};
}
Circle &Circle::operator+=(const Vec2 &v) {
    x += v.x;
    y += v.y;
    return *this;
}
Circle &Circle::operator-=(const Vec2 &v) {
    x -= v.x;
    y -= v.y;
    return *this;
}

Circle Circle::operator+(const float f) const {
    return {x,y,z, radius + f};
}
Circle Circle::operator-(const float f) const {
    return {x,y,z, radius - f};
}

Circle &Circle::operator+=(const float f) {
    radius += f;
    return *this;
}

Circle &Circle::operator-=(float f) {
    radius -= f;
    return *this;
}

Circle::operator Vec3() const {
    return {x,y,z};
}

Circle::operator Vec2() const {
    return {x,y};
}

Circle::operator float() const {
    return radius;
}

Vec3 Circle::get_center() const {
    return {x,y,z};
}

float Circle::dist_circle(const Circle &other) const {
    return this->get_center().dist_vec3(other.get_center());
}

float Circle::dist_circle_plane(const Circle &other) const {
    return ((Vec2) this->get_center()).dist_vec2((Vec2) other.get_center());
}

bool Circle::contains(const Vec3 &v) const {
    bool ret = false;
    if(z != v.z) {
        float dist = Vec2(this->get_center()).dist_vec2((Vec2)v);
        ret = dist <= radius;
    }
    return ret;
}

bool Circle::contains(const Vec2 &v) const {
    float dist = Vec2(this->get_center()).dist_vec2(v);
    return dist <= radius;
}

Circle Circle::base() {
    return {Vec3::zero(),1};
}