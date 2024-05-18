//
// Created by kitsai on 17/05/24.
//
#include "Vec2.h"
#include <cmath>

Vec2::Vec2(const float x,const float y) {
    this->x = x;
    this->y = y;
}

Vec2& Vec2::operator=(const Vec2& v) = default;

Vec2 Vec2::operator+(const Vec2& v) const {
    return {this->x + v.x, this->y + v.y};
}

Vec2 Vec2::operator-(const Vec2& v) const {
    return {this->x - v.x, this->y - v.y};
}

Vec2 Vec2::operator*(const Vec2& v) const {
    return {this->x * v.x, this->y * v.y};
}

void Vec2::operator+=(const Vec2& v) {
    this->x += v.x;
    this->y += v.y;
}

void Vec2::operator-=(const Vec2& v) {
    this->x -= v.x;
    this->y -= v.y;
}

bool Vec2::operator==(const Vec2& v) const {
    return this->x == v.x && this->y == v.y;
}

bool Vec2::operator!=(const Vec2& v) const {
    return this->x != v.x || this->y != v.y;
}

bool Vec2::operator>(const Vec2& v) const {
    return this->x > v.x && this->y > v.y;
}

bool Vec2::operator<(const Vec2& v) const {
    return this->x < v.x && this->y < v.y;
}

bool Vec2::operator>=(const Vec2& v) const {
    return this->x >= v.x && this->y >= v.y;
}

bool Vec2::operator<=(const Vec2& v) const {
    return this->x <= v.x && this->y <= v.y;
}

Vec2 Vec2::operator+(const float& v) const {
    return {this->x + v, this->y + v};
}

Vec2 Vec2::operator-(const float& v) const {
    return {this->x - v, this->y - v};
}

Vec2 Vec2::operator*(const float& v) const {
    return {this->x * v, this->y * v};
}

Vec2::operator Vec3() const {
    return {this->x,this->y,0};
}

Vec2::operator Vec3Int() const {
    return {this->x,this->y,0};
}

Vec2::operator Vec2Int() const {
    return {this->x,this->y};
}

float Vec2::magSq() const {
    return this->x * this->x + this->y * this->y;
}

float Vec2::mag() const {
    return std::sqrt(this->magSq());
}

Vec2 Vec2::normalize() const {
    const float m = this->mag();
    return {this->x / m, this->y / m};
}

float Vec2::distVec2(const Vec2& other) const{
    return (*this - other).mag();
}

float Vec2::incl() const{
    return std::atan2(this->y, this->x);
}

float Vec2::inclVec2(const Vec2& other) const {
    return (*this - other).incl();
}

Vec2 Vec2::rotate(float const angle) const {
    const float s = std::sin(angle);
    const float c = std::cos(angle);
    return {this->x * c - this->y * s, this->x * s + this->y * c};
}

Vec2 Vec2::abs() const {
    return {std::abs(this->x), std::abs(this->y)};
}

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
    return {0,-1};
}
