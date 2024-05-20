//
// Created by luck3 on 5/20/2024.
//

#ifndef IDJ_ENGINE_CIRCLE_H
#define IDJ_ENGINE_CIRCLE_H

#include "Vec3.h"

class Circle {
public:
    float x;
    float y;
    float z;
    float radius;

    Circle(float x, float y, float z, float radius);
    Circle(Vec3 center, float radius);

    Circle& operator=(const Circle &c) = default;

    Circle operator+(const Vec3 &v) const;
    Circle operator-(const Vec3 &v) const;
    Circle &operator+=(const Vec3 &v);
    Circle &operator-=(const Vec3 &v);

    Circle operator+(const Vec2 &v) const;
    Circle operator-(const Vec2 &v) const;
    Circle &operator+=(const Vec2 &v);
    Circle &operator-=(const Vec2 &v);

    Circle operator+(float f) const;
    Circle operator-(float f) const;
    Circle &operator+=(float f);
    Circle &operator-=(float f);

    explicit operator Vec3() const;
    explicit operator Vec2() const;
    explicit operator float() const;

    [[nodiscard]] Vec3 get_center() const;

    [[nodiscard]] float dist_circle(const Circle &other) const;
    [[nodiscard]] float dist_circle_plane(const Circle &other) const;

    [[nodiscard]] bool contains(const Vec3 &v) const;
    [[nodiscard]] bool contains(const Vec2 &v) const;

    static Circle base();
};


#endif //IDJ_ENGINE_CIRCLE_H
