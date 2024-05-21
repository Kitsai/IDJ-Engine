//
// Created by luck3 on 5/18/2024.
//

#ifndef IDJ_ENGINE_COMPONENT_H
#define IDJ_ENGINE_COMPONENT_H

#include <string>
#include <memory>

namespace fyrebird {
    class GameObject;

    class Component {
    protected:
        GameObject &_associated;
    public:
        explicit Component(GameObject &assoc);

        virtual ~Component();

        virtual void update();

        virtual void fixed_update();

        virtual void render();

        virtual bool is(std::string type) = 0;

        virtual void start();

        virtual void notify_collision(GameObject &other);
    };
}

#endif //IDJ_ENGINE_COMPONENT_H
