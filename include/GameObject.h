//
// Created by luck3 on 5/18/2024.
//

#ifndef IDJ_ENGINE_GAMEOBJECT_H
#define IDJ_ENGINE_GAMEOBJECT_H

#include "components/Component.h"
#include "exceptions/ComponentNotFoundException.h"
#include "arith/Rect.h"
#include <vector>

namespace fyrebird {
    class GameObject {
    private:
        std::vector<std::shared_ptr<Component>> _component_array;
        bool _is_dead;
        bool _started;
    public:
        Rect box;
        float angle_deg;

        GameObject();

        ~GameObject();

        void start();

        void update();

        void fixed_update();

        void render();

        [[nodiscard]] bool is_dead() const;

        void request_delete();

        std::weak_ptr<Component> add_component(Component *cpt);

        void remove_component(Component *cpt);

        std::weak_ptr<Component> get_component(const std::string &type);

//        std::weak_ptr<Component> get_component()

        void notify_collision(GameObject &other);
    };
}

#endif //IDJ_ENGINE_GAMEOBJECT_H
