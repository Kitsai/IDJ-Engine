//
// Created by luck3 on 5/20/2024.
//

#ifndef IDJ_ENGINE_CIRCLE_H
#define IDJ_ENGINE_CIRCLE_H

#include "Vec3.h"

namespace fyrebird {
    class Circle {
    public:
        real x;
        real y;
        real z;
        real radius;

        Circle(real x, real y, real z, real radius);

        Circle(Vec3 center, real radius);

        Circle &operator=(const Circle &c) = default;

        Circle operator+(const Vec3 &v) const;

        Circle operator-(const Vec3 &v) const;

        Circle &operator+=(const Vec3 &v);

        Circle &operator-=(const Vec3 &v);

        Circle operator+(const Vec2 &v) const;

        Circle operator-(const Vec2 &v) const;

        Circle &operator+=(const Vec2 &v);

        Circle &operator-=(const Vec2 &v);

        Circle operator+(real f) const;

        Circle operator-(real f) const;

        Circle &operator+=(real f);

        Circle &operator-=(real f);

        explicit operator Vec3() const;

        explicit operator Vec2() const;

        explicit operator real() const;

        [[nodiscard]] Vec3 get_center() const;

        [[nodiscard]] real dist_circle(const Circle &other) const;

        [[nodiscard]] real dist_circle_plane(const Circle &other) const;

        [[nodiscard]] bool contains(const Vec3 &v) const;

        [[nodiscard]] bool contains(const Vec2 &v) const;

        static Circle base();
    };
}

#endif //IDJ_ENGINE_CIRCLE_H
