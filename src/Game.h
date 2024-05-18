//
// Created by luck3 on 5/18/2024.
//

#ifndef IDJ_ENGINE_GAME_H
#define IDJ_ENGINE_GAME_H

#include "State.h"
#include "SDL2/SDL.h"
#include <stack>
#include <memory>

class Game {
private:
    static Game* _instance;
    Game(const char *title, int width, int height);

    unsigned _frame_start;
    float dt;
    void calculate_delta_time();

    std::unique_ptr<State> _stored_state;
    std::unique_ptr<SDL_Window> _window;
    std::unique_ptr<SDL_Renderer> _renderer;
    std::stack<std::unique_ptr<State>> _state_stack;

    int _window_width;
    int _window_height;
public:
    Game(const Game&) = delete;
    Game(Game&&) noexcept = default;

    ~Game();

    static Game& Instance();
    SDL_Renderer &Renderer();
    State &current_state();

    void push(State *state);

    void run();

    void delta_time();
    void window_width();
    void window_height();
};


#endif //IDJ_ENGINE_GAME_H
