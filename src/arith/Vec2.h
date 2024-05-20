//
// Created by kitsai on 17/05/24.
//

#ifndef VEC2_H
#define VEC2_H

class Vec3; // Forward declaration of Vec3
class Vec2Int; // Forward declaration of Vec2Int
class Vec3Int; // Forward declaration of Vec3Int

class Vec2 {
public:
    float x, y;

    Vec2(float x, float y);

    //VEC2
    Vec2 &operator=(const Vec2 &v);
    Vec2 operator+(const Vec2 &v) const;
    Vec2 operator-(const Vec2 &v) const;
    Vec2 operator*(const Vec2 &v) const;
    void operator+=(const Vec2 &v);
    void operator-=(const Vec2 &v);
    void operator*=(const Vec2 &v);
    bool operator==(const Vec2 &v) const;
    bool operator!=(const Vec2 &v) const;
    bool operator>(const Vec2 &v) const;
    bool operator<(const Vec2 &v) const;
    bool operator>=(const Vec2 &v) const;
    bool operator<=(const Vec2 &v) const;

    //VEC3
    Vec2 &operator=(const Vec3 &v);
    Vec2 operator+(const Vec3 &v) const;
    Vec2 operator-(const Vec3 &v) const;
    Vec2 operator*(const Vec3 &v) const;
    void operator+=(const Vec3 &v);
    void operator-=(const Vec3 &v);
    void operator*=(const Vec3 &v);

    //SCALER
    Vec2 operator+(const float &v) const;
    Vec2 operator-(const float &v) const;
    Vec2 operator*(const float &v) const;

    //CONVERSION
    explicit operator Vec3() const;
    explicit operator Vec3Int() const;
    explicit operator Vec2Int() const;

    //OPERATIONS
    [[nodiscard]] float magSq() const;
    [[nodiscard]] float mag() const;
    [[nodiscard]] Vec2 normalize() const;
    [[nodiscard]] float distVec2(const Vec2 &other) const;
    [[nodiscard]] float incl() const;
    [[nodiscard]] float incl_vec2(const Vec2 &other) const;
    [[nodiscard]] Vec2 rotate(float angle) const;
    [[nodiscard]] Vec2 abs() const;
    [[nodiscard]] float dot(const Vec2 &v) const;
    [[nodiscard]] Vec2 cross(const Vec2 &v) const;

    //INITIALIZERS
    static Vec2 zero();
    static Vec2 left();
    static Vec2 right();
    static Vec2 up();
    static Vec2 down();
};

#endif //VEC2_H
