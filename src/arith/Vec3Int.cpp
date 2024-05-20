//
// Created by kitsai on 17/05/24.
//

#include "Vec3Int.h"
#include "Vec3.h"
#include "Vec2Int.h"
#include "Vec2.h"
#include <cmath>

Vec3Int::Vec3Int(int x, int y, int z) {
    this->x = x;
    this->y = y;
    this->z = z;
}

Vec3Int &Vec3Int::operator=(const Vec3Int &v) = default;

Vec3Int Vec3Int::operator+(const Vec3Int &v) const {
    return {this->x + v.x, this->y + v.y, this->z + v.z};
}

Vec3Int Vec3Int::operator-(const Vec3Int &v) const {
    return {this->x - v.x, this->y - v.y, this->z - v.z};
}

Vec3Int Vec3Int::operator*(const Vec3Int &v) const {
    return {this->x * v.x, this->y * v.y, this->z * v.z};
}

void Vec3Int::operator+=(const Vec3Int &v) {
    this->x += v.x;
    this->y += v.y;
    this->z += v.z;
}

void Vec3Int::operator-=(const Vec3Int &v) {
    this->x -= v.x;
    this->y -= v.y;
    this->z -= v.z;
}

bool Vec3Int::operator==(const Vec3Int &v) const {
    return this->x == v.x && this->y == v.y && this->z == v.z;
}

bool Vec3Int::operator!=(const Vec3Int &v) const {
    return this->x != v.x || this->y != v.y || this->z != v.z;
}

bool Vec3Int::operator>(const Vec3Int &v) const {
    return this->x > v.x && this->y > v.y && this->z > v.z;
}

bool Vec3Int::operator<(const Vec3Int &v) const {
    return this->x < v.x && this->y < v.y && this->z < v.z;
}

bool Vec3Int::operator>=(const Vec3Int &v) const {
    return this->x >= v.x && this->y >= v.y && this->z >= v.z;
}

bool Vec3Int::operator<=(const Vec3Int &v) const {
    return this->x <= v.x && this->y <= v.y && this->z <= v.z;
}

Vec3Int Vec3Int::operator+(const int &v) const {
    return {this->x + v, this->y + v, this->z + v};
}

Vec3Int Vec3Int::operator-(const int &v) const {
    return {this->x - v, this->y - v, this->z - v};
}

Vec3Int Vec3Int::operator*(const int &v) const {
    return {this->x * v, this->y * v, this->z * v};
}

Vec3Int::operator Vec2Int() const {
    return {this->x, this->y};
}

Vec3Int::operator Vec2() const {
    return {static_cast<float>(this->x),static_cast<float>(this->y)};
}

Vec3Int::operator Vec3() const {
    return {static_cast<float>(this->x),static_cast<float>(this->y),static_cast<float>(this->z)};
}

int Vec3Int::magSq() const{
    return this->x * this->x + this->y * this->y + this->z * this->z;
}

float Vec3Int::mag() const {
    return std::sqrt(this->magSq());
}

Vec3Int Vec3Int::normalize() const {
    const float m = this->mag();
    return {static_cast<int>(this->x / m), static_cast<int>(this->y / m), static_cast<int>(this->z / m)};
}

float Vec3Int::distVec3Int(const Vec3Int &other) const {
    return std::sqrt(
            (this->x - other.x) * (this->x - other.x) + (this->y - other.y) * (this->y - other.y) + (this->z - other.z)
                                                                                                    * (this->z - other.z));
}

float Vec3Int::incl() const {
    return std::atan2(this->y, this->x);
}

float Vec3Int::inclVec3Int(const Vec3Int &other) const {
    return std::atan2(other.y - this->y, other.x - this->x);
}

Vec3Int Vec3Int::rotate(const float angle) const{
    const float s = std::sin(angle);
    const float c = std::cos(angle);
    return {static_cast<int>(this->x * c - this->y * s), static_cast<int>(this->x * s + this->y * c), this->z};
}

Vec3Int Vec3Int::abs() const {
    return {std::abs(this->x), std::abs(this->y), std::abs(this->z)};
}

Vec3Int Vec3Int::zero() {
    return {0, 0, 0};
}

Vec3Int Vec3Int::left() {
    return {-1, 0, 0};
}

Vec3Int Vec3Int::right() {
    return {1, 0, 0};
}

Vec3Int Vec3Int::up() {
    return {0, 1, 0};
}

Vec3Int Vec3Int::down() {
    return {0, -1, 0};
}

Vec3Int Vec3Int::forward() {
    return {0, 0, 1};
}

Vec3Int Vec3Int::back() {
    return {0, 0, -1};
}