//
// Created by kitsai on 17/05/24.
//

#include "arith/Vec3.h"
#include "arith/Vec3Int.h"
#include "arith/Vec2.h"
#include "arith/Vec2Int.h"
#include <cmath>

Vec3::Vec3(float x, float y, float z) {
    this->x = x;
    this->y = y;
    this->z = z;
}

//VEC3
Vec3 &Vec3::operator=(const Vec3 &v) = default;
Vec3 Vec3::operator+(const Vec3 &v) const {
    return {this->x + v.x, this->y + v.y, this->z + v.z};
}
Vec3 Vec3::operator-(const Vec3 &v) const {
    return {this->x - v.x, this->y - v.y, this->z - v.z};
}
Vec3 Vec3::operator*(const Vec3 &v) const {
    return {this->x * v.x, this->y * v.y, this->z * v.z};
}
void Vec3::operator+=(const Vec3 &v) {
    this->x += v.x;
    this->y += v.y;
    this->z += v.z;
}
void Vec3::operator-=(const Vec3 &v) {
    this->x -= v.x;
    this->y -= v.y;
    this->z -= v.z;
}
void Vec3::operator*=(const Vec3 &v) {
    this->x *= v.x;
    this->y *= v.y;
    this->z *= v.z;
}
bool Vec3::operator==(const Vec3 &v) const {
    return this->x == v.x && this->y == v.y && this->z == v.z;
}
bool Vec3::operator!=(const Vec3 &v) const {
    return this->x != v.x || this->y != v.y || this->z != v.z;
}
bool Vec3::operator>(const Vec3 &v) const {
    return this->x > v.x && this->y > v.y && this->z > v.z;
}
bool Vec3::operator<(const Vec3 &v) const {
    return this->x < v.x && this->y < v.y && this->z < v.z;
}
bool Vec3::operator>=(const Vec3 &v) const {
    return this->x >= v.x && this->y >= v.y && this->z >= v.z;
}
bool Vec3::operator<=(const Vec3 &v) const {
    return this->x <= v.x && this->y <= v.y && this->z <= v.z;
}

//SCALER
Vec3 Vec3::operator+(const float &v) const {
    return {this->x + v, this->y + v, this->z + v};
}
Vec3 Vec3::operator-(const float &v) const {
    return {this->x - v, this->y - v, this->z - v};
}
Vec3 Vec3::operator*(const float &v) const {
    return {this->x * v, this->y * v, this->z * v};
}

//VEC2
Vec3 &Vec3::operator=(const Vec2 &v) {
    this->x = v.x;
    this->y = v.y;
    return *this;
}
Vec3 Vec3::operator+(const Vec2 &v) const {
    return {x * v.x, y + v.y, 0};
}
Vec3 Vec3::operator-(const Vec2 &v) const {
    return {x - v.x, y - v.y, 0};
}
Vec3 Vec3::operator*(const Vec2 &v) const {
    return {x * v.x, y*v.y, 0};
}
void Vec3::operator+=(const Vec2 &v) {
    this->x += v.x;
    this->y += v.y;
}
void Vec3::operator-=(const Vec2 &v) {
    this->x -= v.x;
    this->y -= v.y;
}
void Vec3::operator*=(const Vec2 &v) {
    this->x *= v.x;
    this->y *= v.y;
}

//CONVERSIONS
Vec3::operator Vec2() const {
    return {this->x, this->y};
}
Vec3::operator Vec2Int() const {
    return {static_cast<int>(this->x), static_cast<int>(this->y)};
}
Vec3::operator Vec3Int() const {
    return {static_cast<int>(this->x), static_cast<int>(this->y), static_cast<int>(this->z)};
}

//OPERATIONS
float Vec3::magSq() const{
    return this->x * this->x + this->y * this->y + this->z * this->z;
}
float Vec3::mag() const {
    return std::sqrt(this->magSq());
}
Vec3 Vec3::normalize() const {
    const float m = this->mag();
    return {this->x * (1.f/m), this->y * (1.f/m), this->z * (1.f/m)};
}
float Vec3::dist_vec3(const Vec3 &other) const {
    return std::sqrt(
            (this->x - other.x) * (this->x - other.x) + (this->y - other.y) * (this->y - other.y) + (this->z - other.z)
                                                                                                    * (this->z - other.z));
}
float Vec3::incl() const {
    return std::atan2(this->y, this->x);
}
float Vec3::incl_vec3(const Vec3 &other) const {
    return std::atan2(other.y - this->y, other.x - this->x);
}
Vec3 Vec3::rotate(const float angle) const{
    const float s = std::sin(angle);
    const float c = std::cos(angle);
    return {this->x * c - this->y * s, this->x * s + this->y * c, this->z};
}
Vec3 Vec3::abs() const {
    return {std::abs(this->x), std::abs(this->y), std::abs(this->z)};
}
float Vec3::dot(const Vec3 &v) const {
    const Vec3 product = *this * v;
    return product.x + product.y + product.z;
}

//INITIALIZERS
Vec3 Vec3::zero() {
    return {0, 0, 0};
}
Vec3 Vec3::left() {
    return {-1, 0, 0};
}
Vec3 Vec3::right() {
    return {1, 0, 0};
}
Vec3 Vec3::up() {
    return {0, 1, 0};
}
Vec3 Vec3::down() {
    return {0, -1, 0};
}
Vec3 Vec3::forward() {
    return {0, 0, 1};
}
Vec3 Vec3::back() {
    return {0, 0, -1};
}

