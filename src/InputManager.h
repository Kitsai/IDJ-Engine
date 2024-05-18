//
// Created by kitsai on 17/05/24.
//

#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

#include "arith/Vec2Int.h"
#include "SDL2/SDL.h"

class InputManager {
private:
    static InputManager *_instance;

    InputManager();

    bool _mouse_state[6]{};
    unsigned _mouse_update[6]{};

    bool _key_state[416]{};
    unsigned _key_update[416]{};

    bool _quit_requested;
    unsigned _update_counter;

    Vec2Int _mouse;

public:
    static InputManager &Instance();

    InputManager(InputManager& im) = delete;
    InputManager& operator=(const InputManager&) = delete;

    [[nodiscard]] bool quit_requested() const;
    Vec2Int get_mouse();

    [[nodiscard]] bool key_press(int key) const;
    [[nodiscard]] bool key_release(int key) const ;
    [[nodiscard]] bool is_key_down(int key) const;

    [[nodiscard]] bool mouse_press(int button) const;
    [[nodiscard]] bool mouse_release(int button) const;
    [[nodiscard]] bool is_mouse_down(int button) const;

    void update();
};

#endif //INPUTMANAGER_H
