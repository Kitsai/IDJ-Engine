//
// Created by luck3 on 5/19/2024.
//

#ifndef IDJ_ENGINE_CAMERA_H
#define IDJ_ENGINE_CAMERA_H

#include "GameObject.h"

class Camera: public Component {
protected:
    std::weak_ptr<GameObject> _focus;
public:
     static std::shared_ptr<Camera> current_camera;

     void follow(std::weak_ptr<GameObject> focus);
     void unfollow();
     void update() override;
     Vec2 pos();

     explicit Camera(GameObject &assoc, bool set_as_current = false);
};

#endif //IDJ_ENGINE_CAMERA_H
