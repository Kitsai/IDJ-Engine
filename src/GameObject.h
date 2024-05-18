//
// Created by luck3 on 5/18/2024.
//

#ifndef IDJ_ENGINE_GAMEOBJECT_H
#define IDJ_ENGINE_GAMEOBJECT_H

#include "components/Component.h"
#include "arith/Rect.h"
#include <vector>

class GameObject {
private:
    std::vector<std::unique_ptr<Component>> _component_array;
    bool _is_dead;
    bool _started;
public:
    Rect box;
    double angle_deg;

    GameObject();
    ~GameObject();

    void start();
    void update(float dt);
    void fixed_update();
    void render();

    bool is_dead();
    void request_delete();

    Component &add_component(Component* cpt);
    void remove_component(Component &cpt);
    Component &get_component(std::string type);

    void notify_collision(GameObject& other);
};


#endif //IDJ_ENGINE_GAMEOBJECT_H
