//
// Created by luck3 on 5/19/2024.
//

#include <utility>

#include "components/Camera.h"


namespace fyrebird {
    std::shared_ptr<Camera> Camera::current_camera = {};

    void Camera::follow(std::weak_ptr<GameObject> focus) {
        _focus = std::move(focus);
    }

    void Camera::unfollow() {
        _focus.reset();
    }

    void Camera::update() {
        if (!_focus.expired()) {
            _associated.box;
        }
    }

    Vec2 Camera::pos() {
        return (Vec2) _associated.box;
    }

    Camera::Camera(GameObject &assoc, bool set_as_current) : Component(assoc) {
        if (set_as_current)
            current_camera = std::shared_ptr<Camera>(this);
    }
}