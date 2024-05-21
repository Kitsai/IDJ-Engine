//
// Created by kitsai on 17/05/24.
//

#include "InputManager.h"

namespace fyrebird {
    InputManager *InputManager::_instance = nullptr;

    InputManager &InputManager::Instance() {
        if (!_instance) _instance = new InputManager();
        return *_instance;
    }

    InputManager::InputManager() : _mouse(0, 0) {
        for (integer i = 0; i < 6; i++) {
            _mouse_state[i] = false;
            _mouse_update[i] = 0;
        }

        for (integer i = 0; i < 416; i++) {
            _key_state[i] = false;
            _key_update[i] = 0;
        }

        _quit_requested = false;
        _update_counter = 0;
    }

    bool InputManager::quit_requested() const {
        return _quit_requested;
    }

    Vec2Int InputManager::get_mouse() {
        return _mouse;
    }

    bool InputManager::key_press(integer key) const {
        if (key > 0x40000000) key -= 0x3FFFFF81;
        const bool pressed = _key_state[key];
        const bool updated = _key_update[key] == _update_counter;
        return pressed && updated;
    }

    bool InputManager::key_release(integer key) const {
        if (key > 0x40000000) key -= 0x3FFFFF81;
        const bool pressed = _key_state[key];
        const bool updated = _key_update[key] == _update_counter;
        return pressed && updated;
    }

    bool InputManager::is_key_down(integer key) const {
        if (key > 0x40000000) key -= 0x3FFFFF81;
        const bool pressed = _key_state[key];
        return pressed;
    }

    bool InputManager::mouse_press(const integer button) const {
        const bool pressed = _mouse_state[button];
        const bool updated = _mouse_update[button];
        return pressed && updated;
    }

    bool InputManager::mouse_release(const integer button) const {
        const bool pressed = _mouse_state[button];
        const bool updated = _mouse_update[button];
        return !pressed && updated;
    }

    bool InputManager::is_mouse_down(const integer button) const {
        const bool pressed = _mouse_state[button];
        return pressed;
    }

    void InputManager::update() {
        SDL_Event event;

        SDL_GetMouseState(&_mouse.x, &_mouse.y);

        _update_counter++;

        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) _quit_requested = true;

            if (event.type == SDL_MOUSEBUTTONDOWN || event.type == SDL_MOUSEBUTTONUP) {
                _mouse_state[event.button.button] = event.type == SDL_MOUSEBUTTONDOWN;
                _mouse_update[event.button.button] = _update_counter;
            }

            if ((event.type == SDL_KEYDOWN || event.type == SDL_KEYUP) && event.key.repeat == 0) {
                integer idx = event.key.keysym.sym;
                if (idx > 0x40000000) idx -= 0x3FFFFF81;
                _key_state[idx] = event.type == SDL_KEYDOWN;
                _key_update[idx] = _update_counter;
            }
        }
    }
}