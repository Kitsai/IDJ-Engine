//
// Created by luck3 on 5/17/2024.
//

#ifndef IDJ_ENGINE_Vec2INT_H
#define IDJ_ENGINE_Vec2INT_H

class Vec3Int; // Forward declaration of Vec3Int
class Vec2; // Forward declaration of Vec2
class Vec3; // Forward declaration of Vec3

class Vec2Int {
public:
    int x, y;

    Vec2Int(int x, int y);

    Vec2Int &operator=(const Vec2Int &v);

    Vec2Int operator+(const Vec2Int &v) const;

    Vec2Int operator-(const Vec2Int &v) const;

    Vec2Int operator*(const Vec2Int &v) const;

    void operator+=(const Vec2Int &v);

    void operator-=(const Vec2Int &v);

    bool operator==(const Vec2Int &v) const;

    bool operator!=(const Vec2Int &v) const;

    bool operator>(const Vec2Int &v) const;

    bool operator<(const Vec2Int &v) const;

    bool operator>=(const Vec2Int &v) const;

    bool operator<=(const Vec2Int &v) const;

    Vec2Int operator+(const int &v) const;

    Vec2Int operator-(const int &v) const;

    Vec2Int operator*(const int &v) const;

    explicit operator Vec3Int() const;
    explicit operator Vec3() const;
    explicit operator Vec2() const;

    [[nodiscard]] int magSq() const;

    [[nodiscard]] float mag() const;

    [[nodiscard]] Vec2Int normalize() const;

    [[nodiscard]] float distVec2Int(const Vec2Int &other) const;

    [[nodiscard]] float incl() const;

    [[nodiscard]] float inclVec2Int(const Vec2Int &other) const;

    [[nodiscard]] Vec2Int rotate(float angle) const;

    [[nodiscard]] Vec2Int abs() const;

    static Vec2Int zero();

    static Vec2Int left();

    static Vec2Int right();

    static Vec2Int up();

    static Vec2Int down();
};


#endif //IDJ_ENGINE_Vec2INT_H
