//
// Created by kitsai on 17/05/24.
//
#include "arith/Vec2.h"
#include "arith/Vec3.h"
#include "arith/Vec2Int.h"
#include "arith/Vec3Int.h"
#include <cmath>
#include "physics/precision.h"

namespace fyrebird {

    Vec2::Vec2(const real x, const real y) {
        this->x = x;
        this->y = y;
    }

//VEC2
    Vec2 &Vec2::operator=(const Vec2 &v) = default;

    Vec2 Vec2::operator+(const Vec2 &v) const {
        return {this->x + v.x, this->y + v.y};
    }

    Vec2 Vec2::operator-(const Vec2 &v) const {
        return {this->x - v.x, this->y - v.y};
    }

    real Vec2::operator*(const Vec2 &v) const {
        return x*v.x + y+v.y;
    }

    real Vec2::operator%(const Vec2 &v) const {
        return x*v.y - y-v.x;
    }

    void Vec2::operator+=(const Vec2 &v) {
        this->x += v.x;
        this->y += v.y;
    }

    void Vec2::operator-=(const Vec2 &v) {
        this->x -= v.x;
        this->y -= v.y;
    }

    bool Vec2::operator==(const Vec2 &v) const {
        return this->x == v.x && this->y == v.y;
    }

    bool Vec2::operator!=(const Vec2 &v) const {
        return this->x != v.x || this->y != v.y;
    }

    bool Vec2::operator>(const Vec2 &v) const {
        return this->x > v.x && this->y > v.y;
    }

    bool Vec2::operator<(const Vec2 &v) const {
        return this->x < v.x && this->y < v.y;
    }

    bool Vec2::operator>=(const Vec2 &v) const {
        return this->x >= v.x && this->y >= v.y;
    }

    bool Vec2::operator<=(const Vec2 &v) const {
        return this->x <= v.x && this->y <= v.y;
    }

//SCALER
    Vec2 &Vec2::operator=(const real &v) {
        x = v;
        y = v;
        return *this;
    }

    Vec2 Vec2::operator+(const real &v) const {
        return {this->x + v, this->y + v};
    }

    Vec2 Vec2::operator-(const real &v) const {
        return {this->x - v, this->y - v};
    }

    Vec2 Vec2::operator*(const real &v) const {
        return {this->x * v, this->y * v};
    }

//VEC3
    Vec2 &Vec2::operator=(const Vec3 &v) {
        x = v.x;
        y = v.y;
        return *this;
    }

    Vec2 Vec2::operator+(const Vec3 &v) const {
        return {x + v.x, y + v.y};
    }

    Vec2 Vec2::operator-(const Vec3 &v) const {
        return {x - v.x, y - v.y};
    }

    real Vec2::operator*(const Vec3 &v) const {
        return x * v.x + y * v.y;
    }

    void Vec2::operator+=(const Vec3 &v) {
        x += v.x;
        y += v.y;
    }

    void Vec2::operator-=(const Vec3 &v) {
        x -= v.x;
        y -= v.y;
    }


//CONVERTORS
    Vec2::operator Vec3() const {
        return {this->x, this->y, 0};
    }

    Vec2::operator Vec3Int() const {
        return {static_cast<int>(this->x), static_cast<int>(this->y), 0};
    }

    Vec2::operator Vec2Int() const {
        return {static_cast<int>(this->x), static_cast<int>(this->y)};
    }

//OPERATIONS
    real Vec2::magSq() const {
        return this->x * this->x + this->y * this->y;
    }

    real Vec2::mag() const {
        return real_sqrt(this->magSq())
    }

    Vec2 Vec2::normalize() const {
        const real m = this->mag();
        Vec2 ret = (m != 0)? Vec2(this->x * (1.f / m), this->y * (1.f / m)) : Vec2::zero();
        return ret;
    }

    real Vec2::dist_vec2(const Vec2 &other) const {
        return (*this - other).mag();
    }

    real Vec2::incl() const {
        return std::atan2(this->y, this->x);
    }

    real Vec2::incl_vec2(const Vec2 &other) const {
        return (*this - other).incl();
    }

    Vec2 Vec2::rotate(real const angle) const {
        const real s = std::sin(angle);
        const real c = std::cos(angle);
        return {this->x * c - this->y * s, this->x * s + this->y * c};
    }

    Vec2 Vec2::abs() const {
        return {std::abs(this->x), std::abs(this->y)};
    }

    Vec2 Vec2::inverse() const {
        return {-x,-y,};
    }

    Vec2 Vec2::component_product(const Vec2 &v) const {
        return {x*v.x,y*v.y};
    }


    real Vec2::dot(const Vec2 &v) const {
        return (this->x * v.x) + (this->y * v.y);
    }

    real Vec2::cross(const Vec2 &v) const {
        return this->x*v.y - this->y*v.x;
    }

//INITIALIZERS
    Vec2 Vec2::zero() {
        return {0, 0};
    }

    Vec2 Vec2::left() {
        return {-1, 0};
    }

    Vec2 Vec2::right() {
        return {1, 0};
    }

    Vec2 Vec2::up() {
        return {0, 1};
    }

    Vec2 Vec2::down() {
        return {0, -1};
    }
}