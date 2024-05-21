//
// Created by kitsai on 17/05/24.
//

#ifndef VEC3_H
#define VEC3_H

#include "physics/precision.h"
namespace fyrebird {
    class Vec2; // Forward declaration of Vec2
    class Vec2Int; // Forward declaration of Vec2Int
    class Vec3Int; // Forward declaration of Vec3Int

    class Vec3 {
    public:
        real x, y, z;

        Vec3(real x, real y, real z);

        //VEC3
        Vec3 &operator=(const Vec3 &v);

        Vec3 operator+(const Vec3 &v) const;

        Vec3 operator-(const Vec3 &v) const;

        real operator*(const Vec3 &v) const;

        Vec3 operator%(const Vec3 &v) const;

        void operator+=(const Vec3 &v);

        void operator-=(const Vec3 &v);

        void operator%=(const Vec3 &v);

        bool operator==(const Vec3 &v) const;

        bool operator!=(const Vec3 &v) const;

        bool operator>(const Vec3 &v) const;

        bool operator<(const Vec3 &v) const;

        bool operator>=(const Vec3 &v) const;

        bool operator<=(const Vec3 &v) const;

        //VEC2
        Vec3 &operator=(const Vec2 &v);

        Vec3 operator+(const Vec2 &v) const;

        Vec3 operator-(const Vec2 &v) const;

        real operator*(const Vec2 &v) const;

        void operator+=(const Vec2 &v);

        void operator-=(const Vec2 &v);

        //SCALER
        Vec3 &operator=(const real &v);
        Vec3 operator+(const real &v) const;

        Vec3 operator-(const real &v) const;

        Vec3 operator*(const real &v) const;

        //CONVERSION
        explicit operator Vec2() const;

        explicit operator Vec2Int() const;

        explicit operator Vec3Int() const;

        //OPERATIONS
        [[nodiscard]] real magSq() const;

        [[nodiscard]] real mag() const;

        [[nodiscard]] Vec3 normalize() const;

        [[nodiscard]] real dist_vec3(const Vec3 &other) const;

        [[nodiscard]] real incl() const;

        [[nodiscard]] real incl_vec3(const Vec3 &other) const;

        [[nodiscard]] Vec3 rotate(real angle) const;

        [[nodiscard]] Vec3 abs() const;

        [[nodiscard]] Vec3 inverse() const;

        [[nodiscard]] Vec3 component_producr(const Vec3 &v) const;

        [[nodiscard]] real dot(const Vec3 &v) const;

        [[nodiscard]] Vec3 cross(const Vec3 &v) const;

        //INITIALIZERS
        static Vec3 zero();

        static Vec3 left();

        static Vec3 right();

        static Vec3 up();

        static Vec3 down();

        static Vec3 forward();

        static Vec3 back();
    };
}

#endif //VEC3_H
