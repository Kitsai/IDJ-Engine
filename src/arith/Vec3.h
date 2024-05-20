//
// Created by kitsai on 17/05/24.
//

#ifndef VEC3_H
#define VEC3_H

class Vec2; // Forward declaration of Vec2
class Vec2Int; // Forward declaration of Vec2Int
class Vec3Int; // Forward declaration of Vec3Int

class Vec3 {
public:
    float x, y, z;

    Vec3(float x, float y, float z);

    //VEC3
    Vec3 &operator=(const Vec3 &v);
    Vec3 operator+(const Vec3 &v) const;
    Vec3 operator-(const Vec3 &v) const;
    Vec3 operator*(const Vec3 &v) const;
    void operator+=(const Vec3 &v);
    void operator-=(const Vec3 &v);
    void operator*=(const Vec3 &v);
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
    Vec3 operator*(const Vec2 &v) const;
    void operator+=(const Vec2 &v);
    void operator-=(const Vec2 &v);
    void operator*=(const Vec2 &v);

    //SCALER
    Vec3 operator+(const float &v) const;
    Vec3 operator-(const float &v) const;
    Vec3 operator*(const float &v) const;

    //CONVERSION
    explicit operator Vec2() const;
    explicit operator Vec2Int() const;
    explicit operator Vec3Int() const;

    //OPERATIONS
    [[nodiscard]] float magSq() const;
    [[nodiscard]] float mag() const;
    [[nodiscard]] Vec3 normalize() const;
    [[nodiscard]] float distVec3(const Vec3 &other) const;
    [[nodiscard]] float incl() const;
    [[nodiscard]] float inclVec3(const Vec3 &other) const;
    [[nodiscard]] Vec3 rotate(float angle) const;
    [[nodiscard]] Vec3 abs() const;
    [[nodiscard]] float dot(const Vec3 &v) const;

    //INITIALIZERS
    static Vec3 zero();
    static Vec3 left();
    static Vec3 right();
    static Vec3 up();
    static Vec3 down();
    static Vec3 forward();
    static Vec3 back();
};


#endif //VEC3_H
