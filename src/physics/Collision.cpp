//
// Created by luck3 on 5/19/2024.
//
#ifndef Collision_h_
#define Collision_h_

#include "arith/Rect.h"
#include "arith/Circle.h"

#include <algorithm>
#include <cmath>

class Collision {

public:
    // Observação: IsColliding espera ângulos em radianos!
    // Para usar graus, forneça a sua própria implementação de Rotate,
    // ou transforme os ângulos no corpo de IsColliding.
    static inline bool IsColliding(Rect& a, Rect& b, float angleOfA, float angleOfB) {
        Vec2 A[] = { Vec2( a.x, a.y + a.h ),
                     Vec2( a.x + a.w, a.y + a.h ),
                     Vec2( a.x + a.w, a.y ),
                     Vec2( a.x, a.y )
        };
        Vec2 B[] = { Vec2( b.x, b.y + b.h ),
                     Vec2( b.x + b.w, b.y + b.h ),
                     Vec2( b.x + b.w, b.y ),
                     Vec2( b.x, b.y )
        };

        for (auto& v : A) {
            v = Rotate(v - (Vec2)a.get_center(), angleOfA) + (Vec2)a.get_center();
        }

        for (auto& v : B) {
            v = Rotate(v - (Vec2)b.get_center(), angleOfB) + (Vec2)b.get_center();
        }

        Vec2 axes[] = { Norm(A[0] - A[1]), Norm(A[1] - A[2]), Norm(B[0] - B[1]), Norm(B[1] - B[2]) };

        for (auto& axis : axes) {
            float P[4];

            for (int i = 0; i < 4; ++i) P[i] = Dot(A[i], axis);

            float minA = *std::min_element(P, P + 4);
            float maxA = *std::max_element(P, P + 4);

            for (int i = 0; i < 4; ++i) P[i] = Dot(B[i], axis);

            float minB = *std::min_element(P, P + 4);
            float maxB = *std::max_element(P, P + 4);

            if (maxA < minB || minA > maxB)
                return false;
        }

        return true;
    }

    static inline bool IsColliding(Circle &a,Circle &b) {
        const float dist = a.dist_circle_plane(b);
        return dist < a.radius + b.radius;
    }

    static inline bool IsColliding(Circle &a, Rect &b, float angle_b) {
        Vec2 B[] = {
                {b.x,b.y+b.h},
                {b.x + b.w, b.y+b.h},
                {b.x + b.w, b.y},
                {b.x,b.y}
        };

        for(auto& v: B) {
            v = Rotate(v - (Vec2)b.get_center(), angle_b) + (Vec2)b.get_center();
        }

        Vec2 axes[] = {Norm(B[0] - B[1]), Norm(B[1] - B[2])};
        for(auto& axis: axes) {
            float P[4];
            for(int i = 0; i < 4; ++i) P[i] = Dot(B[i], axis);

            float minB = *std::min_element(P,P + 4);
            float maxB = *std::max_element(P, P + 4);

            Vec2 v = (Vec2::right()*a.radius).rotate(axis.incl());
            Vec2 a1 = Vec2(a)+v;
            Vec2 a2 = Vec2(a)-v;
            float p1 = Dot(a1,axis);
            float p2 = Dot(a2,axis);

            float minA = std::min(p1,p2);
            float maxA = std::max(p1,p2);

            if(maxA < minB || minA > maxB)
                return false;
        }
        return true;
    }

private:

    static inline float Mag(const Vec2& p) {
        return std::sqrt(p.x * p.x + p.y * p.y);
    }

    static inline Vec2 Norm(const Vec2& p) {
        return {p.x * (1.f / Mag(p)), p.y * (1.f / Mag(p))};
    }

    static inline float Dot(const Vec2& a, const Vec2& b) {
        return a.x * b.x + a.y * b.y;
    }

    static inline Vec2 Rotate(const Vec2& p, float angle) {
        float cs = std::cos(angle), sn = std::sin(angle);
        return {p.x * cs - p.y * sn, p.x * sn + p.y * cs} ;
    }
};

#endif