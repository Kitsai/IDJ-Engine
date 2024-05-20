//
// Created by kitsai on 17/05/24.
//

#ifndef RECT_H
#define RECT_H

#include "Vec3.h"
#include "Vec2.h"

class Rect {
public:
    float x, y, z, w, h;

    Rect(float x, float y, float z, float w, float h);
    Rect(float x, float y, float w, float h);

    Rect &operator=(const Rect &r);
    Rect operator+(const Rect &r) const;
    Rect operator-(const Rect &r) const;

    Rect &operator=(const Vec3 &r);
    Rect operator+(const Vec3 &v) const;
    Rect operator-(const Vec3 &v) const;
    void operator+=(const Vec3 &v);
    void operator-=(const Vec3 &v);

    explicit operator Vec3() const;
    explicit operator Vec2() const;

    [[nodiscard]] Vec3 get_pos() const;

    [[nodiscard]] Vec3 get_center() const;

    void set_center(const Vec2 &center);

    [[nodiscard]] float dist_rect(const Rect &other) const;

    [[nodiscard]] bool contains(const Vec3 &v) const;
    [[nodiscard]] bool contains(const Vec2 &v) const;
};


#endif //RECT_H
