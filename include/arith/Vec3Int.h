//
// Created by luck3 on 5/17/2024.
//

#ifndef IDJ_ENGINE_Vec3INT_H
#define IDJ_ENGINE_Vec3INT_H

#include "physics/precision.h"

namespace fyrebird {
    class Vec2Int; // Forward declaration of Vec2Int
    class Vec2; // Forward declaration of Vec2
    class Vec3; // Forward declaration of Vec3

    class Vec3Int {
    public:
        integer x, y, z;

        Vec3Int(integer x, integer y, integer z);

        Vec3Int &operator=(const Vec3Int &v);

        Vec3Int operator+(const Vec3Int &v) const;

        Vec3Int operator-(const Vec3Int &v) const;

        Vec3Int operator*(const Vec3Int &v) const;

        void operator+=(const Vec3Int &v);

        void operator-=(const Vec3Int &v);

        bool operator==(const Vec3Int &v) const;

        bool operator!=(const Vec3Int &v) const;

        bool operator>(const Vec3Int &v) const;

        bool operator<(const Vec3Int &v) const;

        bool operator>=(const Vec3Int &v) const;

        bool operator<=(const Vec3Int &v) const;

        Vec3Int operator+(const integer &v) const;

        Vec3Int operator-(const integer &v) const;

        Vec3Int operator*(const integer &v) const;

        explicit operator Vec2Int() const;

        explicit operator Vec2() const;

        explicit operator Vec3() const;

        [[nodiscard]] integer magSq() const;

        [[nodiscard]] float mag() const;

        [[nodiscard]] Vec3Int normalize() const;

        [[nodiscard]] float distVec3Int(const Vec3Int &other) const;

        [[nodiscard]] float incl() const;

        [[nodiscard]] float inclVec3Int(const Vec3Int &other) const;

        [[nodiscard]] Vec3Int rotate(float angle) const;

        [[nodiscard]] Vec3Int abs() const;

        static Vec3Int zero();

        static Vec3Int left();

        static Vec3Int right();

        static Vec3Int up();

        static Vec3Int down();

        static Vec3Int forward();

        static Vec3Int back();
    };
}

#endif //IDJ_ENGINE_Vec3INT_H
