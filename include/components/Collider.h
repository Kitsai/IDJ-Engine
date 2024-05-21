//
// Created by luck3 on 5/20/2024.
//

#ifndef IDJ_ENGINE_COLLIDER_H
#define IDJ_ENGINE_COLLIDER_H

#include "Component.h"
#include "arith/Vec2.h"
#include "SDL2/SDL.h"
#include "Defines.h"
#include "physics/Collision.cpp"

namespace fyrebird {
    class Collider : public Component {
    protected:
        Vec2 scale;
        Vec2 offset;
        SDL_Color color;
    public:
        explicit Collider(GameObject &associated, Vec2 scale = {1, 1}, Vec2 offset = {0, 0},
                          SDL_Color color = COLOR_RED);

        bool active;

        bool is(std::string type) override;

        void set_scale(Vec2 s);

        void set_offset(Vec2 offs);

        void set_color(SDL_Color c);

        [[nodiscard]] virtual Vec2 get_center() const = 0;

        virtual bool is_colliding(GameObject &other) = 0;
    };
}

#endif //IDJ_ENGINE_COLLIDER_H
