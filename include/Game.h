//
// Created by luck3 on 5/19/2024.
//

#ifndef IDJ_ENGINE_GAME_H
#define IDJ_ENGINE_GAME_H

#include "State.h"
#include "SDL2/SDL.h"
#include "settings/Settings.h"
#include "time/Time.h"
#include "InputManager.h"
#include "Resources.h"
#include <memory>
#include <stack>

namespace fyrebird {
    class Game {
    private:
        struct SDLWindowDestroyer {
            void operator()(SDL_Window *w) const {
                SDL_DestroyWindow(w);
            }
        };

        struct SDLRendererDestroyer {
            void operator()(SDL_Renderer *w) const {
                SDL_DestroyRenderer(w);
            }
        };

        static std::unique_ptr<Game> _instance;

        Game();

        std::unique_ptr<State> _stored_state;
        std::unique_ptr<SDL_Window, SDLWindowDestroyer> _window;
        std::unique_ptr<SDL_Renderer, SDLRendererDestroyer> _renderer;
        std::stack<std::unique_ptr<State>> _state_stack;
    public:
        Game(const Game &) = delete;

        Game(Game &&) noexcept = default;

        ~Game();

        static Game &Instance();

        SDL_Renderer &Renderer();

        State &current_state();

        void push(State *state);

        void run();
    };
}

#endif //IDJ_ENGINE_GAME_H
