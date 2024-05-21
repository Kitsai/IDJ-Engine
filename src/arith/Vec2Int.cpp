//
// Created by luck3 on 5/17/2024.
//

#include "arith/Vec2Int.h"
#include "arith/Vec2.h"
#include "arith/Vec3Int.h"
#include "arith/Vec3.h"
#include <cmath>

namespace fyrebird {
    Vec2Int::Vec2Int(const integer x, const integer y) {
        this->x = x;
        this->y = y;
    }

    Vec2Int &Vec2Int::operator=(const Vec2Int &v) = default;

    Vec2Int Vec2Int::operator+(const Vec2Int &v) const {
        return {this->x + v.x, this->y + v.y};
    }

    Vec2Int Vec2Int::operator-(const Vec2Int &v) const {
        return {this->x - v.x, this->y - v.y};
    }

    integer Vec2Int::operator*(const Vec2Int &v) const {
        return this->x * v.x + this->y * v.y;
    }

    void Vec2Int::operator+=(const Vec2Int &v) {
        this->x += v.x;
        this->y += v.y;
    }

    void Vec2Int::operator-=(const Vec2Int &v) {
        this->x -= v.x;
        this->y -= v.y;
    }

    bool Vec2Int::operator==(const Vec2Int &v) const {
        return this->x == v.x && this->y == v.y;
    }

    bool Vec2Int::operator!=(const Vec2Int &v) const {
        return this->x != v.x || this->y != v.y;
    }

    bool Vec2Int::operator>(const Vec2Int &v) const {
        return this->x > v.x && this->y > v.y;
    }

    bool Vec2Int::operator<(const Vec2Int &v) const {
        return this->x < v.x && this->y < v.y;
    }

    bool Vec2Int::operator>=(const Vec2Int &v) const {
        return this->x >= v.x && this->y >= v.y;
    }

    bool Vec2Int::operator<=(const Vec2Int &v) const {
        return this->x <= v.x && this->y <= v.y;
    }

    Vec2Int Vec2Int::operator+(const integer &v) const {
        return {this->x + v, this->y + v};
    }

    Vec2Int Vec2Int::operator-(const integer &v) const {
        return {this->x - v, this->y - v};
    }

    Vec2Int Vec2Int::operator*(const integer &v) const {
        return {this->x * v, this->y * v};
    }

    Vec2Int::operator Vec3Int() const {
        return {this->x, this->y, 0};
    }

    Vec2Int::operator Vec3() const {
        return {static_cast<float>(this->x), static_cast<float>(this->y), 0};
    }

    Vec2Int::operator Vec2() const {
        return {static_cast<float>(this->x), static_cast<float>(this->y)};
    }

    integer Vec2Int::magSq() const {
        return this->x * this->x + this->y * this->y;
    }

    float Vec2Int::mag() const {
        return std::sqrt(this->magSq());
    }

    Vec2Int Vec2Int::normalize() const {
        const float m = this->mag();
        return {static_cast<integer>(this->x * (1.f / m)), static_cast<integer>(this->y * (1.f / m))};
    }

    float Vec2Int::distVec2Int(const Vec2Int &other) const {
        return (*this - other).mag();
    }

    float Vec2Int::incl() const {
        return std::atan2(this->y, this->x);
    }

    float Vec2Int::inclVec2Int(const Vec2Int &other) const {
        return (*this - other).incl();
    }

    Vec2Int Vec2Int::rotate(float const angle) const {
        const float s = std::sin(angle);
        const float c = std::cos(angle);
        return {static_cast<integer>(this->x * c - this->y * s), static_cast<integer>(this->x * s + this->y * c)};
    }

    Vec2Int Vec2Int::abs() const {
        return {static_cast<integer>(std::abs(static_cast<float>(this->x))),
                static_cast<integer>(std::abs(static_cast<float>(this->y)))};
    }

    Vec2Int Vec2Int::zero() {
        return {0, 0};
    }

    Vec2Int Vec2Int::left() {
        return {-1, 0};
    }

    Vec2Int Vec2Int::right() {
        return {1, 0};
    }

    Vec2Int Vec2Int::up() {
        return {0, 1};
    }

    Vec2Int Vec2Int::down() {
        return {0, -1};
    }
}