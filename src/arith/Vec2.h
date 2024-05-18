//
// Created by kitsai on 17/05/24.
//

#ifndef VEC2_H
#define VEC2_H

#include "Vec3.h"
#include "Vec3Int.h"
#include "Vec2Int.h"

class Vec2 {
public:
    float x, y;

    Vec2(float x, float y);

    Vec2 &operator=(const Vec2 &v);

    Vec2 operator+(const Vec2 &v) const;

    Vec2 operator-(const Vec2 &v) const;

    Vec2 operator*(const Vec2 &v) const;

    void operator+=(const Vec2 &v);

    void operator-=(const Vec2 &v);

    bool operator==(const Vec2 &v) const;

    bool operator!=(const Vec2 &v) const;

    bool operator>(const Vec2 &v) const;

    bool operator<(const Vec2 &v) const;

    bool operator>=(const Vec2 &v) const;

    bool operator<=(const Vec2 &v) const;

    Vec2 operator+(const float &v) const;

    Vec2 operator-(const float &v) const;

    Vec2 operator*(const float &v) const;

    explicit operator Vec3() const;
    explicit operator Vec3Int() const;
    explicit operator Vec2Int() const;

    [[nodiscard]] float magSq() const;

    [[nodiscard]] float mag() const;

    [[nodiscard]] Vec2 normalize() const;

    [[nodiscard]] float distVec2(const Vec2 &other) const;

    [[nodiscard]] float incl() const;

    [[nodiscard]] float inclVec2(const Vec2 &other) const;

    [[nodiscard]] Vec2 rotate(float angle) const;

    [[nodiscard]] Vec2 abs() const;

    static Vec2 zero();

    static Vec2 left();

    static Vec2 right();

    static Vec2 up();

    static Vec2 down();
};

#endif //VEC2_H
