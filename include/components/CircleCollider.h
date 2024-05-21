//
// Created by luck3 on 5/20/2024.
//

#ifndef IDJ_ENGINE_CIRCLECOLLIDER_H
#define IDJ_ENGINE_CIRCLECOLLIDER_H

#include "Collider.h"
#include "arith/Circle.h"

namespace fyrebird {
    class CircleCollider : public Collider {
    public:
        Circle circle;
    };


}

#endif //IDJ_ENGINE_CIRCLECOLLIDER_H
