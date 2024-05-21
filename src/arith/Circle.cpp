//
// Created by luck3 on 5/20/2024.
//

#include "arith/Circle.h"
#include "arith/Vec2.h"

namespace fyrebird {

    Circle::Circle(real x, real y, real z, real radius) : x(x), y(y), z(z), radius(radius) {}

    Circle::Circle(Vec3 center, real radius) : x(center.x), y(center.y), z(center.z), radius(radius) {}

    Circle Circle::operator+(const Vec3 &v) const {
        return {x + v.x, y + v.y, z + v.z, radius};
    }

    Circle Circle::operator-(const Vec3 &v) const {
        return {x - v.x, y - v.y, z - v.z, radius};
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
        return {x + v.x, y + v.y, z, radius};
    }

    Circle Circle::operator-(const Vec2 &v) const {
        return {x - v.x, y - v.y, z, radius};
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

    Circle Circle::operator+(const real f) const {
        return {x, y, z, radius + f};
    }

    Circle Circle::operator-(const real f) const {
        return {x, y, z, radius - f};
    }

    Circle &Circle::operator+=(const real f) {
        radius += f;
        return *this;
    }

    Circle &Circle::operator-=(real f) {
        radius -= f;
        return *this;
    }

    Circle::operator Vec3() const {
        return {x, y, z};
    }

    Circle::operator Vec2() const {
        return {x, y};
    }

    Circle::operator real() const {
        return radius;
    }

    Vec3 Circle::get_center() const {
        return {x, y, z};
    }

    real Circle::dist_circle(const Circle &other) const {
        return this->get_center().dist_vec3(other.get_center());
    }

    real Circle::dist_circle_plane(const Circle &other) const {
        return ((Vec2) this->get_center()).dist_vec2((Vec2) other.get_center());
    }

    bool Circle::contains(const Vec3 &v) const {
        bool ret = false;
        if (z != v.z) {
            real dist = Vec2(this->get_center()).dist_vec2((Vec2) v);
            ret = dist <= radius;
        }
        return ret;
    }

    bool Circle::contains(const Vec2 &v) const {
        real dist = Vec2(this->get_center()).dist_vec2(v);
        return dist <= radius;
    }

    Circle Circle::base() {
        return {Vec3::zero(), 1};
    }
}