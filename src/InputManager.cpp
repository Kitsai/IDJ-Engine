//
// Created by kitsai on 17/05/24.
//

#include "InputManager.h"

InputManager *InputManager::_instance = nullptr;

InputManager &InputManager::GetInstance() {
    if (!_instance) _instance = new InputManager();
    return *_instance;
}

InputManager::InputManager(): _mouse(0, 0) {
    for (int i = 0; i < 6; i++) {
        _mouse_state[i] = false;
        _mouse_update[i] = 0;
    }

    for (int i = 0; i < 416; i++) {
        _key_state[i] = false;
        _key_update[i] = 0;
    }

    _quit_requested = false;
    _update_counter = 0;
}

bool InputManager::quit_requested() const  {
    return _quit_requested;
}

Vec2 InputManager::get_mouse() {
    return _mouse;
}

bool InputManager::key_press(int key) const {
    if (key > 0x40000000) key -= 0x3FFFFF81;
    const bool pressed = _key_state[key];
    const bool updated = _key_update[key] == _update_counter;
    return pressed && updated;
}

bool InputManager::key_release(int key) const {
    if (key > 0x40000000) key -= 0x3FFFFF81;
    const bool pressed = _key_state[key];
    const bool updated = _key_update[key] == _update_counter;
    return pressed && updated;
}

bool InputManager::is_key_down(int key) const {
    if (key > 0x40000000) key -= 0x3FFFFF81;
    const bool pressed = _key_state[key];
    return pressed;
}

bool InputManager::mouse_press(const int button) const {
    const bool pressed = _mouse_state[button];
    const bool updated = _mouse_update[button];
    return pressed && updated;
}

bool InputManager::mouse_release(const int button) const {
    const bool pressed = _mouse_state[button];
    const bool updated = _mouse_update[button];
    return !pressed && updated;
}

bool InputManager::is_mouse_down(const int button) const {
    const bool pressed = _mouse_state[button];
    return pressed;
}

void InputManager::update() {
    SDL_Event event;


}
