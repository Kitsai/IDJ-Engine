//
// Created by luck3 on 5/18/2024.
//

#ifndef IDJ_ENGINE_COMPONENT_H
#define IDJ_ENGINE_COMPONENT_H

#include <string>
#include <memory>

class GameObject;

class Component {
protected:
    GameObject &_associated;
public:
    Component(GameObject &assoc);
    virtual ~Component();

    void virtual update(float dt);
    void virtual fixed_update();
    void virtual render();
    bool virtual is(std::string type) = 0;

    void virtual start();

    void virtual notify_collision(GameObject &other);
};


#endif //IDJ_ENGINE_COMPONENT_H
