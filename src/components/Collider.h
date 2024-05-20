//
// Created by luck3 on 5/19/2024.
//

#ifndef IDJ_ENGINE_COLLIDER_H
#define IDJ_ENGINE_COLLIDER_H

#include "Component.h"
#include "arith/Vec2.h"
#include "arith/Rect.h"
#include "Defines.cpp"
#include "SDL2/SDL.h"
#include "Collision.cpp"

#include <vector>

class Collider: public Component {
private:
    Vec2 scale;
    Vec2 offset;
    SDL_Color color;
public:
    explicit Collider(GameObject& associated, Vec2 scale = {1,1}, Vec2 offset = {0,0}, SDL_Color color = COLOR_RED);

    Rect box;
    bool active;

    void update() override;
    void render() override;
    bool is(std::string type) override;

    void set_scale(Vec2 s);
    void set_offset(Vec2 offs);
    void set_color(SDL_Color c);

    [[nodiscard]] Vec2 get_center() const;

    std::vector<Vec2> get_points();

    bool is_colliding(Rect& other_box, float other_angle);
};

#endif //IDJ_ENGINE_COLLIDER_H