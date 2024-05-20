//
// Created by luck3 on 5/19/2024.
//

#ifndef IDJ_ENGINE_BOXCOLLIDER_H
#define IDJ_ENGINE_BOXCOLLIDER_H

#include "Collider.h"
#include "arith/Vec2.h"
#include "arith/Rect.h"
#include "Defines.cpp"
#include "SDL2/SDL.h"

#include <vector>

class BoxCollider: public Collider {
public:
    explicit BoxCollider(GameObject& associated, Vec2 scale = {1, 1}, Vec2 offset = {0, 0}, SDL_Color color = COLOR_RED);

    Rect box;
    bool active;

    void update() override;
    void render() override;
    bool is(std::string type) override;

    [[nodiscard]] Vec2 get_center() const override;

    std::vector<Vec2> get_points();

    bool is_colliding(GameObject &other) override;
};

#endif //IDJ_ENGINE_BOXCOLLIDER_H